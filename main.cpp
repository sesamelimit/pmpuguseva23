#include <iostream>
#include <fstream>
#include "TestNode.h"

int main() {
    LinkedList *A;
    A = new LinkedList();
    ifstream(fin);
    fin.open("C:\\Users\\a9599\\CLionProjects\\PersonTest\\data.txt");
    fin >> *A;
    fin.close();
    cout << *A;
    return 0;
}
