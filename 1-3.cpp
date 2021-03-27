#include <stdio.h>
#include <stdlib.h>

void mergesort(int *a, int s, int f, int *v, int *w) {
    if (f - s == 1) return;

    int m = (f+s)/2;
    mergesort(a, s, m, v, w);
    mergesort(a, m, f, v, w);
    int i;
    for (i = 0; i < m-s; i++) {
        v[i] = a[s+i];
    }
    for (i = 0; i < f-m; i++) {
        w[i] = a[m+i];
    }
    int e, g, h;
    e = 0;
    g = 0;
    h = s;
    for (i = 0; i < f-s; i++) {
        if (e >= m-s) {
            a[h] = w[g];
            h++;
            g++;
        }
        else if (g >= f-m) {
            a[h] = v[e];
            e++;
            h++;
        }
        else if (v[e] < w[g]) {
            a[h] = v[e];
            e++;
            h++;
        }
        else {
            a[h] = w[g];
            h++;
            g++;
        }
    }
    return;
}

int main()
{
    int a[100010];
    int v[55000];
    int w[55000];
    int n, m, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%d", &a[j]);
        }
        mergesort(a, 0, m, v, w);
        for (j = 0; j < m; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }


    return 0;
}
