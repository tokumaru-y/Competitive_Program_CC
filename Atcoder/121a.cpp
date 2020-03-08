#include <stdio.h>
using namespace std;

int main() {
    int h,w,a,b;
    scanf("%d %d", &h,&w);
    scanf("%d %d", &a,&b);
    int ans = (h-a) * (w-b);
    printf("%d",ans);
}