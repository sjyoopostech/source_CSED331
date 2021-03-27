#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int test, a, v, e, e0, e1, i;
    scanf("%d", &test);
    unsigned int dist[100000];
    int visited[100000];
    vector<int> edge[100000];
    queue<int> vvvv;
    for (a = 0; a < test; a++) {
        scanf("%d", &v);
        scanf("%d", &e);
        for (i = 0; i < e; i++) {
            scanf("%d", &e0);
            scanf("%d", &e1);
            edge[e0].push_back(e1);
        }
        dist[0] = 0;
        visited[0] = 1;
        for (i = 1; i < v; i++) {
            dist[i] = -1;
            visited[i] = 0;
        }
        vvvv = queue<int> ();
        vvvv.push(0);
        while (true) {
            //unsigned int minimum = -1;
            int vnum = -1;
            /*for (i = 0; i < v; i++) {
                if (visited[i]) continue;
                if (minimum > dist[i]) {
                    minimum = dist[i];
                    vnum = i;
                }
            }*/
            if (vvvv.empty()) {
                printf("-1\n");
                break;
            }
            vnum = vvvv.front();
            vvvv.pop();
            //if (vnum >= 0) visited[vnum] = 1;
            if (vnum == v-1) {
                printf("%d\n", dist[vnum]);
                break;
            }

            for (i = 0; i < edge[vnum].size(); i++) {
                if (dist[edge[vnum][i]] > dist[vnum]+1) {
                    dist[edge[vnum][i]] = dist[vnum]+1;
                    if (!visited[edge[vnum][i]]) {
                        visited[edge[vnum][i]] = 1;
                        vvvv.push(edge[vnum][i]);
                    }
                }
            }
        }
        for (i = 0; i < v; i++) {
            edge[i].clear();
        }
    }

    return 0;
}
