#include "Camera.h"
#include "Macro.h"
#include "CameraManager.h"

Camera::Camera() : IManagable(GetUniqueID())
{
    Register();
    size = Vector2f();
	center = Vector2f();
    view = new View();
	view->setSize(size);
    UpdateView();
}

Camera::Camera(const Vector2f& _center, const Vector2f _size) : IManagable(GetUniqueID())
{
    Register();
    view = new View();
    center = _center;
    size = _size;

	view->setSize(size);
    UpdateView();
}

Camera::~Camera()
{
	delete view;
}

void Camera::Register()
{
    CameraManager::GetInstance().Add(id, this);
}