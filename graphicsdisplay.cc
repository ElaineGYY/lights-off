#include <iostream>
#include <utility>
#include "graphicsdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(Xwindow &w) :w{w} {
}

void GraphicsDisplay::createG(int n) {
       this->gridSize = n;
       this->sqSize = total / n;
       for (int i = 0; i < gridSize; ++i) {
           for (int j = 0; j < gridSize; ++j) {
               w.fillRectangle(sqSize * i, sqSize * j, sqSize, sqSize, Xwindow::Black);
           }
       }
}

void GraphicsDisplay::clearG() {
       w.fillRectangle(0, 0, total, total, Xwindow::White);
}

void GraphicsDisplay::notify(Subject &whoNotified) {
       Info tem = whoNotified.getInfo();
       if (tem.state) {
          w.fillRectangle(sqSize * tem.col, sqSize * tem.row, sqSize, sqSize, Xwindow::White);
       } else {
          w.fillRectangle(sqSize * tem.col, sqSize * tem.row, sqSize, sqSize, Xwindow::Black);
       }
}

SubscriptionType GraphicsDisplay::subType() const {
       return SubscriptionType::All;
}

GraphicsDisplay::~GraphicsDisplay() {
}

