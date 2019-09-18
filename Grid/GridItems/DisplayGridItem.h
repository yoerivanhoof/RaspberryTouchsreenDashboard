//
// Created by TheRiverVan on 15-Sep-19.
//

#ifndef RPI_TOUCH_DISPLAYGRIDITEM_H
#define RPI_TOUCH_DISPLAYGRIDITEM_H


#include <SDL_rect.h>

class DisplayGridItem {
private:
    int gridWidth = 1;
    int gritHeight = 1;
    int row = 0;
    int colomn = 0;
protected:

public:
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



    virtual void render(int x, int y, int w, int h) = 0;

    virtual void free() = 0;

    virtual void touchDown(SDL_Point point) = 0;

    virtual void touchUp(SDL_Point point) = 0;
};


#endif //RPI_TOUCH_DISPLAYGRIDITEM_H
