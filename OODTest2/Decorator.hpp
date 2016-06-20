//
//  Decorator.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include <iostream>

class Artwork {
public:
    Artwork() {};
    virtual ~Artwork() {}
    
    virtual void hang() = 0;
    virtual int quality() = 0;
};

class AlrightPainting : public Artwork {
public:
    AlrightPainting() {};
    ~AlrightPainting() {};
    
    void hang() {
        std::cout << "ConcretePainting hangin' on the wall\n";
    }
    
    int quality() { return 1000; }
};

class MonetPainting : public Artwork {
public:
    MonetPainting() {};
    ~MonetPainting() {};
    
    void hang() {
        std::cout << "hol' up! monet brin' in da moeny on da wall\n";
    }
    int quality() { return 20000; }
};

class PaintingDecorator : public Artwork {
private:
    Artwork* m_artwork;
    
public:
    PaintingDecorator(Artwork* in) : m_artwork(in) {};
    ~PaintingDecorator() { delete m_artwork; };
    virtual void hang() { m_artwork->hang(); };
    virtual int quality() { return m_artwork->quality(); };
};

class JankyFrame : public PaintingDecorator {
public:
    JankyFrame(Artwork* in) : PaintingDecorator(in) {};
    int quality() { return PaintingDecorator::quality() + 1; }
};

class GoldenFrame : public PaintingDecorator {
public:
    GoldenFrame(Artwork* in) : PaintingDecorator(in) {};
    int quality() { return PaintingDecorator::quality() + 500; }
};

class DiamondFrame : public PaintingDecorator {
public:
    DiamondFrame(Artwork* in) : PaintingDecorator(in) {};
    int quality() { return PaintingDecorator::quality() + 1050; } //Worth more than a regular painting!
};



#endif /* Decorator_hpp */
