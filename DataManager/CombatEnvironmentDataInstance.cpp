#include "stdafx.h"
#include "CombatEnvironmentDataInstance.h"

CombatEnvironmentDataInstance::CombatEnvironmentDataInstance():SustainableStateDataInstance()
{
	targetType = new bool[2]();
	hasmask = false;
	maskColor = new PluginColorInstance();
	magicChangingPosibility = 0;
	magicChangingTargetIdentifier = 0;
	itemNotBeConsumedPosibility = new unsigned short[2]();
	itemNotBeConsumedUpperBoundWithPrice = new unsigned int[2]();
	dealedDamageModificationDirectly = new int[7]();
	dealedMagicDamageModificationDirectlyWithProperty = new int[5]();
	receivedDamageModificationDirectly = new int[7]();
	receivedMagicDamageModificationDirectlyWithProperty = new int[5]();
	usingRealTimeTrigger = false;
	realTimeBasedStateModificationInterval = 0.0;
	sustainableStateInstanceSetIdentifier = new unsigned int[10]();
	temporaryStateInstanceSetIdentifier = new unsigned int[10]();
	sustainableStateInstanceSetPosibility = new unsigned short[10]();
	temporaryStateInstanceSetPosibility = new unsigned short[10]();

	// Triggered: By customizing
	sustainableStateInstanceSetWhenTriggeredFixed = new unsigned int[10]();
	temporaryStateInstanceSetWhenTriggeredFixed = new unsigned int[10]();
}

CombatEnvironmentDataInstance::~CombatEnvironmentDataInstance()
{
	delete[] targetType;
	delete maskColor;
	delete[] itemNotBeConsumedPosibility;
	delete[] itemNotBeConsumedUpperBoundWithPrice;
	delete[] dealedDamageModificationDirectly;
	delete[] dealedMagicDamageModificationDirectlyWithProperty;
	delete[] receivedDamageModificationDirectly;
	delete[] receivedMagicDamageModificationDirectlyWithProperty;
	delete[] sustainableStateInstanceSetIdentifier;
	delete[] temporaryStateInstanceSetIdentifier;
	delete[] sustainableStateInstanceSetPosibility;
	delete[] temporaryStateInstanceSetPosibility;

	delete[] sustainableStateInstanceSetWhenTriggeredFixed;
	delete[] temporaryStateInstanceSetWhenTriggeredFixed;
}

string CombatEnvironmentDataInstance::printData(stringstream ss)
{
	// Get the result from the super class
	string tempStr = SustainableStateDataInstance::printData(ss);

	ss.str("");
    ss.clear();

	int index = 0;
	ss << "-----CombatEnvironmentDataInstance Print Begin-----\n";

	// Information from the super class
	ss << "-----Information From Class SustainableStateDataInstance: Print Begin-----\n";
	ss << tempStr;
	ss << "-----Information From Class SustainableStateDataInstance: Print End-----\n";

	ss << "-----Information From Class CombatEnvironmentDataInstance: Print Begin-----\n";
	ss << "targetType: ";
	for (index = 0; index < 2; ++index)
	{
		ss << n2s(targetType[index]) << " ";
	}
	ss << "\n";
	ss << "hasmask: " << n2s(hasmask) << "\n";
	ss << "maskColor: " << n2s(maskColor->red) << " " << n2s(maskColor->green) << " " << n2s(maskColor->blue) << " " << n2s(maskColor->alpha) << "\n";
	ss << "magicChangingPosibility: " << n2s(magicChangingPosibility) << "\n";
	ss << "magicChangingTargetIdentifier: " << n2s(magicChangingTargetIdentifier) << "\n";
	ss << "itemNotBeConsumedPosibility: ";
	for (index = 0; index < 2; ++index)
	{
		ss << n2s(itemNotBeConsumedPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "itemNotBeConsumedUpperBoundWithPrice: ";
	for (index = 0; index < 2; ++index)
	{
		ss << n2s(itemNotBeConsumedUpperBoundWithPrice[index]) << " ";
	}
	ss << "\n";
	ss << "dealedDamageModificationDirectly: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(dealedDamageModificationDirectly[index]) << " ";
	}
	ss << "\n";
	ss << "dealedMagicDamageModificationDirectlyWithProperty: ";
	for (index = 0; index < 5; ++index)
	{
		ss << n2s(dealedMagicDamageModificationDirectlyWithProperty[index]) << " ";
	}
	ss << "\n";
	ss << "receivedDamageModificationDirectly: ";
	for (index = 0; index < 7; ++index)
	{
		ss << n2s(receivedDamageModificationDirectly[index]) << " ";
	}
	ss << "\n";
	ss << "receivedMagicDamageModificationDirectlyWithProperty: ";
	for (index = 0; index < 5; ++index)
	{
		ss << n2s(receivedMagicDamageModificationDirectlyWithProperty[index]) << " ";
	}
	ss << "\n";
	ss << "usingRealTimeTrigger: " << n2s(usingRealTimeTrigger) << "\n";
	ss << "realTimeBasedStateModificationInterval: " << d2s(realTimeBasedStateModificationInterval) << "\n";
	ss << "sustainableStateInstanceSetIdentifier: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(sustainableStateInstanceSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateInstanceSetIdentifier: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(temporaryStateInstanceSetIdentifier[index]) << " ";
	}
	ss << "\n";
	ss << "sustainableStateInstanceSetPosibility: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(sustainableStateInstanceSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateInstanceSetPosibility: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(temporaryStateInstanceSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "sustainableStateInstanceSetWhenTriggeredFixed: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(sustainableStateInstanceSetWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateInstanceSetWhenTriggeredFixed: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(temporaryStateInstanceSetWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "-----Information From Class CombatEnvironmentDataInstance: Print End-----\n";

	ss << "-----CombatEnvironmentDataInstance Print End-----\n";

	return ss.str();
}