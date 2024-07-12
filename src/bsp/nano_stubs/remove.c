#if defined (_HITECH_C_ALIOTHXX_)
int remove(const char *path)
{
	(void)path;

	return -1;
}
#elif defined (__ARMCC_VERSION) || (_GCC_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)
#include <stdio.h>
#endif
