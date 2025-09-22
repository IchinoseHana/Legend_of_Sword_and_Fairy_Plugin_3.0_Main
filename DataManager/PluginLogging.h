#ifndef _PAL3_PLUGINLOGGING_H_
#define _PAL3_PLUGINLOGGING_H_

#pragma once

#define PLOG(x) PluginLogging::sharedInstance()->log(x)

// Modify this macro to set wether print the log or not.
#define PLUGIN_LOGGING_ENABLE 1

#include <string>

using std::string;

// MARK: The logging system, singleton
// Using "eventvwr.msc" to see the log. Service name: PAL3_Plugin.
class PluginLogging
{
public:

	~PluginLogging();
	static PluginLogging* sharedInstance();

	// Debug
	void log(string str);

private:
	
	PluginLogging();
	PluginLogging(const PluginLogging&);
	PluginLogging& operator = (const PluginLogging&);

	PAL3HOOK_VERIFIED_DATAVAR static PluginLogging *initialInstance;
};

#endif
