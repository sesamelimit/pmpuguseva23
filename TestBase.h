#pragma once
#include "PersonTestClass.h"

class Node
{
private:
    PersonTest data;
    Node* next;
public:
    Node();
    ~Node();
    Node(const Node &object);
    int add(PersonTest object);
    Node* sort(Node* head, Node* tmp, int left, int right);
    int addToSorted(Node*x);
    friend std::ostream& operator<< (std::ostream& out, const Node& pt);
    friend std::ifstream& operator>> (std::ifstream& in, Node& pt);
    int write(string name2, int test_id2, vector<double> inf, vector<double> sup);
    int remove(string name2, int test_id2, vector<double> inf, vector<double> sup);
};
