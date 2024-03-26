// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Node.h"
#include "Stack.h"
#include <iostream>

using namespace std;


// Function to check if a character is an operator
bool checkIfOperator(char token) 
{
    if (token == '+' || token == '-' || token == '*' || token == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to check if a character is a digit
bool checkIfDigit(char token) 
{
    if (token >= '0' && token <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}



void convertingToRPN(Stack &output, Stack &operators) 
{  
    char token;
    //cin.get(token);
    while (cin.get(token) && token != '.')
    {
        if (checkIfDigit(token))
        {
            int number = token - '0'; // Convert char to int
            char nextToken;
            while (cin.peek() && checkIfDigit(cin.peek())) 
            {
                cin.get(nextToken);
                number = number * 10 + (nextToken - '0'); // Build multi-digit number
            }
            output.push(number); // Push integer value onto the output stack
            output.push(' '); // Push space after each number
        }
        else if (checkIfOperator(token)) 
        {
            while (!operators.isEmpty() && operators.peek() != '(' && ((token != '*' && token != '/') || (operators.peek() == '+' || operators.peek() == '-'))) 
            {
                output.push(operators.peek()); // Pop operator from the operator stack and push onto the output stack
                operators.pop();
            }
            operators.push(token); // Push current operator onto the operator stack
        }
        else if (token == '(') 
        {
            operators.push(token); // Push '(' onto the operator stack
        }
        else if (token == ')')
        {
            while (!operators.isEmpty() && operators.peek() != '(') 
            {
                output.push(operators.peek()); // Pop operators from the operator stack and push onto the output stack until '(' is encountered
                operators.pop();
            }
            if (!operators.isEmpty() && operators.peek() == '(') 
            {
                operators.pop(); // Pop '('
            }
        }
    }

    // Pop remaining operators from the operator stack and push onto the output stack
    while (!operators.isEmpty()) 
    {
        output.push(operators.peek());
        operators.pop();
    }

    // Print the contents of the output stack
    output.reverse();
    cout << endl;
}







int main()
{
    Stack operators;
    Stack output;
    int amountOfEquations;

    cin >> amountOfEquations;
    for (int i = 0; i < amountOfEquations; i++)
    {
        convertingToRPN(output, operators);
        cout << endl;
    }
    return 0;









    /*for (int i = 0; i < amountOfEquations; i++)
    {
        while (input != '.')
        {
            cin >> noskipws >> input;
            //stack.push(input);
            if (input != '+' && input != '-' && input != '*' && input != '/' && input != '.' && input != ' ')
            {
                output.push(input);
            }
            else if (input == ' ')
            {
                output.push('<');
            }
            else
            {
                stack.push(input);
                /*if (input == '+' || input == '-')
                {
                    if (stack.peek() == '*' || stack.peek() == '/')
                    {
                        output.push(stack.peek());
                        stack.pop();
                        stack.push(input);
                    }
                    else
                    {
                        stack.push(input);
                    }
                }*/
                /*else
                {
                    stack.push(input);
                }
               
            }      
        }
      
    }
    output.reverse();
    cout << endl;
    //stack.takeAllElementsFromStack(&output);
    //output.reverse();
    output.print();
    cout << endl;
    stack.print();*/
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
