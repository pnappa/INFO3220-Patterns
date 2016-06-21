//
//  Iterator.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

#include <iterator>

class Cow {
private:
    int mooVolume;
public:
    Cow(int dB) : mooVolume(dB) {};
    ~Cow() {};
    int getVol() { return mooVolume; };
};

class CowIterator : std::iterator<std::input_iterator_tag, Cow> {
    Cow* p;
public:
    CowIterator(Cow* iter) : p(iter) {};
    CowIterator(const CowIterator& it) : p(it.p) {};
    CowIterator& operator++() { ++p; return *this; };   //move iterator along one
    CowIterator operator++(int) { CowIterator tmp(*this); operator++(); return tmp; } //move iterator along one, return previous spot (copy)
    bool operator==(CowIterator& rhs) { return p==rhs.p; };
    bool operator!=(CowIterator& rhs) { return p!=rhs.p; };
    Cow& operator*() { return *p; };
    Cow* operator->() { return p; };        //implement this to make it easier for accessing Cow's internals
};

#endif /* Iterator_h */
