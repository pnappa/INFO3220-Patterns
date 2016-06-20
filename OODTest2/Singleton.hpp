//
//  Singleton.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp


class Singleton {
private:
    Singleton() : myData(0) {};
    static Singleton* myInstance;
    
private:
    int myData;
    
public:
    static Singleton* getInstance();
    
    void setData(int x) { myData = x; }
    int getData() { return myData; }
};

#endif /* Singleton_hpp */
