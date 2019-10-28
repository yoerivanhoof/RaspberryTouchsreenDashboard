//
// Created by TheRiverVan on 28-Oct-19.
//

#include <ctime>
#include "Clock.h"
#include "../DisplayGridItemType.h"

void Clock::render(int rx, int ry, int rw, int rh) {

    this->x = rx;
    this->y = ry;
    this->w = rw;
    this->h = rh;

    auto* rect = new SDL_Rect;
    rect->x=rx;
    rect->y=ry;
    rect->w=rw;
    rect->h=rh;

    std::time_t result = std::time(nullptr);
    this->text.loadFromRenderedText(std::asctime(std::localtime(&result)),*gfont, this->textColor);

    SDL_SetRenderDrawColor(this->renderer,this->backgroundColor.r,this->backgroundColor.g,this->backgroundColor.b,this->backgroundColor.a);
    SDL_RenderFillRect(this->renderer,rect);

    int centerx = rx+rw/2-text.getWidth()/2;
    int centery = ry+rh/2-text.getHeight()/2;
    this->text.render(centerx,centery);
}

void Clock::free() {

}

void Clock::touchDown(SDL_Point point) {

}

void Clock::touchUp(SDL_Point point) {

}

Clock::Clock(SDL_Renderer &renderer, TTF_Font &font, std::string text, int row, int colomn, int width, int height,
               std::string command):renderer(&renderer),command(std::move(command)),gfont(&font) {

    this->setRow(row);
    this->setColomn(colomn);
    this->setGridWidth(width);
    this->setGridHeight(height);

    this->text = Texture(renderer);
    this->backgroundColor = SDL_Color({100,100,100});
    this->textColor =SDL_Color({255,255,255});
}
