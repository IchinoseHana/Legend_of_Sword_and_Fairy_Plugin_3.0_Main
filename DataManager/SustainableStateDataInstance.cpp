#include "stdafx.h"
#include "SustainableStateDataInstance.h"

SustainableStateDataInstance::SustainableStateDataInstance()
{
	identifier = 0;
	name = "";
	description = "";
	effectIdentifier = new unsigned int[10]();
	isCenteringEffectPosition = new bool[10]();
	layer = 0;
	step = 0;
	delay = 0;
	slot = 0;
	isForAllPartner = false;
	currentStateModificationPosibility = new unsigned short[8]();
	basicStateModificationPosibility = new unsigned short[12]();
	temporaryStateSetPosibility = new unsigned short[24]();
	isInterruptCurrentAction = new bool[2]();
	specificEffectIdentifier = 0;
	customizedTriggerType = new bool[7]();

	dealedDamageModificationByPercent = new int[7]();
	dealedMagicDamageModificationByPercentWithProperty = new int[5]();
	receivedDamageModificationByPercent = new int[7]();
	receivedMagicDamageModificationByPercentWithProperty = new int[5]();
	basicStateModificationFixed = new int[12]();
	basicStateModificationByPercent = new int[12]();
	consumptionModificationByPercent = new int[3]();
	actionTakesNoEffect = new bool[7]();
	receivedActionTakesNoEffect = new bool[7]();
	actionForbid = new bool[8]();
	receivedDamageReboundByPercent = new unsigned int[7]();
	receivedDamageAbsorbByPercent = new unsigned int[7]();

	currentStateModificationWhenTriggeredFixed = new int[8]();
	currentStateModificationWhenTriggeredByPercent = new int[8]();
	currentStateModificationWhenTriggeredLevelBased = new int[8]();
	basicStateModificationWhenTriggeredFixed = new int[12]();
	basicStateModificationWhenTriggeredByPercent = new int[12]();
	basicStateModificationWhenTriggeredLevelBased = new int[12]();
	temporaryStateSetWhenTriggeredFixed = new unsigned int[24]();
}

SustainableStateDataInstance::~SustainableStateDataInstance()
{
	delete[] effectIdentifier;
	delete[] isCenteringEffectPosition;
	delete[] currentStateModificationPosibility;
	delete[] basicStateModificationPosibility;
	delete[] temporaryStateSetPosibility;
	delete[] isInterruptCurrentAction;
	delete[] customizedTriggerType;

	delete[] dealedDamageModificationByPercent;
	delete[] dealedMagicDamageModificationByPercentWithProperty;
	delete[] receivedDamageModificationByPercent;
	delete[] receivedMagicDamageModificationByPercentWithProperty;
	delete[] basicStateModificationFixed;
	delete[] basicStateModificationByPercent;
	delete[] consumptionModificationByPercent;
	delete[] actionTakesNoEffect;
	delete[] receivedActionTakesNoEffect;
	delete[] actionForbid;
	delete[] receivedDamageReboundByPercent;
	delete[] receivedDamageAbsorbByPercent;

	delete[] currentStateModificationWhenTriggeredFixed;
	delete[] currentStateModificationWhenTriggeredByPercent;
	delete[] currentStateModificationWhenTriggeredLevelBased;
	delete[] basicStateModificationWhenTriggeredFixed;
	delete[] basicStateModificationWhenTriggeredByPercent;
	delete[] basicStateModificationWhenTriggeredLevelBased;
	delete[] temporaryStateSetWhenTriggeredFixed;
}

string SustainableStateDataInstance::printData(stringstream ss)
{
	ss.str("");
    ss.clear();

	int index = 0;
	ss << "-----SustainableStateDataInstance Print Begin-----\n";
	ss << "identifier: " << n2s(identifier) << "\n";
	ss << "name: " << name << "\n";
	ss << "description: " << description << "\n";
	ss << "effectIdentifier: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(effectIdentifier[index]) << " ";
	}
	ss << "\n";
	ss << "isCenteringEffectPosition: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(isCenteringEffectPosition[index]) << " ";
	}
	ss << "\n";
	ss << "layer: " << n2s(layer) << "\n";
	ss << "step: " << n2s(step) << "\n";
	ss << "delay: " << n2s(delay) << "\n";
	ss << "slot: " << n2s(slot) << "\n";
	ss << "isForAllPartner: " << n2s(isForAllPartner) << "\n";
	ss << "currentStateModificationPosibility: ";
	for (index = 0; index < 8; ++index)
	{
		ss << n2s(currentStateModificationPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "basicStateModificationPosibility: ";
	for (index = 0; index < 12; ++index)
	{
		ss << n2s(basicStateModificationPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateSetPosibility: ";
	for (index = 0; index < 24; ++index)
	{
		ss << n2s(temporaryStateSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "isInterruptCurrentAction: ";
	for (index = 0; index < 2; ++index)
	{
		ss << n2s(isInterruptCurrentAction[index]) << " ";
	}
	ss << "\n";
	ss << "specificEffectIdentifier: " << n2s(specificEffectIdentifier) << "\n";
	ss << "customizedTriggerType: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(customizedTriggerType[index]) << " ";
	}
	ss << "\n";
	ss << "dealedDamageModificationByPercent: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(dealedDamageModificationByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "dealedMagicDamageModificationByPercentWithProperty: ";
	for (index = 0; index < 5; ++index)
	{
		ss << n2s(dealedMagicDamageModificationByPercentWithProperty[index]) << " ";
	}
	ss << "\n";
	ss << "receivedDamageModificationByPercent: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(receivedDamageModificationByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "receivedMagicDamageModificationByPercentWithProperty: ";
	for (index = 0; index < 5; ++index)
	{
		ss << n2s(receivedMagicDamageModificationByPercentWithProperty[index]) << " ";
	}
	ss << "\n";
	ss << "basicStateModificationFixed: ";
	for (index = 0; index < 12; ++index)
	{
		ss << n2s(basicStateModificationFixed[index]) << " ";
	}
	ss << "\n";
	ss << "basicStateModificationByPercent: ";
	for (index = 0; index < 12; ++index)
	{
		ss << n2s(basicStateModificationByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "consumptionModificationByPercent: ";
	for (index = 0; index < 3; ++index)
	{
		ss << n2s(consumptionModificationByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "actionTakesNoEffect: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(actionTakesNoEffect[index]) << " ";
	}
	ss << "\n";
	ss << "receivedActionTakesNoEffect: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(receivedActionTakesNoEffect[index]) << " ";
	}
	ss << "\n";
	ss << "actionForbid: ";
	for (index = 0; index < 8; ++index)
	{
		ss << n2s(actionForbid[index]) << " ";
	}
	ss << "\n";
	ss << "receivedDamageReboundByPercent: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(receivedDamageReboundByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "receivedDamageAbsorbByPercent: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(receivedDamageAbsorbByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "currentStateModificationWhenTriggeredFixed: ";
	for (index = 0; index < 8; ++index)
	{
		ss << n2s(currentStateModificationWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "currentStateModificationWhenTriggeredByPercent: ";
	for (index = 0; index < 8; ++index)
	{
		ss << n2s(currentStateModificationWhenTriggeredByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "currentStateModificationWhenTriggeredLevelBased: ";
	for (index = 0; index < 8; ++index)
	{
		ss << n2s(currentStateModificationWhenTriggeredLevelBased[index]) << " ";
	}
	ss << "\n";
	ss << "basicStateModificationWhenTriggeredFixed: ";
	for (index = 0; index < 12; ++index)
	{
		ss << n2s(basicStateModificationWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "basicStateModificationWhenTriggeredByPercent: ";
	for (index = 0; index < 12; ++index)
	{
		ss << n2s(basicStateModificationWhenTriggeredByPercent[index]) << " ";
	}
	ss << "\n";
	ss << "basicStateModificationWhenTriggeredLevelBased: ";
	for (index = 0; index < 12; ++index)
	{
		ss << n2s(basicStateModificationWhenTriggeredLevelBased[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateSetWhenTriggeredFixed: ";
	for (index = 0; index < 24; ++index)
	{
		ss << n2s(temporaryStateSetWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "-----SustainableStateDataInstance Print End-----\n";

	return ss.str();
}