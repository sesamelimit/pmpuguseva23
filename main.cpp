// C:\Users\ultra\CLionProjects\PersonTest\data.txt

#include <iostream>
#include <fstream>
#include "TestNode.h"
#include <string>
using namespace std;

int main() {
/*
    bool is_exit=false;
    LinkedList *A = new LinkedList();
    while(!(is_exit))
    {
        string command;
        cin >> command;
        if (command=="exit")
            is_exit=true;
        if (command=="help")
            cout << "help - print the commands list\n"
                    "clear - clear list\n"
                    "load <filename> - add list from file\n"
                    "- save <filename> - save list as file\n"
                    "    - add - add element to the list\n"
                    "    - sort - sort the list\n"
                    "    - find <conditions> - print elements satisfying the conditions\n"
                    "    - delete <conditions> - remove elements satisfying the conditions\n"
                    "    - exit - stop and exit\n";
        if(command=="clear") {
            vector<double> inf(5, -1);
            vector<double> sup(5, 1000);
            A->remove("*", -1, inf, sup);
        }
        if(command=="load") {
            char *filename = new char();
            cin >> filename;
            ifstream(fin);
            fin.open(filename);
            fin >> *A;
            fin.close();
        }
        if(command=="save"){
            char *filename = new char();
            cin >> filename;
            ofstream(fout);
            fout.open(filename);
            fout << *A;
            fout.close();
        }
        if(command=="add")
        {
            PersonTest x;
            cout << "input data:" << endl;
            cin >> x;
            A->add(x);
            cout << "added" << endl;
        }
        if(command=="sort")
        {
            A->mergesort();
            cout << "sorted ll" << endl;
            cout << *A;
        }
        if(command=="find")
        {
            string name; int id,inf_size,sup_size;
            cout << "input name, id, size of vectors and vectors"<<endl;
            cin >> name >> id;

            cout << "vector 1" << endl;
            cin >> inf_size;
            vector<double> inf(inf_size);
            for (int i = 0; i < inf_size; i++)
                cin >> inf[i];

            cout << "vector 2" << endl;
            cin  >> sup_size;
            vector<double> sup(sup_size);
            for (int i = 0; i < sup_size; i++)
                cin >> sup[i];

            cout << "search results:" << endl;
            A->write(name,id,inf,sup);

        }
        if(command=="delete")
        {
            string name; int id,inf_size,sup_size;
            cout << "input name, id, size of vectors and vectors"<<endl;
            cin >> name >> id;

            cout << "vector 1" << endl;
            cin >> inf_size;
            vector<double> inf(inf_size);
            for (int i = 0; i < inf_size; i++)
                cin >> inf[i];

            cout << "vector 2" << endl;
            cin  >> sup_size;
            vector<double> sup(sup_size);
            for (int i = 0; i < sup_size; i++)
                cin >> sup[i];

            cout << "removing:" << endl;
            A->remove(name,id,inf,sup);
            cout << *A;
        }
        if(command=="testinfo")
        {
            int test_id;
            cout << "Input test id" << endl;
            cin >> test_id;
            vector<double> inf(5, -1);
            vector<double> sup(5, 1000);
            cout << "Test number" << test_id << endl;
            A->write("*", test_id, inf, sup);
        }

    }
    return 0;
*/
    LinkedList A;
    char *filename = new char();
    cin >> filename;
    ifstream(fin);
    fin.open(filename);
    fin >> A;
    fin.close();
    LinkedList B=A;
    cout << A;
    cout << B;
    return 0;
}
// C:\Users\ultra\CLionProjects\PersonTest\data.txt
//C:\Users\ultra\CLionProjects\PersonTest\data2.txt