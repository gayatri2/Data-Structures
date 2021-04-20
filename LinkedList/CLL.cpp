//Singly circular linked list

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node()
    {
        data=0;
        next=NULL;
    }
};
class list{
    node*head;
    node*tail;
    node*p;
    public:
    list()
    {
        head=NULL;
        tail=NULL;
        p=NULL;
    }
    int getno()
    {
        int no;
        cout << endl << "Enter the number:";
        cin >> no;
        return no;
    }
    void ibeg();
    void iend();
    void display();
    void del();
};
void list::ibeg()   //O(n) if tail pointer not maintained. To make the time complexity O(1), a) maintain tail pointer OR b)place new node at head->next position. Then swap contents of head and head->next.
{
    p=new node;
    if(head==NULL)
    {
        p->data=getno();
        p->next=p;    //circular even if there is one node
        head=tail=p;
    }
    else
    {
        p->data=getno();
        
        //commented because it is without using tail pointer
        /*node*curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=p;
        p->next=head;
        head=p;*/

        //this is using tail pointer
        tail->next=p;
        p->next=head;
        head=p;
        
    }
}
void list::iend()
{
    p=new node;
    p->data=getno();
    if(head==NULL)
    {
       
        p->next=p;    //circular even if there is one node
        head=tail=p;
    }
    else
    {
        tail->next=p;
        p->next=head;
        tail=p;

    }
    
}
void list::display()
{
    
    if(head==NULL){cout << "List empty."<< endl; return;}
    cout << head->data << " ";
    for(node*q=head->next;q!=head;q=q->next)
    {
        cout << q->data << " ";
    }
}
void list::del()
{
    
    if(head==NULL){cout << "List empty."<< endl; return;}
    
    int dno;
    cout << endl << "Enter the number to be deleted:";
    cin >> dno;

    //if head node to be deleted and it is a single node
    if(head->data==dno && head->next==head)
    {
        delete head;
        head=NULL;
        tail=NULL;
        cout<<"Node found and deleted"<<endl;           

    }
    //if head node is to be deleted but the list has multiple nodes
    else if(head->data==dno && head->next!=head)
    {
        node*curr=head;
        cout << "head->data:"<<head->data <<endl;
        head=head->next;
        curr->next=NULL;
        delete(curr);
        tail->next=head;
        
        cout<<"Node found and deleted"<<endl;         

    }
    else
    {
        node*curr=head; node*prev=NULL;
        while(curr!=head && curr->data!=dno)
        {
            prev=curr;
            curr=curr->next;
        }
        
        //if key not present in the list
        if(curr == head)
        {
            cout << "Key not present in the list"<< endl;return;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete(curr);
        cout<<"Node found and deleted"<<endl;           


    }

    
     
}
int main()
{
    list l;

    char ans;
    do{
       cout << "MENU:\n 1.INSERT\n 2.DISPLAY\n 3.SEARCH & DELETE\n" << endl;
        int ch;
        cout << endl << "Enter choice:"<<endl;
        cin >> ch; 

    switch(ch)
    {
        case 1:{
            cout << "Insertion Menu:\n 1.Insert from end\n 2.Insert from beginning\n";
            int ch1;
            cout << endl <<"Enter choice:" << endl;
            cin >> ch1;
            switch(ch1)
            {
                case 1:{
                    l.iend();

                }break;
                case 2:{
                    l.ibeg();
                    
                }break;
            }
            
        }
        break;
        case 2:{
            l.display();
        }break;
        case 3:{
            l.del();
        }break;
    }

        
        cout << "Enter main menu?"<<endl;
        cin >> ans;
    }while(ans=='y');
    
    return 0;
}