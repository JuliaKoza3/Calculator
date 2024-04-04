// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Node.h"
#include "Stack.h"
#include <iostream>
#include <cctype>

using namespace std;


// Function to check if a character is an operator
bool checkIfOperator(char token)
{
    if (token == '+' || token == '-' || token == '*' || token == '/' || token == '(' || token == ')' || token == 'N' || token == 'F'|| token == ',' || token == 'X' || token == 'M' || token == '<')
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


void addNumbersToStack(char token, Stack<char> &output, Stack<int> &numbers)
{
    output.addOnBottom(token); // Push digit onto the output stack

    char nextChar;
    while (cin.peek() && checkIfDigit(cin.peek())) {
        cin.get(nextChar);
        output.addOnBottom(nextChar); // Push consecutive digits onto the output stack
    }
    output.addOnBottom(' '); // Push space after each number
}

void addIfSign(char token, Stack<char>& output, Stack<char>& temp)
{
    while (!temp.isEmpty() && (temp.peek() == 'F' || temp.peek() == 'X' || temp.peek() == '<'))
    {
        if (temp.peek() == 'F')
        {
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == 'X')
        {
            output.addOnBottom('M');
            output.addOnBottom('A');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == '<')
        {
            output.addOnBottom('M');
            output.addOnBottom('I');
            output.addOnBottom('N');
            temp.pop();

        }
        else
        {
            output.addOnBottom(temp.peek());
            temp.pop();
        }

    }
    temp.push(token);
}

void addNegativeSign(char token, Stack<char>& output, Stack<char>& temp)
{
    while (!temp.isEmpty() && (temp.peek() == 'F' || temp.peek() == 'X' || temp.peek() == '<'))
    {
        if (temp.peek() == 'F')
        {
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == 'X')
        {
            output.addOnBottom('M');
            output.addOnBottom('A');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == '<')
        {
            output.addOnBottom('M');
            output.addOnBottom('I');
            output.addOnBottom('N');
            temp.pop();

        }
        else
        {
            output.addOnBottom(temp.peek());
            temp.pop();

        }
    }
    temp.push(token);

}

void addMultiplicationAndDivisionSign(char token, Stack<char>& output, Stack<char>& temp)
{
    while (!temp.isEmpty() && (temp.peek() == '*' || temp.peek() == '/' || temp.peek() == 'N' || temp.peek() == 'F' || temp.peek() == 'X' || temp.peek() == '<'))
    {
        if (temp.peek() == 'F')
        {
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == 'X')
        {
            output.addOnBottom('M');
            output.addOnBottom('A');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == '<')
        {
            output.addOnBottom('M');
            output.addOnBottom('I');
            output.addOnBottom('N');
            temp.pop();

        }
        else
        {
            output.addOnBottom(temp.peek());
            temp.pop();
        }
    }
    temp.push(token);
}


void addAdditionAndSubtractionSign(char token, Stack<char>& output, Stack<char>& temp)
{
    while (!temp.isEmpty() && (temp.peek() == '*' || temp.peek() == '/' || temp.peek() == '+' || temp.peek() == '-' || temp.peek() == 'N' || temp.peek() == 'F' || temp.peek() == 'X' || temp.peek() == '<'))
    {
        if (temp.peek() == 'F')
        {
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == 'X')
        {
            output.addOnBottom('M');
            output.addOnBottom('A');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == '<')
        {
            output.addOnBottom('M');
            output.addOnBottom('I');
            output.addOnBottom('N');
            temp.pop();

        }
        else
        {
            output.addOnBottom(temp.peek());
            temp.pop();
        }
    }
    temp.push(token);
}

void takeElementsFromParentheses(Stack<char>& output, Stack<char>& temp)
{
    int comas = 0;
    while (!temp.isEmpty() && temp.peek() != '(')
    {
        
        if (temp.peek() == 'F')
        {
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == ',')
        {
            comas++;
            temp.pop();
        }
        else if (temp.peek() == 'X')
        {
            output.addOnBottom('M');
            output.addOnBottom('A');
            output.addOnBottom(temp.peek());
            temp.pop();
        }
        else if (temp.peek() == '<')
        {
            output.addOnBottom('M');
            output.addOnBottom('I');
            output.addOnBottom('N');
            temp.pop();

        }
        else
        {
            output.addOnBottom(temp.peek());
            temp.pop();
        }
    }
    if (temp.peek() == '(')
    {
        if (temp.oneBeforePeek() == 'F' )
        {
            temp.pop();
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
        }
        else if (temp.oneBeforePeek() == 'N')
        {
            temp.pop();
            output.addOnBottom(temp.peek());
        }
        else if (temp.oneBeforePeek() == 'X')
        {
            temp.pop();
            output.addOnBottom('M');
            output.addOnBottom('A');
            output.addOnBottom(temp.peek());
            char amountOfComas = (comas+1) + '0';
            output.addOnBottom(amountOfComas);
            output.addOnBottom(' ');

        }
        else if (temp.oneBeforePeek() == '<')
        {
            temp.pop();
            output.addOnBottom('M');
            output.addOnBottom('I');
            output.addOnBottom('N');
            char amountOfComas = (comas + 1) + '0';
            output.addOnBottom(amountOfComas);
            output.addOnBottom(' ');
        }        

    }
    temp.pop();

}


void addOperationsToStack(char token, Stack<char>& output, Stack<char>& temp, Stack<char>& operators)
{
    if ((temp.isEmpty() || token == '(') && token !='M')
    {
        temp.push(token);
        operators.push(token);
    }
    else
    {
        if (token == 'X')
        {
            while (!temp.isEmpty() && temp.peek() == 'X')
            {
                if (temp.peek() == 'X')
                {
                    output.addOnBottom('M');
                    output.addOnBottom('A');
                    output.addOnBottom(temp.peek());
                    temp.pop();

                }
                else
                {
                    output.addOnBottom(temp.peek());
                    temp.pop();
                }
        
            }
            temp.push(token);
            operators.push(token);
        }
        else if (token == 'M')
        {
            char nextChar;
            if(cin.peek() == 'I')
            {
                cin.get(nextChar);
                operators.push(nextChar);
                while (!temp.isEmpty() && temp.peek() == '<')
                {
                    if (temp.peek() == '<')
                    {
                        output.addOnBottom('M');
                        output.addOnBottom('I');
                        output.addOnBottom('N');
                        temp.pop();

                    }
                    else
                    {
                        output.addOnBottom(temp.peek());
                        temp.pop();
                    }

                }
                temp.push('<');
                
            }
        }
        else if (token == 'F')
        {
            addIfSign(token, output, temp);
            operators.push(token);
        }
        else if (token == 'N' && operators.peek() != 'I')
        {
            addNegativeSign(token, output, temp);
            operators.push(token);
        }
        else if (token == '*' || token == '/')
        {
            addMultiplicationAndDivisionSign(token, output, temp);  
            operators.push(token);
        }
        else if (token == '+' || token == '-')
        {
            addAdditionAndSubtractionSign(token, output, temp);
            operators.push(token);
        }
        else if (token == ')')
        {
            takeElementsFromParentheses(output, temp);
            operators.push(token);
        }
    }

}


void convertingToRPN(Stack<char>& output, Stack<char>& operators, Stack<int>& numbers, Stack<char>& temp)
{
    char token;
    bool insideOperand = false;
    while (cin.get(token) && token != '.')
    {
        if (checkIfDigit(token))
        {
            addNumbersToStack(token, output, numbers);
            insideOperand = true;
        }
        else if (checkIfOperator(token))
        {
            if (token == ',') // Handle comma separately
            {
                if (!insideOperand) {
                    // Ignore comma if it appears outside of an operand
                    continue;
                }
                if (!temp.isEmpty() && (temp.peek() == '*' || temp.peek() == '/' || temp.peek() == '+' || temp.peek() == '-' || temp.peek() == 'N'))
                {
                    while (!temp.isEmpty() && (temp.peek() == '*' || temp.peek() == '/' || temp.peek() == '+' || temp.peek() == '-' || temp.peek() == 'N'))
                    {
                        output.addOnBottom(temp.peek());
                        temp.pop();// Add space to separate operands
                    }
                }
                temp.push(token);
            }
            else
            {
                addOperationsToStack(token, output, temp, operators);
            }

            //addOperationsToStack(token, output, temp);
            //insideOperand = true;
        }
    }

    // Pop remaining operators from the operator stack and push onto the output stack
    while (!temp.isEmpty())
    {
       if (temp.peek() == 'F')
       {
            output.addOnBottom('I');
            output.addOnBottom(temp.peek());
            temp.pop();
       }
       else if (temp.peek() == '<')
       {
           output.addOnBottom('M');
           output.addOnBottom('I');
           output.addOnBottom('N');
           temp.pop();

       }
       else
       {
           output.addOnBottom(temp.peek());
           temp.pop();
       }
    }

    output.printForward();
    cout << endl;
}

void printSteps(char symbol, Stack<int>& numbers)
{
    cout << symbol <<' ';
    numbers.printNumbers();
    cout << endl;
}

void ifFunction(Stack<int>& numbers, char symbol)
{
    cout << 'I';
    printSteps(symbol, numbers);

    int thirdNumber = numbers.peek();
    numbers.pop();
    int secondNumber = numbers.peek();
    numbers.pop();
    int firstNumber = numbers.peek();
    numbers.pop();

    int result = 0;

    if (firstNumber > 0)
    {
        result = secondNumber;
    }
    else
    {
        result = thirdNumber;
    }
    numbers.push(result);
}

void negative(Stack<int>& numbers, char symbol)
{
    printSteps(symbol, numbers);
    int firstNumber = numbers.peek();
    numbers.pop();

    int result = - firstNumber;
    numbers.push(result);

}

bool division(Stack<int>& numbers, char symbol)
{
    printSteps(symbol, numbers);

    int secondNumber = numbers.peek();
    numbers.pop();
    if (secondNumber == 0)
    {
        cout << "ERROR";
        return false;
    }
    int fisrtNumber = numbers.peek();
    numbers.pop();

    int result = fisrtNumber / secondNumber;
    numbers.push(result);
    return true;
}

void multiplication(Stack<int>& numbers, char symbol)
{
    printSteps(symbol, numbers);

    int secondNumber = numbers.peek();
    numbers.pop();
    int fisrtNumber = numbers.peek();
    numbers.pop();

    int result = fisrtNumber * secondNumber;
    numbers.push(result);
}

void substraction(Stack<int>& numbers, char symbol)
{
    printSteps(symbol, numbers);

    int secondNumber = numbers.peek();
    numbers.pop();
    int fisrtNumber = numbers.peek();
    numbers.pop();

    int result = fisrtNumber - secondNumber;
    numbers.push(result);
}

void addition(Stack<int>& numbers, char symbol)
{
    printSteps(symbol, numbers);

    int secondNumber = numbers.peek();
    numbers.pop();
    int fisrtNumber = numbers.peek();
    numbers.pop();

    int result = fisrtNumber + secondNumber;
    numbers.push(result);
}

bool calculations(char symbol, Stack<int>& numbers)
{
    switch (symbol)
    {
    case '+':
        addition(numbers, '+');
        break;
    case '-':
        substraction(numbers, '-');
        break;
    case '*':
        multiplication(numbers, '*');
        break;
    case '/':
        if (!division(numbers, '/'))
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 'N':
        negative(numbers, 'N');
        break;
    case 'F' :
        ifFunction(numbers, 'F');
        break;
    }
    return true;
}


void check(Node<char>* node, Stack<char>& output, Stack<int> numbers)
{
    if (node == NULL)
    {
        numbers.printNumbers();
        numbers.pop();
        return;
    }
    if (checkIfDigit(node->data))
    {
        int number = node->data - '0'; // Convert char to int
        numbers.push(number);
        while (checkIfDigit(node->next->data))
        {
            int number1 = node->next->data - '0';
            number = number * 10 + number1;
            numbers.pop();
            numbers.push(number);
            node = node->next;           
        }        
    }
    else
    {
        if (!calculations(node->data, numbers))
        {
            return;
        }
    }
    check(node->next, output, numbers);
}

void lookForOperator(Stack<char>& output, Stack<int> numbers)
{
    Node<char>* topOutput;
    topOutput = output.getTopNode();
    if (topOutput== NULL)
    {
        numbers.printNumbers();
        return;
    }
    check(topOutput, output, numbers);
}


int main()
{
    Stack<char> operators;
    Stack<char> output;
    Stack<int> numbers;
    Stack<char> temp;
    int amountOfEquations;

    cin >> amountOfEquations;
    for (int i = 0; i < amountOfEquations; i++)
    {
        
        convertingToRPN(output, operators, numbers, temp);
        lookForOperator(output, numbers);
        while (!output.isEmpty())
        {
            output.pop();
        }
        cout << endl;
        
    }
    return 0;

    
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
