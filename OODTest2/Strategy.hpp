//
//  Strategy.hpp
//  OODTest2
//
//  Created by Patrick Nappa on 21/06/2016.
//  Copyright © 2016 Patrick Nappa. All rights reserved.
//

#ifndef Strategy_h
#define Strategy_h

class Teacher {
public:
    virtual ~Teacher() {};
    virtual void work(int concentration) = 0;
};


class MathsTeacher : public Teacher {
public:
    void work(int concentration) {
        std::cout << "Wow this is really easy! @" << 100 + concentration << std::endl;
        
    }
};

class EnglishTeacher : public Teacher {
public:
    void work(int concentration) {
        std::cout << "Wow! The conjugate megaman is mena:" << concentration << std::endl;
    }
};

class Classroom {
    Teacher* m_teacher = nullptr;
public:
    Classroom(Teacher* tea) : m_teacher(tea) {};
    
    void teach(int concentration) { m_teacher->work(concentration); };
    void setTeacher(Teacher* m) { if (m_teacher != nullptr) delete m_teacher; m_teacher = m; };
};

#endif /* Strategy_h */
