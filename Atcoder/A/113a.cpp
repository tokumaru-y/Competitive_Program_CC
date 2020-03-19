#include <stdio.h>
using namespace std;

int main() {
    int x,y;
    scanf("%d %d", &x, &y);
    int ans = x + (y / 2);
    printf("%d", ans);
}