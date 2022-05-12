#include "TestNode.h"
#include <iostream>
#include <fstream>

LinkedList::Node::Node() {
next=nullptr;
}

LinkedList::Node::~Node() {
    next=nullptr;
}

LinkedList::LinkedList() {
first = new Node();
length=0;
}

LinkedList::~LinkedList() {
    Node* current = first;
    while( current != nullptr ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    length=0;
}

LinkedList::LinkedList(const LinkedList &point) {
this->first->next=point.first->next;
this->first->data=point.first->data;
this->length=point.length;
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
    if (pt.length==0)
        pt.first = new LinkedList::Node();
    current = pt.first;
    in >> current->data;
    ++pt.length;
    while (!(in.eof())) {
        LinkedList::Node *newnode;
        newnode = new LinkedList::Node();
        ++pt.length;
        in >> newnode->data;
        current->next = newnode;
        current = current->next;
    }
    return in;
}

void LinkedList::add(PersonTest point)
{
    LinkedList::Node *x = new LinkedList::Node();
    x->data=point;
    if(this->length==0){
                first = x;
                ++length;
                return;
            }
    LinkedList::Node *current=new LinkedList::Node();
    current=this->first;
    while(current->next!=nullptr)
            current=current->next;

    x->next=current->next;
    current->next=x;
    ++length;
};

void LinkedList::addToSorted(PersonTest point) {
    LinkedList::Node *current = new LinkedList::Node();
    LinkedList::Node *x = new LinkedList::Node();
    x->data=point;

    //если кто-то в белой горячке подумает что пустой список сортированный...
    if(this->length==0) {
        first = x;
        ++length;
        return;
    }

    current = this->first;

    if(current->data.compare(point)==1) {
        x->next = current;
        this->first = x;
        ++length;
        return;
    }
    while(current->next!=nullptr && current->next->data.compare(point)==-1)   //(current < point)
        current=current->next;

    x->next=current->next;
    current->next=x;
    ++length;
}

void LinkedList::write(string name2, int test_id2, vector<double> inf, vector<double> sup) {
auto* current=this->first;
while(current!=nullptr) {
    if (current->data.check(name2, test_id2, inf, sup))
        cout << current->data;
    current = current->next;
}
}

void LinkedList::remove(string name2, int test_id2, vector<double> inf, vector<double> sup) {
 LinkedList::Node *current = first;
 if (current->data.check(name2,test_id2,inf,sup)) {
     first = current->next;
     delete current;
     length--;
 }
 current=first;

 while(current!=nullptr) {
     if (current->next!=nullptr && current->next->data.check(name2, test_id2, inf, sup)) {
         auto *n = current->next->next;
         delete current->next;
         length--;
         current->next = n;
     }
     current=current->next;
 }
}

LinkedList* LinkedList::mergesort(LinkedList *list) {
    if(list==nullptr || list->first==nullptr || list->first->next==nullptr)
        return list;

    LinkedList* a = new LinkedList();
    LinkedList* b = new LinkedList();

    mergesplit(list, a, b);
    a=mergesort(a);
    b=mergesort(b);
    a=merge(a,b);
}

void LinkedList::mergesplit(LinkedList *list, LinkedList *a, LinkedList *b) {
int m=list->length/2;
auto* current=list->first;
a->first->data=current->data;
++a->length;
current=current->next;

for(int i=1;i<m;++i) {
    if (current != nullptr)
        a->add(current->data);
    current=current->next;
}
b->first->data=current->data;
++b->length;
current=current->next;
for(int i=m+1;i<list->length;++i) {
    if (current != nullptr)
        b->add(current->data);
    current = current->next;
}
}

LinkedList* LinkedList::merge(LinkedList *a, LinkedList *b) {
    auto* current=b->first;
    while(current!=nullptr) {
        a->addToSorted(current->data);
        current = current->next;
    }
    return a;
}

