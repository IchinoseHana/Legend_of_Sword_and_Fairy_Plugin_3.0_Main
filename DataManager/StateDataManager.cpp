#include "stdafx.h"
#include "StateDataManager.h"
#include <algorithm>

StateDataManager::StateDataManager()
{
	sustainableStateDataSize = 0;
	temporaryStateDataSize = 0;
	countableStateDataSize = 0;
	combatPropertyDataSize = 0;
	combatEnvironmentDataSize = 0;
	combatStateDataSize = 0;
}

StateDataManager::~StateDataManager()
{
	if (this->sustainableStateData) delete[] sustainableStateData;
	if (this->sustainableStateIdentifierData) delete[] sustainableStateIdentifierData;
	if (this->temporaryStateData) delete[] temporaryStateData;
	if (this->temporaryStateIdentifierData) delete[] temporaryStateIdentifierData;
	if (this->countableStateData) delete[] countableStateData;
	if (this->countableStateIdentifierData) delete[] countableStateIdentifierData;
	if (this->combatPropertyData) delete[] combatPropertyData;
	if (this->combatPropertyIdentifierData) delete[] combatPropertyIdentifierData;
	if (this->combatEnvironmentData) delete[] combatEnvironmentData;
	if (this->combatEnvironmentIdentifierData) delete[] combatEnvironmentIdentifierData;
	if (this->combatStateData) delete[] combatStateData;
	if (this->combatStateIdentifierData) delete[] combatStateIdentifierData;
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
			if (indexstr == 256 && tempstr[tempstr.size() - 1] == '\n') tempstr.erase(tempstr.size() - 1);
			
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

	// MARK: Status slot 5
	CountableStateDataInstance *dataC = new CountableStateDataInstance[maxCountableStateDataSize];
	unsigned int *identifierDataC = new unsigned int[maxCountableStateDataSize]();

	fpcsv = fopen(countableStateDataFilePath.c_str(), "r");
	
	if ( fpcsv == NULL )
	{
		ASSERT(0 && "StateDataManager -> loadData: Load CountableStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> loadData: Load CountableStateDataInstance failed");
		return false;
	}
	
	indexArraySize = 0;
	while(!feof(fpcsv))
	{
		// Read a line
		fgets(templine, maxBufferSizeForLoadingData, fpcsv);
		
		// Current data instance
		CountableStateDataInstance *e = &(dataC[indexArraySize]);

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
			if (indexstr == 260 && tempstr[tempstr.size() - 1] == '\n') tempstr.erase(tempstr.size() - 1);
			
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
			else if (indexstr == 257) e->countValue = static_cast<int>(s2n(tempstr));
			else if (indexstr == 258) e->effectTriggeredWhenCountValueChanging = s2b(tempstr);
			else if (indexstr == 259) e->effectNotTriggeredByCustomTrigger = s2b(tempstr);
			else if (indexstr == 260) e->countValueChangeTriggerType = static_cast<CountableStateCountValueChangeTriggerType>(s2n(tempstr));
		}

		// Current identifier
		identifierDataC[indexArraySize] = e->identifier;

		// Overwrite the description
		e->description = StateDataManager::generateDescriptionForCountableState(e, this->ss);

		indexArraySize++;
	}

	this->countableStateData = dataC;
	this->countableStateIdentifierData = identifierDataC;
	this->countableStateDataSize = indexArraySize;

	fclose(fpcsv);

	// MARK: Combat property
	CombatPropertyDataInstance *dataCP = new CombatPropertyDataInstance[maxCombatPropertyDataSize];
	unsigned int *identifierDataCP = new unsigned int[maxCombatPropertyDataSize]();

	fpcsv = fopen(combatPropertyDataFilePath.c_str(), "r");
	
	if ( fpcsv == NULL )
	{
		ASSERT(0 && "StateDataManager -> loadData: Load CombatPropertyDataInstance failed");
		throw EXCEPTION("StateDataManager -> loadData: Load CombatPropertyDataInstance failed");
		return false;
	}
	
	indexArraySize = 0;
	while(!feof(fpcsv))
	{
		// Read a line
		fgets(templine, maxBufferSizeForLoadingData, fpcsv);
		
		// Current data instance
		CombatPropertyDataInstance *e = &(dataCP[indexArraySize]);

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
			if (indexstr == 30 && tempstr[tempstr.size() - 1] == '\n') tempstr.erase(tempstr.size() - 1);
			
			if (indexstr == 1) e->name = tempstr;
			else if (indexstr == 2) e->description = tempstr;
			else if (indexstr == 3) ; // Comment, drop
			else if (indexstr >= 4 && indexstr <= 6) e->damageType[indexstr - 4] = s2b(tempstr);
			else if (indexstr >= 7 && indexstr <= 13) e->dealedDamageModificationByPercent[indexstr - 7] = s2n(tempstr);
			else if (indexstr >= 14 && indexstr <= 18) e->dealedMagicDamageModificationByPercentWithProperty[indexstr - 14] = s2n(tempstr);
			else if (indexstr >= 19 && indexstr <= 25) e->receivedDamageModificationByPercent[indexstr - 19] = s2n(tempstr);
			else if (indexstr >= 26 && indexstr <= 30) e->receivedMagicDamageModificationByPercentWithProperty[indexstr - 26] = s2n(tempstr);
		}

		// Current identifier
		identifierDataCP[indexArraySize] = e->identifier;

		// Overwrite the description
		e->description = StateDataManager::generateDescriptionForCombatProperty(e, this->ss);

		indexArraySize++;
	}

	this->combatPropertyData = dataCP;
	this->combatPropertyIdentifierData = identifierDataCP;
	this->combatPropertyDataSize = indexArraySize;

	fclose(fpcsv);

	// MARK: Combat environment
	CombatEnvironmentDataInstance *dataCE = new CombatEnvironmentDataInstance[maxCombatEnvironmentDataSize];
	unsigned int *identifierDataCE = new unsigned int[maxCombatEnvironmentDataSize]();

	fpcsv = fopen(combatEnvironmentDataFilePath.c_str(), "r");
	
	if ( fpcsv == NULL )
	{
		ASSERT(0 && "StateDataManager -> loadData: Load CombatEnvironmentDataInstance failed");
		throw EXCEPTION("StateDataManager -> loadData: Load CombatEnvironmentDataInstance failed");
		return false;
	}
	
	indexArraySize = 0;
	while(!feof(fpcsv))
	{
		// Read a line
		fgets(templine, maxBufferSizeForLoadingData, fpcsv);
		
		// Current data instance
		CombatEnvironmentDataInstance *e = &(dataCE[indexArraySize]);

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
			if (indexstr == 260 && tempstr[tempstr.size() - 1] == '\n') tempstr.erase(tempstr.size() - 1);
			
			if (indexstr == 1) e->name = tempstr;
			else if (indexstr == 2) e->description = tempstr;
			else if (indexstr == 3) ; // Comment, drop
			else if (indexstr >= 4 && indexstr <= 13) e->effectIdentifier[indexstr - 4] = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr >= 14 && indexstr <= 23) e->isCenteringEffectPosition[indexstr - 14] = s2b(tempstr);
			else if (indexstr == 24) e->layer = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 25) e->step = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 26) ; // Not useful, drop
			else if (indexstr == 27) ; // Not useful, drop
			else if (indexstr == 28) ; // Not useful, drop
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
			else if (indexstr >= 257 && indexstr <= 258) e->targetType[indexstr - 257] = s2b(tempstr);
			else if (indexstr == 259) e->hasmask = s2b(tempstr);
			else if (indexstr == 260) e->maskColor->red = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr == 261) e->maskColor->green = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr == 262) e->maskColor->blue = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr == 263) e->maskColor->alpha = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr == 264) e->magicChangingPosibility = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr == 265) e->magicChangingTargetIdentifier = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr >= 266 && indexstr <= 267) e->itemNotBeConsumedPosibilityindexstr[indexstr - 266] = static_cast<unsigned short>(s2n(tempstr));
			else if (indexstr >= 268 && indexstr <= 269) e->itemNotBeConsumedUpperBoundWithPrice[indexstr - 268] = static_cast<unsigned int>(s2n(tempstr));
			else if (indexstr == 270) e->usingRealTimeTrigger = s2b(tempstr);
			else if (indexstr == 271) e->realTimeBasedStateModificationInterval = s2d(tempstr);
		}

		// Current identifier
		identifierDataC[indexArraySize] = e->identifier;

		// Overwrite the description
		e->description = StateDataManager::generateDescriptionForCountableState(e, this->ss);

		indexArraySize++;
	}

	this->countableStateData = dataC;
	this->countableStateIdentifierData = identifierDataC;
	this->countableStateDataSize = indexArraySize;

	fclose(fpcsv);

	return true;
}

SustainableStateDataInstance* StateDataManager::sustainableStateInstanceForIdentifier(unsigned int identifier)
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

TemporaryStateDataInstance* StateDataManager::temporaryStateInstanceForIdentifier(unsigned int identifier)
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

CountableStateDataInstance* StateDataManager::countableStateInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->countableStateIdentifierData, this->countableStateIdentifierData + this->countableStateDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->countableStateDataSize; ++index)
		{
			if (this->countableStateData[index].identifier == identifier)
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

CombatPropertyDataInstance* StateDataManager::combatPropertyInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->combatPropertyIdentifierData, this->combatPropertyIdentifierData + this->combatPropertyDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->combatPropertyDataSize; ++index)
		{
			if (this->combatPropertyData[index].identifier == identifier)
			{
				// Find the value, break
				value = index;
				break;
			}
		}
	}

	if (value != -1)
	{
		return &(this->combatPropertyData[value]);
	}
	else
	{
		ASSERT(0 && "StateDataManager -> instanceForIdentifier: Find CombatPropertyDataInstance failed");
		throw EXCEPTION("StateDataManager -> instanceForIdentifier: Find CombatPropertyDataInstance failed");
		// For the error case, return the first value
		return &(this->combatPropertyData[0]);
	}
}

CombatEnvironmentDataInstance* StateDataManager::combatEnvironmentInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->combatEnvironmentIdentifierData, this->combatEnvironmentIdentifierData + this->combatEnvironmentDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->combatEnvironmentDataSize; ++index)
		{
			if (this->combatEnvironmentData[index].identifier == identifier)
			{
				// Find the value, break
				value = index;
				break;
			}
		}
	}

	if (value != -1)
	{
		return &(this->combatEnvironmentData[value]);
	}
	else
	{
		ASSERT(0 && "StateDataManager -> instanceForIdentifier: Find CombatEnvironmentDataInstance failed");
		throw EXCEPTION("StateDataManager -> instanceForIdentifier: Find CombatEnvironmentDataInstance failed");
		// For the error case, return the first value
		return &(this->combatEnvironmentData[0]);
	}
}

CombatStateDataInstance* StateDataManager::combatStateInstanceForIdentifier(unsigned int identifier)
{
	// Using binary search firstly
	unsigned int value = *(std::lower_bound(this->combatStateIdentifierData, this->combatStateIdentifierData + this->combatStateDataSize, identifier));

	// If failed, using linear search to find the index
	if (value != identifier)
	{
		value = -1;

		for (int index = 0; index < this->combatStateDataSize; ++index)
		{
			if (this->combatStateData[index].identifier == identifier)
			{
				// Find the value, break
				value = index;
				break;
			}
		}
	}

	if (value != -1)
	{
		return &(this->combatStateData[value]);
	}
	else
	{
		ASSERT(0 && "StateDataManager -> instanceForIdentifier: Find CombatStateDataInstance failed");
		throw EXCEPTION("StateDataManager -> instanceForIdentifier: Find CombatStateDataInstance failed");
		// For the error case, return the first value
		return &(this->combatStateData[0]);
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
	if (instance->layer > 1) ss << "最大" << n2s(instance->layer) << "层 ";
	
	// Delay
	if (instance->delay > 0) ss << "延迟" << n2s(instance->delay) << "次发动 ";
	
	// Is for all partner
    if (instance->isForAllPartner) ss << "全体 ";

	// Step
    if (instance->step > 0) ss << "发动后威力增加" << n2s(instance->step) << " ";
	
	// Damage description
	string damageDescription = "";
	if (instance->damageType[0] == 1) damageDescription = "伤害";
	else if (instance->damageType[1] == 1) damageDescription = "恢复";
	else if (instance->damageType[2] == 1) damageDescription = "效果";
	else damageDescription = "伤害";

	// MARK: Triggered: Always
	// Dealed damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->dealedDamageModificationByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << damageDescription << (instance->dealedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->dealedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->dealedMagicDamageModificationByPercentWithProperty[index] != 0) ss << StateDataManager::getDescriptionForMagicProperty(index) << "系仙术" << damageDescription << (instance->dealedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->dealedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}
	
	// Received damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageModificationByPercent[index] != 0) ss << "受" << StateDataManager::getDescriptionForAttackType(index) << damageDescription << (instance->receivedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->receivedMagicDamageModificationByPercentWithProperty[index] != 0) ss << "受" << StateDataManager::getDescriptionForMagicProperty(index) << "系仙术" << damageDescription << (instance->receivedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->receivedMagicDamageModificationByPercentWithProperty[index]) << "% ";
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
		if (instance->actionTakesNoEffect[index]) ss << StateDataManager::getDescriptionForAttackType(index) << (index == 6 ? "动作" : "") << "无法生效 ";
	}
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedActionTakesNoEffect[index]) ss << "对" << StateDataManager::getDescriptionForAttackType(index) << (index == 6 ? "动作" : "") << "免疫 ";
	}

	// Action forbid
	for (index = 0; index < 8; ++index)
	{
		if (instance->actionForbid[index]) ss << "无法" << StateDataManager::getDescriptionForBasicAction(index) << " ";
	}
	
	// Received damage rebound
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageReboundByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << "伤害反弹" << (instance->receivedDamageReboundByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageReboundByPercent[index]) << "% ";
	}
	
	// Received damage absorb
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageAbsorbByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << "伤害吸收" << (instance->receivedDamageAbsorbByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageAbsorbByPercent[index]) << "% ";
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
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%："; 
		if (instance->currentStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%："; 
		if (instance->currentStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%："; 
		if (instance->currentStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->currentStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	// Basic state modification
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%："; 
		if (instance->basicStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%：";  
		if (instance->basicStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%：";  
		if (instance->basicStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->basicStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	
	// Temporary state modification
	for (index = 0; index < 24; ++index)
	{
		if (instance->temporaryStateSetPosibility[index] < 100 && instance->temporaryStateSetPosibility[index] > 0) ss << n2s(instance->temporaryStateSetPosibility[index]) << "%：";  
		if (instance->temporaryStateSetWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForTemporaryState(index) << "(" << n2s(instance->temporaryStateSetWhenTriggeredFixed[index]) << ") ";
	}
	
	// MARK: Other information
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) ss << "不触发己方受伤动作 ";
	if (!instance->isInterruptCurrentAction[1]) ss << "不触发敌方受伤动作 ";

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
    if (instance->isForAllPartner) ss << "全体 ";

	// Cancel source effect
	for (index = 0; index < 7; ++index)
	{
		if (instance->cancelSourceEffect[index]) ss << "免疫" << StateDataManager::getDescriptionForAttackType(index) << "效果 ";
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
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%："; 
		if (instance->currentStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%："; 
		if (instance->currentStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->currentStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 8; ++index)
	{
		if (instance->currentStateModificationPosibility[index] < 100 && instance->currentStateModificationPosibility[index] > 0) ss << n2s(instance->currentStateModificationPosibility[index]) << "%："; 
		if (instance->currentStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForCurrentState(index) << (instance->currentStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->currentStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	// Basic state modification
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%："; 
		if (instance->basicStateModificationWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredFixed[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredFixed[index]) << " ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%：";  
		if (instance->basicStateModificationWhenTriggeredByPercent[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredByPercent[index] > 0 ? "+" : "-") << n2s(instance->basicStateModificationWhenTriggeredByPercent[index]) << "% ";
	}
	for (index = 0; index < 12; ++index)
	{
		if (instance->basicStateModificationPosibility[index] < 100 && instance->basicStateModificationPosibility[index] > 0) ss << n2s(instance->basicStateModificationPosibility[index]) << "%：";  
		if (instance->basicStateModificationWhenTriggeredLevelBased[index] != 0) ss << StateDataManager::getDescriptionForBasicState(index) << (instance->basicStateModificationWhenTriggeredLevelBased[index] > 0 ? "+" : "-") << "[" <<n2s(instance->basicStateModificationWhenTriggeredLevelBased[index]) << "] ";
	}
	
	// Temporary state modification
	for (index = 0; index < 24; ++index)
	{
		if (instance->temporaryStateSetPosibility[index] < 100 && instance->temporaryStateSetPosibility[index] > 0) ss << n2s(instance->temporaryStateSetPosibility[index]) << "%：";  
		if (instance->temporaryStateSetWhenTriggeredFixed[index] != 0) ss << StateDataManager::getDescriptionForTemporaryState(index) << "(" << n2s(instance->temporaryStateSetWhenTriggeredFixed[index]) << ") ";
	}
	
	// MARK: Other information
	// Is interrupt current action
	if (!instance->isInterruptCurrentAction[0]) ss << "不触发己方受伤动作 ";
	if (!instance->isInterruptCurrentAction[1]) ss << "不触发敌方受伤动作 ";

	return ss.str();
}

string StateDataManager::generateDescriptionForCountableState(CountableStateDataInstance *instance, stringstream ss)
{
	if (!instance) return "";
	
	// Customized description
	if (instance->description.size() > 1) return instance->description;

	// Get the additional information from the current class first
	string tempStr = StateDataManager::getDescriptionForCountableStateCountValueChangeTriggerType(instance->countValueChangeTriggerType, instance->countValue);

	// Then append the result by the one from the super class
	string tempStrForSuperClass = StateDataManager::generateDescriptionForSustainableState(instance, ss);

	ss.str("");
    ss.clear();

	ss << tempStr << " " << tempStrForSuperClass;

	return ss.str();
}

string StateDataManager::generateDescriptionForCombatProperty(CombatPropertyDataInstance *instance, stringstream ss)
{
	if (!instance) return "";
	
	// Customized description
	if (instance->description.size() > 1) return instance->description;

	ss.str("");
    ss.clear();
	int index;

	// MARK: Basic information
	// Damage description
	string damageDescription = "";
	if (instance->damageType[0] == 1) damageDescription = "伤害";
	else if (instance->damageType[1] == 1) damageDescription = "恢复";
	else if (instance->damageType[2] == 1) damageDescription = "效果";
	else damageDescription = "伤害";

	// MARK: Triggered: Always
	// Dealed damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->dealedDamageModificationByPercent[index] != 0) ss << StateDataManager::getDescriptionForAttackType(index) << damageDescription << (instance->dealedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->dealedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->dealedMagicDamageModificationByPercentWithProperty[index] != 0) ss << StateDataManager::getDescriptionForMagicProperty(index) << "系仙术" << damageDescription << (instance->dealedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->dealedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}
	
	// Received damage modification
	for (index = 0; index < 7; ++index)
	{
		if (instance->receivedDamageModificationByPercent[index] != 0) ss << "受" << StateDataManager::getDescriptionForAttackType(index) << damageDescription << (instance->receivedDamageModificationByPercent[index] > 0 ? "+" : "-") << n2s(instance->receivedDamageModificationByPercent[index]) << "% ";
	}
	for (index = 0; index < 5; ++index)
	{
		if (instance->receivedMagicDamageModificationByPercentWithProperty[index] != 0) ss << "受" << StateDataManager::getDescriptionForMagicProperty(index) << "系仙术" << damageDescription << (instance->receivedMagicDamageModificationByPercentWithProperty[index] > 0 ? "+" : "-") << n2s(instance->receivedMagicDamageModificationByPercentWithProperty[index]) << "% ";
	}

	return ss.str();
}

string StateDataManager::getDescriptionForCustomTriggerType(int index)
{
	switch (index)
	{
	case 0:
		return "回合开始时:";
		break;
	case 1:
		return "进行普通攻击后:";
		break;
	case 2:
		return "使用特技后:";
		break;
	case 3:
		return "施放仙术后:";
		break;
	case 4:
		return "使用物品后:";
		break;
	case 5:
		return "防御后:";
		break;
	case 6:
		return "受到伤害后:";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForAttackType(int index)
{
	switch (index)
	{
	case 0:
		return "普通攻击";
		break;
	case 1:
		return "特技";
		break;
	case 2:
		return "仙术";
		break;
	case 3:
		return "物品";
		break;
	case 4:
		return "魔剑技";
		break;
	case 5:
		return "合击";
		break;
	case 6:
		return "全部";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForMagicProperty(int index)
{
	switch (index)
	{
	case 0:
		return "水";
		break;
	case 1:
		return "火";
		break;
	case 2:
		return "风";
		break;
	case 3:
		return "雷";
		break;
	case 4:
		return "土";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForBasicState(int index)
{
switch (index)
	{
	case 0:
		return "精上限";
		break;
	case 1:
		return "气上限";
		break;
	case 2:
		return "神上限";
		break;
	case 3:
		return "武";
		break;
	case 4:
		return "防";
		break;
	case 5:
		return "速";
		break;
	case 6:
		return "运";
		break;
	case 7:
		return "水属性";
		break;
	case 8:
		return "火属性";
		break;
	case 9:
		return "风属性";
		break;
	case 10:
		return "雷属性";
		break;
	case 11:
		return "土属性";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForConsumptionType(int index)
{
switch (index)
	{
	case 0:
		return "精消耗";
		break;
	case 1:
		return "气消耗";
		break;
	case 2:
		return "神消耗";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForBasicAction(int index)
{
switch (index)
	{
	case 0:
		return "进行普通攻击";
		break;
	case 1:
		return "使用特技";
		break;
	case 2:
		return "施放仙术";
		break;
	case 3:
		return "使用物品";
		break;
	case 4:
		return "使用魔剑技";
		break;
	case 5:
		return "防御";
		break;
	case 6:
		return "逃跑";
		break;
	case 7:
		return "重复上一次动作";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForCurrentState(int index)
{
switch (index)
	{
	case 0:
		return "精";
		break;
	case 1:
		return "气";
		break;
	case 2:
		return "神";
		break;
	case 3:
		return "金钱";
		break;
	case 4:
		return "序列进度";
		break;
	case 5:
		return "武灵";
		break;
	case 6:
		return "仙灵";
		break;
	case 7:
		return "剑气";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForTemporaryState(int index)
{
switch (index)
	{
	case 0:
		return "定";
		break;
	case 1:
		return "封";
		break;
	case 2:
		return "禁";
		break;
	case 3:
		return "眠";
		break;
	case 4:
		return "乱";
		break;
	case 5:
		return "狂";
		break;
	case 6:
		return "镜";
		break;
	case 7:
		return "壁";
		break;
	case 8:
		return "界";
		break;
	case 9:
		return "隐";
		break;
	case 10:
		return "避毒";
		break;
	case 11:
		return "神武";
		break;
	case 12:
		return "坚韧";
		break;
	case 13:
		return "疾速";
		break;
	case 14:
		return "吉运";
		break;
	case 15:
		return "脱力";
		break;
	case 16:
		return "虚弱";
		break;
	case 17:
		return "迟缓";
		break;
	case 18:
		return "诅咒";
		break;
	case 19:
		return "水毒";
		break;
	case 20:
		return "火毒";
		break;
	case 21:
		return "风毒";
		break;
	case 22:
		return "雷毒";
		break;
	case 23:
		return "土毒";
		break;
	}

	return "";
}

string StateDataManager::getDescriptionForCountableStateCountValueChangeTriggerType(CountableStateCountValueChangeTriggerType type, int countValue)
{
	// Generate the result with countValue
	stringstream ss;

	ss.str("");
    ss.clear();

	if (countValue <= 0) return "状态已失效";

switch (type)
	{
	case CountableStateCountValueChangeTriggerTypeNone:
		ss << "持续生效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingNormalAttackDamage:
		ss << "受到" << n2s(countValue) << "点普通攻击伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingSkillDamage:
		ss << "受到" << n2s(countValue) << "点技能伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingMagicDamage:
		ss << "受到" << n2s(countValue) << "点仙术伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingItemDamage:
		ss << "受到" << n2s(countValue) << "点物品伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingSwordSkillDamage:
		ss << "受到" << n2s(countValue) << "点魔剑技伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingCooperatedAttackDamage:
		ss << "受到" << n2s(countValue) << "点合击伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterReceiveingAllDamage:
		ss << "受到" << n2s(countValue) << "点伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingNormalAttackDamage:
		ss << "造成" << n2s(countValue) << "点普通攻击伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingSkillDamage:
		ss << "造成" << n2s(countValue) << "点技能伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingMagicDamage:
		ss << "造成" << n2s(countValue) << "点仙术伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingItemDamage:
		ss << "造成" << n2s(countValue) << "点物品伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingSwordSkillDamage:
		ss << "造成" << n2s(countValue) << "点魔剑技伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingCooperatedAttackDamage:
		ss << "造成" << n2s(countValue) << "点合击伤害后失效";
		break;
	case CountableStateCountValueChangeTriggerTypeAfterDealingAllDamage:
		ss << "造成" << n2s(countValue) << "点伤害后失效";
		break;
	}

	return ss.str();
}

// Debug
string StateDataManager::printData()
{
	string tempStr = "";
	int index = 0;
	/*for (index = 0; index < this->sustainableStateDataSize; ++index)
	{
		SustainableStateDataInstance *e = &(this->sustainableStateData[index]);
		tempStr += e->printData(this->ss);
	}
	for (index = 0; index < this->temporaryStateDataSize; ++index)
	{
		TemporaryStateDataInstance *e = &(this->temporaryStateData[index]);
		tempStr += e->printData(this->ss);
	}*/
	for (index = 0; index < this->countableStateDataSize; ++index)
	{
		CountableStateDataInstance *e = &(this->countableStateData[index]);
		tempStr += e->printData(this->ss);
	}
	for (index = 0; index < this->combatPropertyDataSize; ++index)
	{
		CombatPropertyDataInstance *e = &(this->combatPropertyData[index]);
		tempStr += e->printData(this->ss);
	}

	return tempStr;
}


