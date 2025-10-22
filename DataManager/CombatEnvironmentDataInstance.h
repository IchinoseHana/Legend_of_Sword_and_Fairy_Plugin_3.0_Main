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
	bool hasmask; // If the combat environment can generate a mask.
	PluginColorInstance *maskColor; // The color of the mask.
	unsigned short magicChangingPosibility; // The posibility to change the magic to a specific one.
	unsigned int magicChangingTargetIdentifier; // The identifier of the target magic that the original magic will be transformed into.
	unsigned short *itemNotBeConsumedPosibility; // Size: 2. The posibility that {type5} items will not be consumed.
	unsigned int *itemNotBeConsumedUpperBoundWithPrice; // Size: 2. The maximum of the purchase price that {type5} items will not be consumed.
	bool usingRealTimeTrigger; // If using the real-time based trigger. Effective for variables related to customized triggers.
	unsigned double realTimeBasedStateModificationInterval; // The time interval if using real-time based state modification.
	unsigned short *sustainableStateSetPosibility; // Size: 10. The posibility to set the state of SustainableStateDataInstance. The default value 0 is the same as 100.
	unsigned short *temporaryStateSetPosibility; // Size: 10. The posibility to set the state of TemporaryStateDataInstance. The default value 0 is the same as 100.

	// Triggered: Always
	int *dealedDamageModificationDirectly; // Size: 7. Dealed {type1} damage = v. This gains the higher priority compared to other damage modification variables.
	int *dealedMagicDamageModificationDirectlyWithProperty; // Size: 5. Dealed {property} magic damage = v. This gains the higher priority compared to other damage modification variables.
	int *receivedDamageModificationDirectly; // Size: 7. Recieved {type1} damage = v. This gains the higher priority compared to other damage modification variables.
	int *receivedMagicDamageModificationDirectlyWithProperty; // Size: 5. Recieved {property} magic damage = v. This gains the higher priority compared to other damage modification variables.

	// Triggered: By customizing
	unsigned int *sustainableStateSetWhenTriggeredFixed; // Size: 10. Triggered:  a specific state from SustainableStateDataInstance = v. If multiple states are set in a same slot, the last one becomes effective.
	unsigned int *temporaryStateSetWhenTriggeredFixed; // Size: 10. Triggered:  a specific state from TemporaryStateDataInstance = v. If multiple states are set in a same slot, the last one becomes effective.
	
	// MARK: Detailed effects
	// {object} -> players, enermies
	// {type1} -> normal attack, skill, magic, item, sword skill, cooperated attack, all
	// {type5} -> recover, attack

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