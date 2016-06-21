//
//  Composite.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Composite_h
#define Composite_h

#include <iostream>
#include <list>
///////////////VISITOR
class TreeLeaf;
class InternalLeaf;
class Component;
class Visitor {
public:
    void visit(Component* comp);
    virtual void leafVisit(TreeLeaf* comp) = 0;
    virtual void internalVisit(InternalLeaf* comp) = 0;
};

class ConcreteVisitor : public Visitor {
public:
    void leafVisit(TreeLeaf* comp);
    void internalVisit(InternalLeaf* comp);
};
//////////////VISITOR

class Component {
public:
    Component() {};
    virtual ~Component() {};
    virtual void print() = 0;
    
    //for Visitor
    virtual void accept(Visitor* visitor) = 0;
};

class TreeLeaf : public Component {
    int m_number;
public:
    TreeLeaf(int num) : m_number(num) {};
    void print() {
        std::cout << m_number << std::endl;
    }
    //visitor
    void accept(Visitor* visitor) { std::cout << "accepted @ leaf" << std::endl; };
};

class InternalLeaf : public Component {
private:
    std::list<Component*> m_children;
    
public:
    InternalLeaf() : m_children() {};
    ~InternalLeaf() { for (auto leaf : m_children) delete leaf; };
    
    void addChild(Component* leaf) { m_children.push_back(leaf); };
    
    void print() {
        std::cout << "node contains: \n";
        for (auto leaf : m_children) {
            std::cout << "\t";
            leaf->print();
        }
        std::cout << std::endl;
    }
    void accept(Visitor* visitor) {
        
        for (auto child : m_children) {
            visitor->visit(child);
        }
    };
};

#endif /* Composite_h */
