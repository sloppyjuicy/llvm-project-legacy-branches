; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -slp-vectorizer < %s -S -mtriple="x86_64-grtev3-linux-gnu" -mcpu=corei7-avx | FileCheck %s

target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"

; We used to crash on this example because we were building a constant
; expression during vectorization and the vectorizer expects instructions
; as elements of the vectorized tree.
; PR19621

define void @test() {
; CHECK-LABEL: @test(
; CHECK-NEXT:  bb279:
; CHECK-NEXT:    br label [[BB283:%.*]]
; CHECK:       bb283:
; CHECK-NEXT:    [[TMP0:%.*]] = phi <2 x float> [ undef, [[BB279:%.*]] ], [ [[TMP11:%.*]], [[EXIT:%.*]] ]
; CHECK-NEXT:    [[TMP1:%.*]] = phi <2 x float> [ undef, [[BB279]] ], [ [[TMP15:%.*]], [[EXIT]] ]
; CHECK-NEXT:    br label [[BB284:%.*]]
; CHECK:       bb284:
; CHECK-NEXT:    [[TMP2:%.*]] = fpext <2 x float> [[TMP0]] to <2 x double>
; CHECK-NEXT:    [[TMP3:%.*]] = fsub <2 x double> [[TMP2]], undef
; CHECK-NEXT:    [[TMP4:%.*]] = fsub <2 x double> [[TMP3]], undef
; CHECK-NEXT:    br label [[BB21_I:%.*]]
; CHECK:       bb21.i:
; CHECK-NEXT:    br i1 undef, label [[BB22_I:%.*]], label [[EXIT]]
; CHECK:       bb22.i:
; CHECK-NEXT:    [[TMP5:%.*]] = fadd <2 x double> undef, [[TMP4]]
; CHECK-NEXT:    br label [[BB32_I:%.*]]
; CHECK:       bb32.i:
; CHECK-NEXT:    [[TMP6:%.*]] = phi <2 x double> [ [[TMP5]], [[BB22_I]] ], [ zeroinitializer, [[BB32_I]] ]
; CHECK-NEXT:    br i1 undef, label [[BB32_I]], label [[BB21_I]]
; CHECK:       exit:
; CHECK-NEXT:    [[TMP7:%.*]] = fpext <2 x float> [[TMP1]] to <2 x double>
; CHECK-NEXT:    [[TMP8:%.*]] = fmul <2 x double> <double undef, double 0.000000e+00>, [[TMP7]]
; CHECK-NEXT:    [[TMP9:%.*]] = fadd <2 x double> undef, [[TMP8]]
; CHECK-NEXT:    [[TMP10:%.*]] = fadd <2 x double> undef, [[TMP9]]
; CHECK-NEXT:    [[TMP11]] = fptrunc <2 x double> [[TMP10]] to <2 x float>
; CHECK-NEXT:    [[TMP12:%.*]] = extractelement <2 x float> undef, i32 0
; CHECK-NEXT:    [[TMP13:%.*]] = insertelement <2 x float> undef, float [[TMP12]], i32 0
; CHECK-NEXT:    [[TMP14:%.*]] = extractelement <2 x float> undef, i32 1
; CHECK-NEXT:    [[TMP15]] = insertelement <2 x float> [[TMP13]], float [[TMP14]], i32 1
; CHECK-NEXT:    br label [[BB283]]
;
bb279:
  br label %bb283

bb283:
  %Av.sroa.8.0 = phi float [ undef, %bb279 ], [ %tmp315, %exit ]
  %Av.sroa.5.0 = phi float [ undef, %bb279 ], [ %tmp319, %exit ]
  %Av.sroa.3.0 = phi float [ undef, %bb279 ], [ %tmp307, %exit ]
  %Av.sroa.0.0 = phi float [ undef, %bb279 ], [ %tmp317, %exit ]
  br label %bb284

bb284:
  %tmp7.i = fpext float %Av.sroa.3.0 to double
  %tmp8.i = fsub double %tmp7.i, undef
  %tmp9.i = fsub double %tmp8.i, undef
  %tmp17.i = fpext float %Av.sroa.8.0 to double
  %tmp19.i = fsub double %tmp17.i, undef
  %tmp20.i = fsub double %tmp19.i, undef
  br label %bb21.i

bb21.i:
  br i1 undef, label %bb22.i, label %exit

bb22.i:
  %tmp24.i = fadd double undef, %tmp9.i
  %tmp26.i = fadd double undef, %tmp20.i
  br label %bb32.i

bb32.i:
  %xs.0.i = phi double [ %tmp24.i, %bb22.i ], [ 0.000000e+00, %bb32.i ]
  %ys.0.i = phi double [ %tmp26.i, %bb22.i ], [ 0.000000e+00, %bb32.i ]
  br i1 undef, label %bb32.i, label %bb21.i

exit:
  %tmp303 = fpext float %Av.sroa.0.0 to double
  %tmp304 = fmul double %tmp303, undef
  %tmp305 = fadd double undef, %tmp304
  %tmp306 = fadd double %tmp305, undef
  %tmp307 = fptrunc double %tmp306 to float
  %tmp311 = fpext float %Av.sroa.5.0 to double
  %tmp312 = fmul double %tmp311, 0.000000e+00
  %tmp313 = fadd double undef, %tmp312
  %tmp314 = fadd double %tmp313, undef
  %tmp315 = fptrunc double %tmp314 to float
  %tmp317 = fptrunc double undef to float
  %tmp319 = fptrunc double undef to float
  br label %bb283
}

; Make sure that we probably handle constant folded vectorized trees. The
; vectorizer starts at the type (%t2, %t3) and wil constant fold the tree.
; The code that handles insertelement instructions must handle this.
define <4 x double> @constant_folding() {
; CHECK-LABEL: @constant_folding(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = extractelement <2 x double> <double 1.000000e+00, double 2.000000e+00>, i32 0
; CHECK-NEXT:    [[I1:%.*]] = insertelement <4 x double> undef, double [[TMP0]], i32 1
; CHECK-NEXT:    [[TMP1:%.*]] = extractelement <2 x double> <double 1.000000e+00, double 2.000000e+00>, i32 1
; CHECK-NEXT:    [[I2:%.*]] = insertelement <4 x double> [[I1]], double [[TMP1]], i32 0
; CHECK-NEXT:    ret <4 x double> [[I2]]
;
entry:
  %t0 = fadd double 1.000000e+00 , 0.000000e+00
  %t1 = fadd double 1.000000e+00 , 1.000000e+00
  %t2 = fmul double %t0, 1.000000e+00
  %i1 = insertelement <4 x double> undef, double %t2, i32 1
  %t3 = fmul double %t1, 1.000000e+00
  %i2 = insertelement <4 x double> %i1, double %t3, i32 0
  ret <4 x double> %i2
}
