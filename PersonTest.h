#include <string>
#include <vector>
using namespace std;
const int quan[] = { 6,3,9,5,14,9,13,13,7,9,10,10,6,12,6,6,10,7,12,11,6,9,7,8,7,7,6,11,13,10,12,11,6,13,14,7,12,14,10,9,8,6,7,8,8,9,6,6,8,13 };

int isBukvSymb(char symb);
int isBukvString(char* str);

class PersonTest{
private:
    int test_id;
    string person_name;
    vector<double> results;
public:
    void read_c();
    int compare(PersonTest pt2);
    bool check(string name2, int test_id2, vector<double> inf, std::vector<double> sup);
    double getProperty(vector<double> pt2);
    friend std::ostream& operator<< (std::ostream& out, const PersonTest& pt);
    friend std::istream& operator>> (std::istream& in, PersonTest& pt);
    friend std::ifstream& operator>> (std::ifstream& in, PersonTest& pt);

};
