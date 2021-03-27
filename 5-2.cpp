#include <stdio.h>

int main() {
    int i, j, n;
    int length;

    long long int a;
    int cnt;

    int NUM = 20170429;

    int seq[1010];
    int inc[1010];
    int icnt[1010];
    int dec[1010];
    int dcnt[1010];
    int tt, t;
    scanf("%d", &t);
    for (tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &seq[i]);
            inc[i] = 1;
            icnt[i] = 1;
            dec[i] = 1;
            dcnt[i] = 1;
        }

        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (seq[i] > seq[j]) {
                    if (inc[j] >= inc[i]) {
                        inc[i] = inc[j]+1;
                        icnt[i] = icnt[j];
                    }
                    else if (inc[j]+1 == inc[i]) {
                        icnt[i] += icnt[j];
                        icnt[i] %= NUM;
                    }
                }
            }
        }

        for (i = n-2; i >= 0; i--) {
            for (j = i+1; j < n; j++) {
                if (seq[i] > seq[j]) {
                    if (dec[j] >= dec[i]) {
                        dec[i] = dec[j]+1;
                        dcnt[i] = dcnt[j];
                    }
                    else if (dec[j]+1 == dec[i]) {
                        dcnt[i] += dcnt[j];
                        dcnt[i] %= NUM;
                    }
                }
            }
        }

        length = 0;
        cnt = 0;

        for (i = 0; i < n; i++) {
            a = icnt[i];
            a *= dcnt[i];
            a %= NUM;
            if (length < inc[i]+dec[i]) {
                length = inc[i]+dec[i];
                cnt = a;
                cnt %= NUM;
            }
            else if (length == inc[i]+dec[i]) {
                cnt += a;
                cnt %= NUM;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
