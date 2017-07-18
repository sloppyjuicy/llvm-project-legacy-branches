; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=i686-unknown-unknown   -mattr=+avx,+f16c | FileCheck %s --check-prefix=X32
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=+avx,+f16c | FileCheck %s --check-prefix=X64

define <4 x float> @test_x86_vcvtph2ps_128(<8 x i16> %a0) {
; X32-LABEL: test_x86_vcvtph2ps_128:
; X32:       # BB#0:
; X32-NEXT:    vcvtph2ps %xmm0, %xmm0
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtph2ps_128:
; X64:       # BB#0:
; X64-NEXT:    vcvtph2ps %xmm0, %xmm0
; X64-NEXT:    retq
  %res = call <4 x float> @llvm.x86.vcvtph2ps.128(<8 x i16> %a0) ; <<4 x float>> [#uses=1]
  ret <4 x float> %res
}
declare <4 x float> @llvm.x86.vcvtph2ps.128(<8 x i16>) nounwind readonly


define <8 x float> @test_x86_vcvtph2ps_256(<8 x i16> %a0) {
; X32-LABEL: test_x86_vcvtph2ps_256:
; X32:       # BB#0:
; X32-NEXT:    vcvtph2ps %xmm0, %ymm0
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtph2ps_256:
; X64:       # BB#0:
; X64-NEXT:    vcvtph2ps %xmm0, %ymm0
; X64-NEXT:    retq
  %res = call <8 x float> @llvm.x86.vcvtph2ps.256(<8 x i16> %a0) ; <<8 x float>> [#uses=1]
  ret <8 x float> %res
}
declare <8 x float> @llvm.x86.vcvtph2ps.256(<8 x i16>) nounwind readonly

define <8 x float> @test_x86_vcvtph2ps_256_m(<8 x i16>* nocapture %a) nounwind {
; X32-LABEL: test_x86_vcvtph2ps_256_m:
; X32:       # BB#0:
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtph2ps (%eax), %ymm0
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtph2ps_256_m:
; X64:       # BB#0:
; X64-NEXT:    vcvtph2ps (%rdi), %ymm0
; X64-NEXT:    retq
  %load = load <8 x i16>, <8 x i16>* %a, align 16
  %res = tail call <8 x float> @llvm.x86.vcvtph2ps.256(<8 x i16> %load)
  ret <8 x float> %res
}

define <8 x i16> @test_x86_vcvtps2ph_128(<4 x float> %a0) {
; X32-LABEL: test_x86_vcvtps2ph_128:
; X32:       # BB#0:
; X32-NEXT:    vcvtps2ph $0, %xmm0, %xmm0
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_128:
; X64:       # BB#0:
; X64-NEXT:    vcvtps2ph $0, %xmm0, %xmm0
; X64-NEXT:    retq
  %res = call <8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float> %a0, i32 0) ; <<8 x i16>> [#uses=1]
  ret <8 x i16> %res
}
declare <8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float>, i32) nounwind readonly

define <8 x i16> @test_x86_vcvtps2ph_256(<8 x float> %a0) {
; X32-LABEL: test_x86_vcvtps2ph_256:
; X32:       # BB#0:
; X32-NEXT:    vcvtps2ph $0, %ymm0, %xmm0
; X32-NEXT:    vzeroupper
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_256:
; X64:       # BB#0:
; X64-NEXT:    vcvtps2ph $0, %ymm0, %xmm0
; X64-NEXT:    vzeroupper
; X64-NEXT:    retq
  %res = call <8 x i16> @llvm.x86.vcvtps2ph.256(<8 x float> %a0, i32 0) ; <<8 x i16>> [#uses=1]
  ret <8 x i16> %res
}
declare <8 x i16> @llvm.x86.vcvtps2ph.256(<8 x float>, i32) nounwind readonly

define <4 x float> @test_x86_vcvtps2ph_128_scalar(i64* %ptr) {
; X32-LABEL: test_x86_vcvtps2ph_128_scalar:
; X32:       # BB#0:
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtph2ps (%eax), %xmm0
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_128_scalar:
; X64:       # BB#0:
; X64-NEXT:    vcvtph2ps (%rdi), %xmm0
; X64-NEXT:    retq
  %load = load i64, i64* %ptr
  %ins1 = insertelement <2 x i64> undef, i64 %load, i32 0
  %ins2 = insertelement <2 x i64> %ins1, i64 0, i32 1
  %bc = bitcast <2 x i64> %ins2 to <8 x i16>
  %res = tail call <4 x float> @llvm.x86.vcvtph2ps.128(<8 x i16> %bc) #2
  ret <4 x float> %res
}

define <4 x float> @test_x86_vcvtps2ph_128_scalar2(i64* %ptr) {
; X32-LABEL: test_x86_vcvtps2ph_128_scalar2:
; X32:       # BB#0:
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtph2ps (%eax), %xmm0
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_128_scalar2:
; X64:       # BB#0:
; X64-NEXT:    vcvtph2ps (%rdi), %xmm0
; X64-NEXT:    retq
  %load = load i64, i64* %ptr
  %ins = insertelement <2 x i64> undef, i64 %load, i32 0
  %bc = bitcast <2 x i64> %ins to <8 x i16>
  %res = tail call <4 x float> @llvm.x86.vcvtph2ps.128(<8 x i16> %bc)
  ret <4 x float> %res
}

define void @test_x86_vcvtps2ph_256_m(<8 x i16>* nocapture %d, <8 x float> %a) nounwind {
; X32-LABEL: test_x86_vcvtps2ph_256_m:
; X32:       # BB#0: # %entry
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtps2ph $3, %ymm0, (%eax)
; X32-NEXT:    vzeroupper
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_256_m:
; X64:       # BB#0: # %entry
; X64-NEXT:    vcvtps2ph $3, %ymm0, (%rdi)
; X64-NEXT:    vzeroupper
; X64-NEXT:    retq
entry:
  %0 = tail call <8 x i16> @llvm.x86.vcvtps2ph.256(<8 x float> %a, i32 3)
  store <8 x i16> %0, <8 x i16>* %d, align 16
  ret void
}

define void @test_x86_vcvtps2ph_128_m(<4 x i16>* nocapture %d, <4 x float> %a) nounwind {
; X32-LABEL: test_x86_vcvtps2ph_128_m:
; X32:       # BB#0: # %entry
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtps2ph $3, %xmm0, (%eax)
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_128_m:
; X64:       # BB#0: # %entry
; X64-NEXT:    vcvtps2ph $3, %xmm0, (%rdi)
; X64-NEXT:    retq
entry:
  %0 = tail call <8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float> %a, i32 3)
  %1 = shufflevector <8 x i16> %0, <8 x i16> undef, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
  store <4 x i16> %1, <4 x i16>* %d, align 8
  ret void
}

define void @test_x86_vcvtps2ph_128_m2(double* nocapture %hf4x16, <4 x float> %f4x32) #0 {
; X32-LABEL: test_x86_vcvtps2ph_128_m2:
; X32:       # BB#0: # %entry
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtps2ph $3, %xmm0, (%eax)
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_128_m2:
; X64:       # BB#0: # %entry
; X64-NEXT:    vcvtps2ph $3, %xmm0, (%rdi)
; X64-NEXT:    retq
entry:
  %0 = tail call <8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float> %f4x32, i32 3)
  %1 = bitcast <8 x i16> %0 to <2 x double>
  %vecext = extractelement <2 x double> %1, i32 0
  store double %vecext, double* %hf4x16, align 8
  ret void
}

define void @test_x86_vcvtps2ph_128_m3(i64* nocapture %hf4x16, <4 x float> %f4x32) #0 {
; X32-LABEL: test_x86_vcvtps2ph_128_m3:
; X32:       # BB#0: # %entry
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    vcvtps2ph $3, %xmm0, (%eax)
; X32-NEXT:    retl
;
; X64-LABEL: test_x86_vcvtps2ph_128_m3:
; X64:       # BB#0: # %entry
; X64-NEXT:    vcvtps2ph $3, %xmm0, (%rdi)
; X64-NEXT:    retq
entry:
  %0 = tail call <8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float> %f4x32, i32 3)
  %1 = bitcast <8 x i16> %0 to <2 x i64>
  %vecext = extractelement <2 x i64> %1, i32 0
  store i64 %vecext, i64* %hf4x16, align 8
  ret void
}
