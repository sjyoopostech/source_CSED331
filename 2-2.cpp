#include <stdio.h>

int main() {
    int storage[100005];
    int num,n,i,j,k;
    int s,t,h;
    scanf("%d", &num);
    for (i=0;i<num;i++) {
        for (j=0;j<100005;j++) {
            storage[j]=0;
        }
        scanf("%d",&n);
        for (j=0;j<n;j++) {
            scanf("%d",&s);
            scanf("%d",&t);
            scanf("%d",&h);
            for (k=s;k<t;k++) {
                if (storage[k]<h) {
                    storage[k]=h;
                }
            }
        }
        s=0;
        h=0;
        for (j=0;j<100005;j++) {
            if (h!=storage[j]) {
                if (h) {
                    printf("%d %d %d\n",s,j,h);
                }
                s=j;
                h=storage[j];
            }
        }
    }
    return 0;
}
