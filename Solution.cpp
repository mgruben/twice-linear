#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;

string toString(set<long long unsigned int> s) {
    if (s.size() == 0) return "()";
    string ans = "(";
    for (long long unsigned int i: s) {
        ans += to_string(i);
        ans += ", ";
    }
    ans = ans.substr(0, ans.length() - 2);
    return ans + ")";
}

string toString(deque<long long unsigned int> d) {
    if (d.size() == 0) return "[]";
    string ans = "[";
    for (long long unsigned int i: d) {
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
        int invariantSize = toEval.size();
        while(invariantSize < n) {
            int size = invariantSize;
            for (int i = 0; i < size; i++) {
                long long unsigned int num = toEval.front();
                toEval.pop_front();
                toEval.push_back(2*num + 1);
                toEval.push_back(3*num + 1);
                evaled.insert(num);
            }
            sort(toEval.begin(), toEval.end());
            deque<long long unsigned int>::iterator j = toEval.begin();
            set<long long unsigned int>::iterator toErase;
            toErase = evaled.find(*j);
            while (toErase != evaled.end()) {
                toEval.pop_front();
                toErase = evaled.find(*++j);
            }
            set<long long unsigned int>::reverse_iterator i;
            invariantSize = evaled.size();
            for (i = evaled.rbegin(); i != evaled.rend(); ++i) {
                if (*i > toEval.front()) {
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
    cout << dl.dblLinear(100000) << endl;
    return 0;
}
