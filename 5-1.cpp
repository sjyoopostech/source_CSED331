#include <stdio.h>

int main() {
    int bag[1000001];
    int weight[1000], value[1000];
    int i, j, ww, vv;
    int n, w;
    int tt, t;
    scanf("%d", &t);
    for (tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        scanf("%d", &w);
        for (i = 0; i < n; i++) scanf("%d", &weight[i]);
        for (i = 0; i < n; i++) scanf("%d", &value[i]);

        for (i = 0; i <= w; i++) {
            bag[i] = 0;
        }

        for (i = 0; i < n; i++) {
            ww = weight[i];
            vv = value[i];
            for (j = w; j >= 0; j--) {
                if (j >= ww) {
                    if (bag[j] < bag[j-ww]+vv) {
                        bag[j] = bag[j-ww]+vv;
                    }
                }
            }
        }

        for (i = 0; i <= w; i++) {
            if (bag[0] < bag[i]) bag[0] = bag[i];
        }

        printf("%d\n", bag[0]);
    }

    return 0;
}
