#include "stdafx.h"
#include "CombatStateDataInstance.h"

CombatStateDataInstance::CombatStateDataInstance():CombatEnvironmentDataInstance()
{

}

CombatStateDataInstance::~CombatStateDataInstance()
{

}

string CombatStateDataInstance::printData(stringstream ss)
{
	// Get the result from the super class
	string tempStr = CombatEnvironmentDataInstance::printData(ss);

	ss.str("");
    ss.clear();

	int index = 0;
	ss << "-----CombatStateDataInstance Print Begin-----\n";
	// Information from the super class
	ss << "-----Information From Class CombatEnvironmentDataInstance: Print Begin-----\n";
	ss << tempStr;
	ss << "-----Information From Class CombatEnvironmentDataInstance: Print End-----\n";

	// No extra variables for this class
	ss << "-----Information From Class CombatStateDataInstance: Print Begin-----\n";
	ss << "-----Information From Class CombatStateDataInstance: Print End-----\n";
	ss << "-----CombatStateDataInstance Print End-----\n";

	return ss.str();
}