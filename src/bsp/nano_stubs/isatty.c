#if defined (_GCC_C_ALIOTHXX_)

#include <unistd.h>

int _isatty(int fd)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO)
    {
        return 1;
    }

    return 0;
}
#elif defined (__ARMCC_VERSION) || (_HITECH_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)
#include <stdio.h>
#endif
