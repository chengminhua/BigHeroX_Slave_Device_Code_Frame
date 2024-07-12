#if defined (_HITECH_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

extern char __HEAP;
extern char _Heap_Limit;

char *environ = NULL;

void *sbrk(size_t incr)
{
	void *ret;
	static char *heap_top	= & __HEAP;
	char *new_heap_top = heap_top + incr;
	if (new_heap_top > & _Heap_Limit)
	{
		return (void*)(-1);
	}
	if (new_heap_top < & __HEAP)
		abort();
	ret = (void *) heap_top;
	heap_top = new_heap_top;
	return ret;
}
#elif defined (_GCC_C_ALIOTHXX_)
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *_sbrk(ptrdiff_t incr)
{
    extern char _heap_start[];
    extern char _heap_end[];
    static char *curbrk = _heap_start;

    if ((curbrk + incr < _heap_start) || (curbrk + incr > _heap_end))
    {
        return (void*)((unsigned int)NULL - 1);
    }

    curbrk += incr;
    return curbrk - incr;
}
#elif defined (__ARMCC_VERSION)
#include <stdio.h>
#endif
