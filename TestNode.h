#include "PersonTest.h"
class LinkedList{
private:
    struct Node { //структура узла открытая внутри класса лл
        Node *next;
        PersonTest data;
        Node();
    };
    int length;
    Node *first;
    Node *last;
public:
    LinkedList();
    LinkedList(const LinkedList &point);
    ~LinkedList();
    friend std::ostream& operator<< (std::ostream& out, const LinkedList& pt);
    friend std::ifstream& operator>> (std::ifstream& in, LinkedList& pt);
    void add(PersonTest point);
    void addToSorted(PersonTest point);
    void mergesort();
    void mergesort_a(LinkedList *list);
    void mergesplit(LinkedList *list, LinkedList *a, LinkedList *b );
    LinkedList* merge(LinkedList *a,LinkedList *b);
    void write(string name2, int test_id2, vector<double> inf, vector<double> sup);
    void remove(string name2, int test_id2, vector<double> inf, vector<double> sup);
};
