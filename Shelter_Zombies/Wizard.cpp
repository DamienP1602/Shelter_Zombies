#include "Wizard.h"

#define BUILDING_SHAPE_WIZARD_PATH "GPE/Building/Wizard.png"
#define BUILDING_SHAPE_WIZARD_SIZE Vector2f(200.f,200.f)

Wizard::Wizard(const Vector2f& _position):
	Building("Wizard", ShapeData(_position, BUILDING_SHAPE_WIZARD_SIZE, BUILDING_SHAPE_WIZARD_PATH))
{
	data = new BuildingData(30, 10, BonusType::Construction_SpeedBonus);
}
