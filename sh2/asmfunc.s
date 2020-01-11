.global start
.global _set_imask
.global _RESET_Vectors
.global _sleep
.global _set_vbr
.global _set_fpscr
.extern _main
.extern _PowerON_Reset_PC
.extern _Manual_Reset_PC

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
_sleep:
	SLEEP
	NOP
	RTS
	NOP
_set_vbr:
	LDC     R4, VBR
	RTS
	NOP
_set_fpscr:
	LDS     R4, FPSCR
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

.section .VECTTBL, "a"
	.align  4
_RESET_Vectors:
	.long   _PowerON_Reset_PC
	.long   stack_base
	.long   _Manual_Reset_PC
	.long   stack_base
