// Data_Structures_Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Template Classes

#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b)
    {
        this->a = a;
        this->b = b;
    }

    T Add()
    {
        T c;
        c = a + b;
        return c;
    }

    T Sub()
    {
        T c;
        c = a - b;
        return c;
    }
};

int main()
{
    Arithmetic <int> Ar(25, 15);
    int sum = Ar.Add();
    cout << sum << endl;
    int difference = Ar.Sub();
    cout << difference << endl;

    Arithmetic <float> Ar1(22.2, 3.14);
    float sum1 = Ar1.Add();
    cout << sum1 << endl;
    float difference1 = Ar1.Sub();
    cout << difference1 << endl;
}

