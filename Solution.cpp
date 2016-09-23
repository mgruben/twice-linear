#include <iostream>
#include <queue>

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
        
        // Handle malformed requests
        if (n <= 0) return 1;
        priority_queue<long long unsigned int,
            vector<long long unsigned int>,
            greater<long long unsigned int>> q;
        q.push(1);
        
        /* Discard n-1 invariants, adding their children to q,
         * which will be sorted because of priority_queue magic.
         */
        for (int i = 0; i < n; i++) {
            long long unsigned int num = q.top();
            while (!q.empty() && num == q.top()) {
                
                // Pop this entry and any subsequent duplicates
                q.pop();
            }
            q.push(2*num + 1);
            q.push(3*num + 1);
        }
        
        /* This will be the next invariant to discard, hence it is
         * the nth invariant, hence we return it.
         */
        return q.top();
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(300000) << endl;
    return 0;
}
