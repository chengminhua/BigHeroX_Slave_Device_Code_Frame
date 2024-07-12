#if defined (_HITECH_C_ALIOTHXX_)
int close (int desc)
{
	(void)desc;

	return -1;
}
#elif defined (__ARMCC_VERSION) || (_GCC_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)
#include <stdio.h>
#endif
