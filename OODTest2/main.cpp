
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include <iostream>
#include "Singleton.hpp"
#include "Buildo.hpp"
#include "Prototype.hpp"
#include "AbstractFactory.hpp"
#include "FactoryMethod.hpp"
#include "Decorator.hpp"

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
    
    
    
    return EXIT_SUCCESS;
}
