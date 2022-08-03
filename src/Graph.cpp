#include <iostream>
#include "Graph.h"
#include <iomanip>

using namespace std;

void Graph::setnewnode(string nameofnode , int nodetag) //tabe sakhte node jadid
{
    node newnode; //node jadid ra ijad mikonim
    newnode.name = nameofnode; //gharar dadane esme node
    newnode.tag = nodetag; //gharar dadane tage node
    nodes.push_back(newnode); //pushback dar vectore node ha
}

void Graph::setnewedge(node starting, node ending, string nameofedge, float length, int traffic, int edgetag) //tabe sakhte edge jadid
{
    edge newedge; //edge jadid ra ijad mikonim
    newedge.start = starting; //gharar node dadane shorue edge
    newedge.end = ending; //gharar dadane node payan edge
    newedge.weight = length*traffic; //gharar dadane vazne edge dar graph
    newedge.name = nameofedge; //gharar dadane esme edge
    newedge.length = length; //gharar dadane toole edge (vazn bedoone dar nazar gereftane traffic)
    adjmatrix[starting.tag][ending.tag] = newedge.weight; //gharar dadane vazn dar matrix mojaverat
    adjmatrix[ending.tag][starting.tag] = newedge.weight; //gharar dadane vazn dar matrix mojaverat
    newedge.tag = edgetag; //gharar dadane tag
    edges.push_back(newedge); //pushback dar vectore edge ha
}

node Graph::getnode(string name) //tabe get baraye node ba esme morede nazar
{
    for (auto i : nodes)
    {
        if(i.name == name)
        {
            return i; //agar esm barabar bood, node morede nazar ra return mikonad
        }
    }
}

void Graph::createadjmatrix() //tabe sakhte matrix mojaverat baad az ezafe kardane hame node ha
{
    adjmatrix = new float *[nodes.size()]; //new kardane bode avale matrix mojaverat
    for (int i = 0; i < nodes.size(); i++)
    {
        adjmatrix[i] = new float[nodes.size()]; //new kardane bode dovome matrix mojaverat
    }
    for (size_t i = 0; i < nodes.size(); i++)
    {
        for (size_t j = 0; j < nodes.size(); j++)
        {
            adjmatrix[i][j] = 0; //gharar dadane meghdare 0 dar tamame khane ha
        }
    }  
}

float** Graph::getadj() //tabe get baraye matrix mojaverat
{
    return adjmatrix;
}

string Graph::getnodename(int nodetag) //tabe get baraye esme node ba estefade az tag
{
    for(auto i : nodes)
    {
        if(i.tag == nodetag)
        {
            return i.name; //agar tag barabar bood, esme node morede nazar ra return mikonad
        }
    }
}

string Graph::getedgename(int start, int end) //tabe get baraye esme edge ba estefade az tag shoru va payan
{
    for(auto i : edges)
    {
        if((i.start.tag == start && i.end.tag == end) || (i.start.tag == end && i.end.tag == start)) //sharte barabar boodane tag ha ke 2 halat darad
        {
            return i.name; //return kardane esme edge
        }
    }
}

float Graph::getlength(int start, int end) //tabe ge baraye lengthe edge ba estefade az tag shoru va payan
{
    for(auto i : edges)
    {
        if((i.start.tag == start && i.end.tag == end) || (i.start.tag == end && i.end.tag == start)) //sharte barabar boodane tag ha ke 2 halat darad
        {
            return i.length; //retrun kardane length
        }
    }
}