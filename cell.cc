#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {
       this->r = 0;
       this->c = 0;
}

bool Cell::getState() const { 
       return isOn; 
}

Info Cell::getInfo() const {
       Info myInfo;
       myInfo.row = r;
       myInfo.col = c;
       myInfo.state = isOn;
       return myInfo;
}

void Cell::setOn() {
       isOn = true;
       notifyObservers(SubscriptionType::All);  // state changed
}

void Cell::toggle() {
       notifyObservers(SubscriptionType::SwitchOnly); // notify observers switch happened
}

void Cell::setCoords(int r, int c) { 
       this->r = r; 
       this->c = c; 
}

void Cell::notify(Subject &) {
       if (isOn) {
          isOn = false;
       } else {
          isOn = true;
       }
       notifyObservers(SubscriptionType::All); // state changed
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
