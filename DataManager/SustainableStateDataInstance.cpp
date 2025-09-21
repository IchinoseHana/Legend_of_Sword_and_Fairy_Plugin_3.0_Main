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

void SustainableStateDataInstance::printData()
{
	printf("%d %s %s ", identifier, name, description);
}