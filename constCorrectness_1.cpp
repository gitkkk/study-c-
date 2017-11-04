#if 0
#include <iostream>
#include <memory>
#include <assert.h>

//#define REMOVE_ERRORS // uncomment this line to remove errors

using namespace std;

// Concept 1 :: You can not overload function by having diffrent return type
class classFunctionOverLoading
{
 public:
    void foo(){}
    void foo(int val){}
    void foo(int val1 ,int val2){}
    void foo(int val,char c){}
    void foo(char c, int val){}
    int foo(float f){}
#ifndef REMOVE_ERRORS
    void foo(int val2){}// error. Its the argument type which matters not the argument name
    int foo(){} // error . you can not overload function by having diffrent return type
    char foo(int val1 ,int val2){}// error . you can not overload function by having diffrent return type
    bool foo(int val,char c){}// error . you can not overload function by having diffrent return type
    float foo(char c, int val){}// error . you can not overload function by having diffrent return type
    long foo(float f){}// error . you can not overload function by having diffrent return type

    const int foo(){}// error . "const int " and "int" appears as  diffrent types to compiler. So cant overload as diffrent return types

#endif
};

//----------------------------------------------------------------------------------------------------------





//As learned in the above item , the function rerutning diffrent types can not have same name . Hence
//classToCheckConstFunction has diffrent names functions
class classToCheckConstFunction
{
    int _data;
public:
    void foo_1() const
    {
        std::cout<<_data;// no error. no mutation. member not changed
    }
#ifndef REMOVE_ERRORS
    void foo_2() const
    {
        _data = _data + 0;// error. mutation. member  changed
    }
#endif
    int foo_3()const
    {
        return _data;// no error. no mutation. return by value so member not changed
    }
#ifndef REMOVE_ERRORS
    int& foo_4()const
    {
        return _data; // error. returning refrence to data member exposeses the internal member to outer world, hence making vunrable for change
    }
#endif
    const int& foo_5()const
    {
        return _data;// no error. return by const refrence restrict any change to exposed internal member .
    }
};

int main()
{

    std::cout<<"Lets test the const keyword scenarios !!!" <<std::endl;
    return 0;
}



//Question:: will following code compile ? if No/Yes , why ?

class MyAnotherClass
{
    int _data;

public:
    int& getDataRef()
    {
        return _data;
    }
    const int& getDataRef() const
    {
        return _data;
    }
};





#endif
