#include <stdio.h>

void coloring(int grid[][1020], int x, int y) {
    int i, j;
    for (i = x-1; i <= x+1; i++) {
        for (j = y-1; j <= y+1; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                coloring(grid, i, j);
            }
        }
    }
}

int main() {
    int test, testi;
    int w, h;
    int cnt;
    int grid[1020][1020];
    int i, j;

    scanf("%d", &test);
    for (testi=0;testi<test;testi++) {
        scanf("%d",&h);
        scanf("%d",&w);
        cnt = 0;
        for (i = 0; i < h+10; i++) {
            for (j = 0; j < w+10; j++) {
                grid[i][j] = 0;
            }
        }
        for (i = 5; i < h+5; i++) {
            for (j = 5; j < w+5; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        for (i = 5; i < h+5; i++) {
            for (j = 5; j < w+5; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                    grid[i][j] = 0;
                    coloring(grid, i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
