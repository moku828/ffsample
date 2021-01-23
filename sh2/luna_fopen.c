#include "ff.h"

FIL fil;

void* luna_fopen(const char* filename)
{
	FRESULT ret;
	ret = f_open(&fil, filename, FA_READ);
	return (void*)&fil;
}

long luna_fread(void* ptr, long size, long n, void* fp)
{
	UINT br = 0;
	f_read((FIL*)fp, ptr, size * n, &br);
	return br;
}

long luna_fseek(void* fp, long offset)
{
	f_lseek((FIL*)fp, offset);
	return 0;
}

long luna_fstat(void* fp)
{
	return f_size((FIL*)fp);
}

void luna_fclose(void* fp)
{
	f_close((FIL*)fp);
}
