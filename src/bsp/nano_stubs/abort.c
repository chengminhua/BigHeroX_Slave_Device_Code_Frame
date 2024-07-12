#if defined (_HITECH_C_ALIOTHXX_)
void abort(void)
{
	// TODO: do whatever you need to to at exit, e.g. execute debug instruction
	__asm__ volatile (".long 0xBE11BE11");
	while (1);
}
#elif defined (__ARMCC_VERSION) || (_GCC_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)
#include <stdio.h>
#endif
