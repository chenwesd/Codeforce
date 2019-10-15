struct edge {
    int v1;
    int v2;
    int w;
};
#include <bits/stdc++.h>
using namespace std;
#define oo 0xffffff

int main(int argc, char**argv) {

    edge eg[100002];
    int v, e;
    while (cin >> v >> e) {
        for (int i = 0; i < e; i++) {
            cin >> eg[i].v1 >> eg[i].v2 >> eg[i].w;
        }

        bool inq[100002] = {false};
        for (int i = 0; i < 100002; i++)
            inq[i] = false;
        queue<int> Q;
        int dis[100002];
        for (int i = 0; i < 100002; i++)
            dis[i] = oo;
        dis[1] = 0;
        Q.push(1);
        inq[1] = true;
        int pre[100002];
        for (int i = 0; i < 100002; i++)
            pre[i] = -1;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            inq[cur] = false;
            for (int i = 0; i < e; i++) {
                int nxt = eg[i].v2;
                if (eg[i].v1 == cur && (dis[cur] + eg[i].w < dis[nxt])) {
                    dis[nxt] = dis[cur] + eg[i].w;
                    pre[nxt] = cur;
                    if (inq[nxt] == false) {
                        Q.push(nxt);
                        inq[nxt] = true;
                    }
                }
                else if(eg[i].v2 == cur && (dis[cur] + eg[i].w < dis[eg[i].v1]))
                {
                    dis[eg[i].v1] = dis[cur] + eg[i].w;
                    pre[eg[i].v1] = cur;
                    if (inq[eg[i].v1] == false) {
                        Q.push(eg[i].v1);
                        inq[eg[i].v1] = true;
                    }
                }
            }
        }
        if (dis[v] == oo)
        {cout << -1 << endl;}
        else {
            int pr = v;
            stack<int> si;
            si.push(v);
            while (pre[pr] != -1) {
                si.push(pre[pr]);
                pr = pre[pr];
            }
            while (!si.empty()) {
                cout << si.top() << " ";
                si.pop();
            }
        }
    }
}
