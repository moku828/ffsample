all:
	sh-elf-gcc -c -Wa,-gstabs -o asmfunc.o asmfunc.s
	sh-elf-gcc -c -g -o mmc_rspi.o mmc_rspi.c
	sh-elf-gcc -c -g -o scif.o scif.c
	sh-elf-gcc -c -g -o ff.o ff.c
	sh-elf-gcc -c -g -o xprintf.o xprintf.c
	sh-elf-gcc -c -g -o luna_malloc.o luna_malloc.c
	sh-elf-gcc -c -g -o luna_fopen.o luna_fopen.c
	sh-elf-gcc -c -g -o main.o -I./include/ main.c
	sh-elf-gcc -c -g -o vecttbl.o vecttbl.c
	sh-elf-gcc -c -g -o resetprg.o resetprg.c
	sh-elf-ld -Tsh7262_large.ld -nostartfiles -o ffsample.elf asmfunc.o mmc_rspi.o scif.o ff.o xprintf.o luna_malloc.o luna_fopen.o main.o vecttbl.o resetprg.o -L. -lfreetype -L/usr/local/sh-tools/lib/gcc/sh-elf/3.4.5/m2 -lgcc -lc
	sh-elf-objcopy -j .text -j .data -O binary ffsample.elf ffsample.bin
clean:
	rm ffsample.elf ffsample.bin asmfunc.o mmc_rspi.o scif.o ff.o xprintf.o main.o vecttbl.o resetprg.o
