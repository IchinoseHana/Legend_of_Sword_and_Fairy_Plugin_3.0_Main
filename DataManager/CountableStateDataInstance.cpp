#include "stdafx.h"
#include "CountableStateDataInstance.h"

CountableStateDataInstance::CountableStateDataInstance()
{
	countValue = 0;
	effectTriggeredWhenCountValueChanging = false;
	effectNotTriggeredByCustomTrigger = false;
    countValueChangeTriggerType = CountableStateCountValueChangeTriggerTypeNone;
}

CountableStateDataInstance::~CountableStateDataInstance()
{

}

int CountableStateDataInstance::transformCountableStateCountValueChangeTriggerTypeToNumber(CountableStateCountValueChangeTriggerType type)
{
	return static_cast<int>(type);
}
CountableStateCountValueChangeTriggerType CountableStateDataInstance::transformNumberToCountableStateCountValueChangeTriggerType(int number)
{
	return static_cast<CountableStateCountValueChangeTriggerType>(number);
}

string CountableStateDataInstance::printData(stringstream ss)
{
	// Get the result from the super class
	string tempStr = SustainableStateDataInstance::printData(ss);

	ss.str("");
    ss.clear();

	ss << "-----CountableStateDataInstance Print Begin-----\n";

	// Information from the super class
	ss << "-----Information From Class SustainableStateDataInstance: Print Begin-----\n";
	ss << tempStr;
	ss << "-----Information From Class SustainableStateDataInstance: Print End-----\n";

	ss << "-----Information From Class CountableStateDataInstance: Print Begin-----\n";
    ss << "countValue: " << n2s(countValue) << "\n";
	ss << "effectTriggeredWhenCountValueChanging: " << n2s(effectTriggeredWhenCountValueChanging) << "\n";
	ss << "effectNotTriggeredByCustomTrigger: " << n2s(effectNotTriggeredByCustomTrigger) << "\n";
	ss << "countValueChangeTriggerType: " << n2s(countValueChangeTriggerType) << "\n";
	ss << "-----Information From Class CountableStateDataInstance: Print End-----\n";

	ss << "-----CountableStateDataInstance Print End-----\n";

	return ss.str();
}