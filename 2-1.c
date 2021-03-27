#include <stdio.h>

unsigned long long int dnc(unsigned long long int n, unsigned long long int k) {
    if (k==0) return 1;
	if (k==1) return n;
    unsigned long long int a = dnc(n,k/2);
    a = (a*a)%20170317;
    if (k%2==1) a = (a*n)%20170317;
    return a;
}

int main() {
    int m, i;
    unsigned long long int n, k;
    scanf("%d", &m);
    for (i=0;i<m;i++) {
        scanf("%llu", &n);
        scanf("%llu", &k);
        printf("%llu\n", dnc(n%20170317,k));
    }
    return 0;
}
