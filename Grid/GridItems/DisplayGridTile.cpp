//
// Created by TheRiverVan on 28-Oct-19.
//

#include "DisplayGridTile.h"

void DisplayGridTile::render(int rx, int ry, int rw, int rh) {
    auto* rect = new SDL_Rect;
    rect->x=rx;
    rect->y=ry;
    rect->w=rw;
    rect->h=rh;


    SDL_SetRenderDrawColor(this->renderer,this->backgroundColor.r,this->backgroundColor.g,this->backgroundColor.b,this->backgroundColor.a);
    SDL_RenderFillRect(this->renderer,rect);
}

DisplayGridTile::DisplayGridTile(SDL_Renderer &renderer, int row, int colomn, int width, int height ) {
    this->setRow(row);
    this->setColomn(colomn);
    this->setGridWidth(width);
    this->setGridHeight(height);

    this->backgroundColor = SDL_Color({100,100,100});
    this->renderer = &renderer;


}

DisplayGridTile::~DisplayGridTile() {


}
