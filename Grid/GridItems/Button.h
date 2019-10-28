//
// Created by TheRiverVan on 12-Sep-19.
//

#ifndef RPI_TOUCH_BUTTON_H
#define RPI_TOUCH_BUTTON_H


#include "../../sdl/Texture.h"
#include "DisplayGridTile.h"

class Button : public DisplayGridTile {
private:
    Texture text;
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    std::string textstring;
    SDL_Color textColor;
    std::string command;
    SDL_Renderer *renderer;
    TTF_Font *gfont;
public:
    Button(SDL_Renderer &renderer, TTF_Font &font, std::string text, int row, int colomn, int width = 1, int height = 1,
           std::string command = "");

    ~Button();

    void render(int x, int y, int w, int h) override;

    void free() override;

    bool setText(std::string text, TTF_Font &font, SDL_Color color);

    void touchDown(SDL_Point point) override;

    void touchUp(SDL_Point point) override;
};


#endif //RPI_TOUCH_BUTTON_H
