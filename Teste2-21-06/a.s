	.file	"filtro.c"
	.text
	.globl	filtro
	.type	filtro, @function
filtro:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rdi
	movl	$2, -116(%rbp)
	movl	$4, -112(%rbp)
	movl	-112(%rbp), %eax
	subl	-116(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -108(%rbp)
	movl	-108(%rbp), %edx
	movslq	%edx, %rax
	subq	$1, %rax
	movq	%rax, -104(%rbp)
	movslq	%edx, %rax
	movq	%rax, -144(%rbp)
	movq	$0, -136(%rbp)
	movslq	%edx, %rax
	movq	%rax, %r14
	movl	$0, %r15d
	movslq	%edx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -96(%rbp)
	movl	-112(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -88(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	movslq	%eax, %rdx
	movq	%rdx, %rbx
	movl	$0, %esi
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -80(%rbp)
	movl	-116(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -64(%rbp)
	movl	$0, -124(%rbp)
	jmp	.L2
.L5:
	movl	$0, -120(%rbp)
	jmp	.L3
.L4:
	movq	-96(%rbp), %rax
	movl	-124(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-64(%rbp), %rax
	movl	-120(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %esi
	movl	-124(%rbp), %edx
	movl	-120(%rbp), %eax
	addl	%eax, %edx
	movq	-80(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	imull	%esi, %eax
	addl	%eax, %ecx
	movq	-96(%rbp), %rax
	movl	-124(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -120(%rbp)
.L3:
	movl	-120(%rbp), %eax
	cmpl	-116(%rbp), %eax
	jl	.L4
	addl	$1, -124(%rbp)
.L2:
	movl	-124(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jl	.L5
	movq	%rdi, %rsp
	nop
	movq	-56(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L6
	call	__stack_chk_fail
.L6:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	filtro, .-filtro
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	filtro
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2.1) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
