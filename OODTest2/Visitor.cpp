//
//  Visitor.cpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#include "Composite.hpp"

#include <iostream>


void Visitor::visit(Component* comp) {
    auto x1 = dynamic_cast<TreeLeaf*>(comp);
    auto x2 = dynamic_cast<InternalLeaf*>(comp);
    
    if (x1) this->leafVisit(x1);
    if (x2) this->internalVisit(x2);
}

void ConcreteVisitor::leafVisit(TreeLeaf* comp){
    std::cout << "visiting leaf" << std::endl;
    comp->accept(this);
};


void ConcreteVisitor::internalVisit(InternalLeaf* comp){
    std::cout << "visiting internal" << std::endl;
    comp->accept(this);
};

