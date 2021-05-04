//Descending priority queue - Largest priority element deleted first

#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

template<class T>
class node
{
public:
    T data;
    int priority;
    node<T>* next;
    template < class K >
    friend class Priority; 
    node()
    {
        next = NULL;
        priority = -1;
    }
    node(T data, int priority)
    {
        this->data = data;
        this->priority = priority;
        next = NULL;

    }

    bool operator <=(node& obj)
    {
        return (this->priority <= obj.priority);
    }
};

template<class T>
class Priority
{
public:
    node<T>* head;

    Priority()
    {
        head = NULL;
    }

    void addnode(T data, int priority)
    {
        node<T>* add = new node<T>(data, priority);
        if (head == NULL)
        {
            head = add;

        }

        else
        {
            node< T >* current = head;
            node< T >* prev = NULL;
            if (priority > current->priority)   //if priority greater, the add before 
            {
                add->next = current;
                head = add;
            }
            else
            {
                while ((current != NULL) && ((*add) <= (*current)))     //if priority lesser, then add after
                {
                    prev = current;
                    current = current->next;
                }
                add->next = current;
                prev->next = add;
            }

        }
    }


    void pop()
    {
        node < T >* del;
        if (head == NULL)
        {
            cout << "Queue in Underflow...!!!" << endl;
        }
        else
        {
            del = head;
            cout << "Deleted item is =" << del->data << "\n" << endl;
            head = head->next;
            delete del;

        }
    }

    void display()
    {
        node < T >* ptr;
        ptr = head;
        if (head == NULL)
        {
            cout << "Queue is empty...!!!" << endl;
        }
        else
        {
            cout << "               ===Queue ===" << endl;
            cout << endl;
            cout << left << setw(20) << "Priority" << left <<
                setw(20) << "Item" << endl;
            cout << endl;
            while (ptr != NULL)
            {
                cout << left << setw(20) << ptr->priority
                    << left << setw(20) << ptr->data << endl;
                cout << "\n\n";
                ptr = ptr->next;
            }
        }
    }
};

int main()
{
    int choice;
    int data;
    int priority;
    Priority<int> p;
    while (1)
    {
        cout << "1) Insert item\n2) Delete item\n3) Display item\n4) Exit\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter item:";
            cin >> data;
            cout << endl;
            cout << "Enter Priority: ";
            cin >> priority;
            p.addnode(data, priority);
            break;

        case 2:
            p.pop();
            break;

        case 3:
            p.display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Wrong choice entered, try again.\n";
            break;
        }
    }

    return 0;
}