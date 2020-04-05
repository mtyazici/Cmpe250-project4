#include <iostream>
#include <fstream>
#include <set>

#include "Graph2.h"
using namespace std;
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

    ifstream infile(argv[1]);
    int N;
    int M;
    infile>>N >> M ;

    vector<int> ladder;
    vector<vector<int>> adjMatrix;
    for(int i = 0 ; i<N-1 ; ++i) {
        int ladderr;

            for (int k = 0; k < M; ++k) {
                infile >> ladderr;
                ladder.push_back(ladderr);
                vector<int> adjs;

                adjs.push_back(i * M + k + M);
                if (k < M - 1) {
                    adjs.push_back(i * M + k + 1);
                }
                adjMatrix.push_back(adjs);
            }
    }

    for (int k = 0; k < M; ++k) {
        int ladderr;
        infile >> ladderr;
        ladder.push_back(ladderr);
        vector<int> adjs;
        if (k < M - 1) {
            adjs.push_back((N-1) * M + k + 1);
        }
        adjMatrix.push_back(adjs);

    }



    Graph2 graph = Graph2(M*N);

    for(int i = 0 ; i < M*N; i++){
        for(auto k = adjMatrix[i].begin(); k != adjMatrix[i].end();k++){
            graph.addEdge(i, *k, abs(ladder[i] - ladder[*k]));
        }
    }

    graph.prim();

    graph.toAdjMatrix();

    graph.findDepth();

    int nofquerries;
    infile>>nofquerries;
    ofstream myfile;
    myfile.open (argv[2]);

    for(int i = 0 ; i < nofquerries; ++i){
        int x1,x2,y1,y2;
        infile>>x1>>x2>>y1>>y2;
        myfile<<graph.findDistance((x1-1)*M+x2-1,(y1-1)*M+y2-1)<<endl;
    }


    return 0;
}