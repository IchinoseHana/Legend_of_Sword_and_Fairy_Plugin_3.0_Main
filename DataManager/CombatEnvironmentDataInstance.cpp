#include "stdafx.h"
#include "CombatEnvironmentDataInstance.h"

CombatEnvironmentDataInstance::SustainableStateDataInstance()
{
	targetType = new bool[2]();
	hasmask = false;
	maskColor = new PluginColorInstance();

}

CombatEnvironmentDataInstance::~SustainableStateDataInstance()
{
	delete[] effectIdentifier;
	delete[] isCenteringEffectPosition;
	delete[] currentStateModificationPosibility;
	delete[] basicStateModificationPosibility;
	delete[] temporaryStateSetPosibility;
	delete[] isInterruptCurrentAction;
	delete[] customizedTriggerType;
	delete[] cancelSourceEffect;

	delete[] currentStateModificationWhenTriggeredFixed;
	delete[] currentStateModificationWhenTriggeredByPercent;
	delete[] currentStateModificationWhenTriggeredLevelBased;
	delete[] basicStateModificationWhenTriggeredFixed;
	delete[] basicStateModificationWhenTriggeredByPercent;
	delete[] basicStateModificationWhenTriggeredLevelBased;
	delete[] temporaryStateSetWhenTriggeredFixed;
}

string TemporaryStateDataInstance::printData(stringstream ss)
{
	ss.str("");
    ss.clear();

	int index = 0;
	ss << "-----TemporaryStateDataInstance Print Begin-----\n";
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
	ss << "cancelSourceEffect: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(cancelSourceEffect[index]) << " ";
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
	ss << "-----TemporaryStateDataInstance Print End-----\n";

	return ss.str();
}