/* See LICENSE of license details. */

#include <stdio.h>

void _exit(int code)
{
    printf("Program has exited with code: %d\r\n", code);

    for (;;)
    {

    }
}
