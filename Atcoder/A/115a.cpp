#include <stdio.h>
using namespace std;

int main() {
    int d;
    scanf("%d",&d);
    if (d==25) {
        printf("%s", "Christmas");
    } else if (d==24) {
        printf("%s", "Christmas Eve");
    } else if (d==23) {
        printf("%s", "Christmas Eve Eve");
    } else {
        printf("%s", "Christmas Eve Eve Eve");
    }
}