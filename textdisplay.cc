#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n) : gridSize{n} {
       for (int i = 0; i < this->gridSize; ++i) {
           vector<char> rowoG(n, '_');
           theDisplay.push_back(rowoG);
       } 
}

void TextDisplay::notify(Subject &whoNotified) {
       Info cur_inf = whoNotified.getInfo();
       if (cur_inf.state) {  // change the textdisplay
          theDisplay[cur_inf.row][cur_inf.col] = 'X';
       } else {
          theDisplay[cur_inf.row][cur_inf.col] = '_';
       }
}

TextDisplay::~TextDisplay() {
       for (int i = 0; i < gridSize; ++i) {
           theDisplay[i].clear();
       }
       theDisplay.clear();
}

SubscriptionType TextDisplay::subType() const {
       return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
       for (int i = 0; i < td.gridSize; ++i) {
           for (int j = 0; j < td.gridSize; ++j) {
               out << td.theDisplay[i][j];
           }
           out << endl;
       }
       return out;
}
