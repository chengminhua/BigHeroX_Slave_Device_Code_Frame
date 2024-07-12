#if defined (_GCC_C_ALIOTHXX_)
void _init()
{

}

void _fini()
{

}
#elif defined (__ARMCC_VERSION) || (_HITECH_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)
#include <stdio.h>
#endif

