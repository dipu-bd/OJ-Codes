	.file	"outgen.cpp"
.lcomm __ZStL8__ioinit,1,1
	.globl	_test
	.bss
	.align 4
_test:
	.space 4
	.globl	_cas
	.data
	.align 4
_cas:
	.long	1
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "w\0"
	.align 4
LC1:
	.ascii "H:\\Dropbox\\Codes\\UVA Codes\\Volume 111\\11115 - Uncle Jack\\input.txt\0"
LC2:
	.ascii "%d %d\12\0"
LC3:
	.ascii "0 0\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	__imp___iob, %eax
	addl	$32, %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_freopen
	movl	$0, 28(%esp)
	jmp	L2
L5:
	movl	$1, 24(%esp)
	jmp	L3
L4:
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	incl	24(%esp)
L3:
	cmpl	$10, 24(%esp)
	setle	%al
	testb	%al, %al
	jne	L4
	incl	28(%esp)
L2:
	cmpl	$25, 28(%esp)
	setle	%al
	testb	%al, %al
	jne	L5
	movl	$LC3, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	ret
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L8
	cmpl	$65535, 12(%ebp)
	jne	L8
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L8:
	leave
	ret
	.section .rdata,"dr"
	.align 8
__ZL2PI:
	.long	1413754136
	.long	1074340347
	.align 8
__ZL4EXP1:
	.long	-1961601175
	.long	1074118410
	.text
	.def	__GLOBAL__sub_I_test;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_test:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_test
	.def	_freopen;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
