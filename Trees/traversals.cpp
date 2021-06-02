/*
TRAVERSALS:

1.Breadth First Search (BFS): Queue FIFO
2.Depth First Search (DFS): Stack LIFO

*/

#include<bits/stdc++.h>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node*left;
    node*right;
    node()
    {
        left=right=NULL;
    }
    
};
class tree
{
    node *root;
    public:
    tree()
    {
        root=NULL;
    }
    bool isempty()
    {
	    return (root == NULL);
    }
    
    node * getroot()
    {
    return root;
    }
    void insert();
    void level(node*root);
    void inorder_i(node*root);
    void preorder_i(node*root);
    void postorder_i(node*root);
    void inorder_r(node*root);
    void preorder_r(node*root);
    void postorder_r(node*root);

};
void tree::insert()
{
    node*p=new node;
    node*curr=NULL;
    int flag;
    int x;
    cout << "Enter the data to be inserted:"<<endl;
    cin >> x;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    if(isempty())
    {
        root=p;
    }
    else
    {
        curr = root; flag=0;
        do
        {
            if(p->data > curr->data)
            {
                if(curr->right==NULL)
                {
                    curr->right=p;
                    flag=1;
                }
                else
                {
                    curr=curr->right;
                }
            }      
            else if (p->data < curr->data)
            {
                if(curr->left==NULL)
                {
                    curr->left=p;
                    flag=1;
                }
                else
                {
                    curr=curr->left;
                }
            }
            else
            {
                cout << "Duplicated not allowed."<<endl;
                return;
            }
        }while(flag==0);
        
            
        
    }
}

void tree::level(node*root)
{
  /*Time complexity: O(n) ie no of nodes
    Space complexity: best- O(1), worst- O(n)
  */

  
  if (root == NULL)
  {
      cout << "Empty"<< endl;
      return;
  }  
 
    // Create an empty queue for level order traversal
    queue<node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        node *current = q.front();
        cout << current->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (current->left != NULL)
            q.push(current->left);
 
        /*Enqueue right child */
        if (current->right != NULL)
            q.push(current->right);
    }
  
}
void tree::inorder_i(node*root)
{
    
    if (root == NULL)
    {
        cout << "Empty"<< endl;
        return;
    }
    stack<node*> st;
    node*curr=root;
    while(curr!=NULL || st.empty()==false)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        curr=curr->right;
        

    }
}
void tree::preorder_i(node*root)
{
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
void tree::postorder_i(node*root)
{
    if (root == NULL)
        return;
  
    // Create two stacks
    stack<node*> s1, s2;
  
    // push root to first stack
    s1.push(root);
    node* Node;
  
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        Node = s1.top();
        s1.pop();
        s2.push(Node);
  
        // Push left and right children
        // of removed item to s1
        if (Node->left)
            s1.push(Node->left);
        if (Node->right)
            s1.push(Node->right);
    }
  
    // Print all elements of second stack
    while (!s2.empty()) {
        Node = s2.top();
        s2.pop();
        cout << Node->data << " ";
    }
}
void tree::inorder_r(node*root)
{
    if (root == NULL) {
        return;
    }
    inorder_r(root->left);
    cout << root->data << " ";
    inorder_r(root->right);

}
void tree::preorder_r(node*root)
{
     if (root == NULL) {
        
        return;
    }
    cout << root->data << " ";
    preorder_r(root->left);
    preorder_r(root->right);

}
void tree::postorder_r(node*root)
{
     if (root == NULL) {
        
        return;
    }
    postorder_r(root->left);
    postorder_r(root->right);
    cout << root->data << " ";

}


int main()
{
    tree t1;
    char ans;
    do
    {
        cout << endl << "MENU:\n 1.INSERT\n 2.LEVEL ORDER TRAVERSAL\n 3.DFS-INORDER Iterative\n 4.DFS-PREORDER Iterative\n 5.DFS-POSTORDER Iterative\n 6.DFS-INORDER Recursive\n 7.DFS-PREORDER Recursive\n 8.DFS-POSTORDER Recursive\n"<<endl;
        int choice;
        cout << "Enter choice:"<<endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                t1.insert();
            }break;
            case 2:
            {
               t1.level(t1.getroot());
            }break;
            case 3:
            {
                t1.inorder_i(t1.getroot());
            }break;
            case 4:{
                t1.preorder_i(t1.getroot());
            }break;
            case 5:{
                t1.postorder_i(t1.getroot());
            }break;
            case 6:{
                t1.inorder_r(t1.getroot());               
            }break;
            case 7:{
                t1.preorder_r(t1.getroot());
            }break;
            case 8:{
                t1.postorder_r(t1.getroot());
            }break;
            default: "Wrong choice!";
            
        }  
        
        
        cout << "Enter menu again?(y/n)" << endl;
        cin >> ans;
    } while (ans=='y');
    
    
    return 0;
}