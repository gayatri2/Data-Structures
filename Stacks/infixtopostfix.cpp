
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
}*top = NULL;

void push(char x)
{
	struct Node* t;
	t = new Node;
	if (t == NULL)
	{
		cout << "Stack overflow";
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}
int pop()
{
	struct Node* p;
	int x = -1;
	if (top == NULL)
	{
		cout << "Stack underflow";
	}
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		delete p;

	}
	return x;

}

int precedence(char x)
{
	if (x == '+' || x == '-')					
		return 1;
	else if (x == '*' || x == '/')				
		return 2;
	else										
		return 0;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')		
		return 0;
	else													
		return 1;
}


char* InfixToPostfix(char* infix)
{
	int i = 0; int  j = 0;
	char* postfix;												
	int len = strlen(infix);									
	postfix = (char*)malloc((len + 1) * sizeof(char));			

	while (infix[i] != '\0')										
	{
		if (isOperand(infix[i]))									
			postfix[j++] = infix[i++];							
		else
		{
			if (precedence(infix[i]) > precedence(top->data))	
				push(infix[i++]);								
			else															
			{
                while (precedence(infix[i]) <= precedence(top->data))
                {
                    postfix[j++] = pop();
                }
                							
			}
		}
	}

	
	while (top->data != '#')
	{
		postfix[j++] = pop();
	}
										
	postfix[j] = '\0';										
	return postfix;                                         
}

int main()
{
	char infix[50];
	cout << "Enter the string:" << endl;
	cin >> infix;
	 						     
	push('#');												

	char* postfix = InfixToPostfix(infix);					

	cout << postfix;
	return 0;
}
