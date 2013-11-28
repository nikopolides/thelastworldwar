#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#include "SDL/SDL_mixer.h"
#include "SDL/SDL.h"
#include <thread>

using namespace std;

class AudioHandler{
	
	public:
			
		Mix_Music *music = NULL;
   		Mix_Chunk *effect = NULL;

		AudioHandler();

		 int playMusic();
		 int playMusicGame();
		 int playMusicCreditos();
		 int playMusicOpcoes();
		 int playVoiceMenu();
		 int playEscolhaNacao();
		 int playEffect();
		 int playEffect_Enemy();

		 void initialize();	
		 void finalize();	

};


#endif 
