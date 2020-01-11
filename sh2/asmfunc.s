.global start
.global _set_imask
.extern _main

.section .stack, "w"
	.align  4
	.space  65536
stack_base:

.section .text, "ax"

start:
	MOV.L   _stack_base, SP
	MOV.L   __main, R0
	JSR     @R0
	NOP
loop:
	BRA     loop
	NOP
_set_imask:
	MOV.L   __imask, R0
	SHLL2   R4
	SHLL2   R4
	AND     R0, R4
	NOT     R0, R0
	STC     SR, R1
	AND     R0, R4
	OR      R4, R1
	LDC     R1, SR
	RTS
	NOP

	.align  4
__main:
	.long   _main
_stack_base:
	.long   stack_base
__imask:
	.long   0x000000F0

.section .bss, "aw"

.section .text, "ax"

