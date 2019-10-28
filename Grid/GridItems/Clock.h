//
// Created by TheRiverVan on 28-Oct-19.
//

#ifndef RPI_TOUCH_CLOCK_H
#define RPI_TOUCH_CLOCK_H


#include "DisplayGridItem.h"
#include "../../sdl/Texture.h"

class Clock: public DisplayGridItem {

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
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    std::string textstring;
    SDL_Color textColor;
    SDL_Color backgroundColor;
    std::string command;
    SDL_Renderer *renderer;
    TTF_Font *gfont;
};


#endif //RPI_TOUCH_CLOCK_H
