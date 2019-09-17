//
// Created by TheRiverVan on 12-Sep-19.
//

#include <iostream>
#include "Button.h"

Button::~Button() = default;

void Button::free() {
    this->text.free();
}

bool Button::setText(std::string text, TTF_Font& font, SDL_Color color) {
    this->textstring = text;
    this->textColor = color;
    this->text.loadFromRenderedText(this->textstring,font, this->textColor);
    return true;
}


void Button::touchDown(SDL_Point point) {
    if(point.x > x && point.x < x+this->w){
        if(point.y > y && point.y < y+this->h){
            this->text.loadFromRenderedText("click",*gfont,this->textColor);
        }
    }
}

void Button::touchUp(SDL_Point point) {
    setText(this->textstring,*gfont, this->textColor);
    if(point.x > x && point.x < x+this->w){
        if(point.y > y && point.y < y+this->h){
            system(this->command.c_str());
        }
    }
}

void Button::render(int rx, int ry, int rw, int rh) {
    this->x = rx;
    this->y = ry;
    this->w = rw;
    this->h = rh;

    auto* rect = new SDL_Rect;
    rect->x=rx;
    rect->y=ry;
    rect->w=rw;
    rect->h=rh;

    SDL_SetRenderDrawColor(this->renderer,this->backgroundColor.r,this->backgroundColor.g,this->backgroundColor.b,this->backgroundColor.a);
    SDL_RenderFillRect(this->renderer,rect);

    int centerx = rx+rw/2-text.getWidth()/2;
    int centery = ry+rh/2-text.getHeight()/2;
    this->text.render(centerx,centery);
}

Button::Button(SDL_Renderer &renderer, TTF_Font &font, std::string text, int row, int colomn, int width, int height,
               std::string command):renderer(&renderer),command(std::move(command)),gfont(&font) {

    this->setRow(row);
    this->setColomn(colomn);
    this->setGridWidth(width);
    this->setGridHeight(height);

    this->text = Texture(renderer);
    this->setText(std::move(text),font,SDL_Color({255,255,255}));
    this->backgroundColor = SDL_Color({100,100,100});
    this->textColor =SDL_Color({255,255,255});
}
