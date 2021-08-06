//THREADED      //right threaded is enough for doing inorder and pre order traversal. But use left thread to do post order.

#include<iostream>
using namespace std;
class node
{
    public:
    node*left;
    node*right;
    int data;
    bool rflag;
    bool lflag;
    node()
    {
        left=right=NULL;
        data=0;
        rflag=0;
        lflag=0;
    }
};
class threadedt
{
    node*root;
    public:
    threadedt()
    {
        root=NULL;
    }
    node*getroot()
    {
        return root;
    }
    void create();
    void inorder(node*root);
    void preorder(node*root);
    void adelete(node*,node*,char x);
    void dummydel(char x)
    {

        adelete(root,root,x);
        return;
    }

   
};
void threadedt::create()
{
    
    int x;
    cout << "Enter data to be inserted:"<<endl;
    cin >> x;
    node*p=new node;
    p->left=NULL;
    p->right=NULL;
    p->data=x;
    if(root==NULL)
    {
        root=p;
    }
    else
    {
        node*q=root; bool flag=0;
        do
        {
            if(p->data < q->data)
            {
                if(q->lflag==1) //left thread 
                {
                    p->lflag=1;
                    p->left=q->left;
                    q->lflag=0;
                    q->left=p;
                    p->right=q;
                    p->rflag=1;
                    flag=1;
                    
                }
                
                else if(q->left == NULL)
                {
                    q->left=p;
                    p->right=q;
                    p->rflag=1;
                    flag=1;
                }
                else 
                {
                    q=q->left;
                }
            }
            else if(p->data > q->data)
            {
                if(q->rflag==1) //right thread
                {
                    p->rflag=1;
                    p->right=q->right;
                    q->rflag=0;
                    q->right=p;
                    p->left=q; //
                    p->lflag=1; // 
                    flag=1;
                }
                else if(q->right == NULL)   //normal link, not a thread
                {
                    q->right=p;
                    p->left=q; //
                    p->lflag=1; //
                    flag=1;
                }
                else
                {
                    q=q->right;
                }
            }
            else
            {
                cout << "Duplicate element:"<<endl;
                flag=1;
            }
        
        }while(flag==0);


    }
}
void threadedt::inorder(node*root)
{
   node*q=root;
   while(q!=NULL)
   {
       while(q->left!=NULL && q->lflag!=1)
       {
           q=q->left;
       }
       cout << q->data << " ";
       while(q->rflag==1)
       {
           q=q->right;
           cout << q->data << " ";
   
       }
       q=q->right;
           
   }
    
}
void threadedt::preorder(node*root)
{
    node*q=root;
    while(q!=NULL)
    {
        cout << q->data << " ";
        while(q->left!=NULL && q->lflag!=1)
        {
            q=q->left;
            cout << q->data << " ";
        }
        while(q->rflag==1)
        {
            q=q->right;
        }
        q=q->right;
    }
}
void threadedt::adelete(node* q,node* par,char x)
{

    node* r;
    if(q==NULL){
        cout<<"No such node exists, cannot be deleted"<<endl;
        return;
    }
    if(x<q->data){
        adelete(q->left,q,x);
    }
    else if(x>q->data){
        adelete(q->right,q,x);
    }
    else{
           // cout<<"Element to be deleted is found"<<endl;


    if((q->left==NULL && q->rflag==1)||(q->right==NULL &&q->lflag==1)) //leftmost or rightmost node
    {
        if(par->left==q)
        {
            par->left=NULL;
        }
        else
        {
            par->right=NULL;
        }
        q=NULL;
        delete q;
        return;
    }


    else if((q->rflag==1) &&(q->lflag==1))  //contains both threads
    {
        if(q==par->left)
        {
            par->lflag=1;
            par->left=q->left;
        }
        else
        {
            par->rflag=1;
            par->right=q->right;

        }
        q=NULL;
        delete q;
        return;
    }
    else if(q->rflag==1 || q->right==NULL)  //left child present
    {
       r=q->left;
       while(r->rflag!=1)
       {
           r=r->right;
       }
       q->data=r->data;
       adelete(q->left,q,r->data);
       return;
    }
    else    //right child present
    {
        r=q->right;
        while(r->lflag!=1)
        {
            r=r->left;

        }
        q->data=r->data;
        adelete(q->right,q,r->data);
        return;
    }
}
}
int main()
{
    
    threadedt t;
    char ans;
    do
    {
        cout << endl << "MENU:\n 1.INSERT\n 2.INORDER DISPLAY\n 3.PREORDER DISPLAY 4.DELETE";
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                t.create();
            }break;
            case 2:
            {
                t.inorder(t.getroot());                
            }break;
            case 3:
            {
                t.preorder(t.getroot());
            }break;
            case 4:{
                int x;
                cout << "Enter the data to be deleted:" << endl;
                cin >> x;
                t.dummydel(x);
                cout<<"Deleted successfully!"<<endl;

            }
            
            
        }  
        
        
        cout << "Enter menu again?(y/n)" << endl;
        cin >> ans;
    } while (ans=='y');
    

    return 0;
}