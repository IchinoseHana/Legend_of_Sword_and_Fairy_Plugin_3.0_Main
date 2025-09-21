#include "stdafx.h"
#include "StateDataManager.h"
#include <sstream>

using std::stringstream;
using std::string;

StateDataManager::StateDataManager()
{
	dataSize = 0;
}

StateDataManager::~StateDataManager()
{
	if (this->sustainableStateData) delete[] sustainableStateData;
}

StateDataManager* StateDataManager::sharedInstance()
{
	StateDataManager *initialInstance = new StateDataManager();
	return initialInstance;
}

// Function
bool StateDataManager::loadData()
{
	// Public variables
	int indexArraySize=0;
	int indexstr=0;
	char templine[maxBufferSizeForLoadingData];
	char *tempstrraw;
	FILE *fpcsv;

	// MARK: Status slot 1 & 2
	SustainableStateDataInstance *data = new SustainableStateDataInstance[maxSustainableStateDataSize];

	fpcsv = fopen(sustainableStateDataFilePath.c_str(), "r");
	
	if ( fpcsv == NULL )
	{
		ASSERT(0 && "Load SustainableStateDataInstance -> Failed\n");
		throw EXCEPTION("Load SustainableStateDataInstance -> Failed");
		return false;
	}
	
	indexArraySize = 0;
	while(!feof(fpcsv))
	{
		// Read a line
		fgets(templine, maxBufferSizeForLoadingData, fpcsv);
		
		// Current data instance
		SustainableStateDataInstance *e = &(data[indexArraySize]);

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
			else if (indexstr >= 83 && indexstr <= 89) e->dealedDamageModificationByPercent[indexstr - 83] = s2n(tempstr);
			else if (indexstr >= 90 && indexstr <= 94) e->dealedMagicDamageModificationByPercentWithProperty[indexstr - 90] = s2n(tempstr);
			else if (indexstr >= 95 && indexstr <= 101) e->receivedDamageModificationByPercent[indexstr - 95] = s2n(tempstr);
			else if (indexstr >= 102 && indexstr <= 106) e->receivedMagicDamageModificationByPercentWithProperty[indexstr - 90] = s2n(tempstr);
			else if (indexstr >= 107 && indexstr <= 118) e->basicStateModificationFixed[indexstr - 107] = s2n(tempstr);
			else if (indexstr >= 119 && indexstr <= 130) e->basicStateModificationByPercent[indexstr - 119] = s2n(tempstr);
			else if (indexstr >= 131 && indexstr <= 133) e->consumptionModificationByPercent[indexstr - 131] = s2n(tempstr);
			else if (indexstr >= 134 && indexstr <= 140) e->actionTakesNoEffect[indexstr - 134] = s2b(tempstr);
			else if (indexstr >= 141 && indexstr <= 147) e->receivedActionTakesNoEffect[indexstr - 141] = s2b(tempstr);
			else if (indexstr >= 148 && indexstr <= 155) e->actionForbid[indexstr - 148] = s2b(tempstr);
			else if (indexstr >= 156 && indexstr <= 162) e->receivedDamageReboundByPercent[indexstr - 156] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 163 && indexstr <= 169) e->receivedDamageAbsorbByPercent[indexstr - 163] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 170 && indexstr <= 177) e->currentStateModificationWhenTriggeredFixed[indexstr - 170] = s2n(tempstr);
			else if (indexstr >= 178 && indexstr <= 185) e->currentStateModificationWhenTriggeredByPercent[indexstr - 178] = s2n(tempstr);
			else if (indexstr >= 186 && indexstr <= 193) e->currentStateModificationWhenTriggeredLevelBased[indexstr - 186] = s2n(tempstr);
			else if (indexstr >= 194 && indexstr <= 205) e->basicStateModificationWhenTriggeredFixed[indexstr - 194] = s2n(tempstr);
			else if (indexstr >= 206 && indexstr <= 217) e->basicStateModificationWhenTriggeredByPercent[indexstr - 206] = s2n(tempstr);
			else if (indexstr >= 218 && indexstr <= 229) e->basicStateModificationWhenTriggeredLevelBased[indexstr - 218] = s2n(tempstr);
			else if (indexstr >= 230 && indexstr <= 253) e->temporaryStateSetWhenTriggeredFixed[indexstr - 230] = static_cast<unsigned short>(s2n(tempstr));
		}

		// Overwrite the description
		e->description = StateDataManager::generateDescriptionForSustainableState(e);

		indexArraySize++;
	}

	this->sustainableStateData = data;
	this->dataSize = indexArraySize;

	fclose(fpcsv);

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
	
	// Customized description
	if (instance->description.size() > 1) return instance->description;

	stringstream tempRes;
	tempRes.str("");
    tempRes.clear();
	int index;

	// MARK: Basic information
	// Layer
	if (instance->layer > 1) tempRes << "���" << n2s(instance->layer) << "�� ";
	
	// Delay
	if (instance->delay > 0) tempRes << n2s(instance->delay) << "�غϺ󷢶� ";
	
	// Is for all partner
    if (instance->isForAllPartner) tempRes << "ȫ�� ";

	// Step
    if (instance->step > 0) tempRes << "��������������" << n2s(instance->step) << " ";
	
	// MARK: Triggered: Always
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
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationFixed[index] != 0) tempRes << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
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

	// Action forbid
	for (index = 0; index < 8; ++index)
	{
		if (instance->actionForbid[index]) tempRes << "�޷�" << StateDataManager::getDescriptionForBasicAction(index) << "";
	}
	
	// Received damage rebound
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageReboundByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForAttackType(index) << "�˺�����" << (instance->receivedDamageReboundByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageReboundByPercent[index]) << "% ";
	}
	
	// Received damage absorb
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageAbsorbByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForAttackType(index) << "�˺�����" << (instance->receivedDamageAbsorbByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageAbsorbByPercent[index]) << "% ";
	}
	
	// MARK: Triggered: By customizing
	// Customized trigger type
	for (index = 0; index < 7; ++index)
	{
		if (instance->customizedTriggerType[index]) tempRes << StateDataManager::getDescriptionForCustomTriggerType(index) << " ";
	}
	
	// Current state modification
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100) tempRes << n2s(instance->currentStateModificationPosibility[index]) << "��"; 
		if (instance->currentStateModificationWhenTriggeredFixed[index] != 0) tempRes << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100) tempRes << n2s(instance->currentStateModificationPosibility[index]) << "��"; 
		if (instance->currentStateModificationWhenTriggeredByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100) tempRes << n2s(instance->currentStateModificationPosibility[index]) << "��"; 
		if (instance->currentStateModificationWhenTriggeredLevelBased[index] != 0) tempRes << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->currentStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	// Basic state modification
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100) tempRes << n2s(instance->basicStateModificationPosibility[index]) << "��"; 
		if (instance->basicStateModificationWhenTriggeredFixed[index] != 0) tempRes << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100) tempRes << n2s(instance->basicStateModificationPosibility[index]) << "��"; 
		if (instance->basicStateModificationWhenTriggeredByPercent[index] != 0) tempRes << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100) tempRes << n2s(instance->basicStateModificationPosibility[index]) << "��"; 
		if (instance->basicStateModificationWhenTriggeredLevelBased[index] != 0) tempRes << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->basicStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	
	// Temporary state modification
	for (index = 0; index < 24; ++index)
	{
		if (instance->temporaryStateSetPosibility[index] < 100) tempRes << n2s(instance->temporaryStateSetPosibility[index]) << "��"; 
		if (instance->temporaryStateSetWhenTriggeredFixed[index] != 0) tempRes << StateDataManager::getDescriptionForTemporaryState(index) << "(" << n2s(instance->temporaryStateSetWhenTriggeredFixed[index]) << ") ";
	}
	
	// MARK: Other information
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) tempRes << "�������������˶��� ";
	if (!instance->isInterruptCurrentAction[1]) tempRes << "�������з����˶��� ";

	tempRes.str("");
    tempRes.clear();
	return tempRes.str();
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


// Basic function
string StateDataManager::numberToString(int num)
{
	char buffer[maxBufferSizeForNumberToString];
    _itoa(num, buffer, 10);
	string temp = buffer;
	return temp;
}

int StateDataManager::stringToNumber(const string& str)
{
	return atoi(str.c_str());
}

bool StateDataManager::stringToBool(const string& str)
{
	return str == "0" ? false : true;
}