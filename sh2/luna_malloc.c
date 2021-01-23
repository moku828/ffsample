#define NULL 0

unsigned char mem[384/*512*/ * 1024];
typedef struct {
  void* addr;
  long size;
} s_allocentry;
s_allocentry alloctbl[128];

void* luna_malloc(long size);
void luna_free(void* ptr);
void* luna_realloc(void* ptr, long size);


void* luna_malloc(long size)
{
	void* addr;
	long pos;
	int i;
	size = (size + 3) & ~0x03;
	addr = NULL;
	pos = 0;
	for (i = 0; i < sizeof(alloctbl) / sizeof(alloctbl[0]); i++)
	{
		if (alloctbl[i].addr == NULL && (alloctbl[i].size == 0 || alloctbl[i].size > size))
		{
			addr = (void*)(&mem[pos]);
			alloctbl[i].addr = addr;
			if (alloctbl[i].size == 0)
			{
				alloctbl[i].size = size;
			}
			break;
		}
		pos += alloctbl[i].size;
		if ((pos + size) > sizeof(mem))
		{
			break;
		}
	}
	return addr;
}

void luna_free(void* ptr)
{
	int i;
	for (i = 0; i < sizeof(alloctbl) / sizeof(alloctbl[0]); i++)
	{
		if (alloctbl[i].addr == ptr)
		{
			alloctbl[i].addr = NULL;
			break;
		}
	}
}

void* luna_realloc(void* ptr, long size)
{
	void* addr;
	long pos;
	int i;
	size = (size + 3) & ~0x03;
	addr = NULL;
	pos = 0;
	for (i = 0; i < sizeof(alloctbl) / sizeof(alloctbl[0]); i++)
	{
		if (alloctbl[i].addr == NULL && (alloctbl[i].size == 0 || alloctbl[i].size > size))
		{
			addr = (void*)(&mem[pos]);
			alloctbl[i].addr = addr;
			if (alloctbl[i].size == 0)
			{
				alloctbl[i].size = size;
			}
			break;
		}
		pos += alloctbl[i].size;
		if ((pos + size) > sizeof(mem))
		{
			break;
		}
	}
	if (addr == NULL)
	{
		return NULL;
	}
	for (i = 0; i < sizeof(alloctbl) / sizeof(alloctbl[0]); i++)
	{
		if (alloctbl[i].addr == ptr)
		{
			memcpy(addr, alloctbl[i].addr, alloctbl[i].size);
			alloctbl[i].addr = NULL;
			break;
		}
	}
	return addr;
}
