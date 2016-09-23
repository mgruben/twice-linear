#include <iostream>
#include <set>
#include <vector>
#include <queue>
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

string toString(priority_queue<long long unsigned int,
            vector<long long unsigned int>,
            greater<long long unsigned int>> d) {
    if (d.size() == 0) return "[]";
    string ans = "[";
    for (int i = 0; i < d.size(); i++) {
        ans += to_string(d.top());
        d.pop();
        ans += ", ";
    }
    return ans.substr(0, ans.length() - 2) + "]";
}

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
        priority_queue<long long unsigned int,
            vector<long long unsigned int>,
            greater<long long unsigned int>> toEval;
        set<long long unsigned int> evaled;
        toEval.push(1);
        int invariantSize = toEval.size();
        int overlap = 1;
        while(invariantSize < n) {
            int size = toEval.size();
            cout << "Begin insertion" << endl; // This is the slowest
            for (int i = 0; i < size; i++) {
                long long unsigned int num = toEval.top();
                while (toEval.size() > 0 && num == toEval.top()) {
                    toEval.pop(); // Handle upcoming duplicates
                    i++; // Since list advancement
                }
                toEval.push(2*num + 1);
                toEval.push(3*num + 1);
                evaled.insert(num);
            }
            cout << "Begin overlap count" << endl;
            invariantSize = evaled.size();
            set<long long unsigned int>::iterator i;
            i = evaled.lower_bound(toEval.top());
            overlap = distance(i, evaled.end());
            invariantSize -= overlap;
            cout << *evaled.end() << endl;
        }
        vector<int> v(evaled.begin(), evaled.end());
        return v[n];
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(200000) << endl;
    return 0;
}
