//
//  Bridge.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Bridge_hpp
#define Bridge_hpp

class Renderer {
public:
    Renderer() {};
    virtual ~Renderer() {};
    virtual void drawShape(int left, int top, int width, int height) = 0;
};

class CheapRenderer : public Renderer {
public:
    CheapRenderer() {};
    ~CheapRenderer() {};
    void drawShape(int left, int top, int width, int height) {
        std::cout << "Cheapo function, poor quality " << left << " " << top << "->" << left+width << " " << top + height << std::endl;
    }
    
};

class ExpensiveRenderer : public Renderer {
public:
    ExpensiveRenderer() {};
    ~ExpensiveRenderer() {};
    void drawShape(int left, int top, int width, int height) {
        std::cout << "Expensive function, good quality " << left << " " << top << "->" << left+width << " " << top + height << std::endl;
    }
};



class Shape {
protected:
    Renderer* m_renderer;
    
public:
    Shape(Renderer* renderer) : m_renderer(renderer) {};
    virtual ~Shape() { delete m_renderer; };
    
    virtual void draw() = 0;
};

class Square : public Shape {
private:
    int m_x, m_y;
    int m_width, m_height;
    
public:
    Square(Renderer* renderer, int x, int y, int w, int h) : Shape(renderer), m_x(x), m_y(y), m_width(w), m_height(h) {};
    ~Square() {};
    
    void draw() { m_renderer->drawShape(m_x, m_y, m_width, m_height); };
};


#endif /* Bridge_hpp */
