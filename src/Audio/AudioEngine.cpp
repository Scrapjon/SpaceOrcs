#include "AudioEngine.h"

AudioEngine &AudioEngine::GetInstance ()
{
	static AudioEngine instance;
	return instance;
}