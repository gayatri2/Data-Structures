#include<iostream>
using namespace std;
class node{
    public:

    int data;
    node*next;
    node*prev;
    node()
    {
        data=0;
        next=NULL;
        prev=NULL;
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
    void iany();
    int countnodes();
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
            head->prev=NULL;
            head->next=NULL;
            tail=head;
        }
        else
        {
            p=new node;
            p->data=getno();
            p->next=NULL;
            p->prev=tail;
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
            head->prev=NULL;
            head->next=NULL;
            tail=head;
        }
        else
        {
            p=new node;
            p->data=getno();
            p->prev=NULL;
            p->next=head;
            head->prev=p;
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
       
        if(loc==1 && head==NULL)
        {
            p=new node;
            p->data=getno();
            p->prev=NULL;
            p->next=NULL;
            head=tail=p;
        }
        else if(loc==1 && head!=NULL)
        {
            p=new node;
            p->data=getno();
            p->next=head;
            head->prev=p;
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
            q->next->prev=p;
            q->next=p;
            p->prev=q;
            
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
        int dno;
        cout << endl << "Enter the number to be deleted:";
        cin >> dno;
        
        q=head;
        node*pr=NULL;
  

        if(q != NULL && q->data == dno) //if head node is to be deleted
        {
            head=q->next; 
            q->next=NULL;
            head->prev=NULL;
            delete q;            
            return;
        }
        else
        {
            while (q != NULL && q->data != dno)
            {
                pr = q;
                q = q->next;
            }   
 
            // If key was not present in linked list
            if (q == NULL)
                return;
 
            // Unlink the node from linked list
            pr->next = q->next;
            q->next->prev=pr;
            q->next=NULL;
            q->prev=NULL;
 
            // Free memory
            delete q;
        }
        
    }
    void list::reverse()
    {
        node*current=head; node*sprev=NULL;node*snext=NULL;
        if(current==NULL)
        {
            cout << "List is empty"<<endl;
            return;
        }
        while(current!=NULL)
        {
            snext=current->next;
            current->prev=current->next;
            current->next=sprev;
            sprev=current;
            current=snext;
        }
        head=sprev;

    }
int main()
{
    list l;
    
    
    char ans;
    do{
       cout << "MENU:\n 1.INSERT\n 2.DISPLAY\n 3.SEARCH & DELETE\n 4.COUNT NODES\n 5.REVERSE LIST" << endl;
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
                }
                break;
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
            cout << "Total number of nodes:" << ans;
        }break;
        case 5:{
            l.reverse();
        }break;
        
    }

        
        cout << "Enter main menu?"<<endl;
        cin >> ans;
    }while(ans=='y');
    
    return 0;
}
