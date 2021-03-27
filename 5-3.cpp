#include <stdio.h>
#include <vector>

using namespace std;

int main() {

    int now;
    int v, e;
    int i, j;
    int in, out;

    vector<int> inedge[10000];
    vector<int> outedge[10000];
    int visitededge[10000];
    int visited[10000];
    long long int num[10000];

    int tt, t;
    scanf("%d", &t);
    for (tt = 0; tt < t; tt++) {
        scanf("%d", &v);
        scanf("%d", &e);
        for (i = 0; i < v; i++) {
            inedge[i].clear();
            outedge[i].clear();
            num[i] = 0;
            visited[i] = 0;
            visitededge[i] = 0;
        }
        num[0] = 1;

        for (i = 0; i < e; i++) {
            scanf("%d", &in);
            scanf("%d", &out);
            inedge[out].push_back(in);
            outedge[in].push_back(out);
            visitededge[out]++;
        }


        for (i = 0; i < v; i++) {
            now = 0;
            for (j = 0; j < v; j++) {
                if (visitededge[j]==0 && visited[j]==0) {
                    now = j;
                    break;
                }
            }
            visited[now] = 1;
            for (j = 0; j < outedge[now].size(); j++) {
                visitededge[outedge[now][j]]--;
            }
            for (j = 0; j < inedge[now].size(); j++) {
                num[now] += num[inedge[now][j]];
                num[now] %= 2017231920182101;
            }
        }
        //for (i = 0; i < v; i++) printf("%d ", num[i]);

        printf("%lld\n", num[v-1]);


    }
    return 0;
}
