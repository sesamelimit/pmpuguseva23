#import "PersonTest.h"
#include "TestNode.h"

#include <iostream>
#include <fstream>

int isBukvSymb(char symb)
{
    return (symb >= (char)'a' && symb <= (char)'z' || symb >= (char)'A' && symb <= (char)'Z');
}

int isBukvString(string str)
{
    for (char i : str) {
        if (isBukvSymb(i) == 0)
            return 1;
    }
    return 0;
}

void PersonTest::read_c() {
    cout << "Input data: name, test id, results \n";
    cin >> person_name;
    while (isBukvString(person_name)) {
        cout << "Wrong name format, input correct data \n";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> person_name;
}
    cin >> test_id;
    while ((test_id < 0 || test_id>50) || test_id != (int)test_id) {
        cout << "Wrong test id format, input correct data \n";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> test_id;
    }
    double input;
    for (int i = 0; i < quan[test_id]; i++)
    {
        (cin >> input);
        results.push_back(input);
    }
}

int PersonTest::compare(PersonTest pt2)
{
    if (test_id < pt2.test_id)
        return -1;
    else if (test_id > pt2.test_id)
        return 1;
    else if (test_id == pt2.test_id) {
        if (person_name < pt2.person_name)
            return -1;
        else if (person_name > pt2.person_name)
            return 1;
        else if (person_name == pt2.person_name)
            return 0;
    }

}

bool PersonTest::check(string name2, int test_id2, vector<double> inf, vector<double> sup)
{
    if ((test_id2 == -1) || (test_id2 == test_id)) {
        if ((name2 == "*") || (person_name == name2)) {
            if ((inf <= results) && (results <= sup))
                return true;
            else return false;
        }
        else return false;
    }
    else { return false; }
}

double PersonTest::getProperty(std::vector<double> pt2)
{
    double sum = 0;
    for (int i = 0; i < quan[test_id]; i++)
        sum += results[i] * pt2[i];
    return sum;
}

std::ostream& operator<< (std::ostream& out, const PersonTest& pt)
{
    out << pt.person_name << "\n" << pt.test_id << "\n";
    for (int i = 0; i < quan[pt.test_id]; i++)
        out << pt.results[i] << "\n";
    return out;
}

std::istream& operator>> (std::istream& in, PersonTest& pt)
{
    in >> pt.person_name;
    in >> pt.test_id;
    double input;
    for (int i = 0; i < quan[pt.test_id]; i++) {
        cin >> input;
        pt.results.push_back(input);
    }
    return in;
}


std::ifstream& operator>> (std::ifstream& in, PersonTest& pt) {
    in >> pt.person_name;
    in >> pt.test_id;
    double input;
    for (int i = 0; i < quan[pt.test_id]; i++) {
        in >> input;
        pt.results.push_back(input);
    }
    return in;
}

