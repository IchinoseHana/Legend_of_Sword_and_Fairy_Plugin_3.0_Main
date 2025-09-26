#ifndef _PAL3_COMBATENVIRONMENTDATAINSTANCE_H_
#define _PAL3_COMBATENVIRONMENTDATAINSTANCE_H_

#pragma once

#include "SustainableStateDataInstance.h"

// Use an external file to manage datas.
// The default value is 0 or false. Use a negative value to achieve the contrast effect.

// MARK: Combat environment
// 3 slots for the maximum
struct CombatEnvironmentDataInstance: public SustainableStateDataInstance
{	
public:

	// MARK: The same as SustainableStateDataInstance
	// Notice: Some variables take no effects. Including:
	// unsigned int delay; // The count before the state taking effect.
	// unsigned int slot; // The slot of the state.
	// bool isForAllPartner; // If the state can apply its effect to all pertners.

	// MARK: Additional properties
	bool *targetType; // Size: 2. The effect can be applied to {object}.

	
	// MARK: Detailed effects
	// {object} -> players, enermies

	// Constructor & destructor
	CombatEnvironmentDataInstance();
	~CombatEnvironmentDataInstance();

	// Debug
	string printData(stringstream ss);

private:

	CombatEnvironmentDataInstance(const CombatEnvironmentDataInstance&);
	CombatEnvironmentDataInstance& operator = (const CombatEnvironmentDataInstance&);
};

#endif