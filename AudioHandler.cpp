#include "AudioHandler.h" 



AudioHandler::AudioHandler(){

}

int AudioHandler::playMusic(){
	
	music = Mix_LoadMUS( "soundtrack/musica2.ogg" );
	
	return Mix_PlayMusic(music, -1);
	 
}

int AudioHandler::playMusicGame(){
	
	Mix_HaltMusic();
	
	music = Mix_LoadMUS( "soundtrack/musica3.ogg" );
	
	
	Mix_VolumeMusic(1);	
	//Mix_VolumeMusic(this->itens_values[this->select]);
		 	
	return Mix_PlayMusic(music, -1);
}

int AudioHandler:: playVoiceMenu(){
	
	effect = Mix_LoadWAV( "soundtrack/thelastworldwar.ogg" );
	
	return Mix_PlayChannel( 2,effect, 0 );

}

int AudioHandler:: playEffect(){
	
	effect = Mix_LoadWAV( "sound_effects/effect_selecionar.ogg" );
	
	
	Mix_VolumeMusic(128);

	return Mix_PlayChannel( 2,effect, 0 );

}

int AudioHandler::playEffect_Enemy(){
	
	effect = Mix_LoadWAV( "sound_effects/effect_selecionar_inimigo.ogg" );
	
	
	Mix_VolumeMusic(128);

	return Mix_PlayChannel( 2,effect, 0 );

}

void AudioHandler:: initialize(){

	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    
}

void AudioHandler:: finalize(){
	Mix_FreeMusic( music );
	//Mix_FreeMusic( effect );

	Mix_CloseAudio();
	
}

