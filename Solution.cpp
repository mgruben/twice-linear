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
private:
    static int lowerLimit(int n) {
        int numIters = ceil(log2(n) + 1);
        int ans = 1;
        for (int i = 0; i < numIters; i++) {
            ans = 2*ans + 1;
        }
        return ans;
    };

public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
        deque<int> toEval;
        set<int> evaled;
        toEval.push_back(1);
        cout << "Added 1 to toEval" << endl;
        cout << "toEval.size() = " << toEval.size() << endl;
        cout << endl;
        int lim = lowerLimit(n);
        cout << lim << endl;
        int adjustedSize = evaled.size();
        while(adjustedSize < n) { // "size" here needs to be up to
                                   // toEval.front(), not the whole size.
            deque<int> evaling(toEval);
            sort(evaling.begin(), evaling.end());
            int size = toEval.size();
            toEval.clear();
            for (int i = 0; i < size; i++) {
                int num = evaling.front();
                evaling.pop_front();
                toEval.push_back(2*num + 1);
                toEval.push_back(3*num + 1);
                evaled.insert(num);
            }
            set<int>::reverse_iterator i;
            adjustedSize = evaled.size();
            for (i = evaled.rbegin(); i != evaled.rend(); ++i) {
                if (*i > toEval.front()) adjustedSize--;
                else break;
            }
        }
        vector<int> v(evaled.begin(), evaled.end());
        cout << v.size() << endl;
        return v[n];
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(67322) << endl;
    return 0;
}
