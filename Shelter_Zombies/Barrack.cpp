#include "Barrack.h"
#include "Knight.h"
#include "Archer.h"
#include "Church.h"
#include "Catapult.h"
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
		if (AllyEntityManager::GetInstance().AddKnight(new Knight(Vector2f(0, 0), 0)))
			break;
		break;
	case 1: //Shooter
		//Cost 3
		if (AllyEntityManager::GetInstance().AddArcher(new Archer(Vector2f(0, 0), 0)))
			break;
		break;
	case 2: //Support
		//Cost 5
		if (AllyEntityManager::GetInstance().AddChurch(new Church(Vector2f(0, 0), 0)))
			break;
		break;
	case 3: //Artillery
		//Cost 10
		if (AllyEntityManager::GetInstance().AddCatapult(new Catapult(Vector2f(0, 0), 0)))
			break;
		break;
	}
}
