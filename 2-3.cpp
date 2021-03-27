#include <stdio.h>
#include <stdlib.h>



void rec(long long int* alpha, int t) {
    if (t==0) {
        alpha[0] = 1;
        alpha[1] = 0;
        alpha[2] = 0;
    }
    else if (t==1) {
        alpha[0] = 1;
        alpha[1] = 1;
        alpha[2] = 0;
    }
    else {
        rec(alpha, t/2);
        long long int x = alpha[0]*alpha[0]+alpha[1]*alpha[1];
        long long int y = alpha[0]*alpha[1]+alpha[1]*alpha[2];
        long long int z = alpha[1]*alpha[1]+alpha[2]*alpha[2];
        alpha[0] = x%20170317;
        alpha[1] = y%20170317;
        alpha[2] = z%20170317;
        if (t%2==1) {
            alpha[2] = alpha[1];
            alpha[1] = alpha[0];
            alpha[0] = (alpha[1]+alpha[2])%20170317;
        }
    }
}

long long int fib(int t) {
    long long int* a = (long long int*)malloc(3*sizeof(long long int));
    rec(a, t);
    return a[1];
}

int main() {
    int t,i,k;
    scanf("%d", &t);
    for (i=0;i<t;i++) {
        scanf("%d",&k);
        printf("%lld\n",fib(k));
    }
    return 0;
}
