//
//  Adapter.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 20/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <iostream>
#include <list>
#include <queue>




//******************* FOLLOWING CODE FROM TUTORIAL 8 INFO3220

class StringStack
{
public:
    virtual ~StringStack(){}
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual const std::string& peek() const = 0;
    virtual void push(const std::string &string) = 0;
    virtual std::string pop() = 0;
};
///////////////////////////////////

//class adaptor (multi inheritance)
class VectorStack : public StringStack, private std::vector<std::string> {
public:
    VectorStack() : std::vector<std::string>() {};
    
    virtual bool empty() const { return this->vector::size() == 0; }
    virtual size_t size() const { return this->vector::size(); }
    virtual const std::string& peek() const { return this->vector::back(); }
    virtual void push(const std::string &string) { this->vector::push_back(string); }
    virtual std::string pop() { std::string ref = peek(); this->vector::pop_back(); return ref; }
};

//object adaptor
class StackVector : public StringStack {
private:
    //this one is simply adapting the stack and vector
    std::vector<std::string> m_vector;
    
public:
    virtual bool empty() const { return size() == 0; }
    virtual size_t size() const { return m_vector.size(); }
    virtual const std::string& peek() const { return m_vector.back(); }
    virtual void push(const std::string &string) { m_vector.push_back(string); }
    virtual std::string pop() { std::string ref = peek(); m_vector.pop_back(); return ref; }
};


#endif /* Adapter_hpp */
