#ifndef _PAL3_STATEDATAMANAGER_H_
#define _PAL3_STATEDATAMANAGER_H_

const static int stateMaximumEffectIdentifier = 10; // The maximum size of the effect identifier

#pragma once

enum StateDataManagerCustomizedTriggerType
{
	StateDataManagerCustomizedTriggerTypeNone, // Triggered: None
    StateDataManagerCustomizedTriggerTypeByRound, // Triggered: At the start of each round
    StateDataManagerCustomizedTriggerTypeAfterNormalAttack, // Triggered: After doing a normal attack
	StateDataManagerCustomizedTriggerTypeAfterSkill, // Triggered: After casting a skill
	StateDataManagerCustomizedTriggerTypeAfterMagic, // Triggered: After casting a magic
	StateDataManagerCustomizedTriggerTypeAfterItem, // Triggered: After using an item
	StateDataManagerCustomizedTriggerTypeAfterDefense, // Triggered: After defending
	StateDataManagerCustomizedTriggerTypeAfterRecievingDamage // Triggered: After receiving damage
};

class StateDataManager
{
public:

	StateDataManager();
	~StateDataManager();
};

struct SustainableStateDataInstance
{
public:

	// Use a list of external files to manage datas.
    // The default value is 0 or false. Use a negative value to achieve the contrast effect.

    // If the state is used to hurt enemies, it will not disrupt the current action of the target.
	unsigned identifier; // The ID of the state.
	char *name; // The name of the state.
	char *description; // The description of the state.
	unsigned int effectIdentifier[stateMaximumEffectIdentifier]; // The effect identifier when triggered.
	BOOL isCenteringEffectPosition[stateMaximumEffectIdentifier]; // If the effect should be put in center of all partners instead of the position of the target. Corresponding to each effect identifier.
	unsigned int layer; // The maximum number of layers for a specific state. An effect of a state will be multiplied by the value of the current layer. The value 0 takes the same effect as 1. Slot 2: States from players and items which can be removed or replaced easily. However, if the target is an enemy, it is impossible to be removed or replaced.
	unsigned int step; // The step of the value. After being triggered, the value will be added by this value.
	unsigned int delay; // The count before the state taking effect.
	unsigned int slot; // The slot of the state. Slot 1: states from enemies and items. If the target is a role of the player, it cannot be removed except waiting for elimination natually or using some special items.
	BOOL isForAllPertner; // If the state can apply its effect to all pertners.
	unsigned short currentStateModificationPosibility[8]; // The posibility to set the state included in {state1}.
	unsigned short basicStateModificationPosibility[7]; // The posibility to set the state included in {state2}.
	unsigned short temporaryStateModificationPosibility[24]; // The posibility to set the state included in {state3}.
	BOOL isInterruptCurrentAction[2]; // If the effect can interrupt the current action of {object}.
	unsigned int specificEffectIdentifier; // Specific effect which cannot be descripted by this framwork easily.
    BOOL customizedTriggerType[7]; // The custom trigger. 
	
	// MARK: Detailed effects
	// {object} -> players, enermies
	// {type1} -> normal attack, skill, magic, item, sword skill, cooperated attack, all
	// {type2} -> HP, SP, MP
	// {type3} -> normal attack, skill, magic, item, sword skill, defend, escape, repeat the last action
    // {property} -> water, fire, wind, thunder, earth
	// {state1} -> current HP, current SP, current MP, money, the progress of attack sequence, skill soul, magic soul, sword skill point
	// {state2} -> HP, SP, MP, attack, defense, speed, luck
	// {state3} -> stable, blank, forbid, sleep, chaos, mad, mirror, wall, bound, hermit, immunity, attack inc, defense inc, speed inc, luck inc, attack dec, defense dec, speed dec, luck dec, poison water, poison fire, poison wind, poison thunder, poison earth

	// Triggered: Always
	int dealedDamageModificationByPercent[7]; // Dealed {type1} damage + v%.
	int dealedMagicDamageModificationByPercentWithProperty[5]; // Dealed {property} magic damage + v%.
	int receivedDamageModificationByPercent[7]; // Recieved {type1} damage + v%.
	int receivedMagicDamageModificationByPercentWithProperty[5]; // Recieved {property} magic damage + v%.
	int basicStateModificationFixed[7]; // {state2} + v.
	int basicStateModificationByPercent[7]; // {state2} + v%.
	int consumptionModificationByPercent[3]; // {type2} cost when casting skill or magic + v%.
	int actionTakesNoEffect[7]; // {type1} based action takes no effect.
	int receivedActionTakesNoEffect[7]; // Received {type1} based action takes no effect.
	int actionForbid[8]; // Cannot execute {type3} based action.
	int receivedDamageReboundByPercent[7]; // Rebound received {type1} damage + v%. The source of the damage takes v% of the damage, while the target takes the remaining 1 - v% damage.
    int receivedDamageAbsorbByPercent[7]; // Absorb received {type1} damage + v%. The damage takes no effect, then the target revovers the state by v% of the damage.

	// Triggered: By customizing
	int currentStateModificationWhenTriggeredFixed[8]; // Triggered: {state1} + v.
    int currentStateModificationWhenTriggeredByPercent[8]; // Triggered:  {state1} + v%.
    int currentStateModificationWhenTriggeredLevelBased[8]; // Triggered:  {state1} + [v].
	int basicStateModificationWhenTriggeredFixed[7]; // Triggered:  {state2} + v.
    int basicStateModificationWhenTriggeredByPercent[7]; // Triggered:  {state2} + v%.
    int basicStateModificationWhenTriggeredLevelBased[7]; // Triggered:  {state2} + [v].
	int temporaryStateModificationWhenTriggered[24]; // Triggered:  {state3} + v.
};

struct StateDataRunningInfo
{
public:

	// The running data of a state.
	// Each status slot of a specific object, or role has a "StateDataRunningInfo" instance.

	unsigned identifier; // The ID of the state.
	unsigned int currentLayer; // The current layer value. It will be added by 1 if triggered, but cannot exceed the maximum layer.
	unsigned int currentDuration; // The current duration which will be subtracted by 1 at the start of each round. If the duration is 0, the state will be removed.
	unsigned int currentDelay; // The remaning rounds before the effect taking effect. If the current value is 0, the state will become effective.
};

#endif