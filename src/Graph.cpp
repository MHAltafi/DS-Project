#include <iostream>
#include "Graph.h"

using namespace std;

void Graph::setnewnode(string nameofnode , int nodetag)
{
    node newnode;
    newnode.name = nameofnode;
    newnode.tag = nodetag;
    nodes.push_back(newnode);
}

void Graph::setnewedge(node starting, node ending, string nameofedge, float length, int traffic)
{
    edge newedge;
    newedge.start = starting;
    newedge.end = ending;
    newedge.weight = length*traffic;
    newedge.name = nameofedge;
    edges.push_back(newedge);
}

node Graph::getnode(string name)
{
    for (auto i : nodes)
    {
        if(i.name == name)
        {
            return i;
        }
    }
}