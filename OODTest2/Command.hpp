//
//  Command.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>
#include <iostream>

class Application {
public:
    void foldStuff() {};
    void flimStuff() {};
};

class Command {
public:
    virtual ~Command() {}
    
    virtual void Execute() = 0;
protected:
    Command();
};

class FoldCommand : public Command {
public:
    FoldCommand(Application* app) : m_app(app) {};
    virtual void Execute() { zooper(); m_app->foldStuff(); };
    
protected:
    void zooper() { std::cout << "zooper" << std::endl; }
    
private:
    Application* m_app;
};


class FlimCommand : public Command {
public:
    FlimCommand(Application* app) : m_app(app) {};
    virtual void Execute() { dooper(); m_app->flimStuff(); };
    
protected:
    void dooper() { std::cout << "dooper" << std::endl; }
    
private:
    Application* m_app;
};


#endif /* Command_hpp */
