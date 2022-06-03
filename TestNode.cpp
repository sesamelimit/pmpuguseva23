#include "TestNode.h"
#include <iostream>
#include <fstream>

LinkedList::Node::Node() {
next=nullptr;
}

LinkedList::LinkedList() {
first=nullptr;
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
    first=nullptr;
    last=nullptr;
    length=0;
}

void LinkedList::destroy(){
    Node* current = first;
    while( current != nullptr ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    first=nullptr;
    last=nullptr;
    length=0;
}

LinkedList::LinkedList(const LinkedList &point) {
    LinkedList::Node *current=first;
    while (current != nullptr && length!=0) {
            LinkedList::Node *next = current->next;
            delete current;
            current = next;
    }
    first=nullptr;
    last=nullptr;
    length=point.length;

    first=new Node();
    first->data=point.first->data;
    Node* target=first;
    current=point.first->next;
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

std::ifstream &operator>>(ifstream &in, LinkedList &pt) {
     LinkedList::Node *current=pt.first;
    while (current != nullptr) {
        LinkedList::Node *next = current->next;
        delete current;
        current = next;
    }
    pt.first=nullptr;
    pt.length = 0;

    while (!(in.eof())) {
        PersonTest point;
        in >> point;
        pt.add(point);
    }
    return in;
}

void LinkedList::add(PersonTest point)
{
    if(this->first==nullptr) {
        first = new Node();
        first->data=point;
        last=first;
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
        ++length;
        return;
    }

    //Если элемент минус первый
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
    auto* current=first;
    while(current!=nullptr && current->next!=nullptr){
        if(current->next->data.check(name2,test_id2,inf,sup))
        {
            auto* temp=current->next->next;
            delete current->next;
            current->next=temp;
            --length;
        }
        if(current->next->next==nullptr && current->next->data.check(name2,test_id2,inf,sup))
        {
            delete current->next;
            last=current;
            --length;
            current->next=nullptr;
        }
        current=current->next;
    }
    current=first;
    while(current!=nullptr && current->next!=nullptr){
        if(current->next->data.check(name2,test_id2,inf,sup))
        {
            auto* temp=current->next->next;
            delete current->next;
            current->next=temp;
            --length;
        }
        if(current->next->next==nullptr && current->next->data.check(name2,test_id2,inf,sup))
        {
            delete current->next;
            last=current;
            --length;
            current->next=nullptr;
        }
        current=current->next;
    }

    if(first->data.check(name2,test_id2,inf,sup))
    {
        auto* temp=first->next;
        delete first;
        first=temp;
        --length;
    }
    if(length==0 || length==1)
        last=first;
}


LinkedList* LinkedList::mergesort(LinkedList *list) {
    if(list==nullptr || list->first==nullptr || list->first->next==nullptr)
        return list;

    auto* a = new LinkedList();
    auto* b = new LinkedList();

    mergesplit(list, a, b);
    mergesort(a);
    mergesort(b);
    merge(list,a,b);
    a->destroy(); b->destroy();
    return list;
}

void LinkedList::mergesplit(LinkedList *list, LinkedList *a, LinkedList *b) {
int m=list->length/2;
auto* current=list->first;

a->first = new Node();
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
b->first=new Node();
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

LinkedList* LinkedList::merge(LinkedList *list, LinkedList *a, LinkedList *b) {
    list->destroy();
    list->first=new Node();
    list->last=list->first;
    list->length=a->length;
    list->first->data=a->first->data;
    Node* target=list->first;
    auto* current=a->first->next;
    while(current!=nullptr)
    {
        target->next=new Node();
        target=target->next;
        target->data=current->data;
        list->last=target;
        current=current->next;
    }

    auto* current_b=b->first;
    while(list->first!=nullptr && current_b!=nullptr && list->first->data.compare(current_b->data)==1)
    {
        auto* x = new Node();
        x->data=current_b->data;
        x->next=list->first;
        list->first=x;
        ++list->length;
        current_b=current_b->next;
    }
    auto* current_a=list->first;
    while(current_b!=nullptr){
        while(current_a->next!=nullptr && current_a->next->data.compare(current_b->data)==-1)
            current_a=current_a->next;
        auto* x = new Node();
        x->data=current_b->data;
        x->next=current_a->next;
        current_a->next=x;
        ++list->length;
        if (x->next==nullptr)
            list->last=x;

        current_b=current_b->next;
    }
    return a;
}

void LinkedList::testinfo(int test_id){
    auto* current=this->first;
    vector<double> inf(5, -1);
    vector<double> sup(5, 1000);
    while(current!=nullptr){
        if(current->data.check("*", test_id, inf, sup)) {
            current->data.print_scores();
            cout << endl;
        }
        current=current->next;
    }
};