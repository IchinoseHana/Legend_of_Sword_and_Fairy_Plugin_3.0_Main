#include "stdafx.h"
#include "PEP3Logging.h"
#include <windows.h>
#include <stdio.h>

PEP3Logging::PEP3Logging()
{
	
}

PEP3Logging::~PEP3Logging()
{
	
}

PAL3HOOK_VERIFIED_DATAVAR static PEP3Logging* initialInstance = new PEP3Logging();
PEP3Logging* PEP3Logging::sharedInstance()
{
	return initialInstance;
}

// Debug
void PEP3Logging::log(string str)
{
	#ifdef PLUGIN_LOGGING_ENABLE
		
	HANDLE EventResourceHandle;
	LPCTSTR ErrorEventStr = str.c_str();
	LPTSTR ServiceName = "PAL3_Plugin";
	EventResourceHandle = RegisterEventSource(NULL, ServiceName);
	if ( EventResourceHandle != NULL )
	{
		if (!ReportEvent(EventResourceHandle, EVENTLOG_INFORMATION_TYPE, 0, 0, NULL, 1, 0, &ErrorEventStr, NULL))
		{
			printf("PEP3Logging -> log: Could not report the event.");
		}
		DeregisterEventSource( EventResourceHandle );
	}
	printf("PEP3Logging -> log: Could not register the event source.");
	
	#endif
}