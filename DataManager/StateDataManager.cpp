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
	if (instance->layer > 1) tempRes << "���" << StateDataManager::numberToString(instance->layer) << "�� ";
	
	// Delay
	if (instance->delay > 0) tempRes << StateDataManager::numberToString(instance->delay) << "�غϺ󷢶� ";
	
	// Is for all partner
    if (instance->isForAllPartner) tempRes << "ȫ�� ";
	
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) tempRes << "�������������˶��� ";
	if (!instance->isInterruptCurrentAction[1]) tempRes << "�������з����˶��� ";
	
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
		return "�غϿ�ʼʱ: ";
		break;
	case 1:
		return "������ͨ������: ";
		break;
	case 2:
		return "�������ܺ�: ";
		break;
	case 3:
		return "ʩ��������: ";
		break;
	case 4:
		return "ʹ����Ʒ��: ";
		break;
	case 5:
		return "������: ";
		break;
	case 6:
		return "�ܵ��˺���: ";
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