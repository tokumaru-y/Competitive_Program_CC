#include <bits/stdc++.h>
using namespace std;
int main () {
    int a;scanf("%d", &a);
    if(a=100) {
        printf("Perfect\n");
    } else if (a>=90) {
        printf("Great\n");
    } else if (a>=60) {
        printf("Good\n");
    } else {
        printf("Bad\n");
    }
}