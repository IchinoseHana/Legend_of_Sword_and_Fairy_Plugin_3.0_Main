#include "stdafx.h"
#include "SustainableStateDataInstance.h"

SustainableStateDataInstance::SustainableStateDataInstance()
{
	identifier = 0;
	name = "";
	description = "";
	effectIdentifier = new unsigned int[stateMaximumEffectIdentifier]();
	isCenteringEffectPosition = new bool[stateMaximumEffectIdentifier]();
	layer = 0;
	step = 0;
	delay = 0;
	slot = 0;
	isForAllPartner = false;
	currentStateModificationPosibility = new unsigned short[8]();
	basicStateModificationPosibility = new unsigned short[7]();
	temporaryStateModificationPosibility = new unsigned short[24]();
	isInterruptCurrentAction = new bool[2]();
	specificEffectIdentifier = 0;
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
	temporaryStateModificationWhenTriggeredFixed = new int[24]();
}

SustainableStateDataInstance::~SustainableStateDataInstance()
{
	delete[] effectIdentifier;
	delete[] isCenteringEffectPosition;
	delete[] currentStateModificationPosibility;
	delete[] basicStateModificationPosibility;
	delete[] temporaryStateModificationPosibility;
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
	delete[] temporaryStateModificationWhenTriggeredFixed;
}
