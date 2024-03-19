#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

using namespace std;

class EnemyEntityManager : public Singleton<EnemyEntityManager>, public IManager<string, Entity>
{

};
