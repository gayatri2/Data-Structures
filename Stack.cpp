//STACK using ARRAY     //time complexity O(1)

/*#include<iostream>
using namespace std;
class stack
{

    int *arr;
    int top;
    int cap;
    public:
    stack() //constructor initializing values
    {
        cout << "Enter size of array:"<<endl;
        cin >> cap;
        arr=new int[cap];
        top=-1;
    }
    void push();
    void pop();
    void peek();
    void size();
    bool isEmpty()
    {
        return (top==-1);
    }
};
void stack::push()
{
    if(top==cap-1){cout<< "Stack overflow:"<<endl;return;}

    int x;
    cout << "Enter number to be pushed:"<<endl;
    cin >> x;
    top++;
    arr[top]=x;
    cout << "Element pushed:"<<arr[top]<<endl;

}
void stack::pop()
{
    if(isEmpty()==true){cout << "Stack underflow:"<<endl;return;}
    int temp=arr[top];
    top--;
    cout << "Element popped:"<< temp << endl;
}
void stack::peek()
{
    if(isEmpty()==true){cout << "Underflow, top=-1"<<endl;return;}
    cout << "Element at top is:"<<arr[top] << endl;
}
void stack::size()
{
    cout << "Size of stack is:"<<top+1;
}
int main()
{
    stack s;
    s.push();
    s.push();
    s.pop();
    s.peek();   //gives the element at postition top
    
    
    
    return 0;

}*/

//STACK using LINKED LIST   //push and pop at the head node so that time complexity is O(1)

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

class stack
{
    node*head;
    int sz;
    public:
    stack()
    {
        head=NULL;
        sz=0;
    }
    void push();
    void display();
    void pop();
    void size();
    void peek();
    bool isEmpty()
    {
        return (head==NULL);
    }
};
int getdata()
{
	int rno;
	cout << endl << "Enter rno:";
	cin >> rno;
	return rno;
}
void stack::push()
{
    node*p=new node;
    p->data=getdata();
    p->next=head;
    head=p;
    sz++;
    cout << "Data pushed:"<<p->data << endl;
}
void stack::pop()
{
    if(isEmpty()==true){cout << "Empty"<<endl;return;}
    int temp=head->data;
    node*p=head;    
    p->next=NULL;
    head=head->next;
    delete(p);
    sz--;
    cout << "Data deleted:"<<temp << endl;
    
}
void stack::size()
{
    cout<<"Size:"<<sz<<endl;
}
void stack::peek()
{
   if(isEmpty()==true){cout << "Empty"<<endl;return;}
   cout<<"Element at peek:"<<head->data<<endl; 
}
int main()
{
    stack s;
    s.push();
    s.pop();
    s.size();
    s.peek();

    return 0;
}*/

//stack using STL

/*push – It adds/pushes an item into the stack.
pop – It removes/pops an item from the stack.
peek – Returns the top item of the stack without removing it.
full – Checks whether a stack is full.
empty – Checks whether a stack is empty.
size- Returns the size of the queue */

/*#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    
    s.push(4);
    s.push(5);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
}*/
