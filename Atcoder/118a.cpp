#include <stdio.h>
using namespace std;

int main() {
    int a,b;
    scanf("%d %d", &a,&b);
    if (b % a == 0) {
        printf("%d", a+b);
    } else {
        printf("%d", b-a);
    }
}