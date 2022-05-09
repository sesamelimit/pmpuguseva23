#include "TestNode.h"
#include <iostream>
#include <fstream>

LinkedList::Node::Node() {
next=nullptr;
}

LinkedList::LinkedList() {
first=new LinkedList::Node();
}

LinkedList::~LinkedList() {
    Node* current = first;
    while( current != nullptr ) {
        Node* next = current->next;
        delete[] current;
        current = next;
    }
    first = nullptr;
}

LinkedList::LinkedList(const LinkedList &point) {
this->first->next=point.first->next;
this->first->data=point.first->data;
}

std::ostream &operator<<(ostream &out, const LinkedList &pt) {
    LinkedList::Node *current=new LinkedList::Node();
    current=pt.first;
    while(current!=nullptr)
    {
        out << current->data << endl;
        current=current->next;
    }
    return out;
}

std::ifstream &operator>>(ifstream &in, LinkedList &pt) {
    LinkedList::Node *current;
    current = pt.first;
    in >> current->data;
    while (!(in.eof())) {
        LinkedList::Node *newnode;
        newnode = new LinkedList::Node();
        in >> newnode->data;
        current->next = newnode;
        current = current->next;
    }
    return in;
}

void LinkedList::add(Node point)
{
    LinkedList::Node *current=new LinkedList::Node();
    current=this->first;
    while(current!=nullptr)
            current=current->next;
    LinkedList::Node *x = new LinkedList::Node();
    x->data=point.data;
    x->next=current->next;
    current->next=x;
};

void LinkedList::addToSorted(LinkedList::Node point) {
    LinkedList::Node *current=new LinkedList::Node();
    current=this->first;
    while(current!=nullptr)
        if(current->data.compare(point.data)==1)
    {
        cout << current->data << ">" << point.data << endl;
        current=current->next;
    };
    LinkedList::Node *x = new LinkedList::Node();
    x->data=point.data;
    x->next=current->next;
    current->next=x;
}

void LinkedList::sort() {

}




