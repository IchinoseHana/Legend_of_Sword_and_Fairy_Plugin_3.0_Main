#ifndef _PAL3_PEP3LOGGING_H_
#define _PAL3_PEP3LOGGING_H_

#pragma once

#define PLOG(x) PEP3Logging::sharedInstance()->log(x)

// Modify this macro to set wether print the log or not.
#define PLUGIN_LOGGING_ENABLE 0

#include <string>

using std::string;

// MARK: The logging system, singleton
// Using "eventvwr.msc" to see the log. Service name: PAL3_Plugin.
class PEP3Logging
{
public:
	~PEP3Logging();
	PEP3Logging();
	static PEP3Logging* sharedInstance();

	void log(string str);
};

#endif
