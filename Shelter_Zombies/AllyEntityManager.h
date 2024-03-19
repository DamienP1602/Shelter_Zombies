#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

class Fighter;
class Shooter;
class Support;
class Artillery;

using namespace std;

class AllyEntityManager : public Singleton<AllyEntityManager>, public IManager<string, Entity>
{
private:

public:
	void AddFighter(Fighter _fighter);
	void AddShooter(Shooter _shooter);
	void AddSupport(Support _support);
	void AddArtillery(Artillery _artillery);
	void SpawnEntities();
};