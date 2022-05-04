#include "PersonTest.h"
class Node{
private:
    Node* next;
    PersonTest data;
public:
    Node();
    ~Node();
    Node(const Node &point);
    friend std::ostream& operator<< (std::ostream& out, const Node& pt);
    friend std::ifstream& operator>> (std::ifstream& in, Node& pt);
    void add(Node point);
    void sort();
    void addToSorted(Node point);
    void write();
    void remove();
};