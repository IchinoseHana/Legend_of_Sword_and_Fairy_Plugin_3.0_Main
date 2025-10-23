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
	sustainableStateSetIdentifier = new unsigned int[10]();
	temporaryStateSetIdentifier = new unsigned int[10]();
	sustainableStateSetPosibility = new unsigned short[10]();
	temporaryStateSetPosibility = new unsigned short[10]();

	// Triggered: By customizing
	sustainableStateSetWhenTriggeredFixed = new unsigned int[10]();
	temporaryStateSetWhenTriggeredFixed = new unsigned int[10]();
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
	delete[] sustainableStateSetIdentifier;
	delete[] temporaryStateSetIdentifier;
	delete[] sustainableStateSetPosibility;
	delete[] temporaryStateSetPosibility;

	delete[] sustainableStateSetWhenTriggeredFixed;
	delete[] temporaryStateSetWhenTriggeredFixed;
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
	ss << "realTimeBasedStateModificationInterval: " << n2s(realTimeBasedStateModificationInterval) << "\n";
	ss << "sustainableStateSetIdentifier: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(sustainableStateSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateSetIdentifier: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(temporaryStateSetIdentifier[index]) << " ";
	}
	ss << "\n";
	ss << "sustainableStateSetPosibility: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(sustainableStateSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateSetPosibility: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(temporaryStateSetPosibility[index]) << " ";
	}
	ss << "\n";
	ss << "sustainableStateSetWhenTriggeredFixed: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(sustainableStateSetWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "temporaryStateSetWhenTriggeredFixed: ";
	for (index = 0; index < 10; ++index)
	{
		ss << n2s(temporaryStateSetWhenTriggeredFixed[index]) << " ";
	}
	ss << "\n";
	ss << "-----Information From Class CombatEnvironmentDataInstance: Print End-----\n";

	ss << "-----CombatEnvironmentDataInstance Print End-----\n";

	return ss.str();
}