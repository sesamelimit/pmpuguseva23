// C:\Users\ultra\CLionProjects\PersonTest\data.txt

#include <iostream>
#include <fstream>
#include "TestNode.h"
#include <string>
using namespace std;

int main() {
    bool is_exit=false;
    auto  *A = new LinkedList();
    while(!(is_exit))
    {
        string command;
        cin >> command;
        if(command=="write")
            cout << *A;
        if (command=="exit")
            is_exit=true;
        if (command=="help")
            cout << "    - help - print the commands list\n"
                    "    - clear - clear list\n"
                    "    - load <filename> - add list from file\n"
                    "    - save <filename> - save list as file\n"
                    "    - add - add element to the list\n"
                    "    - sort - sort the list\n"
                    "    - find <conditions> - print elements satisfying the conditions\n"
                    "    - delete <conditions> - remove elements satisfying the conditions\n"
                    "    - exit - stop and exit\n";
        if(command=="clear") {
            A->destroy();
            cout << "array is cleared" << endl;
        }

        if(command=="load") {
            char* filename = new char[255];
            cin >> filename;
            ifstream(fin);
            fin.open(filename);
            while(!(fin.is_open())){
                cout << "File not found, try again\n";
                fin.close();
                cin >> filename;
                fin.open(filename);}
            fin >> *A; cout << "loaded" << endl;
            fin.close();
            delete[] filename;
        }
        if(command=="save"){
            char *filename = new char[255];
            cin >> filename;
            ofstream(fout);
            fout.open(filename);
            while(!(fout.is_open())){
                fout.close();
                cout << "File not found, try again\n";
                cin >> filename;
                fout.open(filename);}
            fout << *A;
            fout.close();
            delete[] filename;
        }
        if(command=="add")
        {
            PersonTest x;
            cout << "input data:" << endl;
            cin >> x;
            cout << "is read" << endl;
            A->add(x);
            cout << "added" << endl;
        }
        if(command=="sort")
        {
            A->mergesort(A);
            cout << "sorted ll" << endl;
            cout << *A;
        }
        if(command=="find")
        {
            string name; int id,inf_size,sup_size;
            cout << "input name, id, size of vectors and vectors"<<endl;
            cin >> name >> id;

            cout << "input vector 1" << endl;
            cin >> inf_size;
            vector<double> inf(inf_size);
            for (int i = 0; i < inf_size; i++)
                cin >> inf[i];

            cout << "input vector 2" << endl;
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
            cout << "input name, id, size of vectors and vectors" << endl;
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
        }
        if(command=="testinfo")
        {
            int test_id;
            cout << "Input test id" << endl;
            cin >> test_id;
            A->testinfo(test_id);
        }

    }
    delete A;
    return 0;
}

//C:\Users\ultra\CLionProjects\PersonTest\data.txt
//C:\Users\ultra\CLionProjects\PersonTest\data2.txt