#ifndef _SCIF2
#define _SCIF2

void scif2_init (unsigned long bps);
void scif3_init (unsigned long bps);
int scif2_test (void);
void scif3_putc (unsigned char d);
unsigned char scif2_getc (void);

#endif

