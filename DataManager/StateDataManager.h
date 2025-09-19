#ifndef _PAL3_STATEDATAMANAGER_H_
#define _PAL3_STATEDATAMANAGER_H_

#pragma once

#define n2s(x) StateDataManager::numberToString(x)

#include "SustainableStateDataInstance.h"
#include <sstream>

using std::stringstream;
using std::string;

// File path
static const string sustainableStateDataFilePath = ".\\PLUGIN_3.0\\BaseData\\sustainableStateDataInstance.txt";

// Data size
const int maxSustainableStateDataSize = 300;

// Size of the buffer used to transform a number to a string
const int maxBufferSizeForNumberToString = 128;

// MARK: The manager of state data, singleton
class StateDataManager
{
public:

	~StateDataManager();
	static StateDataManager& sharedInstance();

	// Data
	SustainableStateDataInstance *sustainableStateData; // Status slot 1 and 2

	// Function
	// Load status slot 1 and 2 from the specific file.
	bool loadData();
	
	// Utility
	// Get a fixed name for a status, including the layer information
    //std::wstring getFixedName(StateDataRunningInfo *info);
	// Get the state instance for a specific running information.
	//SustainableStateDataInstance* stateInstanceForRunningInfo:(StateDataRunningInfo *info);
	// Generate a default description for status slot 1 and 2.
	static string generateDescriptionForSustainableState(SustainableStateDataInstance *instance);
	// Get the description for a specific custom trigger type
	static string getDescriptionForCustomTriggerType(int index);
	// Get the description for a specific attack type
	static string getDescriptionForAttackType(int index);
	// Get the description for a specific magic property
	static string getDescriptionForMagicProperty(int index);
	// Get the description for a basic state
	static string getDescriptionForBasicState(int index);
	// Get the description for a consumption type
	static string getDescriptionForConsumptionType(int index);
	
	// Basic function
	// Tfansform a number to a string
	static string numberToString(int num);

private:
	
	StateDataManager();
	StateDataManager(const StateDataManager&);
	StateDataManager& operator = (const StateDataManager&);
};

#endif