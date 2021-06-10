/*

Height of a tree: no of EDGES in the longest path from the node to a leaf node
Depth of a tree: no of EDGES in path from root to that node

height=max(depth)

*/
#include<bits/stdc++.h>
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
    void inorder(node*root);
    void count_leaf_i(node*root);
    int count_leaf_r(node*root);
    void count_inter_i(node*root);
    int count_inter_r(node*root);
    int height_r(node*root);
    int height_i(node*root);
    void mirror_r(node*root);
    void mirror_i(node*root);
    void deletetree(node*root);
    node* deletenode(node*root,int);
    node* find_min(node*root);





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
void tree::inorder(node*root)
{
    if (root == NULL) {
        
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
void tree::count_leaf_i(node*root)
{
    int count=0;
    if (root == NULL) {
        cout << "Count: 0" << endl;
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
        if(curr->left==NULL && curr->right==NULL){count+=1;}
        //cout << curr->data << " ";

        curr=curr->right;
        

    }
    cout << "Leaf Count:"<< count << endl;

}
int tree::count_leaf_r(node*root)
{
    int count=0;
    if(root == NULL)      
        return 0;  
    if(root->left == NULL && root->right == NULL)  
        return 1;          
    else
        return count_leaf_r(root->left)+  
            count_leaf_r(root->right);  

}
void tree::count_inter_i(node*root)
{
    int count=0;
    if (root == NULL || (root->left==NULL && root->right==NULL)) {
        cout << "Count: 0" << endl;
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
        //cout << curr->data << " ";
        if(curr->left!=NULL || curr->right!=NULL)
        {
            count+=1;
        }
        curr=curr->right;
        

    }
    
    cout << "Intermediate Count:"<< count << endl;
}
int tree::count_inter_r(node*root)
{
    if(root == NULL)      
        return 0;  
    if(root->left == NULL && root->right == NULL)  
        return 0;          
    else
        return count_inter_r(root->left)+count_inter_r(root->right)+1;   //+1 for root
}
int tree::height_r(node*root)
{
    int x=0,y=0;
    if(root==0)
    {return -1;}
    x=height_r(root->left);
    y=height_r(root->right);
    if(x>y)
        return x+1; //+1 for edge connecting that node to root
    else
        return y+1; //+1 for edge connecting that node to root

    
}
int tree::height_i(node*root) //takes no of nodes from root to deepest leaf as height
{
  // Base Case
    if (root == NULL)
        return 0;
 
    // Create an empty queue for level order tarversal
    queue<node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    int height = 0;
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current level.
        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;
 
        height++;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }  
}
void tree::mirror_r(node*root)
{
    /*TC: O(n)*/
    /*After mirroring, BST won't remain a BST. It will just be a normal binary tree.*/
    if (root == NULL)
        return;
    else
    {
        node* temp=NULL;
         
        /* do the subtrees */
        mirror_r(root->left);
        mirror_r(root->right);
     
        /* swap the pointers in this node */
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
void tree::mirror_i(node*root)
{
    /*After mirroring, BST won't remain a BST. It will just be a normal binary tree.*/
    if (root == NULL)
        return;
    
    /*BFS*/
    queue<node*> q;
    q.push(root);
    while (q.empty() == false)
    {
        
        // Print front of queue and remove it from queue
        node *current = q.front();
        q.pop();

       swap(current->left,current->right);
 
        /* Enqueue left child */
        if (current->left != NULL)
            q.push(current->left);
 
        /*Enqueue right child */
        if (current->right != NULL)
            q.push(current->right);
        
    }
}
void tree::deletetree(node*root)  
{  
    if (root == NULL) return;  
  
    
    deletetree(root->left);  
    deletetree(root->right);  
      
    
    cout << "\n Deleting node: " << root->data << endl;
    delete root; 
} 
node*tree::find_min(node*root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node * tree::deletenode(node*root,int ndel)
{
    if(root==NULL)
    {cout << "Element not found" << endl; 
     return NULL;
    }
    if(ndel < root->data)
    {
        root->left=deletenode(root->left,ndel);
        return root;
    }
    if(ndel > root->data)
    {
        root->right=deletenode(root->right,ndel);
        return root;
    }
    //element found
    if(root->left==NULL && root->right==NULL) //leaf node
    {
        delete root;
        root=NULL;
        return root;
    }
    if(root->left==NULL)
    {
        node*temp=root;
        root=root->right;
        delete temp;
        return root;
    }
    
    if(root->right==NULL)
    {
        node*temp=root;
        root=root->left;
        delete temp;
        return root;
    }
    //node with two children
    node*temp=find_min(root->right);
    root->data=temp->data;
    root->right=deletenode(root->right,temp->data);
    return root;

}
int main()
{
    tree t1;
    char ans;
    do
    { 
        cout << endl << "MENU:\n 1.INSERT\n 2.DISPLAY\n 3.COUNT LEAVES(I)\n 4.COUNT LEAVES(R)\n 5.COUNT INTERMEDIATE NODES(I)\n 6.COUNT INTERMEDIATE NODES(R)\n 7.HEIGHT OF TREE(R)\n 8.HEIGHT OF TREE(I)\n 9.MIRROR(R)\n 10.MIRROR(I)\n 11.DELETE ENTIRE TREE\n 12.DELETE ONE NODE \n"<<endl;
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
                t1.inorder(t1.getroot());
            }break;
            case 3:{
               t1.count_leaf_i(t1.getroot()); 
            }break;
            case 4:{
                int cntl=t1.count_leaf_r(t1.getroot());
                cout << "Leaf count:" << cntl << endl;
                
            }break;
            case 5:{
                t1.count_inter_i(t1.getroot());
            }break;
            case 6:{
                int cnt=t1.count_inter_r(t1.getroot());
                cout << "Intermediate count:" << cnt << endl;
            }break;
            case 7:{
                int h=t1.height_r(t1.getroot());
                cout << "Height"<< h << endl;
            }break;
            case 8:{
                int h2=t1.height_i(t1.getroot());
                cout << "Height" << h2 << endl;

            }break;
            case 9:{
                t1.mirror_r(t1.getroot());
            }break;
            case 10:{
                t1.mirror_i(t1.getroot());
                
            }break;
            case 11:{
                t1.deletetree(t1.getroot());
            }break;
            case 12:{
                int ndel;
                cout << "Enter the node to be deleted:"<<endl;
                cin >> ndel;
                t1.deletenode(t1.getroot(),ndel);
            }break;

            default: "Wrong choice!";
            
        }  
        
        
        cout << "Enter menu again?(y/n)" << endl;
        cin >> ans;
    } while (ans=='y');
    
    
    return 0;
}