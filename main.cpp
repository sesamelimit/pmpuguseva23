#include <iostream>
#include <fstream>
#include "TestNode.h"

int main() {
    Node x;
    ifstream(fin);
    fin.open("C:\\Users\\a9599\\CLionProjects\\PersonTest\\data.txt");
    fin >> x;
    fin.close();
    cout << x;
    return 0;
}
