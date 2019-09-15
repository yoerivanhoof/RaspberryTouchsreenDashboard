//
// Created by TheRiverVan on 12-Sep-19.
//

#ifndef RPI_TOUCH_BUTTON_H
#define RPI_TOUCH_BUTTON_H


#include "Texture.h"
#include "DisplayGridItem.h"

class Button: public DisplayGridItem {
private:
    Texture text;
    int x;
    int y;
    int w;
    int h;
    std::string textstring;
    SDL_Color textColor;
    SDL_Color backgroundColor;
    std::string command;
    SDL_Renderer* renderer;
    TTF_Font* gfont;
public:
    Button(SDL_Renderer &renderer, TTF_Font& font, std::string text, std::string command = "");
    Button(SDL_Renderer &renderer, TTF_Font& font, int x, int y, std::string text, std::string command = "");
    Button(SDL_Renderer &renderer, TTF_Font& font, int x, int y, int width, int height, std::string text, std::string command = "");
    ~Button();
    void render() override ;
    void render(int x, int y , int w ,int h) override;


    void free() override ;

    bool setText(std::string text,TTF_Font& font, SDL_Color color);

    void touchDown(SDL_Point point) override ;

    void touchUp(SDL_Point point) override ;
};


#endif //RPI_TOUCH_BUTTON_H
