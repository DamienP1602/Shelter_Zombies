#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Camera.h"


class CameraManager : public Singleton<CameraManager>, public IManager<int, Camera>
{

};