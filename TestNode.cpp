#include "TestNode.h"
#include <iostream>
#include <fstream>

LinkedList::Node::Node() {
next=nullptr;
}

LinkedList::LinkedList() {
first = new Node();
last=first;
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

LinkedList::LinkedList(const LinkedList &point) { //todo
    Node *current=point.first;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    first=new Node();
    first->data=point.first->data;
    Node* target=first;
    current=point.first;
    while(current!=nullptr)
    {
        target->next=new Node();
        target=target->next;
        target->data=current->data;
        last=target;

        current=current->next;
    }
}

std::ostream &operator<<(ostream &out, const LinkedList &pt) {
    LinkedList::Node *current;
    current=pt.first;
    while(current!=nullptr)
    {
        out << current->data << endl;
        current=current->next;
    }
    return out;
}

std::ifstream &operator>>(ifstream &in, LinkedList &pt) { //todo
    LinkedList::Node *current=pt.first;
    while (current != nullptr) {
        LinkedList::Node *next = current->next;
        delete current;
        current = next;
    }
    pt.length = 0;

    pt.first = new LinkedList::Node();
    in >> pt.first->data;
    ++pt.length;
    current=pt.first;
    while (!(in.eof())) {
        auto *newnode = new LinkedList::Node();
        ++pt.length;
        in >> newnode->data;
        current->next = newnode;
        current = current->next;
    }
    pt.last=current;
    return in;
}

void LinkedList::add(PersonTest point)
{
    if(this->first==nullptr) {
        first = new Node();
        first->data=point;
        last=first;
        return;
    }

    if(this->length==0){
        first->data=point;
        ++length;
        return;
    }

    this->last->next=new Node();
    this->last->next->data=point;
    this->last=this->last->next;
    ++length;
};

void LinkedList::addToSorted(PersonTest point) {
    if(this->first==nullptr) {
        first = new Node();
        first->data=point;
        last=first;
        return;
    }

    if(this->length==0) {
        first->data=point;
        ++length;
        last=first;
        return;
    }
    //Если элемент минус первый получается
    auto* current = this->first;
    if(current->data.compare(point)==1) {
        auto* x = new Node();
        x->data=point;
        x->next = current;
        this->first = x;
        ++length;
        return;
    }
    while(current!=nullptr && current->next!=nullptr && current->next->data.compare(point)==-1)   //(current < point)
        current=current->next;
    auto* x = new Node();
    x->data=point;
    x->next=current->next;
    current->next=x;
    ++length;
    if (x->next==nullptr)
        last=x;
}

void LinkedList::write(string name2, int test_id2, vector<double> inf, vector<double> sup) {
auto* current=this->first;
while(current!=nullptr) {
    if (current->data.check(name2, test_id2, inf, sup))
        cout << current->data;
    current = current->next;
}
}

void LinkedList::remove(string name2, int test_id2, vector<double> inf, vector<double> sup) {//todo
 LinkedList::Node *current = this->first;
 while(current!=nullptr) {
     if (current->next != nullptr && current->next->data.check(name2, test_id2, inf, sup)) {
         auto *n = current->next->next;
         delete current->next;
         length--;
         current->next = n;
     }

     //проверка конца
     if(current->next->next == nullptr && current->next->data.check(name2,test_id2,inf,sup))
     {
         delete current->next;
         last=current;
         --length;
     }
     current=current->next;
 }
 if(this->first->data.check(name2, test_id2, inf, sup)) {
     auto *temp = this->first->next;
     delete this->first;
     this->first=temp;
 }

}

void LinkedList::mergesort(){
    mergesort_a(this);

};

void LinkedList::mergesort_a(LinkedList *list) {
    if(list==nullptr || list->first==nullptr || list->first->next==nullptr)
        return;

    LinkedList* a = new LinkedList();
    LinkedList* b = new LinkedList();

    mergesplit(list, a, b);
    mergesort_a(a);
    mergesort_a(b);
    list=merge(a,b);
}

void LinkedList::mergesplit(LinkedList *list, LinkedList *a, LinkedList *b) {
int m=list->length/2;
auto* current=list->first;
a->first->data=current->data;
++a->length;
a->last=a->first;
current=current->next;

for(int i=1;i<m;++i) {
    if (current != nullptr) {
        a->add(current->data);
    }
    current=current->next;
}

b->first->data=current->data;
++b->length;
b->last=b->first;
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

