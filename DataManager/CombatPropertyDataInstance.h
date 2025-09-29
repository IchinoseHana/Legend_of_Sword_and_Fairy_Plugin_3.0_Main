#ifndef _PAL3_COMBATEPROPERTYDATAINSTANCE_H_
#define _PAL3_COMBATEPROPERTYDATAINSTANCE_H_

#pragma once

#include "PluginUtility.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

// Use an external file to manage datas.
// The default value is 0 or false. Use a negative value to achieve the contrast effect.

// MARK: Combat property
// 1 slots for the maximum
struct CombatPropertyDataInstance
{	
public:

	unsigned int identifier; // The ID of the state.
	std::string name; // The name of the state.
	std::string description; // The description of the state.
	bool *damageType; // Size: 3. The damage type is {type4}. The type "damage" gains the highest priority.

	// {type1} -> normal attack, skill, magic, item, sword skill, cooperated attack, all
	// {type4} -> damage, recoverage, all
    // {property} -> water, fire, wind, thunder, earth

	// Triggered: Always
	int *dealedDamageModificationByPercent; // Size: 7. Dealed {type1} damage + v%.
	int *dealedMagicDamageModificationByPercentWithProperty; // Size: 5. Dealed {property} magic damage + v%.
	int *receivedDamageModificationByPercent; // Size: 7. Recieved {type1} damage + v%.
	int *receivedMagicDamageModificationByPercentWithProperty; // Size: 5. Recieved {property} magic damage + v%.

	// Constructor & destructor
	CombatPropertyDataInstance();
	~CombatPropertyDataInstance();

	// Debug
	string printData(stringstream ss);

private:

	CombatPropertyDataInstance(const CombatPropertyDataInstance&);
	CombatPropertyDataInstance& operator = (const CombatPropertyDataInstance&);
};

#endif