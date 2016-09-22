#include <iostream>
#include <set>

using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
        set<int> s;
        s.insert(1);
        while (s.size() < n) {
            set<int> tmp = s;
            for (int i: s) {
                tmp.insert(2*i + 1);
                tmp.insert(3*i + 1);
            }
            s = tmp;
        }
        return -1;
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(10) << endl;
    return 0;
}
