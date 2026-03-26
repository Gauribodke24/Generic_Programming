#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>

class node
{
    public:
        int data;
        node *next;

        node(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class SinglyLLL
{
    private:            
        node * first;
        int iCount;

    public:    
        SinglyLLL();
        
        void InsertFirst(int no);
        
        void InsertLast(int no); 
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(int no, int pos);
        
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets Created.\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    node * newn = NULL;
    newn = new node(no);
    
    newn->next = this->first;    
    this->first = newn;

    this->iCount++;
}

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    node * newn = NULL;
    node * temp = NULL;

    newn = new node(no);

    if(this->iCount == 0)        
    {
        this->first = newn;
    } 
    else
    {
        temp = this->first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;
}

template<class T>
void SinglyLLL :: DeleteFirst()
{
    node * temp = NULL;

    if(this->first == NULL)        
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete(temp);
    }
    this->iCount--;
}

template<class T>
void SinglyLLL :: DeleteLast()
{
    node * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this-> iCount--;
}


template<class T>
void SinglyLLL :: Display()
{
    node * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)      
    {
        cout<<" | " << temp->data << " | ->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SinglyLLL :: Count()
{
    return this->iCount;
}

template<class T>
void SinglyLLL :: InsertAtPos(int no, int pos)
{
    node * newn = NULL;
    node * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
        
        this->iCount++;
    }
}

template<class T>
void SinglyLLL :: DeleteAtPos(int pos)
{
    node * temp = NULL;
    node * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        target = temp->next;

        temp->next = target->next;
        delete target;
    
        
        this->iCount--;
    }
}

int main()
{
    SinglyLLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes are :"<<iRet<<"\n";


    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes are :"<<iRet<<"\n";


    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes are :"<<iRet<<"\n";


    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes are :"<<iRet<<"\n";


    obj.InsertAtPos(105,4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes are :"<<iRet<<"\n";


    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes are :"<<iRet<<"\n";


    return 0;
}