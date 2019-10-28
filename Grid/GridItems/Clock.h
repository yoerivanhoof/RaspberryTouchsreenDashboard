//
// Created by TheRiverVan on 28-Oct-19.
//

#ifndef RPI_TOUCH_CLOCK_H
#define RPI_TOUCH_CLOCK_H

#include "../../sdl/Texture.h"
#include "DisplayGridTile.h"

class Clock: public DisplayGridTile {

    ~Clock();

    void render(int x, int y, int w, int h) override;

    void free() override;

    void touchDown(SDL_Point point) override;

    void touchUp(SDL_Point point) override;

public:
    Clock(SDL_Renderer &renderer, TTF_Font &font, std::string text, int row, int colomn, int width = 1, int height = 1,
            std::string command = "");

private:
    Texture text;
    std::string textstring;
    SDL_Color textColor;
    std::string command;
    TTF_Font *gfont;
};


#endif //RPI_TOUCH_CLOCK_H
