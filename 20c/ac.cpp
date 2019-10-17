#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v;
    int w;

    edge(int v, int w) : v(v), w(w) {
    }

    bool operator<(const edge &rhs) const {
        if(w != rhs.w)
            return w < rhs.w;
        else
            return v < rhs.v; 
    }

    bool operator>(const edge &rhs) const {
        if(w != rhs.w)
            return w > rhs.w;
        else
            return v > rhs.v; 
    }
};
#define oo INT_MAX
#define MAXN 100003
int main(int argc, char**argv) {
    vector<edge> eg[MAXN];
    ios_base::sync_with_stdio(false);
    int v, e;
    while (cin >> v >> e) {
        int v1, v2, w;
        for (int i = 0; i < e; i++) {
            cin >> v1 >> v2 >> w;
            edge e1(v1, w);
            edge e2(v2, w);
            eg[v1].push_back(e2);
            eg[v2].push_back(e1);
        }

        bool inq[MAXN] = {false};
        for (int i = 0; i < MAXN; i++)
            inq[i] = false;
        int dis[MAXN];
        for (int i = 0; i < MAXN; i++)
            dis[i] = oo;
        int pre[MAXN];
        for (int i = 0; i < MAXN; i++)
            pre[i] = -1;
        priority_queue<edge, vector<edge>, greater < edge>> PQ;
        dis[1] = 0;
        PQ.push(edge(1, 0));
        bool arrive=false;
        while (!PQ.empty()) {
            int cur = PQ.top().v;
            if(cur==v)
            {
                arrive=true;
                break;
            }
            PQ.pop();
            inq[cur] = true;
            for (int i = 0; i < eg[cur].size(); i++) {
                int nxt = eg[cur][i].v;
                int wet = eg[cur][i].w;
                if (inq[nxt] == false&&dis[cur] + wet < dis[nxt]) {
                    dis[nxt] = dis[cur] + wet;
                    pre[nxt] = cur;
                    PQ.push(edge(nxt,dis[nxt]));
                }
            }
        }
        if (arrive == false) {
            cout << -1 << "\n";
        } else {
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
            cout << "\n";
        }
    }
}
