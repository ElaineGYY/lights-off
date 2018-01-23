#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit|ios::badbit);
  string cmd;
  Xwindow w;
  Grid g{w};
  int moves = 0;

  try {
    while (true) {
          cin >> cmd;
          if (cmd == "new") {
             int n;
             if(cin >> n) {
               g.init(n);
             }
          } else if (cmd == "init") {
             int row;
             int col;
             while (true) {
                   cin >> row >> col;
                   if (row == -1 && col == -1) { // end command
                      break;
                   } 
                   g.turnOn(row, col); 
             }
             cout << g;
          } else if (cmd == "game") {
             cin >> moves;
             if (moves == 0) { // run out of moves, check for result
                cout << moves << " move left" << endl;
                if (g.isWon()) {
                   cout << "Won" << endl;
                   break;
                } else {
                   if (!g.isWon() && moves == 0) {
                      cout << "Lost" << endl;
                      break;
                   }
                }
                break;
             } else {
                if (moves == 1) {
                   cout << moves << " move left" << endl;
                } else {
                   cout << moves << " moves left" << endl;
                }
             }
          } else if (cmd == "switch") {
             if (moves == 0) { // run out of moves, check for result
                cout << moves << " move left" << endl;
                if (g.isWon()) {
                   cout << "Won" << endl;
                   break;
                } else {
                   if (!g.isWon() && moves == 0) {
                      cout << "Lost" << endl;
                      break;
                   }
                }
                break;
             } else {
                int r = 0, c = 0;
                if (cin >> r >> c) {
                g.toggle(r, c);
                }
                cout << g;
                moves--;
                if (moves == 1) {
                   cout << moves << " move left" << endl;
                } else {
                   cout << moves << " moves left" << endl;
                }
                if (g.isWon()) { // check for result per switch
                   cout << "Won" << endl;
                   break;
                } else {
                   if (!g.isWon() && moves == 0) {
                      cout << "Lost" << endl;
                      break;
                   }
                }
             }
          }
    }
  } catch (ios::failure &) {
    return 0;
  }
  return 0;
}
