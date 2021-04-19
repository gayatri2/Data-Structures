//QUEUE USING ARRAY
//Normal queue  //delete O(n), rest are O(1)

/*#include<iostream>
using namespace std;

class queue
{
    int *arr;
    int front;
    int rear;
    int cap;
    public:
    queue()
    {
        front=0;rear=-1;
        cout << "Enter capacity of array:"<<endl;
        cin >> cap;
        arr=new int[cap];

    }
    bool isFull()
    {
        return (rear==cap-1);
    }
    bool isEmpty()
    {
        return (rear==-1);
    }

    void enqueue();
    void dequeue();
    void size();
    int getfront()
    {
        if(isEmpty()==true)
            return -1;
        else
            return 0;
        
    }
    int getrear()
    {
        if(isEmpty()==true)
            return -1;
        else
            return rear;
    }
   
};
void queue::enqueue()   
{
    if(isFull()==true){cout << "Queue overflow:"<<endl; return;}
    int ele;
    cout << "Enter the element to enqueue:"<<endl;
    cin >> ele;
    rear++;
    arr[rear]=ele;
    cout << "Element enqueued:"<<arr[rear]<<endl;
}
void queue::dequeue()
{
    if(isEmpty()==true){cout << "Queue underflow:"<<endl; return;}
    
    cout << endl << "Element popped:"<< arr[front]<<endl;
    for(int i=0;i<cap;i++)  //maintaining front at 0th place
    {
        arr[i]=arr[i++];
    }
    cap--;
    rear--;
    
}

int main()
{
    
    queue q;
    q.enqueue();
    q.enqueue();
    q.enqueue();
    q.dequeue();
    cout << "Rear pos:"<<q.getrear();    
    return 0;
}*/

//Circular queue

//efficient way so that enqueue & dequeue both are O(1)

/*#include<iostream>
using namespace std;

class cirqueue
{
    int *arr;
    int front,rear;
    int size;
    int cap;
    public:
    cirqueue()
    {
        front=0; //rear=-1;
        size=0;
        cout << "Enter capacity:"<<endl;
        cin >> cap;
        arr=new int[cap];
    }
    void enqueue();
    void dequeue();
    bool isEmpty()
    {
        return (size==0);
    }
    bool isFull()
    {
        return (cap==size);
    }
    int getFront()
    {
        if(isEmpty())
            return -1;
        else 
            return front;
    }
    int getRear()
    {
        if(isEmpty())
            return -1;
        else
            return(front+size-1)%cap;
    }

};
void cirqueue::enqueue()
{
    if(isFull()){cout << "Full"<<endl;return;}
    int x;
    cout << "Enter the element to be pushed:"<<endl;
    cin >> x;
    int rear=getRear();
    rear=(rear+1)%cap;
    arr[rear]=x;
    size++;
}
void cirqueue::dequeue()
{
    if(isEmpty()){cout << "Empty:"<<endl;return;}
    cout << "Element deleted:"<<arr[front]<<endl;
    front=(front+1)%cap;
    size--;
}
int main()
{
    cirqueue c;
    c.enqueue();
    c.enqueue();
    c.dequeue();
    
    return 0;
}*/


//QUEUE USING LINKED LIST

/*#include<iostream>
using namespace std;
class node
{
   public:
    int data;
    node* next;  
    node()
    {
        data=0;
        next=NULL;
    }
};
class queue
{
    node*front;
    node*rear;
    int size;
    public:
    queue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }
    void enqueue();
    void dequeue();
    int getSize();
    bool isEmpty()
    {
        return(front==NULL);
    }
    int getFront()
    {
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }

};
int getdata()
{
    int data;
    cout << "Enter data:"<<endl;
    cin >> data; 
    return data;
}
void queue::enqueue()
{
    node*p=new node;
    p->data=getdata();
    p->next=NULL;
    if(front==NULL){front=rear=p;}
    else{
        rear->next=p;
        rear=p;
    }
    size++;
}
void queue::dequeue()
{
    
    if(isEmpty()){cout << "Empty"<<endl; return;}
    node*q=front;
    int temp=front->data;
    front=front->next;
    q->next=NULL;
    if(front==NULL){rear=NULL;}//deleting the last item
    delete q;
    size--;
}
int queue::getSize()
{
    return size;
}
int main()
{
    queue q;
    q.enqueue();
    q.enqueue();
    q.dequeue();
    cout << "Size:"<< q.getSize()<<endl;
    cout << "Data at front postition:"<<q.getFront() << endl;
    cout << "Data at rear position:"<<q.getRear() << endl;

    return 0;
}*/

//queue using STL

/*push – It adds/pushes an item into the queue.
pop – It removes/pops an item from the queue.
front – Returns the item at the front.
back - Returns the item at the back.
size- Returns the size of the queue
empty – Checks whether a stack is empty.*/

/*#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue  <int> q;
    q.push(10);
    q.push(20);
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    

    
}*/