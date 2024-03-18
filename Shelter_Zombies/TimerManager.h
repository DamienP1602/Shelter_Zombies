#pragma once
#include <SFML/System.hpp>
#include <iostream>
#include "Singleton.h"
#include "IManager.h"
#include "Timer.h"

using namespace sf;
using namespace std;

class TimerManager : public Singleton<TimerManager>, public IManager<int, Timer>
{
	// Clock pour avoir acc�s � toutes les donn�es de temps
	Clock clock;

	float current;
	float max;
	float time; // Temps en seconde depuis le d�but du programme

	float lastTime; // Mettre � jour les timers

	float lastFrameTime; // Mettre � jour les compteurs de FPS

	float elapsedTime; // Temps en seconde depuis la derni�re image rendue

	float timeScale; // Vitesse � laquelle le temps s'�coule

	float deltaTime; // Temps en seconde depuis la derni�re image rendue avec le time scale

	unsigned int framesCount; // Nombre d'images qui ont �t� rendu depuis le d�but

	unsigned int maxFrameRate; // Maximum d'image � rendre par seconde

	float fps; // Nombre d'image rendu par seconde

	function<void()> renderCallback; // M�thode de rappel � �x�cuter si le rendu est � jour

	bool isPause;

private:
	void ComputeFPS()
	{
		fps = 1000.0f / (time - lastFrameTime);
	}
	bool Render()
	{
		if (lastFrameTime == 0 || time - lastFrameTime >= 1000.0f / maxFrameRate)
		{
			ComputeFPS();
			lastFrameTime = time;
			return true;
		}

		return false;
	}
public:
	void SetTimeScale(const float _timeScale)
	{
		timeScale = _timeScale;
	}
	void SetMaxFrameRate(const unsigned int _maxFrameRate)
	{
		maxFrameRate = _maxFrameRate;
	}
	void SetRenderCallback(const function<void()>& _callback)
	{
		renderCallback = _callback;
	}
	float GetDeltaTime() const
	{
		return deltaTime;
	}
	float GetFPS() const
	{
		return fps;
	}

	void SetPause(const bool _isPause)
	{
		isPause = _isPause;
	}

public:
	TimerManager();

private:
	void UpdateTimers();

public:
	void Update();

	void Pause(const float _duration);
};