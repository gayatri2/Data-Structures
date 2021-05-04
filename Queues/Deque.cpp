//DEQUEUE USING DOUBLY LINKED LIST. DOUBLY so that all operations are O(1)

/*#include<iostream>      
using namespace std;
class node
{
    public:
    int data;
    node* next;  
    node*prev;
    node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    }
};
class dequeue
{
    node*front;
    node*rear;
    int size;
    public:
    dequeue()
    {
        front=rear=NULL;
        size=0;
    }
    void insertfront();
    void insertRear();
    int getFront()
    {
        return (front->data);
    }
    int getRear()
    {
        return (rear->data);
    }
    int isEmpty()
    {
        return(front==NULL);
    }
    void displaylist();
    void deleteFront();
    void deleteRear();
    
};
int getdata()
{
	int rno;
	cout << endl << "Enter rno:";
	cin >> rno;
	return rno;
}
void dequeue::insertfront()
{
    node*p=new node;
    p->data=getdata();
    p->next=NULL; 
    p->prev=NULL;
    cout << "Element inserted from front:"<< p->data << endl;
    if(front==NULL)
    {front=rear=p;}
    
    if(front!=NULL)
    {   p->next=front;
        front->prev=p;
        front=p;
    }
    
}
void dequeue::insertRear()
{
     node*p=new node;
    p->data=getdata();
    p->next=NULL; 
    p->prev=NULL;
    cout << "Element inserted from rear:"<< p->data << endl;
    if(rear==NULL)
    {
        front=rear=p;
    }
    if(rear!=NULL)
    {   p->prev=rear;
        rear->next=p;
        rear=p;
    }
    

}
void dequeue::deleteFront()
{
    if(isEmpty())
    {cout << "Empty:"<<endl; return;}
    node*d=front;
    int temp=front->data; cout << "Element deleted:"<<temp << endl;
    front=front->next;
    front->prev=NULL;
    d->next=NULL;
    
    delete(d);

}
void dequeue::deleteRear()
{
    if(isEmpty())
    {cout << "Empty:"<<endl; return;}
    int temp=rear->data; cout << "Element deleted:"<<temp << endl;
    node*d=rear->prev;
    d->next=NULL;
    d=rear;
    rear=rear->prev;
    d->prev=NULL;
    delete(d);

}

void dequeue::displaylist()
{
    
    if(isEmpty()){cout << "Empty:"<< endl; return;}
    node*q=front;
    while(q!=NULL)
    {
        cout << q->data << " ";
        q=q->next;
    }
}
int main()
{
    
    dequeue dq;
    dq.insertfront();
    dq.insertRear();
    dq.insertfront();
    dq.deleteFront();
    dq.deleteRear();
    dq.displaylist();    
    cout << "Element at front:"<< dq.getFront()<<endl;
    cout << "Element at rear:"<< dq.getRear()<<endl;
    
    return 0;
}*/

//DEQUEUE USING ARRAY //simple implementation

/*#include<iostream>              //assume front is always 0 
using namespace std;

class dequeue
{
    int size;           
    int cap;
    int *arr;
    public:
    dequeue()
    {
        size=0;
        cout << "Enter capacity:"<<endl;
        cin >> cap;
        arr=new int[cap];
    }
    void insertF(); //O(n)
    void insertR(); 
    void deleteF(); //O(n)
    void deleteR();
    int getFront()                      //rest operations are O(1)
    {
        if(isEmpty()){return -1;}
        else{return (size-1);}
    }             
    int getRear()
    {
        if(isEmpty()){return -1;}
        else {return 0;}    //front always at 0
    }
    int isFull()
    {
        return (size==cap);
    }
    bool isEmpty()
    {
        return (size==0);
    }   

};
void dequeue::insertR()
{
    if(isFull())
    {
        cout << "Full:" << endl; return;
    }
    int x;
    cout << "Enter element to be inserted:"<<endl; cin >> x;
    arr[size]=x;
    size++;
}
void dequeue::deleteR()
{
    if(isEmpty())
    {
        cout << "Empty:"<<endl; return;
    }
    size--;
}
void dequeue::insertF()
{
    if(isFull())
    {
        cout << "Full: "<<endl; return;
    }
    int x;
    cout << "Enter element to be inserted:"<< endl; cin >> x;
    for(int i=size;i>=0;i--)
    {
        arr[i+1]=arr[i];

    }
    arr[0]=x;
    size++;
}
void dequeue::deleteF()
{
     if(isEmpty())
     {
         cout << "Empty:"<<endl; return;
     }
     for(int i=0;i<size-1;i++)
     {
         arr[i]=arr[i+1];
     }
     
     size--;
}
int main()
{
    dequeue d;
    d.insertF();   
    return 0;
}*/

//for efficient implementation, use circular array.
//initialize front=0
//insertF: front=(front+cap-1)%cap; 
//insertR: rear=(front+1+size-1)%cap;
//deleteF: front=(front+1)%cap;
//deleteR: size--;
//getRear: (front+size-1)%cap;


//deque using STL 




#include<iostream>
#include<deque>
using namespace std;
void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    deque <int> dq;
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(15);
    cout << "The deque is : ";
    showdq(dq);
    dq.pop_front();
    cout << "The new deque is : ";
    showdq(dq);
  
}