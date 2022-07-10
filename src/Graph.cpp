#include <iostream>
#include "Graph.h"
#include <iomanip>

using namespace std;

void Graph::setnewnode(string nameofnode , int nodetag)
{
    node newnode;
    newnode.name = nameofnode;
    newnode.tag = nodetag;
    nodes.push_back(newnode);
}

void Graph::setnewedge(node starting, node ending, string nameofedge, float length, int traffic, int edgetag)
{
    edge newedge;
    newedge.start = starting;
    newedge.end = ending;
    newedge.weight = length*traffic;
    newedge.name = nameofedge;
    adjmatrix[starting.tag][ending.tag] = newedge.weight;
    adjmatrix[ending.tag][starting.tag] = newedge.weight;
    newedge.tag = edgetag;
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

void Graph::createadjmatrix()
{
    adjmatrix = new float *[nodes.size()];
    for (int i = 0; i < nodes.size(); i++)
    {
        adjmatrix[i] = new float[nodes.size()];
    }
    for (size_t i = 0; i < nodes.size(); i++)
    {
        for (size_t j = 0; j < nodes.size(); j++)
        {
            adjmatrix[i][j] = 0;
        }
        
    }
    
}

void Graph::printadj()
{
    for (size_t i = 0; i < nodes.size(); i++)
    {
        for (size_t j = 0; j < nodes.size(); j++)
        {
            cout << left << setw(8) << adjmatrix[i][j];
        }
        cout <<" " << endl;
        
    }
}

float** Graph::getadj()
{
    return adjmatrix;
}

string Graph::getnodename(int nodetag)
{
    for(auto i : nodes)
    {
        if(i.tag == nodetag)
        {
            return i.name;
        }
    }
}

string Graph::getedgename(int edgetag)
{
    for(auto i : edges)
    {
        if(i.tag == edgetag)
        {
            return i.name;
        }
    }
}