//Generic

#include<iostream>
using namespace std;

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int no);
        ~ArrayX();
        void Accept();
        void Display();
        T Addition();
        T Maximum();
        int Frequency(T);
};

template<class T>
ArrayX<T> :: ArrayX(int no)
{
    cout<<"Inside Constructor\n";
    iSize = no;
    Arr = new T[iSize];
}

template<class T>
ArrayX<T> :: ~ArrayX()
{
    cout<<"Inside Destructor\n";
    delete [] Arr;
}

template<class T>
void ArrayX<T> :: Accept()
{
    int iCnt = 0;
    cout<<"Enter Elements : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template<class T>
void ArrayX<T> :: Display()
{
    int iCnt  = 0;

    cout<<"Elements of the Array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\n";
    }
    cout<<"\n";

}

template<class T>
T ArrayX<T> :: Addition()
{
    T iSum ;
    int iCnt = 0;

    iSum = Arr[0]- Arr[0];       //design pattern for default value

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

template<class T>
T ArrayX<T> :: Maximum()
{
    T iMax = 0;
    int iCnt = 0;

    iMax = Arr[0];

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }
    }
    return iMax;
}

template<class T>
int ArrayX<T> :: Frequency(T iNo)
{
    int iCnt = 0;
    int iCount = 0;

    for(iCnt = 0; iCnt <iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            iCount++;
        }
    }
    return iCount;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the number of Elements : \n";
    cin>>iValue;

    //ArrayX aobj(10);       static allo

    //Step 1 : Allocate the memory
    ArrayX<int> *aobj = new ArrayX<int>(iValue);      // dynamic allo
    
    //Step 2 : Use the Memory
    aobj->Accept();
    aobj->Display();

    cout<<"Summation of all Elements :"<<aobj->Addition()<<"\n";
    cout<<"Maximun is :"<<aobj->Maximum()<<"\n";
    cout<<"Frequency is :"<<aobj->Frequency(11)<<"\n";
    //Step 3 : Deallocate the memory
    delete aobj;

    return 0;
}