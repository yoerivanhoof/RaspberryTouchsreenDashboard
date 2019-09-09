//
// Created by TheRiverVan on 09-Sep-19.
//

#ifndef RPI_TOUCH_BUTTON_H
#define RPI_TOUCH_BUTTON_H


#include "Texture.h"

class Button {

public:
    Button();

    ~Button();

    Button(int x, int y, int width, int height, std::string text, SDL_Color backgroundColor, SDL_Renderer& renderer);

    void render();

private:
    Texture background;
    Texture text;

    int x;
    int y;
    int width;
    int height;
    SDL_Renderer* renderer;
};


#endif //RPI_TOUCH_BUTTON_H
