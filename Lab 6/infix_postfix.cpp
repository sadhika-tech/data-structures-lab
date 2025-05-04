//Program to implement infix to postfix and postfix evaluation

#include <iostream>
#include <cctype>
#include <cstdlib>
#include "stack.h"

using namespace std;

string infixToPostfix(string infix);
int evaluatePostfix(string postfix);
int precedence(char op);

int main() {
    string infixExpression, postfixExpression;
    int choice;
    
    do {
        //Printing Menu Card
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> infixExpression;
                break;

            case 2:
                if (infixExpression.empty()) {
                    cout << "Please enter an infix expression first.\n";
                } else {
                    postfixExpression = infixToPostfix(infixExpression);
                    cout << "Postfix Expression: " << postfixExpression << endl;
                }
                break;

            case 3:
                if (postfixExpression.empty()) {
                    cout << "Convert an infix expression first.\n";
                } else {
                    cout << "Evaluation Result: " << evaluatePostfix(postfixExpression) << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}

// Function to determine precedence of operators
int precedence(char op) {
    if (op== '=') return 1;
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/'|| op=='%' ) return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack s;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) { 
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isempty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        } else { 
            while (!s.isempty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isempty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack s;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        } else {  
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '%': s.push(val1 % val2); break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Division by zero error!\n";
                        return -1;
                    }
                    s.push(val1 / val2);
                    break;
            }
        }
    }

    return s.pop();
}
