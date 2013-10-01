
SDL_Surface *load_image( std::string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        //optimizedImage = SDL_DisplayFormat( loadedImage );
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

	//If the image was optimized just fine 
	if( optimizedImage != NULL ) 
	{ 
		//Map the color key 
		//Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0, 0 );
	
		//Set all pixels of color R 0, G 0, B 0 to be transparent 
		//SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey ); 
	}

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

string intToString(int x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}


