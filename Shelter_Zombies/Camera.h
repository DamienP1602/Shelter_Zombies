#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "IManagable.h"

using namespace std;
using namespace sf;

class Camera : public IManagable<int>
{
    Vector2f center;
    Vector2f size;
    View* view;

private:
    void UpdateView()
    {
        view->setCenter(center);	
    }

public:
    View* GetView()
    {
		return view;
    }
    void UpdateCenter(const Vector2f& _center)
    {
        center = _center;
        UpdateView();
    }
    void UpdateSize(const Vector2f& _size)
    {
        size = _size;
		view->setSize(size);
        UpdateView();
    }
    void SetZoom(const float _zoom)
    {
        view->zoom(_zoom);
    }

public:
    Camera();
    Camera(const Vector2f& _center, const Vector2f _size);
    ~Camera();
public:
    void Register();


};