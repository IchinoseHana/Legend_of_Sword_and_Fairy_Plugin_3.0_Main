#include "stdafx.h"
#include "StateDataManager.h"
#include <sstream>

using std::stringstream;
using std::string;

StateDataManager::StateDataManager()
{
	sustainableStateData = new SustainableStateDataInstance[maxSustainableStateDataSize]();
}

StateDataManager::~StateDataManager()
{

}

StateDataManager& StateDataManager::sharedInstance()
{
	static StateDataManager instance;
	return instance;
}

// Function
bool StateDataManager::loadData()
{
	// Status slot 1 & 2
	FILE *fp = fopen("sustainableStateDataFilePath","rb");
	//gbVFile *fp = gbVfopen("cbdata\\pal3_softstar.gdb", GB_VFILE_READONLY | GB_VFILE_BIN);
	if ( fp == NULL )
	{
		ASSERT(0 && "Can't search GDB_file\n");
		throw EXCEPTION("Combat data couldn't found");
		return false;
	}

	return true;
}

// Utility
/*std::wstring StateDataManager::getFixedName(StateDataRunningInfo *instance)
{
	if (!instance) return "";

	std::ostringstream tempRes;

	tempRes << instance.name;
	tempRes << "(";
	tempRes << 
	return 
}*/

string StateDataManager::generateDescriptionForSustainableState(SustainableStateDataInstance *instance)
{
	if (!instance) return "";

	stringstream tempRes;

	// Layer
	if (instance->layer > 1) tempRes << "最大" << StateDataManager::numberToString(instance->layer) << "层 ";
	
	// Delay
	if (instance->delay > 0) tempRes << StateDataManager::numberToString(instance->delay) << "回合后发动 ";
	
	// Is for all partner
    if (instance->isForAllPartner) tempRes << "全体 ";
	
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) tempRes << "不触发己方受伤动作 ";
	if (!instance->isInterruptCurrentAction[1]) tempRes << "不触发敌方受伤动作 ";
	
	// Customized trigger type
	for (int index = 0; index < 7; ++index)
	{
		if (instance->customizedTriggerType[index]) tempRes << StateDataManager::getDescriptionForCustomTriggerType(index);
	}
	
	//tempRes.clear


	/*
	step = 0;
	delay = 0;
	currentStateModificationPosibility = new unsigned short[8]();
	basicStateModificationPosibility = new unsigned short[7]();
	temporaryStateModificationPosibility = new unsigned short[24]();
	customizedTriggerType = new bool[7]();

	dealedDamageModificationByPercent = new int[7]();
	dealedMagicDamageModificationByPercentWithProperty = new int[5]();
	receivedDamageModificationByPercent = new int[7]();
	receivedMagicDamageModificationByPercentWithProperty = new int[5]();
	basicStateModificationFixed = new int[7]();
	basicStateModificationByPercent = new int[7]();
	consumptionModificationByPercent = new int[3]();
	actionTakesNoEffect = new int[7]();
	receivedActionTakesNoEffect = new int[7]();
	actionForbid = new int[8]();
	receivedDamageReboundByPercent = new int[7]();
	receivedDamageAbsorbByPercent = new int[7]();

	currentStateModificationWhenTriggeredFixed = new int[8]();
	currentStateModificationWhenTriggeredByPercent = new int[8]();
	currentStateModificationWhenTriggeredLevelBased = new int[8]();
	basicStateModificationWhenTriggeredFixed = new int[7]();
	basicStateModificationWhenTriggeredByPercent = new int[7]();
	basicStateModificationWhenTriggeredLevelBased = new int[7]();
	temporaryStateModificationWhenTriggeredFixed = new int[24]();*/
	return "";
}

string StateDataManager::getDescriptionForCustomTriggerType(int index)
{
	switch (index)
	{
	case 0:
		return "回合开始时: ";
		break;
	case 1:
		return "进行普通攻击后: ";
		break;
	case 2:
		return "发动技能后: ";
		break;
	case 3:
		return "施放仙术后: ";
		break;
	case 4:
		return "使用物品后: ";
		break;
	case 5:
		return "防御后: ";
		break;
	case 6:
		return "受到伤害后: ";
		break;
	}

	return "";
}

// Basic function
string StateDataManager::numberToString(int num)
{
	char buffer[maxBufferSizeForNumberToString];
    _itoa(num, buffer, 10);
	return (string)buffer;
    
}