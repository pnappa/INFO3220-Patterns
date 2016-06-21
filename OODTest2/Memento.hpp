//
//  Memento.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Memento_h
#define Memento_h

#include <iostream>

class Originator {
public:
    class Momento {
    public:
        std::string momento_data;
        
    public:
        Momento(std::string data) : momento_data(data) {};
        ~Momento() {}
        std::string getState() { return momento_data; };
    };
private:
    std::string m_data;
    
public:
    void set(std::string data) { m_data = data; };
    
    Momento* saveToMomento() {
        return new Momento(m_data);
    }
    
    std::string getStr() { return m_data; };
    
    void restoreFrom(Momento* mom) {
        this->m_data = mom->momento_data;
    }
    
public:
    
};

#endif /* Memento_h */
