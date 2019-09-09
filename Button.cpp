//
// Created by TheRiverVan on 09-Sep-19.
//

#include "Button.h"

#include <utility>
#include <iostream>


Button::~Button() {

}

void Button::render() {
    std::cout << "x " << x << "y " << y << "\n";
    background.render(x,y);
    text.render(x,y);
}

Button::Button(int x, int y, int width, int height, std::string text, SDL_Color backgroundColor,
               SDL_Renderer &renderer): x(x), y(y), width(width), height(height), renderer(&renderer) {
    this->text =  Texture(renderer);
    this->text.loadFromRenderedText(std::move(text), SDL_Color({0,0,0}));

    this->background = Texture(renderer);
    this->background.loadFromFile( "touch_down.png");
    //this->background.setColor(0,0,0);
}

Button::Button() {

}

