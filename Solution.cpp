#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

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
            greater<long long unsigned int>> q;
        q.push(1);
        cout << "Begin insertion" << endl; // This is the slowest
        for (int i = 0; i < n; i++) {
            long long unsigned int num = q.top();
            while (!q.empty() && num == q.top()) {
                q.pop(); // Handle upcoming duplicates
            }
            q.push(2*num + 1);
            q.push(3*num + 1);
        }
        return q.top();
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(300000) << endl;
    return 0;
}
