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
	// Clock pour avoir accès à toutes les données de temps
	Clock clock;

	float current;
	float max;
	float time; // Temps en seconde depuis le début du programme

	float lastTime; // Mettre à jour les timers

	float lastFrameTime; // Mettre à jour les compteurs de FPS

	float elapsedTime; // Temps en seconde depuis la dernière image rendue

	float timeScale; // Vitesse à laquelle le temps s'écoule

	float deltaTime; // Temps en seconde depuis la dernière image rendue avec le time scale

	unsigned int framesCount; // Nombre d'images qui ont été rendu depuis le début

	unsigned int maxFrameRate; // Maximum d'image à rendre par seconde

	float fps; // Nombre d'image rendu par seconde

	function<void()> renderCallback; // Méthode de rappel à éxécuter si le rendu est à jour

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