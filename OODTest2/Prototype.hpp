//
//  Prototype.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Prototype_hpp
#define Prototype_hpp

#include <stdio.h>
#include <string>

class Prototype {
public:
    virtual Prototype* clone() = 0;
};

class CellCell : public Prototype {
    
    std::string* m_1;
    std::string* m_2;
    std::string* m_3;
    std::string* m_4;
public:
    CellCell(std::string* m1, std::string* m2, std::string* m3, std::string* m4) : m_1(new std::string(*m1)), m_2(new std::string(*m2)), m_3(new std::string(*m3)), m_4(new std::string(*m4)) {};
    
    ~CellCell() { delete m_1; delete m_2; delete m_3; delete m_4; }
    
    Prototype* clone() { return new CellCell(m_1, m_2, m_3, m_4); }
};

#endif /* Prototype_hpp */
