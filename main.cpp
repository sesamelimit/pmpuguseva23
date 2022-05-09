#include <iostream>
#include <fstream>
#include "TestNode.h"

int main() {
    Node x;
    ifstream(fin);
    fin.open("C:\\Users\\a9599\\CLionProjects\\second_semester\\data.txt");
    fin >> x;
    fin.close();
    Node y;
    fin.open("C:\\Users\\a9599\\CLionProjects\\second_semester\\data2.txt");
    fin >> y;
    fin.close();
    x.add(y);
    cout << x;
    return 0;
}
