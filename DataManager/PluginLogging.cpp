#include "stdafx.h"
#include "PluginLogging.h"
#include <windows.h>
#include <stdio.h>

PluginLogging::PluginLogging()
{
	
}

PluginLogging::~PluginLogging()
{
	
}

PluginLogging* PluginLogging::sharedInstance()
{
	PluginLogging *initialInstance = new PluginLogging();
	return initialInstance;
}

// Debug
void PluginLogging::log(string str)
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
			printf("PluginLogging -> log: Could not report the event.");
		}
		DeregisterEventSource( EventResourceHandle );
	}
	printf("PluginLogging -> log: Could not register the event source.");
	
	#endif
}