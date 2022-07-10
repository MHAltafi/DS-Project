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
    int tag;
};

class Graph
{
    private:
        vector<node> nodes;
        vector<edge> edges;
        float** adjmatrix;
        
    public:
        void setnewnode(string nameofnode , int nodetag);
        void setnewedge(node starting, node ending, string nameofedge, float length, int traffic, int edgetag);
        node getnode(string name);
        void createadjmatrix();
        void printadj();
        float** getadj();
        string getnodename(int nodetag);
        string getedgename(int edgetag);
};





#endif
