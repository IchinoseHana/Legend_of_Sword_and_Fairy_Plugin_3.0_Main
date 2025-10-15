#include "stdafx.h"
#include "StateDataManager.h"
#include <algorithm>

StateDataManager::StateDataManager()
{
	sustainableStateDataSize = 0;
	temporaryStateDataSize = 0;
}

StateDataManager::~StateDataManager()
{
	if (this->sustainableStateData) delete[] sustainableStateData;
	if (this->sustainableStateIdentifierData) delete[] sustainableStateIdentifierData;
	if (this->temporaryStateData) delete[] temporaryStateData;
	if (this->temporaryStateIdentifierData) delete[] temporaryStateIdentifierData;
}

StateDataManager* StateDataManager::initialInstance = new StateDataManager();
StateDataManager* StateDataManager::sharedInstance()
{
	return initialInstance;
}

// Function
bool StateDataManager::loadData()
{
	// Public variables
	int indexArraySize = 0;
	int indexstr = 0;
	char templine[maxBufferSizeForLoadingData];
	char *tempstrraw;
	FILE *fpcsv;

	// MARK: Status slot 1 & 2
	SustainableStateDataInstance *dataS = new SustainableStateDataInstance[maxSustainableStateDataSize];
	unsigned int *identifierDataS = new unsigned int[maxSustainableStateDataSize]();

	fpcsv = fopen(sustainableStateDataFilePath.c_str(), "r");
	
	if ( fpcsv == NULL )
	{
		ASSERT(0 && "StateDataManager -> loadData: Load SustainableStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> loadData: Load SustainableStateDataInstance failed");
		return false;
	}
	
	indexArraySize = 0;
	while(!feof(fpcsv))
	{
		// Read a line
		fgets(templine, maxBufferSizeForLoadingData, fpcsv);
		
		// Current data instance
		SustainableStateDataInstance *e = &(dataS[indexArraySize]);

		// Current index 
		indexstr = 0;
		
		// Handle the data in the lineData processing
		tempstrraw = strtok(templine, "\t");
		string tempstr = tempstrraw;
		e->identifier = static_cast<unsigned int>(s2n(tempstr));
		
		// Remaining data processing
		while(tempstrraw = strtok(NULL, "\t"))
		{
			++indexstr;
			tempstr = tempstrraw;

			// Remove the char '\n'
			if (indexstr == 253 && tempstr[tempstr.size() - 1] == '\n') tempstr.erase(tempstr.size() - 1);
			
			if (indexstr == 1) e->name = tempstr;
			else if (indexstr == 2) e->description = tempstr;
			else if (indexstr == 3) ; // Comment, drop
			else if (indexstr >= 4 && indexstr <= 13) e->effectIdentifier[indexstr - 4] = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr >= 14 && indexstr <= 23) e->isCenteringEffectPosition[indexstr - 14] = s2b(tempstr);
			else if (indexstr == 24) e->layer = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 25) e->step = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 26) e->delay = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 27) e->slot = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 28) e->isForAllPartner = s2b(tempstr);
			else if (indexstr >= 29 && indexstr <= 36) e->currentStateModificationPosibility[indexstr - 29] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 37 && indexstr <= 48) e->basicStateModificationPosibility[indexstr - 37] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 49 && indexstr <= 72) e->temporaryStateSetPosibility[indexstr - 49] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 73 && indexstr <= 74) e->isInterruptCurrentAction[indexstr - 73] = s2b(tempstr);
			else if (indexstr == 75) e->specificEffectIdentifier = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr >= 76 && indexstr <= 82) e->customizedTriggerType[indexstr - 76] = s2b(tempstr);
			else if (indexstr >= 83 && indexstr <= 85) e->damageType[indexstr - 83] = s2b(tempstr);
			else if (indexstr >= 86 && indexstr <= 92) e->dealedDamageModificationByPercent[indexstr - 86] = s2n(tempstr);
			else if (indexstr >= 93 && indexstr <= 97) e->dealedMagicDamageModificationByPercentWithProperty[indexstr - 93] = s2n(tempstr);
			else if (indexstr >= 98 && indexstr <= 104) e->receivedDamageModificationByPercent[indexstr - 98] = s2n(tempstr);
			else if (indexstr >= 105 && indexstr <= 109) e->receivedMagicDamageModificationByPercentWithProperty[indexstr - 105] = s2n(tempstr);
			else if (indexstr >= 110 && indexstr <= 121) e->basicStateModificationFixed[indexstr - 110] = s2n(tempstr);
			else if (indexstr >= 122 && indexstr <= 133) e->basicStateModificationByPercent[indexstr - 122] = s2n(tempstr);
			else if (indexstr >= 134 && indexstr <= 136) e->consumptionModificationByPercent[indexstr - 134] = s2n(tempstr);
			else if (indexstr >= 137 && indexstr <= 143) e->actionTakesNoEffect[indexstr - 137] = s2b(tempstr);
			else if (indexstr >= 144 && indexstr <= 150) e->receivedActionTakesNoEffect[indexstr - 144] = s2b(tempstr);
			else if (indexstr >= 151 && indexstr <= 158) e->actionForbid[indexstr - 151] = s2b(tempstr);
			else if (indexstr >= 159 && indexstr <= 165) e->receivedDamageReboundByPercent[indexstr - 159] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 166 && indexstr <= 172) e->receivedDamageAbsorbByPercent[indexstr - 166] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 173 && indexstr <= 180) e->currentStateModificationWhenTriggeredFixed[indexstr - 173] = s2n(tempstr);
			else if (indexstr >= 181 && indexstr <= 188) e->currentStateModificationWhenTriggeredByPercent[indexstr - 181] = s2n(tempstr);
			else if (indexstr >= 189 && indexstr <= 196) e->currentStateModificationWhenTriggeredLevelBased[indexstr - 189] = s2n(tempstr);
			else if (indexstr >= 197 && indexstr <= 208) e->basicStateModificationWhenTriggeredFixed[indexstr - 197] = s2n(tempstr);
			else if (indexstr >= 209 && indexstr <= 220) e->basicStateModificationWhenTriggeredByPercent[indexstr - 209] = s2n(tempstr);
			else if (indexstr >= 221 && indexstr <= 232) e->basicStateModificationWhenTriggeredLevelBased[indexstr - 221] = s2n(tempstr);
			else if (indexstr >= 233 && indexstr <= 256) e->temporaryStateSetWhenTriggeredFixed[indexstr - 233] = static_cast<unsigned short>(s2n(tempstr));
		}

		// Current identifier
		identifierDataS[indexArraySize] = e->identifier;

		// Overwrite the description
		e->description = StateDataManager::generateDescriptionForSustainableState(e, this->ss);

		indexArraySize++;
	}

	this->sustainableStateData = dataS;
	this->sustainableStateIdentifierData = identifierDataS;
	this->sustainableStateDataSize = indexArraySize;

	fclose(fpcsv);

	// MARK: Status slot 3 & 4
	TemporaryStateDataInstance *dataT = new TemporaryStateDataInstance[maxTemporaryStateDataSize];
	unsigned int *identifierDataT = new unsigned int[maxTemporaryStateDataSize]();

	fpcsv = fopen(temporaryStateDataFilePath.c_str(), "r");
	
	if ( fpcsv == NULL )
	{
		ASSERT(0 && "StateDataManager -> loadData: Load TemporaryStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> loadData: Load TemporaryStateDataInstance failed");
		return false;
	}
	
	indexArraySize = 0;
	while(!feof(fpcsv))
	{
		// Read a line
		fgets(templine, maxBufferSizeForLoadingData, fpcsv);
		
		// Current data instance
		TemporaryStateDataInstance *e = &(dataT[indexArraySize]);

		// Current index 
		indexstr = 0;
		
		// Handle the data in the lineData processing
		tempstrraw = strtok(templine, "\t");
		string tempstr = tempstrraw;
		e->identifier = static_cast<unsigned int>(s2n(tempstr));
		
		// Remaining data processing
		while(tempstrraw = strtok(NULL, "\t"))
		{
			++indexstr;
			tempstr = tempstrraw;

			// Remove the char '\n'
			if (indexstr == 170 && tempstr[tempstr.size() - 1] == '\n') tempstr.erase(tempstr.size() - 1);
			
			if (indexstr == 1) e->name = tempstr;
			else if (indexstr == 2) e->description = tempstr;
			else if (indexstr == 3) ; // Comment, drop
			else if (indexstr >= 4 && indexstr <= 13) e->effectIdentifier[indexstr - 4] = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr >= 14 && indexstr <= 23) e->isCenteringEffectPosition[indexstr - 14] = s2b(tempstr);
			else if (indexstr == 24) e->slot = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 25) e->isForAllPartner = s2b(tempstr);
			else if (indexstr >= 26 && indexstr <= 33) e->currentStateModificationPosibility[indexstr - 26] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 34 && indexstr <= 45) e->basicStateModificationPosibility[indexstr - 34] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 46 && indexstr <= 69) e->temporaryStateSetPosibility[indexstr - 46] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 70 && indexstr <= 71) e->isInterruptCurrentAction[indexstr - 70] = s2b(tempstr);
			else if (indexstr == 72) e->specificEffectIdentifier = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr >= 73 && indexstr <= 79) e->customizedTriggerType[indexstr - 73] = s2b(tempstr);
			else if (indexstr >= 80 && indexstr <= 86) e->cancelSourceEffect[indexstr - 80] = s2b(tempstr);
			else if (indexstr >= 87 && indexstr <= 94) e->currentStateModificationWhenTriggeredFixed[indexstr - 87] = s2n(tempstr);
			else if (indexstr >= 95 && indexstr <= 102) e->currentStateModificationWhenTriggeredByPercent[indexstr - 95] = s2n(tempstr);
			else if (indexstr >= 103 && indexstr <= 110) e->currentStateModificationWhenTriggeredLevelBased[indexstr - 103] = s2n(tempstr);
			else if (indexstr >= 111 && indexstr <= 122) e->basicStateModificationWhenTriggeredFixed[indexstr - 111] = s2n(tempstr);
			else if (indexstr >= 123 && indexstr <= 134) e->basicStateModificationWhenTriggeredByPercent[indexstr - 123] = s2n(tempstr);
			else if (indexstr >= 135 && indexstr <= 146) e->basicStateModificationWhenTriggeredLevelBased[indexstr - 135] = s2n(tempstr);
			else if (indexstr >= 147 && indexstr <= 170) e->temporaryStateSetWhenTriggeredFixed[indexstr - 147] = static_cast<unsigned short>(s2n(tempstr));
		}

		// Current identifier
		identifierDataT[indexArraySize] = e->identifier;

		// Overwrite the description
		e->description = StateDataManager::generateDescriptionForTemporaryState(e, this->ss);

		indexArraySize++;
	}

	this->temporaryStateData = dataT;
	this->temporaryStateIdentifierData = identifierDataT;
	this->temporaryStateDataSize = indexArraySize;

	fclose(fpcsv);

	return true;
}

SustainableStateDataInstance* StateDataManager::sustainableInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->sustainableStateIdentifierData, this->sustainableStateIdentifierData + this->sustainableStateDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->sustainableStateDataSize; ++index)
		{
			if (this->sustainableStateData[index].identifier == identifier)
			{
				// Find the value, break
				value = index;
				break;
			}
		}
	}

	if (value != -1)
	{
		return &(this->sustainableStateData[value]);
	}
	else
	{
		ASSERT(0 && "StateDataManager -> instanceForIdentifier: Find SustainableStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> instanceForIdentifier: Find SustainableStateDataInstance failed");
		// For the error case, return the first value
		return &(this->sustainableStateData[0]);
	}
}

TemporaryStateDataInstance* StateDataManager::temporaryInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->temporaryStateIdentifierData, this->temporaryStateIdentifierData + this->temporaryStateDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->temporaryStateDataSize; ++index)
		{
			if (this->temporaryStateData[index].identifier == identifier)
			{
				// Find the value, break
				value = index;
				break;
			}
		}
	}

	if (value != -1)
	{
		return &(this->temporaryStateData[value]);
	}
	else
	{
		ASSERT(0 && "StateDataManager -> instanceForIdentifier: Find TemporaryStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> instanceForIdentifier: Find TemporaryStateDataInstance failed");
		// For the error case, return the first value
		return &(this->temporaryStateData[0]);
	}
}

CountableStateDataInstance* StateDataManager::countableInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->countableStateIdentifierData, this->countableStateIdentifierData + this->countableStateDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->countableStateDataSize; ++index)
		{
			if (this->countableStateIdentifierData[index].identifier == identifier)
			{
				// Find the value, break
				value = index;
				break;
			}
		}
	}

	if (value != -1)
	{
		return &(this->countableStateData[value]);
	}
	else
	{
		ASSERT(0 && "StateDataManager -> instanceForIdentifier: Find CountableStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> instanceForIdentifier: Find CountableStateDataInstance failed");
		// For the error case, return the first value
		return &(this->countableStateData[0]);
	}
}

// Utility
/*std::wstring StateDataManager::getFixedName(StateDataRunningInfo *instance)
{
	if (!instance) return "";

	std::ostringstream ss;

	ss << instance.name;
	ss << "(";
	ss << 
	return 
}*/

string StateDataManager::generateDescriptionForSustainableState(SustainableStateDataInstance *instance, stringstream ss)
{
	if (!instance) return "";
	
	// Customized description
	if (instance->description.size() > 1) return instance->description;

	ss.str("");
    ss.clear();
	int index;

	// MARK: Basic information
	// Layer
	if (instance->layer > 1) ss << "���" << n2s(instance->layer) << "�� ";
	
	// Delay
	if (instance->delay > 0) ss << "�ӳ�" << n2s(instance->delay) << "�η��� ";
	
	// Is for all partner
    if (instance->isForAllPartner) ss << "ȫ�� ";

	// Step
    if (instance->step > 0) ss << "��������������" << n2s(instance->step) << " ";
	
	// MARK: Triggered: Always
	// Damage description
	string damageDescription = "";
	if (instance->damageType[0] == 1) damageDescription = "�˺�";
	else if (instance->damageType[1] == 1) damageDescription = "�ָ�";
	else if (instance->damageType[2] == 1) damageDescription = "Ч��";
	else damageDescription = "�˺�";

	// Dealed damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->dealedDamageModificationByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << damageDescription << (instance->dealedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->dealedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->dealedMagicDamageModificationByPercentWithProperty[index] != 0) ss << StateDataManager::getDescriptionForMagicProperty(index) << "ϵ����" << damageDescription << (instance->dealedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->dealedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}
	
	// Received damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageModificationByPercent[index] != 0) ss << "��" << StateDataManager::getDescriptionForAttackType(index) << damageDescription << (instance->receivedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->receivedMagicDamageModificationByPercentWithProperty[index] != 0) ss << "��" << StateDataManager::getDescriptionForMagicProperty(index) << "ϵ����" << damageDescription << (instance->receivedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->receivedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}
	
	// Basic state modification
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationFixed[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationByPercent[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationByPercent[index]) << "% ";
	}

	// Consumption modification
	for (index = 0; index < 3; ++index)
	{
		if (instance->consumptionModificationByPercent[index] != 0) ss << StateDataManager::getDescriptionForConsumptionType(index) << (instance->consumptionModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->consumptionModificationByPercent[index]) << "% ";
	}
	
	// Action takes no effect
	for (index = 0; index < 7; ++index)
	{
		if (instance->actionTakesNoEffect[index]) ss << StateDataManager::getDescriptionForAttackType(index) << (index == 6 ? "����" : "") << "�޷���Ч ";
	}
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedActionTakesNoEffect[index]) ss << "��" << StateDataManager::getDescriptionForAttackType(index) << (index == 6 ? "����" : "") << "���� ";
	}

	// Action forbid
	for (index = 0; index < 8; ++index)
	{
		if (instance->actionForbid[index]) ss << "�޷�" << StateDataManager::getDescriptionForBasicAction(index) << " ";
	}
	
	// Received damage rebound
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageReboundByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << "�˺�����" << (instance->receivedDamageReboundByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageReboundByPercent[index]) << "% ";
	}
	
	// Received damage absorb
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageAbsorbByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << "�˺�����" << (instance->receivedDamageAbsorbByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageAbsorbByPercent[index]) << "% ";
	}
	
	// MARK: Triggered: By customizing
	// Customized trigger type
	for (index = 0; index < 7; ++index)
	{
		if (instance->customizedTriggerType[index]) ss << StateDataManager::getDescriptionForCustomTriggerType(index) << " ";
	}
	
	// Current state modification
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%��"; 
		if (instance->currentStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%��"; 
		if (instance->currentStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%��"; 
		if (instance->currentStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->currentStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	// Basic state modification
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%��"; 
		if (instance->basicStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%��";  
		if (instance->basicStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%��";  
		if (instance->basicStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->basicStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	
	// Temporary state modification
	for (index = 0; index < 24; ++index)
	{
		if (instance->temporaryStateSetPosibility[index] < 100 && instance->temporaryStateSetPosibility[index] > 0) ss << n2s(instance->temporaryStateSetPosibility[index]) << "%��";  
		if (instance->temporaryStateSetWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForTemporaryState(index) << "(" << n2s(instance->temporaryStateSetWhenTriggeredFixed[index]) << ") ";
	}
	
	// MARK: Other information
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) ss << "�������������˶��� ";
	if (!instance->isInterruptCurrentAction[1]) ss << "�������з����˶��� ";

	return ss.str();
}

string StateDataManager::generateDescriptionForTemporaryState(TemporaryStateDataInstance *instance, stringstream ss)
{
	if (!instance) return "";
	
	// Customized description
	if (instance->description.size() > 1) return instance->description;

	ss.str("");
    ss.clear();
	int index;

	// MARK: Basic information
	// Is for all partner
    if (instance->isForAllPartner) ss << "ȫ�� ";

	// Cancel source effect
	for (index = 0; index < 7; ++index)
	{
		if (instance->cancelSourceEffect[index]) ss << "����" << StateDataManager::getDescriptionForAttackType(index) << "Ч�� ";
	}
	
	// MARK: Triggered: By customizing
	// Customized trigger type
	for (index = 0; index < 7; ++index)
	{
		if (instance->customizedTriggerType[index]) ss << StateDataManager::getDescriptionForCustomTriggerType(index) << " ";
	}
	
	// Current state modification
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%��"; 
		if (instance->currentStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%��"; 
		if (instance->currentStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%��"; 
		if (instance->currentStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->currentStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	// Basic state modification
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%��"; 
		if (instance->basicStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%��";  
		if (instance->basicStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%��";  
		if (instance->basicStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->basicStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	
	// Temporary state modification
	for (index = 0; index < 24; ++index)
	{
		if (instance->temporaryStateSetPosibility[index] < 100 && instance->temporaryStateSetPosibility[index] > 0) ss << n2s(instance->temporaryStateSetPosibility[index]) << "%��";  
		if (instance->temporaryStateSetWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForTemporaryState(index) << "(" << n2s(instance->temporaryStateSetWhenTriggeredFixed[index]) << ") ";
	}
	
	// MARK: Other information
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) ss << "�������������˶��� ";
	if (!instance->isInterruptCurrentAction[1]) ss << "�������з����˶��� ";

	return ss.str();
}

string StateDataManager::getDescriptionForCustomTriggerType(int index)
{
	switch (index)
	{
	case 0:
		return "�غϿ�ʼʱ:";
		break;
	case 1:
		return "������ͨ������:";
		break;
	case 2:
		return "ʹ���ؼ���:";
		break;
	case 3:
		return "ʩ��������:";
		break;
	case 4:
		return "ʹ����Ʒ��:";
		break;
	case 5:
		return "������:";
		break;
	case 6:
		return "�ܵ��˺���:";
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
	case 7:
		return "ˮ����";
		break;
	case 8:
		return "������";
		break;
	case 9:
		return "������";
		break;
	case 10:
		return "������";
		break;
	case 11:
		return "������";
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

string StateDataManager::getDescriptionForBasicAction(int index)
{
switch (index)
	{
	case 0:
		return "������ͨ����";
		break;
	case 1:
		return "ʹ���ؼ�";
		break;
	case 2:
		return "ʩ������";
		break;
	case 3:
		return "ʹ����Ʒ";
		break;
	case 4:
		return "ʹ��ħ����";
		break;
	case 5:
		return "����";
		break;
	case 6:
		return "����";
		break;
	case 7:
		return "�ظ���һ�ζ���";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForCurrentState(int index)
{
switch (index)
	{
	case 0:
		return "��";
		break;
	case 1:
		return "��";
		break;
	case 2:
		return "��";
		break;
	case 3:
		return "��Ǯ";
		break;
	case 4:
		return "���н���";
		break;
	case 5:
		return "����";
		break;
	case 6:
		return "����";
		break;
	case 7:
		return "����";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForTemporaryState(int index)
{
switch (index)
	{
	case 0:
		return "��";
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
	case 5:
		return "��";
		break;
	case 6:
		return "��";
		break;
	case 7:
		return "��";
		break;
	case 8:
		return "��";
		break;
	case 9:
		return "��";
		break;
	case 10:
		return "�ܶ�";
		break;
	case 11:
		return "����";
		break;
	case 12:
		return "����";
		break;
	case 13:
		return "����";
		break;
	case 14:
		return "����";
		break;
	case 15:
		return "����";
		break;
	case 16:
		return "����";
		break;
	case 17:
		return "�ٻ�";
		break;
	case 18:
		return "����";
		break;
	case 19:
		return "ˮ��";
		break;
	case 20:
		return "��";
		break;
	case 21:
		return "�綾";
		break;
	case 22:
		return "�׶�";
		break;
	case 23:
		return "����";
		break;
	}

	return "";
}

// Debug
string StateDataManager::printData()
{
	string tempStr = "";
	int index = 0;
	for (index = 0; index < this->sustainableStateDataSize; ++index)
	{
		SustainableStateDataInstance *e = &(this->sustainableStateData[index]);
		tempStr += e->printData(this->ss);
	}
	for (index = 0; index < this->temporaryStateDataSize; ++index)
	{
		TemporaryStateDataInstance *e = &(this->temporaryStateData[index]);
		tempStr += e->printData(this->ss);
	}

	return tempStr;
}


