#include <iostream>
#include <vector>
#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

struct node
{
    string name;
    int tag;
};

struct edge
{
    node start, end;
    float weight;
    string name;
};

class Graph
{
    private:
        vector<node> nodes;
        vector<edge> edges;
        //adj matrix
        float** adjmatrix;
        
    public:
        void setnewnode(string nameofnode , int nodetag);
        void setnewedge(node starting, node ending, string nameofedge, float length, int traffic);
        node getnode(string name);
};





#endif
