//
//  Mediator.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Mediator_h
#define Mediator_h

class RootComponent {
public:
    virtual void update(int shitcunt) = 0;
};

class HigherComp1 : public RootComponent {
public:
    void update(int shitcunt) { std::cout << shitcunt * 2 << " depressions imminent" << std::endl; }
};

class HigherComp2 : public RootComponent {
public:
    void update(int shitcunt) { std::cout << shitcunt * 3 << " depressions imminent" << std::endl; };
};

class Mediator {
    //should be pointers, such that the objects can exist without
    HigherComp2 h2;
    HigherComp1 h1;
    
public:
    void keepCool(int shitcunt) {
        shitcunt /= 1;
        //lol jk
        h2.update(shitcunt);
        h1.update(shitcunt);
    }
};

#endif /* Mediator_h */
