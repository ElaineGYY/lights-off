#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include "window.h"
#include "observer.h"

class Cell;

class GraphicsDisplay: public Observer {
      int total = 500; // defualt Xwindow size.
      int gridSize;  // size of grid.
      int sqSize;  // size of each square in window.
      Xwindow &w; // the window;
      
      public: 
      GraphicsDisplay(Xwindow &w);  
      
      void createG(int n); // create a new display of grid.
      void clearG(); // clear the existing grid.

      void notify(Subject &whoNotified) override;  // when state changes, notified by the changed cell.
      SubscriptionType subType() const override; 
      
      ~GraphicsDisplay();
};

#endif
