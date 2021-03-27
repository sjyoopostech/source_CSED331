#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class edge {
public :
    edge (int ss, int dd, int ww) {
        this->ss = ss;
        this->dd = dd;
        this->ww = ww;
    }
    int ss;
    int dd;
    int ww;
};

bool operator < (const edge &a, const edge &b) {
    return a.ww > b.ww;
}

int main() {
    int visited[10000];
    vector<edge> vv[10000];
    priority_queue<edge> pops;
    edge now(-1, -1, -1);

    unsigned int minw;
    int mins, mind;
    int cnt, weight;
    int i;
    int v, e;
    int ss, dd, ww;
    int tt, t;

    scanf("%d", &t);
    for (tt = 0; tt < t; tt++) {
        scanf("%d", &v);
        scanf("%d", &e);

        while (!pops.empty()) {
            pops.pop();
        }

        for (i = 0; i < v; i++) {
            vv[i].clear();
            visited[i] = 0;
        }

        minw = -1;
        for (i = 0; i < e; i++) {
            scanf("%d", &ss);
            scanf("%d", &dd);
            scanf("%d", &ww);
            vv[ss].push_back(edge(ss,dd,ww));
            vv[dd].push_back(edge(dd,ss,ww));
            if (ww < minw) {
                minw = ww;
                mins = ss;
                mind = dd;
            }
        }

        visited[mins] = 1;
        visited[mind] = 1;
        cnt = 2;
        weight = minw;
        for (i = 0; i < vv[mins].size(); i++) {
            pops.push(vv[mins][i]);
        }
        for (i = 0; i < vv[mind].size(); i++) {
            pops.push(vv[mind][i]);
        }
        while (cnt < v) {
            now = pops.top();
            pops.pop();
            if (!visited[now.ss]) {
                visited[now.ss] = 1;
                cnt++;
                weight += now.ww;
                for (i = 0; i < vv[now.ss].size(); i++) {
                    pops.push(vv[now.ss][i]);
                }
            }
            if (!visited[now.dd]) {
                visited[now.dd] = 1;
                cnt++;
                weight += now.ww;
                for (i = 0; i < vv[now.dd].size(); i++) {
                    pops.push(vv[now.dd][i]);
                }
            }
        }
        printf("%d\n", weight);
    }

    return 0;
}
