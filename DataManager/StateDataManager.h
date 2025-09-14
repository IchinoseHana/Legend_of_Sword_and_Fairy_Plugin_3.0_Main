#ifndef _PAL3_STATEDATAMANAGER_H_
#define _PAL3_STATEDATAMANAGER_H_

#pragma once

// State Slot One
// State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWind]
// Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonThunder]

// Define the state slot one
// States from enemies and items. If the target is a role of the player, it cannot be removed except waiting for elimination natually or using some special items
// If the state is used to hurt enemies, it will not disrupt the current action of the target
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect


// State Slot Two
// State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonFire]
// Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonEarth]

// Define the state slot two
// States from players and items which can be removed or replaced easily. However, if the target is an enemy, it is impossible to remove or replace this
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect
// "_S" will be added when the state should be implemented by specific ways in the code


// State Slot Three
// State -> byAbsorbHPWormRoundExtend[nRoleIndex]

// Define the state slot one
// States just be effective once or a specific number of times
// Almost used by players
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect

	
class StateDataManager
{
public:

	// Use a list of external files to manage datas.
    // The default value is zero. Use a negative value to achieve the contrast effect.
 
	// MARK: State Slot One
    // State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWind]
    // Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonThunder]

    // Define the state slot one.
    // States from enemies and items. If the target is a role of the player, it cannot be removed except waiting for elimination natually or using some special items.
    // If the state is used to hurt enemies, it will not disrupt the current action of the target.
	int identifier; // The ID of the state.
	char *name; // The name of the state.
	char *description; // The description of the state.
	unsigned int effectIdentifier[10]; // The effect identifier when triggered
	unsigned int layer; // The max number of layers for a specific state. A effect of a state will be multiplied by this variable. The value 0 takes the same effect as 1.
	
	// MARK: Detailed effects
	// {type} -> normal attack, skill, magic, item, sword skill, all
    // {property} -> water, fire, wind, thunder, earth
	// {state1} -> current HP, current SP, current MP, money
	// {state2} -> HP, SP, MP, attack, defense, speed, luck

	// Triggered: At a specific time
	int dealedDamageModificationByPercent[6]; // Dealed {type} damage + v% 
	int dealedMagicDamageModificationByPercentWithProperty[5]; // Dealed {property} magic damage + v% 
	int receivedDamageModificationByPercent[6]; // Recieved {type} damage + v%
	int receivedMagicDamageModificationPercentWithProperty[5]; // Recieved {property} magic damage + v%
	int stateModification[7]; // {state2} + v
	int stateModificationByPercent[7]; // {state2} + v%
	int actionTakesNoEffect[6]; // {type} based action takes no effect

	// Triggered: At the start of the each round
	int stateModificationByRoundFixed[4]; // At the start of the round: {state1} + v
    int stateModificationByRoundFixedPercent[4]; // At the start of the round: {state1} + v%
    int stateModificationByRoundLevelBased[3]; // At the start of the round: {state1} + v
	

	// Special effects


	StateDataManager();
	~StateDataManager();
};




#endif // #ifndef _PAL3_CB2DEFFECT_H_