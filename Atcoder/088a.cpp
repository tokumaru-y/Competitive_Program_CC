#include <bits/stdc++.h>
using namespace std; 

int main () {
    int a,b;
    scanf("%d",&a);
    scanf("%d", &b);
    int div = a % 500 ;
    if (div <= b){
        printf("%s", "Yes");
    } else {
        printf("%s", "No");
    }
}