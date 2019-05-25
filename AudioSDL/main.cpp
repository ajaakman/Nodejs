#include <SDL.h>

double dTime = 0.0;

void MyAudioCallback(void* userdata, Uint8* stream, int streamLength)
{	
	for (Uint32 i = 0; i < streamLength / 2; ++i)
	{		
		((Sint16*)stream)[i] = Sint16(sin(440.0 * 6.28318530 * dTime) * 32767.0);
		dTime += 1.0 / 41000.0;
	}		
}

int main()
{	
	SDL_Init(SDL_INIT_AUDIO);
			
	SDL_AudioSpec spec;
	SDL_AudioDeviceID device;

	spec.channels = 1;
	spec.freq = 44100;
	spec.format = AUDIO_S16SYS;
	spec.samples = 2048;
	spec.callback = MyAudioCallback;

	device = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);

	SDL_PauseAudioDevice(device, 0);
}