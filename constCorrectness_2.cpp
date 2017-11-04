#if 0
#include <iostream>
#include <memory>
#include <assert.h>
//#define REMOVE_ERRORS // uncomment this line to remove errors
using namespace std;


class MyClass
{
    int _data;

public:

    int getDaysInYear()
    {
        return 365;
    }
    int& getDataRef()
    {
        return _data;
    }
    int getDataVal()
    {
        return _data;
    }
    void setData(int newValue)
    {
        _data=newValue;
    }
    const int& getDataRef() const
    {
        return _data;
    }
    void helloWorld()
    {
        std::cout<<"Hello World "<<__LINE__<<std::endl;
    }
    void helloWorld() const
    {
        std::cout<<"Hello World "<<__LINE__<<std::endl;
    }
};


void functionTakingRef(MyClass& obj)
{
    obj.getDaysInYear();
    obj.getDataVal();
    obj.setData(100);
    obj.getDataRef(); // which of the two same name method will be called ?
    obj.helloWorld();// which of the two same name method will be called ?
}

void functionTakingConstRef(const MyClass& obj)
{
#ifndef REMOVE_ERRORS
    obj.getDaysInYear();// error . non const members can not be called
    obj.getDataVal();// error . non const members can not be called
    obj.setData(100);
#endif
    obj.getDataRef();// which of the two same name method will be called ?
    obj.helloWorld();// which of the two same name method will be called ?


}

int main()
{

    std::cout<<"Lets test the const keyword scenarios !!!" <<std::endl;

    MyClass obj;
    functionTakingRef(obj);
    functionTakingConstRef(obj);
    return 0;
}

#endif
