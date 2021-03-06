#include "AudioHandler.h" 



AudioHandler::AudioHandler(){

}

int AudioHandler::playMusic(){
	
	music = Mix_LoadMUS( "soundtrack/musicaMenu.ogg" );
	
	return Mix_PlayMusic(music, -1);
	 
}

int AudioHandler::playMusicGame(){
	
	Mix_HaltMusic();
	
	music = Mix_LoadMUS( "soundtrack/musicaJogo.ogg" );
	
	 Mix_VolumeMusic(5);	
		 	
	return Mix_PlayMusic(music, -1);
}

int AudioHandler:: playVoiceMenu(){
	
	effect = Mix_LoadWAV( "soundtrack/thelastworldwar.ogg" );
	Mix_VolumeChunk(effect,MIX_MAX_VOLUME); 
	return Mix_PlayChannel( 2,effect, 0 );

}

int AudioHandler:: playEscolhaNacao(){
	
	effect = Mix_LoadWAV( "soundtrack/escolha_nacao.ogg" );
	
	return Mix_PlayChannel( 2,effect, 0 );

}

int AudioHandler:: playEffect(){
	
	effect = Mix_LoadWAV( "sound_effects/effect_selecionar.ogg" );
	
	Mix_VolumeChunk(effect,MIX_MAX_VOLUME);
	return Mix_PlayChannel( 2,effect, 0 );

}

int AudioHandler::playEffect_Enemy(){
	
	effect = Mix_LoadWAV( "sound_effects/ataque.ogg" );
	
	Mix_VolumeChunk(effect,MIX_MAX_VOLUME);

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

