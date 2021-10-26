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
	.p2align 4
	.globl	lcs_dp
	.def	lcs_dp;	.scl	2;	.type	32;	.endef
	.seh_proc	lcs_dp
lcs_dp:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$120, %rsp
	.seh_stackalloc	120
	.seh_endprologue
	movq	%rdx, %r14
	movq	%rcx, 104(%rsp)
	movq	%rcx, %r15
	call	strlen
	movq	%r14, %rcx
	movq	%rax, %rsi
	movq	%rax, 88(%rsp)
	call	strlen
	movl	$4, %edx
	movq	%rax, %rdi
	movq	%rax, 96(%rsp)
	movl	%esi, %eax
	movl	%edi, %ecx
	addl	$1, %eax
	addl	$1, %ecx
	movl	%eax, 84(%rsp)
	imull	%eax, %ecx
	movslq	%ecx, %rcx
	call	calloc
	movq	%rax, 56(%rsp)
	movq	%rax, %rcx
	testl	%esi, %esi
	jle	.L2
	movl	%esi, %eax
	movl	$0, 44(%rsp)
	movl	$1, %r13d
	movq	%r15, %rbp
	addl	%eax, %eax
	movl	$-1, 76(%rsp)
	cltq
	movl	$-1, 72(%rsp)
	leaq	8(%rcx,%rax,4), %rax
	movl	$0, 64(%rsp)
	movq	%rax, 32(%rsp)
	movl	%esi, 68(%rsp)
	leal	-1(%rdi), %esi
	movl	%edi, 80(%rsp)
	addq	$2, %rsi
	movq	%r14, %rdi
	movl	%r13d, %r14d
	.p2align 4,,10
	.p2align 3
.L3:
	movl	68(%rsp), %eax
	addl	44(%rsp), %eax
	movl	$1, %ebx
	leaq	.LC0(%rip), %r13
	movl	%eax, 48(%rsp)
	movl	80(%rsp), %eax
	leaq	.LC1(%rip), %r15
	testl	%eax, %eax
	jg	.L6
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L4:
	addq	$1, %rbx
	cmpq	%rsi, %rbx
	je	.L9
.L6:
	movzbl	-1(%rdi,%rbx), %eax
	movl	%ebx, %r8d
	cmpb	%al, 0(%rbp)
	jne	.L4
	movq	32(%rsp), %rax
	movq	56(%rsp), %r10
	movl	48(%rsp), %edx
	movl	(%rax), %ecx
	movl	44(%rsp), %eax
	addl	%ebx, %edx
	addl	%ebx, %eax
	movslq	%edx, %rdx
	cltq
	movl	-4(%r10,%rax,4), %eax
	addl	$1, %eax
	movl	%eax, (%r10,%rdx,4)
	cmpl	64(%rsp), %eax
	jle	.L5
	movl	%r14d, %edx
	movl	%eax, 64(%rsp)
	subl	%eax, %edx
	movl	%edx, 72(%rsp)
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	%edx, 76(%rsp)
.L5:
	movq	32(%rsp), %rax
	movl	(%rax), %r12d
	cmpl	%ecx, %r12d
	je	.L4
	movl	%r14d, %edx
	movq	%r13, %rcx
	addq	$1, %rbx
	call	printf
	movl	%r12d, %edx
	movq	%r15, %rcx
	call	printf
	cmpq	%rsi, %rbx
	jne	.L6
.L9:
	movl	48(%rsp), %ecx
	leal	1(%r14), %eax
	addq	$1, %rbp
	movl	%ecx, 44(%rsp)
	cmpl	84(%rsp), %eax
	je	.L7
	movl	%eax, %r14d
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L7:
	movl	$10, %ecx
	movl	80(%rsp), %ebx
	movl	$1, %r15d
	call	putchar
	movl	88(%rsp), %eax
	movl	%r14d, 44(%rsp)
	movq	%rdi, 48(%rsp)
	movl	%eax, 32(%rsp)
	movq	96(%rsp), %rax
	leal	-1(%rax), %r12d
	addq	$2, %r12
	.p2align 4,,10
	.p2align 3
.L11:
	testl	%ebx, %ebx
	jle	.L16
	movq	56(%rsp), %rsi
	movslq	32(%rsp), %rax
	movl	$1, %r13d
	movl	$32, %ebp
	movl	$10, %edi
	leaq	(%rsi,%rax,4), %r14
	leaq	.LC2(%rip), %rsi
	.p2align 4,,10
	.p2align 3
.L13:
	cmpl	%r13d, %ebx
	movl	%edi, %r8d
	movl	(%r14,%r13,4), %edx
	movq	%rsi, %rcx
	cmovne	%ebp, %r8d
	addq	$1, %r13
	call	printf
	cmpq	%r13, %r12
	jne	.L13
.L16:
	movl	68(%rsp), %esi
	leal	1(%r15), %eax
	addl	%esi, 32(%rsp)
	cmpl	%r15d, 44(%rsp)
	je	.L14
	movl	%eax, %r15d
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L14:
	movl	64(%rsp), %esi
	movq	48(%rsp), %r14
	testl	%esi, %esi
	jne	.L45
.L10:
	movq	56(%rsp), %rcx
	addq	$120, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	jmp	free
.L45:
	movq	104(%rsp), %rcx
	xorl	%ebp, %ebp
	movl	$94, %edi
	call	puts
	movl	72(%rsp), %ebx
	movl	72(%rsp), %r12d
	addl	%esi, %ebx
	movl	$32, %esi
	testl	%ebx, %ebx
	jle	.L21
	.p2align 4,,10
	.p2align 3
.L17:
	cmpl	%ebp, %r12d
	movl	%esi, %ecx
	cmovle	%edi, %ecx
	addl	$1, %ebp
	call	putchar
	cmpl	%ebx, %ebp
	jne	.L17
.L21:
	movl	$10, %ecx
	xorl	%r12d, %r12d
	movl	$94, %ebp
	movl	$32, %edi
	call	putchar
	movq	%r14, %rcx
	call	puts
	movl	64(%rsp), %esi
	addl	76(%rsp), %esi
	movl	76(%rsp), %r13d
	testl	%esi, %esi
	jle	.L19
	.p2align 4,,10
	.p2align 3
.L18:
	cmpl	%r12d, %r13d
	movl	%edi, %ecx
	cmovle	%ebp, %ecx
	addl	$1, %r12d
	call	putchar
	cmpl	%r12d, %esi
	jne	.L18
.L19:
	movl	$10, %ecx
	call	putchar
	movl	72(%rsp), %edi
	movl	64(%rsp), %r9d
	leaq	.LC3(%rip), %rcx
	movl	76(%rsp), %r8d
	movl	%edi, %edx
	call	printf
	cmpl	%ebx, %edi
	jge	.L2
	movslq	72(%rsp), %rax
	movq	104(%rsp), %rdi
	leaq	1(%rdi,%rax), %rsi
	leaq	(%rdi,%rax), %rbx
	movl	64(%rsp), %eax
	subl	$1, %eax
	addq	%rax, %rsi
	.p2align 4,,10
	.p2align 3
.L25:
	movsbl	(%rbx), %ecx
	addq	$1, %rbx
	call	putchar
	cmpq	%rsi, %rbx
	jne	.L25
.L2:
	movl	$10, %ecx
	call	putchar
	jmp	.L10
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC4:
	.ascii "abcdefghijk1\0"
.LC5:
	.ascii "1234567890\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	leaq	.LC4(%rip), %rdx
	leaq	.LC5(%rip), %rcx
	call	lcs_dp
	movl	$10, %ecx
	call	putchar
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 9.2.0"
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
