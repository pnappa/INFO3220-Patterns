//
//  Facade.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Facade_hpp
#define Facade_hpp

#include <string>
#include <iostream>

//our classes of complex and hard things
class DifferentialEquationSolver {
public:
    DifferentialEquationSolver(int t) : x(t) {};
    int x;
    
    int differentiate() { return (x*x*x*x / 30000 & 203) | 222 | x * 2 / (3 ^ 0xffffff); };
};
class ClappingOneHanded {
public:
    std::string m_wisdom;
    ClappingOneHanded(std::string wisdom) : m_wisdom(wisdom) {};
    
    void becomeOne() { std::cout << m_wisdom << " and do the hokey pokey" << std::endl; };
};
class GenderStudiesDegree {
public:
    GenderStudiesDegree() {};
    //returns nothing
    virtual void finish() {};
};
class Diamond {
public:
    Diamond() {};
    void x() {};
    void y() {};
    void z() {};
    void diamonte() { std::cout << "De beers with a moh hardness of " << 10 << std::endl; };
};

    
//facade to unify all of these
class Facade {
private:
    DifferentialEquationSolver* dfs;
    ClappingOneHanded* coh;
    GenderStudiesDegree* gs;
    Diamond* dia;
public:
    Facade() {
        dfs = new DifferentialEquationSolver(20);
        coh = new ClappingOneHanded("enter the slipstream");
        gs = new GenderStudiesDegree();
        dia = new Diamond();
    };
    ~Facade() {
        delete dfs;
        delete coh;
        delete gs;
        delete dia;
    };
    
    void facadeDo() {
        //do a set of very difficult things (pretend these are difficult)
        coh->becomeOne();
        gs->finish();
        dia->x();
        dia->z();
        dia->y();
        dia->diamonte();
        std::cout << "derivative is " << dfs->differentiate() << std::endl;
    }
    
};

#endif /* Facade_hpp */
