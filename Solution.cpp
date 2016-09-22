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
            for (int i: s) {
                s.insert(2*i + 1);
                s.insert(3*i + 1);
            }
        }
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(0) << endl;
    return 0;
}
