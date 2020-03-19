#include <iostream>
#include <string>
using namespace std;
int main () {
    string a,b,c;
    cin >> a >> b >> c;
    char ans[3];
    ans[0] = a[0] - 32;
    ans[1] = b[0] - 32;
    ans[2] = c[0] - 32;
    printf("%s", ans);
}