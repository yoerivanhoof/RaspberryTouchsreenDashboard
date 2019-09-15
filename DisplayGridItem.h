//
// Created by TheRiverVan on 15-Sep-19.
//

#ifndef RPI_TOUCH_DISPLAYGRIDITEM_H
#define RPI_TOUCH_DISPLAYGRIDITEM_H


#include <SDL_rect.h>

class DisplayGridItem {
protected:
    int gridWidth = 1;
    int gritHeight = 1;
public:
    virtual void render() = 0;

    void setGridWidth(int width);
    void setGridHeight(int height);

    int getGridWidth();
    int getGridHeight();

    virtual void render(int x, int y, int w, int h) = 0;

    virtual void free() = 0;

    virtual void touchDown(SDL_Point point) = 0;

    virtual void touchUp(SDL_Point point) = 0;
};


#endif //RPI_TOUCH_DISPLAYGRIDITEM_H
