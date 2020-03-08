#include <stdio.h>
using namespace std;

int main () {
    int a,b,c;
    char d,e;
    scanf("%d%c%d%c%d", &a,&d,&b,&e,&c);
    if (b <= 4){
        printf("%s", "Heisei");
    } else {
        printf("%s", "TBD");
    }
}