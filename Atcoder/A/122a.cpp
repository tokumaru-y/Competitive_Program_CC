#include <stdio.h>
using namespace std;

int main() {
    char b;
    scanf("%c", &b);
    if (b=='A'){
        printf("%c",'T');
    } else if (b=='C') {
        printf("%c",'G');
    } else if (b=='G') {
        printf("%c",'C');
    } else if (b=='T') {
        printf("%c",'A');
    }
}