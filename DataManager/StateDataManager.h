#ifndef _PAL3_STATEDATAMANAGER_H_
#define _PAL3_STATEDATAMANAGER_H_

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

#pragma once

// MARK: The manager of state data, singleton
class StateDataManager
{
public:

	~StateDataManager();
	static StateDataManager& sharedInstance();

private:
	
	StateDataManager();
	StateDataManager(const StateDataManager&);
	StateDataManager& operator = (const StateDataManager&);
};

#endif