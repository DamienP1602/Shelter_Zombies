#include "Barrack.h"
#include "Fighter.h"
#include "Shooter.h"
#include "Support.h"
#include "Artillery.h"
#include "AllyEntityManager.h"
#include "IManager.h"

#define BUILDING_SHAPE_BARRACK_PATH "GPE/Building/Barrack.png"
#define BUILDING_SHAPE_BARRACK_SIZE Vector2f(500,500)

Barrack::Barrack(const Vector2f& _position) :
	Building("Barrack", ShapeData(_position, BUILDING_SHAPE_BARRACK_SIZE, BUILDING_SHAPE_BARRACK_PATH))
{
	data = new BuildingData(30, 5, BonusType::None);
}

void Barrack::CreateEntity(int _type)
{
	//temp switch-case
	switch (_type)
	{
	case 0: //Fighter
		//Cost 1
		if (AllyEntityManager::GetInstance().AddFighter(new Fighter(Vector2f(-2000, -2000))))
			break;
		break;
	case 1: //Shooter
		//Cost 3
		if (AllyEntityManager::GetInstance().AddShooter(new Shooter(Vector2f(-2000, -2000))))
			break;
		break;
	case 2: //Support
		//Cost 5
		if (AllyEntityManager::GetInstance().AddSupport(new Support(Vector2f(-2000, -2000))))
			break;
		break;
	case 3: //Artillery
		//Cost 10
		if (AllyEntityManager::GetInstance().AddArtillery(new Artillery(Vector2f(-2000, -2000))))
			break;
		break;
	}
}
