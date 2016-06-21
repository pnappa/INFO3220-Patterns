//
//  State.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <iostream>

class MarioState {
public:
    virtual void jump() = 0;
    virtual void shoot() = 0;
    virtual void hit() = 0;
    MarioState() {};
    virtual ~MarioState() {};
};

class ShortMarioState : public MarioState {
public:
    ShortMarioState() {};
    ~ShortMarioState() {};
    
    void jump() {
        std::cout << "small mario jump: weehaa!\n";
    }
    
    void shoot() {
        std::cout << "sms: can't shoot!\n";
    }
    
    void hit() {
        std::cout << "wow that really hurt!!\n";
    }
};

class FireMarioState : public MarioState {
public:
    FireMarioState() {};
    ~FireMarioState() {};
    
    
    void jump() {
        std::cout << "fire mario jump: woooshaa!\n";
    }
    
    void shoot() {
        std::cout << "fms: napalm strike!\n";
    }
    
    void hit() {
        std::cout << "ow!!\n";
    }
};

class InvincMarioState : public MarioState {
public:
    InvincMarioState() {};
    ~InvincMarioState() {};
    
    
    void jump() {
        std::cout << "invinc mario jump: woopa!\n";
    }
    
    void shoot() {
        std::cout << "ims: no shooty!\n";
    }
    
    void hit() {
        std::cout << "aha can't shoot me!!\n";
    }
};


class Mario {
    
private:
    void switchState(MarioState* newState) {
        //change current state to invinc if not already
        if (prevState!=nullptr) delete prevState;
        prevState = currState;
        currState = newState;
    }
public:
    Mario(MarioState* initState) : currState(initState) {};
    ~Mario() { delete currState; };
    void getStarMan() {
        //better way would be to use a transition table
        auto x = dynamic_cast<InvincMarioState*>(currState);
        if (!x) {
            switchState(new InvincMarioState());
        }
    }
    
    void getFireBall() {
        auto x = dynamic_cast<FireMarioState*>(currState);
        if (!x) {
            switchState(new FireMarioState());
        }
    }
    
    void getHit() {
        currState->hit();
        auto x = dynamic_cast<InvincMarioState*>(currState);
        if (x) { return; }
        //if not invincible, convert to short mario
        switchState(new ShortMarioState());
    }
    
private:
    MarioState* currState;
    MarioState* prevState = nullptr;
};

#endif /* State_hpp */
