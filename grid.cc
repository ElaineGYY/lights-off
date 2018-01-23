#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(Xwindow &w) :gridSize{0}, td{nullptr}, gd{new GraphicsDisplay{w}} {
}

Grid::~Grid() {
       clearGrid();
       delete gd;
}

void Grid::clearGrid() {
       for (int i = 0; i < gridSize; ++i) {  // clear each vector<Cell>.
           theGrid[i].clear();
       }
       theGrid.clear(); // clear theGrid.
       delete td;
       gd->clearG();
       this->gridSize = 0;
}

bool Grid::isWon() const {
       for (int i = 0; i < gridSize; ++i) {
           for (int j = 0; j < gridSize; ++j) {
               if (theGrid[i][j].getState()) { // current cell is ON.
                  return false;
               }
           }
       }
       return true;
}

void Grid::init(int n) {
       clearGrid();
       this->gridSize = n;
       for (int i = 0; i < gridSize; ++i) { // initializing theGrid.
           vector<Cell> rowoG(n, Cell());
           for (int j = 0; j < gridSize; ++j) {
               rowoG[j].setCoords(i, j);
           }
           theGrid.push_back(rowoG); 
       }
       td = new TextDisplay{n};  // new TextDisplay.
       gd->createG(n); // create new GraphicsDisplay.
       for (int k = 0; k < gridSize; ++k) {  // adding attachments.
           for (int h = 0; h < gridSize; ++h) {
               if (k >= 1) {    // attach neighbour cells.
                  theGrid[k][h].attach(&theGrid[k - 1][h]);
               }
               if (k < (gridSize - 1)) {
                  theGrid[k][h].attach(&theGrid[k + 1][h]);
               }
               if (h >= 1) {
                  theGrid[k][h].attach(&theGrid[k][h - 1]);
               }
               if (h < (gridSize - 1)) {
                  theGrid[k][h].attach(&theGrid[k][h + 1]);
               }
               theGrid[k][h].attach(td);
               theGrid[k][h].attach(gd);
               theGrid[k][h].attach(&theGrid[k][h]); // attach self.
           }
       } 
}

void Grid::turnOn(int r, int c) {
       theGrid.at(r).at(c).setOn();
}

void Grid::toggle(int r, int c) {
       theGrid.at(r).at(c).toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
       out << *(g.td);
       return out;
}
