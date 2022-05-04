#include "TestNode.h"
#include <fstream>
#include <iostream>
using namespace std;

Node::Node(){
    next=nullptr;
};

Node::~Node(){

    Node* current=nullptr;
    Node *n =this->next;
    while(n!=nullptr)
    {
        current=n;
        n=n->next;
        delete(current);
    }
    next=NULL; //возможно пофиксить
}

//потестить
Node::Node(const Node &point) {
this->data=point.data;
this->next=point.next;
};

std::ostream& operator<< (std::ostream& out, const Node& pt)
{
    Node copy;
    copy=pt;
    Node* current;
    current=&copy;
    while(current!= nullptr)
    {
        cout << current->data << endl;
        current=current->next;
    }
}

std::ifstream& operator>> (std::ifstream& in, Node& pt) {
    int n;
    Node* current;
    current=&pt;
    in >> n;
    in >> pt.data;
    for(int i;i<n;i++){
        Node* nextnode = new Node();
        in >> nextnode->data;
        current->next=nextnode;
        current=current->next;
        cout << "data is" << pt.data << endl;

    }
    return in;
}

