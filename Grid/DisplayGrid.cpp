//
// Created by TheRiverVan on 15-Sep-19.
//

#include <vector>
#include <iostream>
#include "DisplayGrid.h"


void DisplayGrid::render() {

    for (auto &displayItem : displayItems) {
        int xpos = 0;
        int ypos = 0;
        if (displayItem->getColomn() == 0) {
            xpos = displayItem->getColomn() * 800 / this->coloms;
        } else {
            xpos = displayItem->getColomn() * 800 / this->coloms +
                   (this->coloms * this->space / this->coloms - 3) * displayItem->getColomn();
        }

        if (displayItem->getRow() == 0) {
            ypos = displayItem->getRow() * 480 / this->rows;
        } else {
            ypos = displayItem->getRow() * 480 / this->rows +
                   (this->rows * this->space / this->rows - 3) * displayItem->getRow();
        }

        int xwidth = 0;
        if (displayItem->getGridWidth() == 1) {
            xwidth = 800 / this->coloms - this->space;
        } else if (displayItem->getGridWidth() + displayItem->getColomn() == this->coloms) {
            xwidth = (800 / this->coloms) * displayItem->getGridWidth();
        } else {
            xwidth = (800 / this->coloms) * displayItem->getGridWidth() - (this->coloms * this->space / this->coloms-1);
        }

        int yheight = 0;
        if (displayItem->getGridHeight() == 1) {
            yheight = 480 / this->rows - this->space;
        } else if (displayItem->getGridHeight() + displayItem->getRow() == this->rows) {
            yheight = (480 / this->rows) * displayItem->getGridHeight();
        } else {
            yheight = (480 / this->rows) * displayItem->getGridHeight() - this->space;
        }

        displayItem->render(xpos, ypos, xwidth, yheight);
    }
}

void DisplayGrid::addItem(DisplayGridItem &button) {

    displayItems.push_back(&button);

}

void DisplayGrid::touchDown(SDL_Point point) {
    for (std::vector<Button *>::size_type i = 0; i != displayItems.size(); i++) {
        displayItems[i]->touchDown(point);

    }

}

void DisplayGrid::touchUp(SDL_Point point) {
    for (std::vector<DisplayGridItem *>::size_type i = 0; i != displayItems.size(); i++) {
        displayItems[i]->touchUp(point);
    }
}

void DisplayGrid::free() {
    for (std::vector<DisplayGridItem *>::size_type i = 0; i != displayItems.size(); i++) {
        displayItems[i]->free();
    }
}

DisplayGrid::DisplayGrid(int coloms, int rows) : coloms(coloms), rows(rows) {

}

