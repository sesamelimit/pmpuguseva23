#include "PersonTest.h"
using namespace std;

class Node
{
private:
    Node* next;
    PersonTest data;
public:
    Node();
    ~Node();
    Node(const Node &point);
    friend std::ostream& operator<< (std::ostream& out, const Node& point);
    friend std::ifstream& operator>> (std::ifstream& in, Node& point);
    void add(Node point); //возможно поменять аргумент на указатель на узел
    void sort(Node head);
    void addToSorted(Node point);
    void write();
    void remove();
};