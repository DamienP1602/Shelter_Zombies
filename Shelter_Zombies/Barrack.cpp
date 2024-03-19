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
	Entity* _newEntity = nullptr;
	switch (_type)
	{
	case 0: //Fighter
		_newEntity = new Fighter(Vector2f(-2000, -2000));
	case 1: //Shooter
		_newEntity = new Shooter(Vector2f(-2000, -2000));
	case 2: //Support
		_newEntity = new Support(Vector2f(-2000, -2000));
	case 3: //Artillery
		_newEntity = new Artillery(Vector2f(-2000, -2000));
	}

	AllyEntityManager::GetInstance().Add(_newEntity->GetID(), _newEntity);
}
