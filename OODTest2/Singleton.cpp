//
//  Singleton.cpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#include "Singleton.hpp"

Singleton* Singleton::myInstance = nullptr;

Singleton* Singleton::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new Singleton();
    }
    
    return myInstance;
}