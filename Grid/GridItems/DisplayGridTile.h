//
// Created by TheRiverVan on 28-Oct-19.
//

#ifndef RPI_TOUCH_DISPLAYGRIDTILE_H
#define RPI_TOUCH_DISPLAYGRIDTILE_H


#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_ttf.h>

class DisplayGridTile {
protected:
    int gridWidth = 1;
    int gritHeight = 1;
    int row = 0;
    int colomn = 0;
    SDL_Color backgroundColor;
    SDL_Renderer *renderer;
public:
    DisplayGridTile(SDL_Renderer &renderer, int row, int colomn, int width, int height );
    ~DisplayGridTile();

    void setGridWidth(int newWidth){
        this->gridWidth=newWidth;
    };
    void setGridHeight(int newHeight){
        this->gritHeight=newHeight;
    };

    int getGridWidth(){
        return gridWidth;
    };
    int getGridHeight(){
        return gritHeight;
    };

    void setRow(int newRow){
        this->row=newRow;
    };
    void setColomn(int newColomn){
        this->colomn=newColomn;
    };

    int getRow(){
        return row;
    };
    int getColomn(){
        return colomn;
    };



    virtual void render(int x, int y, int w, int h);

    virtual void free() = 0;

    virtual void touchDown(SDL_Point point) = 0;

    virtual void touchUp(SDL_Point point) = 0;


};


#endif //RPI_TOUCH_DISPLAYGRIDTILE_H
