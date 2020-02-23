#include <iostream>
using namespace std;

int main() {
    int a,b,c ;
    cin >> a >> b >> c;
    if (a+b+c >= 22) {
        puts("bust");
    } else {
        puts("win");
    }
}