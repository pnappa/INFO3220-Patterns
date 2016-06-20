//
//  AbstractFactory.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef AbstractFactory_h
#define AbstractFactory_h

class Kazoo {
public:
    virtual void blow() = 0;
    virtual ~Kazoo() {};
};

class TrebleKazoo : public Kazoo {
public:
    TrebleKazoo() {};
    void blow() { std::cout << "wiiiiiiiiiiiiih\n"; };
    
};

class BassKazoo : public Kazoo {
public:
    BassKazoo() {};
    void blow() { std::cout << "dooooooooooooooooooh\n"; };
    
};

class AbstractFactory {
public:
    virtual Kazoo* createKazoo() = 0;
    virtual ~AbstractFactory() {};
};

class TrebleFactory : public AbstractFactory {
public:
    TrebleFactory() {};
    Kazoo* createKazoo() { return new TrebleKazoo(); }
};

class BassFactory : public AbstractFactory {
public:
    BassFactory() {};
    Kazoo* createKazoo() { return new BassKazoo(); }
};


#endif /* AbstractFactory_h */
