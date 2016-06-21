//
//  Flyweight.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Flyweight_h
#define Flyweight_h

#include <map>

class Image2 {
public:
    Image2() {}
    virtual ~Image2() {};
    virtual void getImageData() {};
};

class ConcreteImage : public Image2 {
public:
    ConcreteImage() {};
    void getImageData() { std::cout << "immy the image\n"; };
};

class ImageLoader {

public:
    std::map<std::string, std::shared_ptr<Image2>> m_images;
    void load(std::string str, std::shared_ptr<Image2> im) { m_images.insert(std::make_pair(str, im)); };
};

class RenderScreen1 {
    std::shared_ptr<ImageLoader> imLoader;
    std::vector<std::shared_ptr<Image2>> myIm;
public:
    RenderScreen1(std::shared_ptr<ImageLoader> iLoader) : imLoader(iLoader), myIm() {};
    void addImage(std::string toGet) { myIm.push_back(imLoader->m_images[toGet]); };
    void getImageData() { for (auto c : myIm) { c->getImageData(); } };
};


#endif /* Flyweight_h */
