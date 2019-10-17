struct edge {
    int v;
    int w;
    edge(int v,int w):v(v),w(w){}
};
#include <bits/stdc++.h>
using namespace std;
#define oo 0xffffff

int main(int argc, char**argv) {
    vector<edge> eg[100002];
    ios_base::sync_with_stdio(false);
    int v, e;
    while (cin >> v >> e) {
        int v1,v2,w;
        for (int i = 0; i < e; i++) {
            cin >> v1 >> v2 >> w;
            edge e1(v1,w);
            edge e2(v2,w);
            eg[v1].push_back(e2);
            eg[v2].push_back(e1);
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
            for (int i = 0; i < eg[cur].size(); i++) {
                int nxt = eg[cur][i].v;
                if (dis[cur] + eg[cur][i].w< dis[nxt]) {
                    dis[nxt] = dis[cur] + eg[cur][i].w;
                    pre[nxt] = cur;
                    if (inq[nxt] == false) {
                        Q.push(nxt);
                        inq[nxt] = true;
                    }
                }
            }
        }
        if (dis[v] == oo)
        {cout << -1 << "\n";}
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
            cout<<"\n";
        }
    }
}
