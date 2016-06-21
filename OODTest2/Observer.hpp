//
//  Observer.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <list>

class Observer;
class Subject2 {
    std::list<Observer*> observers;
public:
    void registerObs(Observer* newOb) { observers.push_back(newOb); }
    void unregisterObs(Observer* old) { observers.remove(old); }
    void update();
};

class Observer {
public:
    virtual void notify(Subject2* x) = 0;
};

class ConcreteInstance : public Observer {
public:
    void notify(Subject2* x) { std::cout << "notified by " << x << std::endl; };
};

void Subject2::update() {
    for (auto observ : observers) observ->notify(this);
}
#endif /* Observer_h */
