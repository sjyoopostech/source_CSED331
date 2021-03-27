#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Path {
public :
    int x;
    int y;
    int length;
    int value;
    Path* next;

    Path(int x, int y, int value) {
        this->x = x;
        this->y = y;
        this->value = value;
        this->length = 1;
        this->next = NULL;
    }
};

bool comp (const Path* a, const Path* b) {
    return a->value > b->value;
}

int main() {
    Path* mount[1000][1000];
    vector<Path*> box;

    int xx, yy;
    int value;
    int i, j;
    int n, m;
    Path* now;

    int tt, t;
    scanf("%d", &t);
    for (tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        scanf("%d", &m);

        box.clear();
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &value);
                mount[i][j] = new Path(i,j,value);
                box.push_back(mount[i][j]);
            }
        }
        sort(box.begin(), box.end(), comp);

        for (i = 0; i < n*m; i++) {
            xx = box[i]->x;
            yy = box[i]->y;

            if (xx > 0) {
                if (mount[xx-1][yy]->value > box[i]->value) {
                    if (mount[xx-1][yy]->length >= box[i]->length) {
                        box[i]->length = mount[xx-1][yy]->length + 1;
                        box[i]->next = mount[xx-1][yy];
                    }
                    else if (box[i]->next->value > mount[xx-1][yy]->value && mount[xx-1][yy]->length+1 == box[i]->length) {
                        box[i]->length = mount[xx-1][yy]->length + 1;
                        box[i]->next = mount[xx-1][yy];
                    }
                }
            }
            if (xx < n-1) {
                if (mount[xx+1][yy]->value > box[i]->value) {
                    if (mount[xx+1][yy]->length >= box[i]->length) {
                        box[i]->length = mount[xx+1][yy]->length + 1;
                        box[i]->next = mount[xx+1][yy];
                    }
                    else if (box[i]->next->value > mount[xx+1][yy]->value && mount[xx+1][yy]->length+1 == box[i]->length) {
                        box[i]->length = mount[xx+1][yy]->length + 1;
                        box[i]->next = mount[xx+1][yy];
                    }
                }
            }
            if (yy > 0) {
                if (mount[xx][yy-1]->value > box[i]->value) {
                    if (mount[xx][yy-1]->length >= box[i]->length) {
                        box[i]->length = mount[xx][yy-1]->length + 1;
                        box[i]->next = mount[xx][yy-1];
                    }
                    else if (box[i]->next->value > mount[xx][yy-1]->value && mount[xx][yy-1]->length+1 == box[i]->length) {
                        box[i]->length = mount[xx][yy-1]->length + 1;
                        box[i]->next = mount[xx][yy-1];
                    }
                }
            }
            if (yy < m-1) {
                if (mount[xx][yy+1]->value > box[i]->value) {
                    if (mount[xx][yy+1]->length >= box[i]->length) {
                        box[i]->length = mount[xx][yy+1]->length + 1;
                        box[i]->next = mount[xx][yy+1];
                    }
                    else if (box[i]->next->value > mount[xx][yy+1]->value && mount[xx][yy+1]->length+1 == box[i]->length) {
                        box[i]->length = mount[xx][yy+1]->length + 1;
                        box[i]->next = mount[xx][yy+1];
                    }
                }
            }
        }
        xx = 0;
        yy = 0;
        value = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (value < mount[i][j]->length) {
                    xx = i;
                    yy = j;
                    value = mount[i][j]->length;
                }
                else if (value == mount[i][j]->length && mount[xx][yy]->value > mount[i][j]->value) {
                    xx = i;
                    yy = j;
                    value = mount[i][j]->length;
                }
            }
        }

        printf("%d\n", value);
        now = mount[xx][yy];
        while (now != NULL) {
            printf("%d ", now->value);
            now = now->next;
        }
        printf("\n");


    }
    return 0;
}
