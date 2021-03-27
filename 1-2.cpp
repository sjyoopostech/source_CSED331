#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, index;
    int a[100010];
    char c[10];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        index = 0;
        for (j = 0; j < m; j++) {
            scanf("%s", c);
            if (c[1] == 'u') {
                scanf("%d", &k);
                a[index] = k;
                index++;
            }
            else {
                index--;
                printf("%d ", a[index]);
            }
        }
        printf("\n");
        for (j = 0; j < index; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    return 0;
}
