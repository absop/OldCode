	.file	"lcs.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "dp(2, 2) changed at (%d, %d)\12\0"
.LC1:
	.ascii "dp(2,2) = %d\12\0"
.LC2:
	.ascii "%3d%c\0"
.LC3:
	.ascii "(%d, %d)[%d]\12\0"
	.text
	.globl	lcs_dp
	.def	lcs_dp;	.scl	2;	.type	32;	.endef
	.seh_proc	lcs_dp
lcs_dp:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rcx
	call	strlen
	movl	%eax, -44(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movl	%eax, -48(%rbp)
	movl	$0, -4(%rbp)
	movl	-44(%rbp), %eax
	leal	1(%rax), %edx
	movl	-48(%rbp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	cltq
	movl	$4, %edx
	movq	%rax, %rcx
	call	calloc
	movq	%rax, -56(%rbp)
	movl	$-1, -8(%rbp)
	movl	$-1, -12(%rbp)
	movl	$1, -16(%rbp)
	jmp	.L2
.L7:
	movl	$1, -20(%rbp)
	jmp	.L3
.L6:
	movl	-44(%rbp), %eax
	addl	%eax, %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -60(%rbp)
	movl	-16(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movl	-20(%rbp), %eax
	cltq
	leaq	-1(%rax), %rcx
	movq	24(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L4
	movl	-16(%rbp), %eax
	subl	$1, %eax
	imull	-44(%rbp), %eax
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	imull	-44(%rbp), %eax
	movl	%eax, %ecx
	movl	-20(%rbp), %eax
	addl	%ecx, %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	addl	$1, %edx
	movl	%edx, (%rax)
	movl	-16(%rbp), %eax
	imull	-44(%rbp), %eax
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jge	.L4
	movl	-16(%rbp), %eax
	imull	-44(%rbp), %eax
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %eax
	subl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-20(%rbp), %eax
	subl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
.L4:
	movl	-44(%rbp), %eax
	addl	%eax, %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -60(%rbp)
	je	.L5
	movl	-20(%rbp), %edx
	movl	-16(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	-44(%rbp), %eax
	addl	%eax, %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
.L5:
	addl	$1, -20(%rbp)
.L3:
	movl	-20(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jle	.L6
	addl	$1, -16(%rbp)
.L2:
	movl	-16(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jle	.L7
	movl	$10, %ecx
	call	putchar
	movl	$1, -24(%rbp)
	jmp	.L8
.L13:
	movl	$1, -28(%rbp)
	jmp	.L9
.L12:
	movl	-28(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jne	.L10
	movl	$10, %ecx
	jmp	.L11
.L10:
	movl	$32, %ecx
.L11:
	movl	-24(%rbp), %eax
	imull	-44(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%ecx, %r8d
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	addl	$1, -28(%rbp)
.L9:
	movl	-28(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jle	.L12
	addl	$1, -24(%rbp)
.L8:
	movl	-24(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jle	.L13
	cmpl	$0, -4(%rbp)
	jle	.L14
	movq	16(%rbp), %rcx
	call	puts
	movl	$0, -32(%rbp)
	jmp	.L15
.L18:
	movl	-8(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jg	.L16
	movl	$94, %eax
	jmp	.L17
.L16:
	movl	$32, %eax
.L17:
	movl	%eax, %ecx
	call	putchar
	addl	$1, -32(%rbp)
.L15:
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	cmpl	%eax, -32(%rbp)
	jl	.L18
	movl	$10, %ecx
	call	putchar
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, -36(%rbp)
	jmp	.L19
.L22:
	movl	-12(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jg	.L20
	movl	$94, %eax
	jmp	.L21
.L20:
	movl	$32, %eax
.L21:
	movl	%eax, %ecx
	call	putchar
	addl	$1, -36(%rbp)
.L19:
	movl	-12(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	cmpl	%eax, -36(%rbp)
	jl	.L22
	movl	$10, %ecx
	call	putchar
	movl	-4(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movl	-8(%rbp), %eax
	movl	%eax, -40(%rbp)
	jmp	.L23
.L24:
	movl	-40(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	putchar
	addl	$1, -40(%rbp)
.L23:
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	cmpl	%eax, -40(%rbp)
	jl	.L24
	movl	$10, %ecx
	call	putchar
.L14:
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	free
	nop
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC4:
	.ascii "abcdefghijk1\0"
.LC5:
	.ascii "1234567890\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	leaq	.LC4(%rip), %rdx
	leaq	.LC5(%rip), %rcx
	call	lcs_dp
	movl	$10, %ecx
	call	putchar
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 9.2.0"
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
