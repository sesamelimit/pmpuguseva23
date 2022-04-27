#include <iostream>
#include "TestBase.h"
using namespace std;


int main()
{
    Node* one;
    Node* two; 
    Node* three;

    one = new Node();
    two = new Node();
    three = new Node();

    one->data = 1;
    one->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    three->next = nullptr;

    Node* current;
    current = one;
    while (current != nullptr)
    {
        cout << current->data << "\n";
        current = current->next;
    }
    return 0;
};

