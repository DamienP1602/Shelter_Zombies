#include "PlayerSoundData.h"

PlayerSoundData::PlayerSoundData()
{
	playerSounds = {};
}

PlayerSoundData::~PlayerSoundData()
{
	for (size_t i = 0; i < playerSounds.size(); i++)
		playerSounds[i] = nullptr;
	playerSounds.clear();
}
