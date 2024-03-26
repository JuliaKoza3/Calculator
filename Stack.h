// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>

//template<typename T>
class Stack
{
    Node* top;
public:
    Stack()
    {
        top = NULL;
    }
    void push(char data) //add node on top of the stack
    {
        Node* temp = new Node(data);

        if (!temp)
        {
            cout << "Stack is full";
            return;
        }

        temp->data = data;
        temp->next = top;
        top = temp;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    char peek()  // return the top node from the stack
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            exit(1);
        }
    }
    void pop() //delet a node from the top of the stack
    {
        Node* temp;
        if (top == NULL)
        {
            cout << "There is no element on top";
            return;
        }
        else
        {
            temp = top;
            top = top->next;
            free(temp);
        }
    }
    void print()  //prints all the elemnets from the stack
    {
        Node* temp;

        if (top == NULL)
        {
            cout << "There is no element on top";
            return;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                if (temp->data == ' ') {
                    cout << " ";
                }
                else {
                    cout << temp->data;
                }
                /*temp = temp->next;
                cout << temp->data;
                temp = temp->next;
                if (temp != NULL)
                {
                    cout << " ";
                }*/

            }
        }
    }

    void reverse()
    {
        if (top == NULL) {
            return;
        }
        printReverse(top);

    }

    void printReverse(Node* node) 
    {
        if (node == NULL) {
            return;
        }
        printReverse(node->next);
        cout << node->data<< " ";
    }

    void takeAllElementsFromStack(Stack* outputStack)
    {
        Node* temp;

        if (top == NULL)
        {
            cout << "There is no element on top";
            return;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                outputStack->push(temp->data);
                temp = temp->next;

            }
        }
    }
    
};

#endif

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
