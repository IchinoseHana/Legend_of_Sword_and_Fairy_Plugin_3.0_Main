#ifndef _PAL3_COUNTABLESTATEDATAINSTANCE_H_
#define _PAL3_COUNTABLESTATEDATAINSTANCE_H_

#pragma once

// The trigger type used to determine how to change the member "countValue".
enum CountableStateCountValueChangeTriggerType
{
	CountableStateCountValueChangeTriggerTypeNone, // countValue always keeps its original value.
    CountableStateCountValueChangeTriggerTypeAfterReceiveingNormalAttackDamage, // countValue -= received damage after being attacked by normal attack.
    CountableStateCountValueChangeTriggerTypeAfterReceiveingSkillDamage, // countValue -= received damage after being attacked by skill.
	CountableStateCountValueChangeTriggerTypeAfterReceiveingMagicDamage, // countValue -= received damage after being attacked by magic.
	CountableStateCountValueChangeTriggerTypeAfterReceiveingItemDamage, // countValue -= received damage after being attacked by item.
    CountableStateCountValueChangeTriggerTypeAfterReceiveingSwordSkillDamage, // countValue -= received damage after being attacked by sword skill.
	CountableStateCountValueChangeTriggerTypeAfterReceiveingCooperatedAttackDamage, // countValue -= received damage after being attacked by cooperated attack.
	CountableStateCountValueChangeTriggerTypeAfterReceiveingAllDamage, // countValue -= received damage.
    CountableStateCountValueChangeTriggerTypeAfterDealingNormalAttackDamage, // countValue -= dealed damage by normal attack.
    CountableStateCountValueChangeTriggerTypeAfterDealingSkillDamage, // countValue -= dealed damage by skill.
	CountableStateCountValueChangeTriggerTypeAfterDealingMagicDamage, // countValue -= dealed damage by magic.
	CountableStateCountValueChangeTriggerTypeAfterDealingItemDamage, // countValue -= dealed damage by item.
    CountableStateCountValueChangeTriggerTypeAfterDealingSwordSkillDamage, // countValue -= dealed damage by sword skill.
	CountableStateCountValueChangeTriggerTypeAfterDealingCooperatedAttackDamage, // countValue -= dealed damage by cooperated attack.
	CountableStateCountValueChangeTriggerTypeAfterDealingAllDamage // countValue -= dealed damage.
};

#include "SustainableStateDataInstance.h"

// Use an external file to manage datas.
// The default value is 0 or false. Use a negative value to achieve the contrast effect.

// MARK: Status slot 5
// 1 slots for the maximum
struct CountableStateDataInstance: public SustainableStateDataInstance
{	
public:

	// MARK: The same as SustainableStateDataInstance

	// MARK: Additional properties
	unsigned int countValue; // The value used to count. If the value becomes zero, the state will be removed.
	bool effectTriggeredWhenCountValueChanging; // If showing the effect after the member "countValue" being changed.
    bool effectNotTriggeredByCustomTrigger; // If do not showing the effect in the case of customized triggers.
    CountableStateCountValueChangeTriggerType countValueChangeTriggerType; // The type of the trigger which is used to change the member "countValue". See "CountableStateCountValueChangeTriggerType" for more detailed information.
	

	// Constructor & destructor
	CountableStateDataInstance();
	~CountableStateDataInstance();

	// Debug
	string printData(stringstream ss);

private:

	CountableStateDataInstance(const CountableStateDataInstance&);
	CountableStateDataInstance& operator = (const CountableStateDataInstance&);
};

#endif