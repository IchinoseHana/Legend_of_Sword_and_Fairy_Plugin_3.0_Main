#ifndef _PAL3_STATEDATAMANAGER_H_
#define _PAL3_STATEDATAMANAGER_H_

#pragma once

#define n2s(x) StateDataManager::numberToString(x)
#define s2n(x) StateDataManager::stringToNumber(x)
#define s2b(x) StateDataManager::stringToBool(x)

#include "SustainableStateDataInstance.h"
#include <sstream>

using std::stringstream;
using std::string;

class StateDataManager;

// File paths.
PAL3HOOK_VERIFIED_DATAVAR static const string sustainableStateDataFilePath = ".\\PLUGIN_3.0\\BaseData\\sustainableStateDataInstance.csv";

// Maximum data sizes.
const int maxSustainableStateDataSize = 300;

// Size of the buffer used to load the file data.
const int maxBufferSizeForLoadingData = 4096;

// Size of the buffer used to transform a number to a string.
const int maxBufferSizeForNumberToString = 128;

// MARK: The manager of state data, singleton
class StateDataManager
{
public:

	~StateDataManager();
	static StateDataManager* sharedInstance();

	// Data
	SustainableStateDataInstance *sustainableStateData; // Status slot 1 and 2
	unsigned int dataSize;

	// Function
	// Load status slot 1 and 2 from the specific file.
	bool loadData();
	
	// Utility
	// Get a fixed name for a status, including the layer information.
    // std::wstring getFixedName(StateDataRunningInfo *info);
	// Get the state instance for a specific running information.
	// SustainableStateDataInstance* stateInstanceForRunningInfo:(StateDataRunningInfo *info);
	// Generate a default description for status slot 1 and 2. If the size of the member "description" is greater than 1, this function will return it as a customized description instead of the default one.
	static string generateDescriptionForSustainableState(SustainableStateDataInstance *instance);
	// Get the description for a specific custom trigger type.
	static string getDescriptionForCustomTriggerType(int index);
	// Get the description for a specific attack type.
	static string getDescriptionForAttackType(int index);
	// Get the description for a specific magic property.
	static string getDescriptionForMagicProperty(int index);
	// Get the description for a basic state.
	static string getDescriptionForBasicState(int index);
	// Get the description for a consumption type.
	static string getDescriptionForConsumptionType(int index);
	// Get the description for a basic action.
	static string getDescriptionForBasicAction(int index);
	// Get the description for a current state.
	static string getDescriptionForCurrentState(int index);
	// Get the description for a temporary state.
	static string getDescriptionForTemporaryState(int index);
	
	// Basic function
	// Transform a number to a string.
	static string numberToString(int num);
	// Transform a string to a number.
	static int stringToNumber(const string& str);
	// Transform a string to a bool. "0" -> false, other -> true.
	static bool stringToBool(const string& str);

private:
	
	StateDataManager();
	StateDataManager(const StateDataManager&);
	StateDataManager& operator = (const StateDataManager&);

	PAL3HOOK_VERIFIED_DATAVAR static StateDataManager *initialInstance;
};

#endif