//
//  FactoryMethod.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef FactoryMethod_h
#define FactoryMethod_h

class ChickenNugget {
public:
    int num_nugs;
    ChickenNugget(int nug) : num_nugs(nug) {}
    
};

class BigMac {
public:
    int volSecretSauce;
    BigMac(int volSauce) : volSecretSauce(volSauce) {}
};

class FactoryMethod {
public:
    
    virtual ChickenNugget* makeNugget(int crazyFactor) {
        return new ChickenNugget(crazyFactor);
    }
    
    virtual BigMac* makeMac(int ejacFactor) {
        return new BigMac(ejacFactor);
    }
};

class SpicyNugget : public ChickenNugget {
public:
    SpicyNugget(int nugo) : ChickenNugget(nugo) {}
};

//now we can also make a second factory which overrides this
class KRAZYFactoryMethod : public FactoryMethod {
public:
    virtual ChickenNugget* makeNugget(int crazyFactor) {
        return new SpicyNugget(crazyFactor*1000);   //v spicy
    }
    
    //big macs are already crazy enough, so don't worry about changing them
};


#endif /* FactoryMethod_h */
