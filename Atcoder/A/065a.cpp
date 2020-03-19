#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int left = b-c;
    if ( left >=0) {
        printf("%s","delicious");
    } else if (left*(-1) <= a){
        printf("%s","safe");
    } else {
        printf("%s", "dangerous");
    }
}