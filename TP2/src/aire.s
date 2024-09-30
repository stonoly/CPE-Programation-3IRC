	.arch armv8-a
	.file	"aire.c"
	.text
	.align	2
	.p2align 4,,11
	.global	calculer_aire
	.type	calculer_aire, %function
calculer_aire:
.LFB0:
	.cfi_startproc
	adrp	x0, .LC0
	fcvt	d0, s0
	ldr	d1, [x0, #:lo12:.LC0]
	fmul	d1, d0, d1
	fmul	d0, d1, d0
	fcvt	s0, d0
	ret
	.cfi_endproc
.LFE0:
	.size	calculer_aire, .-calculer_aire
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC1:
	.string	"L'aire du cercle de rayon %.2f est %.2f\n"
	.section	.text.startup,"ax",@progbits
	.align	2
	.p2align 4,,11
	.global	main
	.type	main, %function
main:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	adrp	x0, .LC2
	fmov	d0, 5.0e+0
	mov	x29, sp
	ldr	d1, [x0, #:lo12:.LC2]
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	printf
	mov	w0, 0
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align	3
.LC0:
	.word	1413754136
	.word	1074340347
	.align	3
.LC2:
	.word	1610612736
	.word	1079222924
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
