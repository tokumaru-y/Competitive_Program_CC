#include <stdio.h>
using namespace std;

int main() {
    int b,c;
    scanf("%d%d",&b,&c);
    char a[b];
    scanf("%c%*c",a);
    a[c-1] += 'a' - 'A';
    printf("%s", "aaaaaa");
    printf("%c", *a);
}