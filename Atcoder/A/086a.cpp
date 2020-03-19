#include <bits/stdc++.h>
using namespace std; 
int main () {
    int a,b;
    scanf("%d %d" , &a,&b);
    if(a %2 == 0 || b % 2 == 0){
        printf("%s", "Even");
    } else {
        printf("%s", "Odd");
    }
}