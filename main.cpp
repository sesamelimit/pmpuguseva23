#include <iostream>
#include <fstream>
#include "TestBase.h"
using namespace std;


int main()
{
    ifstream(fin);
    fin.open("C:\\Users\\ultra\\CLionProjects\\second_semester\\data.txt");
    Node x;
    fin >> x;
    fin.close();
    cout << x;
    return 0;
};
