// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
    Node<T>* top;
public:
    Stack()
    {
        top = NULL;
    }
    void push(T data) //add node on top of the stack
    {
        Node<T>* temp = new Node<T>(data);

        if (!temp)
        {
            cout << "memory allocation failed";
            return;
        }

        temp->data = data;
        temp->next = top;
        if (top != NULL)
        {
            top->prev = temp;
        }
        top = temp;
    }

    void addOnBottom(T data) //add node on bottom of the stack
    {
        Node<T>* temp = new Node<T>(data);

        if (!temp)
        {
            cout << "memeory alloaction failed";
        }

        //if stack is empty
        if (!top)
        {
            top = temp;
            return;
        }

        //initialize current pointer to the adress stored in the top one
        //goes before the top
        Node<T>* current = top;

        //look for last node, moving current to the next pointer 
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;

    }

    void addSomewhereInside(Node<T>* existingNode, char data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (existingNode == nullptr || newNode == nullptr) 
        {
            cout << "Cannot push a null node onto the stack!" << endl;
            return;
        }

        if (top == nullptr) {
            cout << "Stack is empty, cannot insert after a node!" << endl;
            return;
        }

        newNode->next = existingNode->next;
        if (existingNode->next != nullptr) {
            existingNode->next->prev = newNode;
        }
        existingNode->next = newNode;
        newNode->prev = existingNode;

        if (existingNode == top) {
            top = newNode;
        }

    }

    bool isEmpty() //check if stack if empty
    {
        return top == NULL;
    }

    T peek()  // return the top node from the stack
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

    T getLastNodeData() 
    {
        // Check if the list is empty
        if (top == NULL) {
            // Return some default value to indicate an empty list
            return -1; // Assuming -1 is not a valid data value
        }

        // Traverse to the last node in the list
        while (top->next != NULL) {
            top = top->next;
        }

        // Return the data of the last node
        return top->data;
    }

    Node<T>* getTopNode()
    {
        if (!isEmpty())
        {
            return top;
        }
        else
        {
            exit(1);
        }
    }

    void pop() //delet a node from the top of the stack
    {
        Node<T>* temp;
        if (top == NULL)
        {
            cout << "There is no element on top";
            return;
        }
        else
        {
            temp = top;
            top = top->next;
            if (top != NULL)
            {
                top->prev = NULL;
            }
            delete temp;
        }
    }

    void deleteLastNode()
    {
        if (top == nullptr) {
            cerr << "Stack is empty, no nodes to delete!" << endl;
            return;
        }

        if (top->next == nullptr) {
            delete top;
            top = nullptr;
            return;
        }

        Node<T>* current = top;
        while (current->next != nullptr) {
            current = current->next;
        }

        // At this point, current is pointing to the last node
        current->prev->next = nullptr;
        delete current;
    }

    void deleteNode(Node<T>* nodeToDelete) 
    {
        if (top == NULL || nodeToDelete == NULL)
            return;

        // If node to be deleted is head node
        if (top == nodeToDelete)
            top = nodeToDelete->next;

        // Change next only if node to be deleted is NOT the last node
        if (nodeToDelete->next != NULL)
            nodeToDelete->next->prev = nodeToDelete->prev;

        // Change prev only if node to be deleted is NOT the first node
        if (nodeToDelete->prev != NULL)
            nodeToDelete->prev->next = nodeToDelete->next;

        // Finally, delete the node
        delete nodeToDelete;
    }




    void print(Node<T>* node) //print in correct order from first in to last in 
    {
        if (node == NULL) {
            return;
        }
        if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/' || node->data == 'N')
        {
            cout << node->data << ' ';
        }
        else
        {
            cout << node->data;
        }
        print(node->next);
    }

    void printForward()
    {
        if (top == NULL) 
        {
            return;
        }
        print(top);
    }

    void reverse()
    {
        if (top == NULL) {
            return;
        }
        printReverse(top);

    }

    void printReverse(Node<T>* node) //print in reverse order from first in to last in 
    {
        if (node == NULL) {
            return;
        }
        printReverse(node->next);
        if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/')
        {
            cout << node->data << ' ';
        }
        else
        {
            cout << node->data;
        }
    }


    void printWithSpaces(Node<T>* node) //print in correct order from first in to last in 
    {
        if (node == NULL) {
            return;
        }

        cout << node->data << ' ';
        
        printWithSpaces(node->next);
    }

    void printNumbers()
    {
        if (top == NULL)
        {
            return;
        }
        printWithSpaces(top);
    }
    

    

    void takeAllElementsFromStack(Stack<T>* outputStack) 
    {
        Node<T>* temp;

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
