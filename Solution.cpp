#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
        set<int> s;
        s.insert(1);
        cout << "Added 1 to s" << endl;
        cout << "s.size() = " << s.size() << endl;
        while (s.size() < n) {
            set<int> copy = s;
            for (int i: copy) {
                s.insert(2*i + 1);
                cout << "Added " << 2*i + 1 << " to s" << endl;
                cout << "s.size() = " << s.size() << endl;
                s.insert(3*i + 1);
                cout << "Added " << 3*i + 1 << " to s" << endl;
                cout << "s.size() = " << s.size() << endl;
            }
        }
        vector<int> v(s.begin(), s.end());
        return v[n];
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(10) << endl;
    return 0;
}
