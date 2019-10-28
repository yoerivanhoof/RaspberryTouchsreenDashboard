//
// Created by TheRiverVan on 28-Oct-19.
//

#include <ctime>
#include "Clock.h"

void Clock::render(int rx, int ry, int rw, int rh) {
    DisplayGridTile::render(rx,ry,rw,rh);

    std::time_t result = std::time(nullptr);
    this->text.loadFromRenderedText(std::asctime(std::localtime(&result)),*gfont, this->textColor);

    int centerx = rx+rw/2-text.getWidth()/2;
    int centery = ry+rh/2-text.getHeight()/2;
    this->text.render(centerx,centery);
}

void Clock::free() {
    this->text.free();
}

void Clock::touchDown(SDL_Point point) {

}

void Clock::touchUp(SDL_Point point) {

}

Clock::Clock(SDL_Renderer &renderer, TTF_Font &font, std::string text, int row, int colomn, int width, int height,
               std::string command):command(std::move(command)),gfont(&font), DisplayGridTile(renderer, row, colomn, width, height) {

    this->text = Texture(renderer);
    this->textColor =SDL_Color({255,255,255});
}
