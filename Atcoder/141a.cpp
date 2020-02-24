#include <iostream>
#include <string>
using namespace std;

int main() {
    string a,b,c,x;
    a = "Sunny"; b =  "Cloudy"; c = "Rainy";
    cin >> x;
    if (x == "Sunny"){
        cout << b << endl;
    } else if (x == "Cloudy") {
        cout << c << endl;
    } else {
        cout << a << endl;
    }
}