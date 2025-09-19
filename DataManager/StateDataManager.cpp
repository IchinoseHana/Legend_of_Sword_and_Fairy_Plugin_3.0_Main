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
	int index;

	// Layer
	if (instance->layer > 1) tempRes << "���" << n2s(instance->layer) << "�� ";
	
	// Delay
	if (instance->delay > 0) tempRes << n2s(instance->delay) << "�غϺ󷢶� ";
	
	// Is for all partner
    if (instance->isForAllPartner) tempRes << "ȫ�� ";
	
	// Triggered: Always
	// Dealed damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->dealedDamageModificationByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForAttackType(index) << "�˺�" << (instance->dealedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->dealedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->dealedMagicDamageModificationByPercentWithProperty[index] != 0) tempRes << StateDataManager::getDescriptionForMagicProperty(index) << "ϵ�����˺�" << (instance->dealedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->dealedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}
	
	// Received damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageModificationByPercent[index] != 0) tempRes << "��" << StateDataManager::getDescriptionForAttackType(index) << "�˺�" << (instance->receivedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->receivedMagicDamageModificationByPercentWithProperty[index] != 0) tempRes << "��" << StateDataManager::getDescriptionForMagicProperty(index) << "ϵ�����˺�" << (instance->receivedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->receivedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}
	
	// Basic state modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->basicStateModificationFixed[index] != 0) tempRes << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationFixed[index]) << " ";
	}
	for (index = 0; index < 7; ++index)
	{
		if (instance->basicStateModificationByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationByPercent[index]) << "% ";
	}

	// Consumption modification
	for (index = 0; index < 3; ++index)
	{
		if (instance->consumptionModificationByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForConsumptionType(index) << (instance->consumptionModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->consumptionModificationByPercent[index]) << "% ";
	}
	
	// Action takes no effect
	for (index = 0; index < 7; ++index)
	{
		if (instance->actionTakesNoEffect[index]) tempRes << StateDataManager::getDescriptionForAttackType(index) << (index == 6 ? "����" : "") << "�޷���Ч ";
	}
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedActionTakesNoEffect[index]) tempRes << "��" << StateDataManager::getDescriptionForAttackType(index) << (index == 6 ? "����" : "") << "���� ";
	}
	
	
	
	
	
	
	
	
	
	// 
	// Customized trigger type
	for (index = 0; index < 7; ++index)
	{
		if (instance->customizedTriggerType[index]) tempRes << StateDataManager::getDescriptionForCustomTriggerType(index);
	}
	
	
	
	
	
	
	
	
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) tempRes << "�������������˶��� ";
	if (!instance->isInterruptCurrentAction[1]) tempRes << "�������з����˶��� ";

	/*
	step = 0;
	delay = 0;
	currentStateModificationPosibility = new unsigned short[8]();
	basicStateModificationPosibility = new unsigned short[7]();
	temporaryStateModificationPosibility = new unsigned short[24]();
	customizedTriggerType = new bool[7]();

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

string StateDataManager::getDescriptionForAttackType(int index)
{
	switch (index)
	{
	case 0:
		return "��ͨ����";
		break;
	case 1:
		return "�ؼ�";
		break;
	case 2:
		return "����";
		break;
	case 3:
		return "��Ʒ";
		break;
	case 4:
		return "ħ����";
		break;
	case 5:
		return "�ϻ�";
		break;
	case 6:
		return "ȫ��";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForMagicProperty(int index)
{
	switch (index)
	{
	case 0:
		return "ˮ";
		break;
	case 1:
		return "��";
		break;
	case 2:
		return "��";
		break;
	case 3:
		return "��";
		break;
	case 4:
		return "��";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForBasicState(int index)
{
switch (index)
	{
	case 0:
		return "������";
		break;
	case 1:
		return "������";
		break;
	case 2:
		return "������";
		break;
	case 3:
		return "��";
		break;
	case 4:
		return "��";
		break;
	case 5:
		return "��";
		break;
	case 6:
		return "��";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForConsumptionType(int index)
{
switch (index)
	{
	case 0:
		return "������";
		break;
	case 1:
		return "������";
		break;
	case 2:
		return "������";
		break;
	}

	return "";
}

// Basic function
string StateDataManager::numberToString(int num)
{
	char buffer[maxBufferSizeForNumberToString];
    _itoa(num, buffer, 10);
	string temp = buffer;
	return temp;
}