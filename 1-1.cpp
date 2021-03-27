#include <stdio.h>

int main()
{
    int n, i;
    long long int a, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &a);
        scanf("%lld", &b);
        printf("%lld\n", a+b);
    }

    return 0;
}
