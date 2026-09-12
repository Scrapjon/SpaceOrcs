#pragma once
#include <iostream>
#include <memory>
#include <raylib.h>

class AudioEngine {
private:
	AudioEngine ()
	{
		InitAudioDevice ();
	}

public:
	static AudioEngine &GetInstance ();

	AudioEngine (const AudioEngine &)			 = delete;
	AudioEngine &operator= (const AudioEngine &) = delete;
};