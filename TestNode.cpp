#include "TestNode.h"
#include <iostream>
#include <fstream>

Node::Node() {
    next=nullptr;
}

Node::~Node() {
 /*   Node* current = new Node();
    current = this->next;
    while(current!=nullptr)
    {
        Node* n=current->next;
        delete current;
        current=n;
    }*/
}

Node::Node(const Node &point) {
    this->data=point.data;
    this->next=point.next;
};

std::ostream& operator<< (std::ostream& out, const Node& pt)
{
    Node* current=new Node();
    Node copy=pt;
    current = &copy;
    while(current!=nullptr)
    {
        out << current->data << endl;
        current=current->next;
    }
    return out;
}

std::ifstream &operator>>(ifstream &in, Node &pt) {
    Node* current;
    current = &pt;
    in >> pt.data;
    while(!(in.eof()))
    {
        Node *newnode;
        newnode = new Node();
        in >> newnode->data;
        current->next=newnode;
        current=current->next;
    }
    return in;
    //Мораль инициализировать перемеменные
}

void Node::add(Node point) {
Node* current=new Node();
current=this->next;
while(current->next!=nullptr)
    current=current->next;
Node* ptr = new Node();
ptr=&point;
current->next=ptr;
}

void Node::sort() {

};
