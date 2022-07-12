
#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"

void printStack(ArrayStack<int>);

int main()
{
    /// ArrayStack testing
    ArrayStack<int> a1; // primary stack
    int n;
    
    std::cout << "\nEnter integers to add to the stack\n";
    std::cout << "----------------------------------\n";
    for(int i=0;i<MAX_STACK;i++)
    {
        std::cout << i+1 << ": ";
        std::cin >> n;
        a1.push(n);
    }
    printStack(a1);

    /// LinkedStack testing
    LinkedStack<int> b1;
    LinkedStack<int> b2;
    LinkedStack<char> b3;

    b1.push(1);
    b1.push(2);
    b2.push(1);
    b2.push(2);

    b1.contains(1);

    if(b1==b2)
        std::cout << "\nb1 and b2 are identical\n";
    else
        std::cout << "\nb1 and b2 are not identical\n";

    b3.push('&');

    //if(b1!=b3)
        //std::cout << "\nb1 and b3 are not equal\n";
    //else
        //std::cout << "\nb1 and b3 are equal\n";

    return 0;

}

/// Added during lab 10/26/21
/** Function to print the contents of a stack */
void printStack(ArrayStack<int> a1)
{
    ArrayStack<int> a2;

    for(int i=0;i<MAX_STACK;i++)
    {
        a2.push(a1.peek());
        a1.pop();
    }

    std::cout << "\nValues in order\n";
    std::cout << "---------------\n";
    for(int i=0;i<MAX_STACK;i++)
    {
        std::cout << i+1 << " = " << a2.peek();
        std::cout << std::endl;
        a1.push(a2.peek());
        a2.pop();
    }
}
