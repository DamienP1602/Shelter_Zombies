#include "Barrack.h"
#include "Fighter.h"
#include "Shooter.h"
#include "Support.h"
#include "Artillery.h"
#include "AllyEntityManager.h"
#include "IManager.h"

#define BUILDING_SHAPE_BARRACK_PATH ""
#define BUILDING_SHAPE_BARRACK_SIZE Vector2f()

Barrack::Barrack(const Vector2f& _position) :
	Building("Barrack", ShapeData(_position, BUILDING_SHAPE_BARRACK_SIZE, BUILDING_SHAPE_BARRACK_PATH))
{
	data = new BuildingData(30, BonusType::None);
}

void Barrack::CreateEntity(int _type)
{
	//temp switch-case
	switch (_type)
	{
	case 0: //Fighter
		if (AllyEntityManager::GetInstance().AddFighter(new Fighter(Vector2f(-2000, -2000))))
			break;
		break;
	case 1: //Shooter
		if (AllyEntityManager::GetInstance().AddShooter(new Shooter(Vector2f(-2000, -2000))))
			break;
		break;
	case 2: //Support
		if (AllyEntityManager::GetInstance().AddSupport(new Support(Vector2f(-2000, -2000))))
			break;
		break;
	case 3: //Artillery
		if (AllyEntityManager::GetInstance().AddArtillery(new Artillery(Vector2f(-2000, -2000))))
			break;
		break;
	}
}
