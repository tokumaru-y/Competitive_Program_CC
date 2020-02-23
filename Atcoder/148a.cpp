/* #include <iostream>
#include <vector>
using namespace std;

int main() {
    int a,b ;
    vector<int> ll{1,2,3};
    cin >> a ;
    cin >> b;
    ll.erase(remove(ll.begin(), ll.end(), a), ll.end());
    ll.erase(remove(ll.begin(), ll.end(), b), ll.end());
    cout << ll[0] << endl;
} */

#include <iostream>
using namespace std;

int main() {
    int a,b ;
    cin >> a;
    cin >> b;
    cout << 6 - (a+b) << endl;
}