#include <iostream>
#include <vector>

#include "Singleton.hpp"
#include "Buildo.hpp"
#include "Prototype.hpp"
#include "AbstractFactory.hpp"
#include "FactoryMethod.hpp"

#include "Decorator.hpp"
#include "Facade.hpp"
#include "Bridge.hpp"
#include "Composite.hpp"
#include "Proxy.hpp"
#include "Flyweight.hpp"

#include "Iterator.hpp"
#include "Template.hpp"
#include "State.hpp"
//visitor defined in composite.hpp
#include "Command.hpp"
#include "Strategy.hpp"
#include "Observer.hpp"
#include "Mediator.hpp"
#include "Memento.hpp"

int main(int argc, char const** argv)
{
    
    ////////////////////////////////////////////////////////////CREATIONAL
    //***************** SINGLETON ***************//
    auto ins = Singleton::getInstance();
    std::cout << "Singleton data: " << ins->getData() << std::endl;
    Singleton::getInstance()->setData(10);          //can request a new singleton object, still has same data!
    std::cout << "Singleton data: " << ins->getData() << std::endl;
    
    //***************** BUILDER *****************//
    Cat::Builder builder;
    Cat x1 = builder.build();
    Cat x2 = builder.setX(10).setY(111).setZ(11000).build();
    Cat x3 = builder.setXo(std::string("hella cool!")).build();
    
    x1.print();
    x2.print();
    x3.print();
    
    //***************** PROTOTYPE ***************//
    std::string* m1 = new std::string("m1");
    std::string* m2 = new std::string("m2");
    std::string* m3 = new std::string("m3");
    std::string* m4 = new std::string("m4");
    CellCell n(m1, m2, m3, m4);
    CellCell* n2 = (CellCell*) n.clone();
    delete m1; delete m2; delete m3; delete m4;
    
    
    //***************** ABSTRACT FACTORY ********//
    enum kazooType { BASS, TREBLE };
    int kT = kazooType::BASS;
    AbstractFactory* x = nullptr;
    switch (kT) {
        case kazooType::BASS:
                x = (AbstractFactory*) new BassFactory();
            break;
        case kazooType::TREBLE:
            x = (AbstractFactory*) new TrebleFactory();
            break;
    }
    Kazoo* myKaz = x->createKazoo();
    myKaz->blow();
    delete myKaz;
    delete x;
    
    //***************** FACTORY METHOD ***********//
    int nuggFactor = 10;
    int macFactor = 5;
    
    FactoryMethod* myMethod = new FactoryMethod();
    ChickenNugget* nug1 = myMethod->makeNugget(nuggFactor);
    BigMac* mac1 = myMethod->makeMac(macFactor);
    std::cout << "num nugs: " << nug1->num_nugs << std::endl;
    std::cout << "mac vol: " << mac1->volSecretSauce << std::endl;
    delete nug1;
    delete mac1;
    delete myMethod;
    
    //try crazy creation!
    myMethod = new KRAZYFactoryMethod();
    ChickenNugget* nug2 = myMethod->makeNugget(nuggFactor);
    BigMac* mac2 = myMethod->makeMac(macFactor);
    std::cout << "num nugs: " << nug2->num_nugs << std::endl;
    std::cout << "mac vol: " << mac2->volSecretSauce << std::endl;
    delete myMethod;
    delete nug2;
    delete mac2;
    
    ////////////////////////////////////////////////////////////STRUCTURAL
    //******************* CLASS ADAPTOR **************//
    //REFER to VectorStack in Adapter.hpp
    
    //******************* OBJECT ADAPTOR *************//
    //Refer to StackVector in Adapter.hpp
    
    //******************* DECORATOR ******************//
    Artwork* myArt = new JankyFrame(new AlrightPainting());
    //What better to add a golden frame to a janky frame?
    myArt = new GoldenFrame(myArt);
    //A diamond frame as well as a golden frame?!?!? wow! you've done it again
    myArt = new DiamondFrame(myArt);
    myArt->hang();
    std::cout << "Whew! what a beauty, worth at least " << myArt->quality() << std::endl;
    delete myArt;
    
    //******************* FACADE ********************//
    Facade myFac;
    myFac.facadeDo();
    
    //******************* BRIDGE ********************//
    Shape* circle1 = new Square(new CheapRenderer(), 2, 3, 20, 50);
    Shape* circle2 = new Square(new ExpensiveRenderer(), 2, 3, 20, 50);
    circle1->draw();
    circle2->draw();
    delete circle1;
    delete circle2;
    
    //******************* COMPOSITE *****************//
    std::vector<TreeLeaf*> leafies;
    for (int i = 0; i < 39; i+=1) {
        leafies.push_back(new TreeLeaf(i));
    }
    InternalLeaf* node1 = new InternalLeaf();
    InternalLeaf* node2 = new InternalLeaf();
    InternalLeaf* node3 = new InternalLeaf();
    for (int i = 0; i < 10; i+=3) {
        node1->addChild(leafies.at(i));
        node2->addChild(leafies.at(i+1));
        node3->addChild(leafies.at(i+2));
    }
    leafies.clear();
    node1->addChild(node2);
    node1->addChild(node3);
    node1->print();
    delete node1;       //will delete node2, node3, and all other treeleaves

    
    //******************** PROXY *********************//
    Picture* myImg = new ProxyImage();
    myImg->rotate();
    myImg->display();
    myImg->loadImage();         //useless! done by now for sure!
    delete myImg;
    
    //******************** FLYWEIGHT *****************//
    //TODO: dsadsadas
//    {
//    std::shared_ptr<ImageLoader> imLoader;
//    
//    imLoader->load("hello", std::make_shared<Image2>());
//    imLoader->load("hello2", std::make_shared<Image2>());
//    imLoader->load("hello3", std::make_shared<Image2>());
//    
//    RenderScreen1 r(imLoader);
//    r.addImage("hello");
//    r.addImage("hello2");
//    RenderScreen1 rs(imLoader);
//    rs.addImage("hello");
//    rs.addImage("hello3");
//    
//    r.getImageData();
//    rs.getImageData();
//    }
    
    
    //////////////////////////////////////////////////////////////////////BEHAVIOURAL
    ///******************* ITERATOR ******************//
    Cow myCows[6] = {0, 2, 100, 5000, 20, 33000};      //create some cows
    CowIterator start = CowIterator(myCows);
    CowIterator end = CowIterator(myCows + 6);
    std::cout << "Cows:\n";
    for (auto k = start; k!=end; ++k) {
        std::cout << k->getVol() << std::endl;
    }
    
    ///******************* TEMPLATE METHOD ***********//
    Subject* mySub = new COMP3520();
    mySub->doSubject();
    delete mySub;
    mySub = new INFO3220();
    mySub->doSubject();
    delete mySub;
    
    ///******************* STATE ********************//
    Mario* m = new Mario(new ShortMarioState());
    m->getFireBall();       //firestate
    m->getHit();            //revert to short state
    m->getStarMan();        //now forever invincible
    m->getHit();            //can't touch him!
    delete m;               //...ow
    
    //******************* VISITOR ******************//
    Visitor* myVistor = new ConcreteVisitor();
    for (int i = 0; i < 39; i+=1) {
        leafies.push_back(new TreeLeaf(i));
    }
    //note visitor to composite model
    node1 = new InternalLeaf();
    node2 = new InternalLeaf();
    node3 = new InternalLeaf();
    for (int i = 0; i < 10; i+=3) {
        node1->addChild(leafies.at(i));
        node2->addChild(leafies.at(i+1));
        node3->addChild(leafies.at(i+2));
    }
    leafies.clear();
    node1->addChild(node2);
    node1->addChild(node3);
    myVistor->internalVisit(node1);
    
    //******************* COMMAND ****************//
    std::vector<Command*> invoker;      //ideally the invoker would be a class, but no time for that!
    Application* myApp = new Application();
    invoker.push_back(new FlimCommand(myApp));
    invoker.back()->Execute();
    invoker.push_back(new FoldCommand(myApp));
    invoker.back()->Execute();
    
    for (auto r : invoker) delete r;
    invoker.clear();
    delete myApp;
    
    //******************** STRATEGY **************//
    {
        Classroom myClass(new MathsTeacher());
        myClass.teach(100);
        myClass.setTeacher(new EnglishTeacher());
        myClass.teach(100);
        myClass.setTeacher(nullptr);
    }
    
    
    //******************** OBSERVER **************//
    {
        Subject2 subject1;
        Subject2 subject2;
        ConcreteInstance* c1 = new ConcreteInstance();
        ConcreteInstance* c2 = new ConcreteInstance();
        ConcreteInstance* c3 = new ConcreteInstance();
        
        subject1.registerObs(c1);
        subject1.registerObs(c2);
        
        subject2.registerObs(c2);
        subject2.registerObs(c3);
        
        subject1.update();
        subject2.update();
        
        delete c3;
        delete c2;
        delete c1;
    }
    
    //********************* MEDIATOR *************//
    Mediator HEILLO;
    HEILLO.keepCool(200);
    
    
    //********************* MOMENTO *************//
    std::vector<Originator::Momento*> states;
    Originator orig;
    orig.set("hello");
    states.push_back(orig.saveToMomento());
    orig.set("noway!");
    states.push_back(orig.saveToMomento());
    orig.restoreFrom(states.front());       //restore to first state
    std::cout << orig.getStr() << std::endl;
    
    
    
    
    return EXIT_SUCCESS;
}
