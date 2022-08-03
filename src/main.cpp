#include <iostream>
#include <climits>
#include "Graph.h"

using namespace std;

int mindistance(float shortestdistance[], bool shortestpathtree[],int sizeofgraph) //tabe baraye peyda kardane indexe kamtarin meghdar
{
    float min = INT_MAX; //kamtarin meghdar
    int min_index; //indexe kamtarin meghdar
    for (int i = 0; i < sizeofgraph; i++)
    {
        if (shortestpathtree[i] == false && shortestdistance[i] <= min) //agar node dakhele shortest path tree nabood va meghdar kamtar az min bood
        {
            min = shortestdistance[i]; //gharar giri meghdare minimum
            min_index = i; //gharar giri indexe meghdare minimum
        }
    }
    return min_index;
}
 
void printpathnodes(float parentnode[], int j, Graph a) //tabe print node haye masir ba estefade az parent node
{
    if (parentnode[j] == -1) //agar parent nadashte bashad
    {
        return;
    }
    printpathnodes(parentnode, parentnode[j],a);
    cout << a.getnodename(j) << "    "; //print
}

void printpathedges(float parentnode[], int j, Graph a) //tabe print edge haye masir ba estefade az parent node
{
    if (parentnode[j] == -1) //agar parent nadashte bashad
    {
        return;
    }
    printpathedges(parentnode, parentnode[j],a);
    int start = j; //index shoru
    int end = parentnode[j]; //index payan
    if(!(end == -1))
    {
        cout << a.getedgename(start,end) << "    "; //print
    }
}

float printlength(float parentnode[], int j, Graph a) //tabe mohasebe fasele (length)
{
    static float dist;
    if (parentnode[j] == -1) //agar parent nadashte bashad
    {
        return 0;
    }
    printlength(parentnode, parentnode[j],a);
    int start = j; //indexe shoru
    int end = parentnode[j]; //indexe payan
    if(!(end == -1))
    {
        dist += a.getlength(start,end); //ezafe shodan be moteghayere dist ke static ast
    }
    return dist;
}

void printpathtoshandiz(float shortestdistance[], float parentnode[], Graph a) //tabe koli baraye print
{
    cout << "The minimum cost for a path between Shandiz Haji Restaurant and Ghadir Dormitory considering the traffic is : " << shortestdistance[15] << endl;
    cout << "The length for this path is : " << printlength(parentnode, 15, a) << endl;
    cout << "Due to the traffic, your Path should be from these Squares/Intersections:" << endl;
    printpathnodes(parentnode, 15, a);
    cout << endl;
    cout << "Due to the traffic, your path should be from these Streets:" << endl;
    printpathedges(parentnode,15,a);
    cout << endl;
}
 
void dijkstra(Graph a, int src, int sizeofgraph) //tabe algorithme dijkstra
{
    float** graph = a.getadj(); //estefade az matrixe mojaverat
    float shortestdistance[sizeofgraph]; //array baraye negahdari kootah tarin masir az mabda
    shortestdistance[src] = 0; //kootah tarin masir mabda az mabda 0 ast
    for (int i = 1; i < sizeofgraph; i++)
    {
        shortestdistance[i] = INT_MAX; //gharar dadane meghdare bi nahayat baraye baghie node ha
    }
    bool shortestpathtree[sizeofgraph] = { false }; //array baraye vojude node dar shortest path tree
    float parentnode[sizeofgraph] = { -1 }; //array baraye parent node
    for (int i = 0; i < sizeofgraph - 1; i++) 
    {
        int u = mindistance(shortestdistance, shortestpathtree,sizeofgraph); //farakhani tabe baraye peyda kardane indexe kamtarin meghdar (u)
        shortestpathtree[u] = true; //true shodane node baraye boodan dar shortest path tree
        for (int v = 0; v < sizeofgraph; v++)
        {
            if ((!shortestpathtree[v] && graph[u][v]) && (shortestdistance[u] + graph[u][v] < shortestdistance[v])) //relaxation
            {
                parentnode[v] = u; //gharargiri node parent
                shortestdistance[v] = shortestdistance[u] + graph[u][v]; //gharar giri meghdare kamtar
            }
        }
    }
    printpathtoshandiz(shortestdistance, parentnode,a); //farakhani tabe print
}


int main()
{
    Graph a; //sakhte graphe khali
    a.setnewnode("Shandiz Haji Restaurant" , 0); //ezafe kardane node ha
    a.setnewnode("Mofatteh Square" , 1);
    a.setnewnode("Takhti Bridge" , 2);
    a.setnewnode("Imam Square" , 3);
    a.setnewnode("Imamzadeh Abdollah Square" , 4);
    a.setnewnode("Shariati 4-way" , 5);
    a.setnewnode("Buali Sina Square" , 6);
    a.setnewnode("Shariati Square" , 7);
    a.setnewnode("Shokrieh/Mirzade Eshghi Intersection" , 8);
    a.setnewnode("Shokrieh/Besat Blvd Intersection" , 9);
    a.setnewnode("Pajuhesh Square" , 10);
    a.setnewnode("Javadieh/Pasdaran Intersection" , 11);
    a.setnewnode("Basu Enterance" , 12);
    a.setnewnode("Zamani/Pasdaran Intersection" , 13);
    a.setnewnode("Zamani/Ahmadiroshan Intersection" , 14);
    a.setnewnode("Ghadir Dormitory" , 15);
    a.createadjmatrix(); //sakhte matrix mojaverate khali

    a.setnewedge(a.getnode("Shandiz Haji Restaurant"),a.getnode("Mofatteh Square"),"Molla Jalil Alley",0.2,1,0); //ezafe kardane edge ha
    a.setnewedge(a.getnode("Shandiz Haji Restaurant"),a.getnode("Imam Square"),"Shandiz to Imam Sq Alley",0.2,3,1);
    a.setnewedge(a.getnode("Shandiz Haji Restaurant"),a.getnode("Takhti Bridge"),"Shandiz to Takhti Bridge Alley",0.2,1,2);
    a.setnewedge(a.getnode("Mofatteh Square"),a.getnode("Takhti Bridge"),"Mofatteh Blvd",1.4,2,3);
    a.setnewedge(a.getnode("Mofatteh Square"),a.getnode("Imam Square"),"Shohada St",1.3,3,4);
    a.setnewedge(a.getnode("Imam Square"),a.getnode("Takhti Bridge"),"Takhti St",0.2,2,5);
    a.setnewedge(a.getnode("Imam Square"),a.getnode("Imamzadeh Abdollah Square"),"Babataher St",1.9,2,6);
    a.setnewedge(a.getnode("Imamzadeh Abdollah Square"),a.getnode("Shariati 4-way"),"Ayatolah Kashani Blvd",2,1,7);
    a.setnewedge(a.getnode("Imam Square"),a.getnode("Shariati 4-way"),"Ayatolah Kashani Blvd",2.1,3,8);
    a.setnewedge(a.getnode("Takhti Bridge"),a.getnode("Buali Sina Square"),"Madani Blvd",2.4,2,9);
    a.setnewedge(a.getnode("Shariati 4-way"),a.getnode("Buali Sina Square"),"Khajeh Rashid Blvd",1.9,2,10);
    a.setnewedge(a.getnode("Shariati 4-way"),a.getnode("Shariati Square"),"Shariati St",0.1,3,11);
    a.setnewedge(a.getnode("Shariati Square"),a.getnode("Shokrieh/Mirzade Eshghi Intersection"),"Mirzade Eshghi",0.1,1,12);
    a.setnewedge(a.getnode("Buali Sina Square"),a.getnode("Shokrieh/Mirzade Eshghi Intersection"),"Pastor St to Shokrieh",3,3,13);
    a.setnewedge(a.getnode("Shariati Square"),a.getnode("Javadieh/Pasdaran Intersection"),"Pasdaran to Javadieh St",0.1,2,14);
    a.setnewedge(a.getnode("Javadieh/Pasdaran Intersection"),a.getnode("Zamani/Pasdaran Intersection"),"Javadieh to Zamani St",1.1,1,15);
    a.setnewedge(a.getnode("Zamani/Pasdaran Intersection"),a.getnode("Zamani/Ahmadiroshan Intersection"),"Zamani St",1.8,2,16);
    a.setnewedge(a.getnode("Javadieh/Pasdaran Intersection"),a.getnode("Basu Enterance"),"Javadieh St",2,1,17);
    a.setnewedge(a.getnode("Shariati Square"),a.getnode("Pajuhesh Square"),"Mahdieh St",3.5,2,18);
    a.setnewedge(a.getnode("Shokrieh/Mirzade Eshghi Intersection"),a.getnode("Shokrieh/Besat Blvd Intersection"),"Shokrieh St",4.1,2,19);
    a.setnewedge(a.getnode("Shokrieh/Besat Blvd Intersection"),a.getnode("Pajuhesh Square"),"Besat Blvd",1.2,3,20);
    a.setnewedge(a.getnode("Pajuhesh Square"),a.getnode("Basu Enterance"),"Pajuhesh to Basu Enterance",0.8,3,21);
    a.setnewedge(a.getnode("Zamani/Ahmadiroshan Intersection"),a.getnode("Basu Enterance"),"Zamani to Basu Enterance",0.6,3,22);
    a.setnewedge(a.getnode("Basu Enterance"),a.getnode("Ghadir Dormitory"),"BASU",0.2,1,23);
    dijkstra(a,0,16); //farakhani dijkstra
}