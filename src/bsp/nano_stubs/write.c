#include <Base_Modules_Cfg.h>

#if (USE_UART_MODULE == STD_ON) && (UART1_PRINTF == STD_ON)
#include "Uart_Hal.h"
#endif

#if defined (_HITECH_C_ALIOTHXX_)
#include <stdio.h>

int write(int fd, void *s, size_t len)
{
#if (USE_UART_MODULE == STD_ON) && (defined(UART1_PRINTF))
	(void)fd;

	if ((s != NULL) && (len > 0))
	{
		Uart_StatusType UartStatus = UART_STATUS_UNINIT;
		
		Uart_Hal_GetStatus(UART_1, &UartStatus);
		if(UartStatus != UART_STATUS_UNINIT)
		{
			Uart_Hal_SyncTransmit(UART_1, (uint8 *)s, len);
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}

	return len;
#else
	(void)fd;
	(void)s;
	(void)len;

	return -1;
#endif
}
#elif defined (_GCC_C_ALIOTHXX_)
#include <stdint.h>
#include <errno.h>
#include <unistd.h>

ssize_t _write(int fd, const void* ptr, size_t len)
{
#if (USE_UART_MODULE == STD_ON) && (defined(UART1_PRINTF))
	(void)fd;

	if ((ptr != NULL) && (len > 0))
	{
		Uart_StatusType UartStatus = UART_STATUS_UNINIT;

		Uart_Hal_GetStatus(UART_1, &UartStatus);
		if(UartStatus != UART_STATUS_UNINIT)
		{
			Uart_Hal_SyncTransmit(UART_1, (uint8 *)ptr, len);
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}

	return len;
#else
	(void)fd;
	(void)ptr;
	(void)len;

	return -1;
#endif
}
#elif defined (__ARMCC_VERSION)
#include <stdio.h>

int fputc(int ch, FILE *f)
{
#if (USE_UART_MODULE == STD_ON) && (defined(UART1_PRINTF))
	(void)f;
	Uart_StatusType UartStatus = UART_STATUS_UNINIT;

	Uart_Hal_GetStatus(UART_1, &UartStatus);
	if(UartStatus != UART_STATUS_UNINIT)
	{
		Uart_Hal_SyncTransmit(UART_1, (uint8 *)&ch, 1);
	}
	else
	{
		/* do nothing */
	}

	return 0;
#else
	(void)ch;
	(void)f;

	return -1;
#endif
}
#elif defined (_LLVM_C_ALIOTHXX_)
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	puts(const char *__str)
{
#if (USE_UART_MODULE == STD_ON) && (defined(UART1_PRINTF))
	Uart_StatusType UartStatus = UART_STATUS_UNINIT;
	uint8 Pstr[1] = {'\n'};

	Uart_Hal_GetStatus(UART_1, &UartStatus);
	if(UartStatus != UART_STATUS_UNINIT)
	{
		Uart_Hal_SyncTransmit(UART_1, (uint8 *)__str, (uint16)strlen(__str));
		if(__str[strlen(__str) - 1] == '\r')
		{
			Uart_Hal_SyncTransmit(1, Pstr, 1);
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}

	return strlen(__str);
#else
	(void)__str;

	return -1;
#endif
}

int printf(const char *fmt, ...)
{
#if (USE_UART_MODULE == STD_ON) && (defined(UART1_PRINTF))
	char printf_buf[512];
	va_list args;
	int printed;

	va_start(args, fmt);
	printed = vsprintf(printf_buf, fmt, args);
	va_end(args);
	puts(printf_buf);

	return printed;
#else
	(void)fmt;

	return -1;
#endif
}
#endif
