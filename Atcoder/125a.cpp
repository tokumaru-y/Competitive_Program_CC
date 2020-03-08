#include <stdio.h>
using namespace std;

int main() {
    int a,b,t;
    scanf("%d %d %d", &a,&b,&t);
    int ans;
    ans = b * (t/a);
    printf("%d", ans);
}