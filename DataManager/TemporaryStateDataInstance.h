#ifndef _PAL3_TEMPORARYSTATEDATAINSTANCE_H_
#define _PAL3_TEMPORARYSTATEDATAINSTANCE_H_

#pragma once

#include "PluginUtility.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

// Use an external file to manage datas.
// The default value is 0 or false. Use a negative value to achieve the contrast effect.

// MARK: Status slot 3 and 4
// Slot 3: Debuff Slot 4: Buff
struct TemporaryStateDataInstance
{	
public:

	unsigned int identifier; // The ID of the state.
	std::string name; // The name of the state.
	std::string description; // The description of the state.
	unsigned int *effectIdentifier; // Size: 10. The effect identifier when triggered. Just used for customized triggers.
	bool *isCenteringEffectPosition; // Size: 10. If the effect should be put in center of all partners instead of the position of the target. Corresponding to each effect identifier.
	unsigned int slot; // The slot of the state. Slot 3: states from enemies and items. If the target is a role of the player, it cannot be removed except waiting for elimination natually or using some special items.
	bool isForAllPartner; // If the state can apply its effect to all pertners.
	unsigned short *currentStateModificationPosibility; // Size: 8. The posibility to modify the state included in {state1}. The default value 0 is the same as 100.
	unsigned short *basicStateModificationPosibility; // Size: 12. The posibility to modify the state included in {state2}. The default value 0 is the same as 100.
	unsigned short *temporaryStateSetPosibility; // Size: 24. The posibility to set the state included in {state3}. The default value 0 is the same as 100.
	bool *isInterruptCurrentAction; // Size: 2. If the effect can interrupt the current action of {object}.
	unsigned int specificEffectIdentifier; // Specific effect which cannot be descripted by this framwork easily.
    bool *customizedTriggerType; // Size: 7. If using the corresponding custom trigger.
	bool *cancelSourceEffect; // Size: 7. If cancel the effect from {type1}.
	
	// MARK: Detailed effects
	// {object} -> players, enermies
	// {type1} -> normal attack, skill, magic, item, sword skill, cooperated attack, all
	// {type2} -> HP, SP, MP
	// {type3} -> normal attack, skill, magic, item, sword skill, defend, escape, repeat the last action
    // {property} -> water, fire, wind, thunder, earth
	// {state1} -> current HP, current SP, current MP, money, the progress of attack sequence, skill soul, magic soul, sword skill point
	// {state2} -> HP, SP, MP, attack, defense, speed, luck, water property point, fire property point, wind property point, thunder property point, earth property point
	// {state3} -> stable, blank, forbid, sleep, chaos, mad, mirror, wall, bound, hermit, immunity, attack inc, defense inc, speed inc, luck inc, attack dec, defense dec, speed dec, luck dec, poison water, poison fire, poison wind, poison thunder, poison earth

	// Triggered: By customizing
	int *currentStateModificationWhenTriggeredFixed; // Size: 8. Triggered: {state1} + v.
	int *currentStateModificationWhenTriggeredByPercent; // Size: 8. Triggered:  {state1} + v%.
	int *currentStateModificationWhenTriggeredLevelBased; // Size: 8. Triggered:  {state1} + [v].
	int *basicStateModificationWhenTriggeredFixed; // Size: 12. Triggered:  {state2} + v.
	int *basicStateModificationWhenTriggeredByPercent; // Size: 12. Triggered:  {state2} + v%.
	int *basicStateModificationWhenTriggeredLevelBased; // Size: 12. Triggered:  {state2} + [v].
	unsigned int *temporaryStateSetWhenTriggeredFixed; // Size: 24. Triggered:  {state3} = v.

	// Constructor & destructor
	TemporaryStateDataInstance();
	~TemporaryStateDataInstance();

	// Debug
	string printData(stringstream ss);

private:

	TemporaryStateDataInstance(const TemporaryStateDataInstance&);
	TemporaryStateDataInstance& operator = (const TemporaryStateDataInstance&);
};

#endif