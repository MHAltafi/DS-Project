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
    float length;
};

class Graph
{
    private:
        vector<node> nodes; //vectore negahdari node ha
        vector<edge> edges; //vectore negahdari edge ha
        float** adjmatrix; //matrixe mojaverat
        
    public:
        void setnewnode(string nameofnode , int nodetag); //tabe sakhte node jadid
        void setnewedge(node starting, node ending, string nameofedge, float length, int traffic, int edgetag); //tabe sakhte edge jadid
        node getnode(string name); //tabe get baraye node ba esme morede nazar
        void createadjmatrix(); //tabe sakhte matrix mojaverat baad az ezafe kardane hame node ha
        float** getadj(); //tabe get baraye matrix mojaverat
        string getnodename(int nodetag); //tabe get baraye esme node ba estefade az tag
        string getedgename(int start, int end); //tabe get baraye esme edge ba estefade az tag shoru va payan
        float getlength(int start, int end); //tabe ge baraye lengthe edge ba estefade az tag shoru va payan
};

#endif