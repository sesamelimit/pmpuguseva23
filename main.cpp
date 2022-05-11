#include <iostream>
#include <fstream>
#include "TestNode.h"

int main() {
    LinkedList *A;
    PersonTest x;
    A = new LinkedList();
    ifstream(fin);
    fin.open("C:\\Users\\ultra\\CLionProjects\\PersonTest\\data.txt");
    fin >> *A;
    fin.close();

    fin.open("C:\\Users\\ultra\\CLionProjects\\PersonTest\\data2.txt");
    fin >> x;
    fin.close();
    (*A).add(x);
    cout << *A;
    A=A->mergesort(A);
    cout << "-----------------------" << endl;
    cout << *A;
    return 0;

}
