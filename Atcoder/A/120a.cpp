#include <stdio.h>
using namespace std;

int main () {
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    int div = b/a;
    int ans;
    if (div>=c) {
        ans = c;
    } else {
        ans = div;
    }
    printf("%d", ans);
}