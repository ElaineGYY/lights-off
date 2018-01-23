#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) { 
       this->observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) { 
      int size = observers.size();
      for (int i = 0; i < size; ++i) {
           if (observers[i]->subType() == t) {      
              observers[i]->notify(*this);
           }
      }
}

Subject::~Subject() {
}

