#include <stdio.h>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    if(a==3 || a==5 || a==7){
        printf("%s", "YES");
    } else {
        printf("%s", "NO");
    }
}