
#ifndef PROJECT4_GRAPH2_H
#define PROJECT4_GRAPH2_H
#include <vector>
#include <list>
#include <queue>
//#include<bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;


class Graph2
{
public:
    int V;


    list< pair<int, int> > *adj;
    vector<int> parent;
    vector<int> key;
    list<int> *adjOfTree;
    vector<int> depth;
    Graph2(int V);  // Constructor

    void addEdge(int u, int v, int w);

    void prim();
    int findDistance(int a ,int b);
    void toAdjMatrix();
    void findDepth();
};


#endif //PROJECT4_GRAPH2_H
