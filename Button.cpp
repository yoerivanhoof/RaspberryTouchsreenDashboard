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


Button::Button(SDL_Renderer &renderer, TTF_Font& font, int x, int y, int width, int height, std::string text,std::string command): Button(renderer, font,x,y,std::move(text),command) {
    this->w=width;
    this->h=height;
}

void Button::render() {
    int centerx = this->x+this->w/2-text.getWidth()/2;
    int centery = this->y+this->h/2-text.getHeight()/2;
    this->text.render(centerx,centery);
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

Button::Button(SDL_Renderer &renderer, TTF_Font& font, int x, int y, std::string settext, std::string command):renderer(&renderer),x(x),y(y),command(std::move(command)),gfont(&font) {
    this->text = Texture(renderer);
    this->setText(settext,font,SDL_Color({255,255,255}));

    this->w=this->text.getWidth();
    this->h=this->text.getHeight();
    this->backgroundColor = SDL_Color({100,100,100});
}

Button::Button(SDL_Renderer &renderer, TTF_Font& font, std::string text, std::string command):Button(renderer,font,0,0,std::move(text),std::move(command)) {

}

