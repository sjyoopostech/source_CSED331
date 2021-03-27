#include <stdio.h>
#include <vector>

using namespace std;

class se {
public :
    int des;
    int wht;
    se(int d, int w) {
        des = d;
        wht = w;
    }
};

int main() {
    unsigned long long int minimum;
    int vertexnum;
    unsigned int _des, _wht;


    vector<se> edge[10000];
    vector<se> edge2[10000];
    int visited[10000];
    unsigned long long int dista[10000];
    unsigned long long int distb[10000];
    int dep, des, wht;
    int v, e, i, j, k;
    int test, testi;
    scanf("%d", &test);
    for (testi=0;testi<test;testi++) {
        scanf("%d",&v);
        scanf("%d",&e);
        for (i = 0; i < v; i++) {
            edge[i].clear();
            edge2[i].clear();
        }
        for (i = 0; i < e; i++) {
            scanf("%d",&dep);
            scanf("%d",&des);
            scanf("%d",&wht);
            edge[dep].push_back(se(des,wht));
            edge2[des].push_back(se(dep,wht));
        }
        for (i = 0; i < v; i++) {
            visited[i] = 0;
            dista[i] = -1;
        }
        dista[0] = 0;
        while (true) {
            minimum = -1;
            vertexnum = -1;
            for (i = 0; i < v; i++) {
                if (visited[i]) continue;
                if (minimum <= dista[i]) continue;
                minimum = dista[i];
                vertexnum = i;
            }
            if (minimum == -1) {
                break;
            }
            visited[vertexnum] = 1;
            for (i = 0; i < edge[vertexnum].size(); i++) {
                _des = edge[vertexnum][i].des;
                _wht = edge[vertexnum][i].wht;
                if (dista[_des] > dista[vertexnum] + _wht) {
                    dista[_des] = dista[vertexnum] + _wht;
                }
            }
        }
        for (i = 0; i < v; i++) {
            visited[i] = 0;
            distb[i] = -1;
        }
        distb[v-1] = 0;
        while (true) {
            minimum = -1;
            vertexnum = -1;
            for (i = 0; i < v; i++) {
                if (visited[i]) continue;
                if (minimum <= distb[i]) continue;
                minimum = distb[i];
                vertexnum = i;
            }
            if (minimum == -1) {
                break;
            }
            visited[vertexnum] = 1;
            for (i = 0; i < edge2[vertexnum].size(); i++) {
                _des = edge2[vertexnum][i].des;
                _wht = edge2[vertexnum][i].wht;
                if (distb[_des] > distb[vertexnum] + _wht) {
                    distb[_des] = distb[vertexnum] + _wht;
                }
            }
        }

        minimum = dista[v-1];
        for (i = 0; i < v; i++) {
            if (dista[i] == -1) continue;
            for (j = 0; j < edge[i].size(); j++) {
                k = edge[i][j].des;
                if (distb[k] == -1) continue;
                if (minimum > dista[i] + distb[k]) {
                    minimum = dista[i] + distb[k];
                }
            }
        }
        printf("%I64d\n", minimum);
    }


    return 0;
}
