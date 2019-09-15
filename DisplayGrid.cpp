//
// Created by TheRiverVan on 15-Sep-19.
//

#include <vector>
#include <iostream>
#include "DisplayGrid.h"


void DisplayGrid::render() {
    std::vector<std::vector<int>> matrix;
    matrix.resize(this->rows, std::vector<int>(this->coloms, 0));
    for (int row = 0; row < this->rows; row++) {
        for (int colomn = 0; colomn < this->coloms; colomn++) {
            int tempcolom = colomn;
            int temprow = row;
            while (matrix[temprow][tempcolom] != 0) {
                tempcolom++;
                if (tempcolom >= this->coloms) {
                    tempcolom = 0;
                    temprow++;
                }
            }

                if (row * this->coloms + colomn < displayItems.size()) {
                int xpos = 0;
                int ypos = 0;
                if (colomn == 0) {
                    xpos = tempcolom * 800 / this->coloms;
                } else {
                    xpos = tempcolom * 800 / this->coloms + (this->coloms * this->space / this->coloms - 3) * tempcolom;
                }

                if (row == 0) {
                    ypos = temprow * 480 / this->rows;
                } else {
                    ypos = temprow * 480 / this->rows + (this->rows * this->space / this->rows - 3) * temprow;
                }

                int xwidth = 0;
                if (displayItems[row * this->coloms + colomn]->getGridWidth() == 1) {
                    xwidth = 800 / this->coloms - this->space;
                } else {
                    xwidth = (800 / this->coloms) * displayItems[row * this->coloms + colomn]->getGridWidth() -
                             this->space;
                }

                int yheight = 0;
                if (displayItems[row * this->coloms + colomn]->getGridHeight() == 1) {
                    yheight = 480 / this->rows - this->space;
                } else {
                    yheight = (480 / this->rows) * displayItems[row * this->coloms + colomn]->getGridHeight() -
                              this->space;
                }

                displayItems[row * this->coloms + colomn]->render(
                        xpos,
                        ypos,
                        xwidth,
                        yheight);

                for (int srow = 0; srow < displayItems[row * this->coloms + colomn]->getGridHeight(); srow++) {
                    for (int scol = 0; scol < displayItems[row * this->coloms + colomn]->getGridWidth(); scol++) {
                        matrix[temprow + srow][tempcolom + scol] = 1;
                    }
                }

            }

        }

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

