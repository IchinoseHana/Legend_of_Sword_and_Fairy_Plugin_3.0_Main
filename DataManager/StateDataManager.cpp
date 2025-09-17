#include "stdafx.h"
#include "StateDataManager.h"

StateDataManager::StateDataManager()
{
	
}

StateDataManager::~StateDataManager()
{

}

StateDataManager& StateDataManager::sharedInstance()
{
	static StateDataManager instance;
	return instance;
}


