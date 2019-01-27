#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        std::cout<<"Base constructor executed"<<std::endl;
    }
    //the follow destructor will be called after the derived destructor
    //deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in undefined behavior. 
    virtual ~Base(){
        std::cout<<"Base virtual destructor executed"<<std::endl;
    }
    virtual void methodA(){
        std::cout<<"Base methodA executed"<<std::endl;
    }
    virtual void methodB(){
        std::cout<<"Base methodB executed"<<std::endl;
    }
    virtual void methodC(){
        std::cout<<"Base methodC executed"<<std::endl;
    }
    //the follow sentence is not allowed without definition
    //virtual void methodD();
};

class Derived: public Base{
    public:
    Derived(){
        std::cout<<"Derived constructor executed"<<std::endl;
    }
    virtual ~Derived(){
        std::cout<<"Derived virtual destructor executed"<<std::endl;
    }
    void methodA(){
        std::cout<<"Derived methodA executed"<<std::endl;
    }
    virtual void methodC(){
        std::cout<<"Derived methodC executed"<<std::endl;
    }
};

class Derived2: public Derived{
    public:
    Derived2(){
        std::cout<<"Derived2 constructor executed"<<std::endl;
    }
    ~Derived2(){
        std::cout<<"Derived2 destructor executed"<<std::endl;
    }
    void methodC(){
        std::cout<<"Derived2 methodC executed"<<std::endl;
    }
};

int main(){
    Base *base = new Derived2();
    base->methodA();
    base->methodB();
    base->methodC();
    delete base;
    return 0;
}
