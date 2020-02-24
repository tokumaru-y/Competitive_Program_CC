#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int ans = (a+b) / 2;
    if (a == b || (a+b) % 2 == 0) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}