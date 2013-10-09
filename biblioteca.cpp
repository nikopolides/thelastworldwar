SDL_Surface *load_image( std::string filename) 
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

int apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;


    //Colagem da SDL_Surface na screen
   // SDL_BlitSurface( source, clip, destination, &offset );

    //Blit
    return SDL_BlitSurface( source, clip, destination, &offset );
}

string intToString(int x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}

//for drawing

Uint32 getpixel(SDL_Surface *surface, int x, int y)
   {
       int bpp = surface->format->BytesPerPixel;
       /* Here p is the address to the pixel we want to retrieve */
       Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
   
       switch (bpp) {
       case 1:
           return *p;
   
       case 2:
           return *(Uint16 *)p;
   
       case 3:
           if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
               return p[0] << 16 | p[1] << 8 | p[2];
           else
               return p[0] | p[1] << 8 | p[2] << 16;
   
       case 4:
           return *(Uint32 *)p;
 
     default:
         return 0;       /* shouldn't happen, but avoids warnings */
     } // switch
 }



   void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
    {
        int bpp = surface->format->BytesPerPixel;
       /* Here p is the address to the pixel we want to set */
       Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
   
       switch (bpp) {
       case 1:
           *p = pixel;
           break;
   
       case 2:
           *(Uint16 *)p = pixel;
           break;
   
       case 3:
           if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
               p[0] = (pixel >> 16) & 0xff;
               p[1] = (pixel >> 8) & 0xff;
               p[2] = pixel & 0xff;
           }
           else {
               p[0] = pixel & 0xff;
             p[1] = (pixel >> 8) & 0xff;
              p[2] = (pixel >> 16) & 0xff;
          }
          break;
  
      case 4:
          *(Uint32 *)p = pixel;
          break;
  
     default:
          break;           /* shouldn't happen, but avoids warnings */
      } // switch
  }

void drawLine(SDL_Surface *surface, float x1, float y1, float x2, float y2, Uint32 pixel )
{
    // Bresenham's line algorithm
    const bool steep = (abs(y2 - y1) > abs(x2 - x1));
    if(steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if(x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const float dx = x2 - x1;
    const float dy = abs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;

    const int maxX = (int)x2;

    for(int x=(int)x1; x<maxX; x++)
    {
        if(steep)
        {
            putpixel(surface, y, x, pixel);
        }
        else
        {
            putpixel(surface, x, y, pixel);
        }

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}

void drawRect(SDL_Surface *surface, float x, float y, float width, float height, Uint32 pixel )
{
	drawLine(surface, x, y, x + width, y, pixel);
	drawLine(surface, x, y, x, y + height, pixel);
	drawLine(surface, x + width, y + height, x + width, y, pixel);
	drawLine(surface, x + width, y + height, x, y + height, pixel);
}

void drawCircle(SDL_Surface *surface, int n_cx, int n_cy, int radius, Uint32 pixel, bool in_Center = false)
{
    // if the first pixel in the screen is represented by (0,0) (which is in sdl)
    // remember that the beginning of the circle is not in the middle of the pixel
    // but to the left-top from it:
 
	if(!in_Center)
	{
		n_cx += radius;
		n_cy += radius;
	}

    double error = (double)-radius;
    double x = (double)radius -0.5;
    double y = (double)0.5;
    double cx = n_cx - 0.5;
    double cy = n_cy - 0.5;
 
    while (x >= y)
    {
        putpixel(surface, (int)(cx + x), (int)(cy + y), pixel);
        putpixel(surface, (int)(cx + y), (int)(cy + x), pixel);
 
        if (x != 0)
        {
            putpixel(surface, (int)(cx - x), (int)(cy + y), pixel);
            putpixel(surface, (int)(cx + y), (int)(cy - x), pixel);
        }
 
        if (y != 0)
        {
            putpixel(surface, (int)(cx + x), (int)(cy - y), pixel);
            putpixel(surface, (int)(cx - y), (int)(cy + x), pixel);
        }
 
        if (x != 0 && y != 0)
        {
            putpixel(surface, (int)(cx - x), (int)(cy - y), pixel);
            putpixel(surface, (int)(cx - y), (int)(cy - x), pixel);
        }
 
        error += y;
        ++y;
        error += y;
 
        if (error >= 0)
        {
            --x;
            error -= x;
            error -= x;
        }
    }
}


