#ifndef _PAL3_COMBATESTATEDATAINSTANCE_H_
#define _PAL3_COMBATESTATEDATAINSTANCE_H_

#pragma once

#include "CombatEnvironmentDataInstance.h"

// Use an external file to manage datas.
// The default value is 0 or false. Use a negative value to achieve the contrast effect.

// MARK: Combat state
// 1 slot for the maximum
struct CombatStateDataInstance: public CombatEnvironmentDataInstance
{	
public:

	// MARK: The same as CombatEnvironmentDataInstance

	// Constructor & destructor
	CombatStateDataInstance();
	~CombatStateDataInstance();

	// Debug
	string printData(stringstream ss);

private:

	CombatStateDataInstance(const CombatStateDataInstance&);
	CombatStateDataInstance& operator = (const CombatStateDataInstance&);
};

#endif