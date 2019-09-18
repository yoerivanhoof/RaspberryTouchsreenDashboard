//
// Created by TheRiverVan on 15-Sep-19.
//

#ifndef RPI_TOUCH_DISPLAYGRID_H
#define RPI_TOUCH_DISPLAYGRID_H


#include <vector>
#include "GridItems/Button.h"

class DisplayGrid {


public:
    ~DisplayGrid() = default;
    DisplayGrid(int coloms =3, int rows = 4);



    void addItem(DisplayGridItem& button);
    void render();

    void touchDown(SDL_Point point);

    void touchUp(SDL_Point point);

    void free();

private:
    int coloms ;
    int rows ;
    int space = 5;
    std::vector<DisplayGridItem*> displayItems;
};


#endif //RPI_TOUCH_DISPLAYGRID_H
