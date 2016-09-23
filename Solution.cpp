#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;

string toString(set<int> s) {
    if (s.size() == 0) return "()";
    string ans = "(";
    for (int i: s) {
        ans += to_string(i);
        ans += ", ";
    }
    ans = ans.substr(0, ans.length() - 2);
    return ans + ")";
}

string toString(deque<int> d) {
    if (d.size() == 0) return "[]";
    string ans = "[";
    for (int i: d) {
        ans += to_string(i);
        ans += ", ";
    }
    return ans.substr(0, ans.length() - 2) + "]";
}

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
        deque<long long unsigned int> toEval;
        set<long long unsigned int> evaled;
        toEval.push_back(1);
        cout << "Added 1 to toEval" << endl;
        cout << "toEval.size() = " << toEval.size() << endl;
        cout << endl;
        int invariantSize = evaled.size();
        while(invariantSize < n) {
            deque<long long unsigned int> evaling(toEval);
            sort(evaling.begin(), evaling.end());
            int size = toEval.size();
            toEval.clear();
            for (int i = 0; i < size; i++) {
                long long unsigned int num = evaling.front();
                evaling.pop_front();
                toEval.push_back(2*num + 1);
                toEval.push_back(3*num + 1);
                evaled.insert(num);
            }
            set<long long unsigned int>::reverse_iterator i;
            invariantSize = evaled.size();
            cout << "evaled contains: " << toString(evaled) << endl;
            cout << "toEval contains " << toString(toEval) << endl;
            for (i = evaled.rbegin(); i != evaled.rend(); ++i) {
                if (*i > toEval.front()) {
                    cout << *i << ">" << toEval.front() << endl;
                    invariantSize--;
                }
                else break;
            }
            cout << toEval.back() << endl;
        }
        vector<int> v(evaled.begin(), evaled.end());
        return v[n];
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(30) << endl;
    return 0;
}
