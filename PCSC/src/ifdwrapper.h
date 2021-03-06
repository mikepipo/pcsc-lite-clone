/*
 * MUSCLE SmartCard Development ( http://www.linuxnet.com )
 *
 * Copyright (C) 1999-2004
 *  David Corcoran <corcoran@linuxnet.com>
 *  Ludovic Rousseau <ludovic.rouseau@free.fr>
 *
 * $Id$
 */

/**
 * @file
 * @brief This wraps the dynamic ifdhandler functions. The abstraction will
 * eventually allow multiple card slots in the same terminal.
 */

#ifndef __ifdwrapper_h__
#define __ifdwrapper_h__

#ifdef __cplusplus
extern "C"
{
#endif

	LONG IFDOpenIFD(PREADER_CONTEXT);
	LONG IFDCloseIFD(PREADER_CONTEXT);
	LONG IFDPowerICC(PREADER_CONTEXT, DWORD, PUCHAR, /*@out@*/ PDWORD);
	LONG IFDStatusICC(PREADER_CONTEXT, /*@out@*/ PDWORD, /*@out@*/ PUCHAR,
		/*@out@*/ PDWORD);
	LONG IFDControl_v2(PREADER_CONTEXT, PUCHAR, DWORD, /*@out@*/ PUCHAR,
		PDWORD);
	LONG IFDControl(PREADER_CONTEXT, DWORD, LPCVOID, DWORD, LPVOID,
		DWORD, LPDWORD);
	LONG IFDTransmit(PREADER_CONTEXT, SCARD_IO_HEADER,
		PUCHAR, DWORD, /*@out@*/ PUCHAR, PDWORD, PSCARD_IO_HEADER);
	LONG IFDSetPTS(PREADER_CONTEXT, DWORD, UCHAR, UCHAR, UCHAR, UCHAR);
	LONG IFDSetCapabilities(PREADER_CONTEXT, DWORD, DWORD, PUCHAR);
	LONG IFDGetCapabilities(PREADER_CONTEXT, DWORD, PDWORD, /*@out@*/ PUCHAR);

#ifdef __cplusplus
}
#endif

#endif							/* __ifdwrapper_h__ */
