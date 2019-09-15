//
// Created by TheRiverVan on 09-Sep-19.
//

#ifndef RPI_TOUCH_TEXTURE_H
#define RPI_TOUCH_TEXTURE_H


#include <SDL_render.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
class Texture {
public:
    //Initializes variables
    Texture(SDL_Renderer& sdlRenderer);
    Texture();

    //Deallocates memory
    ~Texture();

    //Loads image at specified path
    bool loadFromFile( std::string path );


    bool loadFromRenderedText( std::string textureText,TTF_Font& font, SDL_Color textColor );


    //Creates blank texture
    bool createBlank( int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING );

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Set self as render target
    void setAsRenderTarget();

    //Gets image dimensions
    int getWidth();
    int getHeight();

    //Pixel manipulators
    bool lockTexture();
    bool unlockTexture();
    void* getPixels();
    void copyPixels( void* pixels );
    int getPitch();
    Uint32 getPixel32( unsigned int x, unsigned int y );

private:
    SDL_Surface* textSurface;
    SDL_Renderer* gRenderer;
    //The actual hardware texture
    SDL_Texture* mTexture;
    void* mPixels;
    int mPitch;

    //Image dimensions
    int mWidth;
    int mHeight;
    TTF_Font *gFont = NULL;
    bool loadFromFile(std::string path, SDL_Renderer &gRenderer);
};


#endif //RPI_TOUCH_TEXTURE_H
