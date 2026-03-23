//Specific code
//Automation type conversion from float to double bcoz double is pf more size

#include<iostream>

using namespace std;

double Addition(double No1, double No2)
{
    double Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    float i = 0.0f, j = 0.0f;
    float Ret = 0.0f;

    cout<<"Enter First Number :\n";
    cin>>i;

    cout<<"Enter Second Number :\n";
    cin>>j;

    Ret = Addition(i,j);

    cout<<"Addition is :"<<Ret<<"\n";

    return 0;
}