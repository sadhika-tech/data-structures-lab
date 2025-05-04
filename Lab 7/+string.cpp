#include <iostream>
#include "stack.h"

using namespace std;

string process_string(const string& input) 
{
    stack s; 
    
    for (char ch : input) 
    {
        if (ch == '+') 
        {
            if (!s.isempty()) 
            {
                s.pop();
            }
        } 
        else 
        {
            s.push(ch);
        }
    }

    string result;
    while (!s.isempty()) 
    {
        result = s.pop() + result; 
    }

    return result;
}

int main() 
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = process_string(input);
    cout << "Processed string: " << output << endl;

    return 0;
}
