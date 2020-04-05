//
// Created by student on 13.12.2018.
//

#include "Graph2.h"
// Allocates memory for adjacency list
Graph2::Graph2(int b)
{
    this->V = b;
    adj = new list<iPair> [V];
    parent = vector<int>(V, -1);
    key = vector<int>(V, INF);
    adjOfTree = new list<int>[V];
    depth = vector<int>(V,0);

}

void Graph2::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph2::prim() {

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    int src = 0;             //burası
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
}

int Graph2::findDistance(int s, int t) {
     int ds = depth[s];
     int dt = depth[t];

    int curmax= 0;
    if(ds>dt){
        int leng = ds-dt;
        for(int i = 0; i < leng;++i){
            curmax = max(curmax,key[s]);
            s= parent[s];
        }
    } else {
        int leng = dt-ds;
        for(int i = 0;i< leng;++i){
            curmax = max(curmax,key[t]);
            t= parent[t];
        }
    }

    int lengt = min(dt,ds);
    while(lengt != 0){
        if(s == t){
            break;
        }
        curmax = max(curmax,key[s]);
        curmax = max(curmax,key[t]);
        s = parent[s];
        t= parent[t];
        lengt--;

    }

    return curmax;


}
void Graph2::toAdjMatrix() {

    for( int i = 1 ; i < V ; i++){
        adjOfTree[parent[i]].push_back(i);
    }
}

void Graph2::findDepth() {
    queue<int> q ;
    queue<int> d;
    int source = 0;     //burası
    d.push(0);
    q.push(source);
    while(q.size() != 0){
        int current = q.front();
        depth[current] = d.front();
        q.pop();
        d.pop();
        list<int>::iterator i;
        for (i = adjOfTree[current].begin(); i != adjOfTree[current].end(); ++i) {
            q.push(*i);
            d.push(depth[current]+1);
        }
    }
}