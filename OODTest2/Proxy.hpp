//
//  Proxy.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Proxy_h
#define Proxy_h

class Picture {
public:
    virtual ~Picture() {};
    virtual void rotate() = 0;
    virtual void display() = 0;
    virtual void loadImage() = 0;
};

class Image : public Picture {
public:
    void rotate() {
        std::cout << "image rotate\n";
    };
    
    void display() {
        std::cout << "image display\n";
    };
    
    void loadImage() {
        std::cout << "image load\n";
    };
};

class ProxyImage : public Picture {
    Image* m_image = nullptr;
    
public:
    ~ProxyImage() {
        delete m_image;
    }
    
    void rotate() {
        //try loading
        loadImage();
        
        std::cout << "proxy rotate\n";
        m_image->rotate();
    }
    
    void display() {
        //try loading
        loadImage();
        
        std::cout << "proxy display\n";
        m_image->display();
    }
    
    void loadImage() {
        //load only if never loaded
        if (m_image == nullptr) {
            std::cout << "proxy load\n";
            m_image = new Image();
            loadImage();
        }
    }
    
};

#endif /* Proxy_h */
