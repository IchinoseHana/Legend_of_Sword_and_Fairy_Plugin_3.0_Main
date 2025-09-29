#include "stdafx.h"
#include "CombatPropertyDataInstance.h"

CombatPropertyDataInstance::CombatPropertyDataInstance()
{
	identifier = 0;
	name = "";
	description = "";
	damageType = new bool[3]();

	dealedDamageModificationByPercent = new int[7]();
	dealedMagicDamageModificationByPercentWithProperty = new int[5]();
	receivedDamageModificationByPercent = new int[7]();
	receivedMagicDamageModificationByPercentWithProperty = new int[5]();
}

CombatPropertyDataInstance::~CombatPropertyDataInstance()
{
	delete[] damageType;

	delete[] dealedDamageModificationByPercent;
	delete[] dealedMagicDamageModificationByPercentWithProperty;
	delete[] receivedDamageModificationByPercent;
	delete[] receivedMagicDamageModificationByPercentWithProperty;
}

string CombatPropertyDataInstance::printData(stringstream ss)
{
	ss.str("");
    ss.clear();

	int index = 0;
	ss << "-----CombatPropertyDataInstance Print Begin-----\n";
	// Information from the super class
	ss << "identifier: " << n2s(identifier) << "\n";
	ss << "name: " << name << "\n";
	ss << "description: " << description << "\n";
	ss << "damageType: ";
	for (index = 0; index < 3; ++index)
	{
		ss << n2s(damageType[index]) << " ";
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
	ss << "-----CombatPropertyDataInstance Print End-----\n";

	return ss.str();
}