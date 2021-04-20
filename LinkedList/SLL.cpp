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
    node*q;
    public:
    list()
    {
        head=NULL;
        tail=NULL;
        p=NULL;
        q=NULL;
    }
    int getno()
    {
        int no;
        cout << endl << "Enter the number:";
        cin >> no;
        return no;
    }
    void iend();
    void ibeg();
    int countnodes();
    void iany();
    void display();
    void del();
    void reverse();
};
    void list::iend()
    {
        if(head==NULL)
        {
            head=new node;
            head->data=getno();
            head->next=NULL;
            tail=head;
        }
        else
        {
            p=new node;
            p->data=getno();
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
    }
    void list::ibeg()
    {
       if(head==NULL)
        {
            head=new node;
            head->data=getno();
            head->next=NULL;
            tail=head;
        }
        else
        {
            p=new node;
            p->data=getno();
            p->next=head;
            head=p;
        } 
    }
    int list::countnodes()
    {
        int count=0;
        q=head;
        while(q!=NULL)
        {
            count+=1;
            q=q->next;
        }
        return count;
    }
    void list::iany()
    {
        int loc;
        cout << "Enter the location at which the node is to be inserted:"<<endl;
        cin >> loc;
        int ans1=countnodes();
        if(ans1 < loc)
        {
            cout << "Location greater than total nodes:"<<endl;
            return;
        }   
        if(loc==1 && head==NULL)
        {
            p=new node;
            p->data=getno();
            p->next=NULL;
            head=tail=p;
        }
        else if(loc==1 && head!=NULL)
        {
            p=new node;
            p->data=getno();
            p->next=head;
            head=p;
        }
        else{
            q=head;
            for(int i=1;i<loc-1;i++)
            {
                q=q->next;
            }
            p=new node;
            p->data=getno();
            p->next=q->next;
            q->next=p;
            
        }
    }
    void list::display()
    {
        q=head;
        if(head==NULL)
        {
            cout << "List is empty"<<endl;
            return;
        }
        else{
            while(q!=NULL)
            {
                cout << q->data << " ";
                q=q->next;
            }
        }
        
    }
    void list::del()
    {
         q=head;
        node*prev=NULL;
        
        int dno;
        cout << endl << "Enter the number to be deleted:";
        cin >> dno;
          

        if(q != NULL && q->data == dno) //if head node is to be deleted
        {
            head=q->next; 
            q->next=NULL;
            delete q; 
            cout<<"Node found and deleted"<<endl;           
            return;
        }
        else
        {
            while (q != NULL && q->data != dno)
            {
                prev = q;
                q = q->next;
            }   
 
            // If key was not present in linked list
            if (q == NULL)
            {
                cout << "Key not present in the list"<< endl; return;
            }
            
 
            // Unlink the node from linked list
            prev->next = q->next;
            q->next=NULL;
 
            // Free memory
            delete q;
            cout<<"Node found and deleted"<<endl;           

        }
        
    }
    void list::reverse()
    {
        node*current=head; node*prev=NULL;node*nn=NULL;
        if(current==NULL)
        {
            cout << "List is empty"<<endl;
            return;
        }
        while(current!=NULL)
        {
            nn=current->next;
            current->next=prev;
            prev=current;
            current=nn;
        }
        head=prev;

    }
int main()
{
    list l;
    
    
    char ans;
    do{
       cout << "MENU:\n 1.INSERT\n 2.DISPLAY\n 3.SEARCH & DELETE\n 4.COUNT THE NUMBER OF NODES\n 5.REVERSE LIST" << endl;
        int ch;
        cout << endl << "Enter choice:"<<endl;
        cin >> ch; 

        switch(ch)
    {
        case 1:{
            cout << "Insertion Menu:\n 1.Insert from end\n 2.Insert from beginning\n 3.Insert in the specified postition\n"<<endl;
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
                case 3:{
                    
                    l.iany();
                break;}
            }
            
        }
        break;
        case 2:{
            l.display();
        }break;
        case 3:{
            l.del();
        }break;
        case 4:{
            int ans=l.countnodes();
            cout << "The number of nodes in this list is:"<< ans << endl;
        }break;
        case 5:{
            l.reverse();
        }
        
    }

        
        cout << "Enter main menu?"<<endl;
        cin >> ans;
    }while(ans=='y');
    
    return 0;
}
