#include "TestBase.h"
#include <iostream>
#include <fstream>

Node::Node(){
    next=nullptr;
};

Node::~Node(){
//this это указатель на текущий элемент, с которым вызывается функция
Node *n=this->next;
Node* current = NULL;
while(n) {
    current=n;
    n=n->next;
    delete(current);
}
next=NULL;
};

//КОНСТРУКТОР КОПИРОВАНИЯ
Node::Node(const Node &object)
{
    this->next=object.next;
    this->data=object.data;
}

int Node::add(PersonTest object)
{
    Node* current=next;
    while(current->next!=nullptr)
        current=current->next;
    Node *x;
    x = new Node();
    x->next=nullptr;
    x->data=object;
    current->next=x;
    return 0;
};

/*Node* Node::sort(Node* head, Node* tmp, int left, int right)
{
    if(left==right)
        return head;

    sort(head,tmp,left,(right-left)/2);
    Node* current=head;
    int i;
    for(i=0;i<(right-left)/2;i++)
         current=current->next;
    sort(current,tmp,right/2+1, right);

    if (right==left+1)
        if ((*head).data.compare(head->next->data)) {
            class PersonTest *tmp;
            tmp = (*head)->data;
            (*head).data=(head->next)->data;
            (head->next)->data=tmp;
        }

};

int Node::addToSorted(Node*x){
    Node* current=this;
    while(x->data->compare(*current->data)==-1)
        current=current->next;
    this->next=current->next;
    current->next=this;
    return 0;
};*/

std::ostream& operator<<(std::ostream& out, const Node& pt)
{
    Node copy;
    copy=pt;
    Node* current;
    current=&copy;
    while(current!=nullptr)
    {
        cout << current->data << endl;
        current=current->next;

    }
    return out;
}

std::ifstream& operator>>(std::ifstream& in, Node& pt){
    Node* current;
    current=&pt;
    int n;
    in >> n;
    for(int i=0;i<n;i++) {
        Node* nextnode = new Node();
        in >> current.data;
        current->next=nextnode;
        current=current->next;
        cout << "data is " << pt.data << endl;
    }
    return in;
};

/*int Node::write(string name2, int test_id2, vector<double> inf, vector<double> sup){
    Node* current=this;
    while (current!=nullptr) {
        if ((current->data)->check(name2, test_id2, inf, sup))
            std::cout << current->data;
        current = current->next;
    }
}*/

/*int Node::remove(string name2, int test_id2, vector<double> inf, vector<double> sup){
    Node* current=this;
    while (current!=nullptr)
        if ((current->data)->check(name2,test_id2,inf,sup)) {
            delete current;
            return 0;
        }
}
*/