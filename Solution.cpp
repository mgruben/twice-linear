#include <iostream>
#include <set>

using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (n == 0) return 1;
    }
};


int main() {
    DoubleLinear dl;
    cout << dl.dblLinear(0) << endl;
    return 0;
}
