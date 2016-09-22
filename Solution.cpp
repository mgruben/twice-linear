#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
        unordered_set<int> s;
        s.insert(1);
        cout << "Added 1 to s" << endl;
        cout << "s.size() = " << s.size() << endl;
        while (s.size() < n) {
            unordered_set<int> copy = s;
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
        sort(v.begin(), v.end());
        return v[n];
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(10) << endl;
    return 0;
}
