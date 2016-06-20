//
//  Buildo.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Buildo_hpp
#define Buildo_hpp

#include <string>
#include <iostream>

class Cat {
    
private:
    int m_x;
    int m_y;
    int m_z;
    std::string m_xo;
    
public:
    
    Cat(int x, int y, int z, std::string& xo) : m_x(x), m_y(y), m_z(z), m_xo(xo) {}
    
    class Builder;
    
    void print() {
        std::cout << m_x << " " << m_y << " " << m_z << " " << m_xo << std::endl;
    }
    
};

class Cat::Builder {
private:
    int x = 0;
    int y = 11;
    int z = 22;
    std::string xo = "wow";
    
public:
    Builder() { };
    
    Builder& setX(int newX) { x = newX; return *this; }
    Builder& setY(int newY) { y = newY; return *this; }
    Builder& setZ(int newZ) { z = newZ; return *this; }
    Builder& setXo(std::string newStr) { xo = newStr; return *this; }
    
    Cat build() {
        //check validity
        return Cat(x,y,z,xo);
    }
    
    
    
};

#endif /* Buildo_hpp */
