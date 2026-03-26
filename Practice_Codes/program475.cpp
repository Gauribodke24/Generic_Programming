//from java 108

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no);
        ~ArrayX();
        void Accept();
        void Display();
        int Addition();
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside Constructor\n";
    iSize = no;
    Arr = new int[iSize];
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside Destructor\n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;
    cout<<"Enter Elements : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

void ArrayX :: Display()
{
    int iCnt  = 0;

    cout<<"Elements of the Array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\n";
    }
    cout<<"\n";

}

int ArrayX :: Addition()
{
    int iSum = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the number of Elements : \n";
    cin>>iValue;

    //ArrayX aobj(10);       static allo

    //Step 1 : Allocate the memory
    ArrayX *aobj = new ArrayX(iValue);      // dynamic allo
    
    //Step 2 : Use the Memory
    aobj->Accept();
    aobj->Display();

    cout<<"Summation of all Elements :"<<aobj->Addition()<<"\n";

    //Step 3 : Deallocate the memory
    delete aobj;

    return 0;
}