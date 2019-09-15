/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and, strings

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include "Texture.h"
#include "Button.h"
#include "DisplayGrid.h"


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The window renderer
SDL_Renderer *gRenderer = NULL;

//Screen dimensions
SDL_Rect gScreenRect = {0, 0, 800, 480};

TTF_Font *gFont;

//Scene textures
DisplayGrid displayGrid = DisplayGrid(3, 3);

bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        SDL_ShowCursor(SDL_DISABLE);
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            SDL_Log("Warning: Linear texture filtering not enabled!");
        }

        //Get device display mode
        SDL_DisplayMode displayMode;
        if (SDL_GetCurrentDisplayMode(0, &displayMode) == 0) {
            gScreenRect.w = displayMode.w;
            gScreenRect.h = displayMode.h;
        }

        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 480,
                                   SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL) {
                SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {

                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    SDL_Log("SDL_image could not initialize! %s\n", IMG_GetError());
                    success = false;
                }
                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }


            }
        }
    }

    return success;
}

bool loadMedia() {
    //Loading success flag
    bool success = true;

    gFont = TTF_OpenFont("lazy.ttf", 25);
    if (gFont == NULL) {
        SDL_Log("kan lazy nie lade");
    }

    auto* button = new Button(*gRenderer, *gFont, "Kick Fabian", "wget 0.0.0.0:3000/discord/kick/fabian");
    auto* button2 = new Button(*gRenderer, *gFont, "Kick Pascal", "wget 0.0.0.0:3000/discord/kick/pascal");
    button->setGridHeight(2);
    button2->setGridWidth(2);
    displayGrid.addItem(*button);
    displayGrid.addItem(*button2);

    displayGrid.addItem(*new Button(*gRenderer, *gFont, "Kick Pascal", "wget 0.0.0.0:3000/discord/kick/pascal"));


    displayGrid.addItem(*new Button(*gRenderer, *gFont, "Kick yoeri", "wget 0.0.0.0:3000/discord/kick/yoeri"));
    displayGrid.addItem(*new Button(*gRenderer, *gFont, "Kick Jeffrey", "wget 0.0.0.0:3000/discord/kick/jeffrey"));



    return success;
}

void close() {

    displayGrid.free();

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        SDL_Log("Failed to initialize!\n");
    } else {
        //Load media
        if (!loadMedia()) {
            SDL_Log("Failed to load media!\n");
        } else {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Touch variables
            SDL_Point touchLocation = {gScreenRect.w / 2, gScreenRect.h / 2};




            //While application is running
            while (!quit) {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0) {
                    //User requests quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                        //Window event
                    else if (e.type == SDL_WINDOWEVENT) {
                        //Window resize/orientation change
                        if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                            //Get screen dimensions
                            gScreenRect.w = e.window.data1;
                            gScreenRect.h = e.window.data2;

                            //Update screen
                            SDL_RenderPresent(gRenderer);
                        }
                    }
                        //Touch down
                    else if (e.type == SDL_FINGERDOWN) {

                        touchLocation.x = e.tfinger.x * gScreenRect.w;
                        touchLocation.y = e.tfinger.y * gScreenRect.h;
                        displayGrid.touchDown(touchLocation);

                    }
                        //Touch motion
                    else if (e.type == SDL_FINGERMOTION) {
                        touchLocation.x = e.tfinger.x * gScreenRect.w;
                        touchLocation.y = e.tfinger.y * gScreenRect.h;
                    }
                        //Touch release
                    else if (e.type == SDL_FINGERUP) {
                        touchLocation.x = e.tfinger.x * gScreenRect.w;
                        touchLocation.y = e.tfinger.y * gScreenRect.h;
                        displayGrid.touchUp(touchLocation);
                    }


                }


                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                displayGrid.render();

                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
