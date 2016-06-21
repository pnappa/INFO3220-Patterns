//
//  Template.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Template_h
#define Template_h

#include <iostream>

class Subject {
protected:
    int currentMark = 0;
    int maxMark = 0;                    //cumulative maximum mark
    std::string courseName = "NULL";

    virtual void doQuizA() = 0;         //1 quiz is mandatory per subject
    virtual void doQuizB() {};          //other quizzes aren't necessarily part of other subjects
    virtual void doQuizC() {};
    
    virtual void assignment1() = 0;     //same for assignments
    virtual void assignment2() {};
    virtual void assignment3() {};
    virtual void assignment4() {};
    
    virtual void finalExam() {};        //exams may not exists in some subjects (ENGG1805)
public:
    Subject(std::string name) : courseName(name) {};
    virtual ~Subject() {};
    void doSubject() {
        std::cout << "Doing subject " << courseName << std::endl;
        doQuizA();
        doQuizB();
        
        if ((float)currentMark/maxMark < 0.4) {         //people going horribly must do quiz A and B again
            int tmpMark = currentMark;
            currentMark = 0;
            maxMark = 0;
            
            doQuizA();
            doQuizB();
            
            currentMark = currentMark > tmpMark ? currentMark : tmpMark;        //best mark attempt so far
        }
        assignment1();
        doQuizC();
        assignment2();
        assignment3();
        assignment4();
        
        
        if ((float)currentMark / maxMark < 0.4) {       //cumulative mark of 40% required for exam
            std::cout << "failed course" << std::endl;
            return;
        }
        
        finalExam();
        
        std::cout << "final mark of " << ((float)currentMark * 100.0) / maxMark << "%\n";
    }
};

class INFO3220 : public Subject {
    
    void doQuizA() {
        //mid sem quiz
        currentMark += 39;
        maxMark += 50;
    }
    
    void assignment1() {
        //planets1
        currentMark += 5;
        maxMark += 10;
    }
    void assignment2() {
        //planets2
        currentMark += 9;
        maxMark += 10;
    }
    void assignment3() {
        //planets3
        currentMark += 12;
        maxMark += 20;
    }
    
    virtual void finalExam() {
        currentMark += 55;
        maxMark += 100;
    };
public:
    INFO3220() : Subject("INFO3220") {};
};

class COMP3520 : public Subject {
    virtual void doQuizA() {
        currentMark += 10;
        maxMark += 10;
    }
    virtual void assignment1() {
        currentMark +=  0;              //plagiarism
        maxMark += 10;
    }
    virtual void assignment2() {
        currentMark +=  0;              //plagiarism
        maxMark += 10;
    };
    virtual void assignment3() {
        currentMark +=  0;              //plagiarism
        maxMark += 10;
    };
    virtual void assignment4() {
        currentMark +=  0;              //plagiarism
        maxMark += 10;
    };
    
    virtual void finalExam() {
        currentMark += 1;               //rampant alcoholism
        maxMark += 40;
    };
public:
    COMP3520() : Subject("COMP3520") {};
};

#endif /* Template_h */
