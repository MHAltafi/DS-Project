#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph a;
    a.setnewnode("Shandiz Haji" , 0);
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

    a.setnewedge(a.getnode("Shandiz Haji"),a.getnode("Mofatteh Square"),"Molla Jalil Alley",0.2,1);
    a.setnewedge(a.getnode("Shandiz Haji"),a.getnode("Imam Square"),"Shandiz to Imam Sq Alley",0.2,3);
    a.setnewedge(a.getnode("Shandiz Haji"),a.getnode("Takhti Bridge"),"Shandiz to Takhti Bridge Alley",0.2,1);
    a.setnewedge(a.getnode("Mofatteh Square"),a.getnode("Takhti Bridge"),"Mofatteh Blvd",1.4,2);
    a.setnewedge(a.getnode("Mofatteh Square"),a.getnode("Imam Square"),"Shohada St",1.3,3);
    a.setnewedge(a.getnode("Imam Square"),a.getnode("Takhti Bridge"),"Takhti St",0.2,2);
    a.setnewedge(a.getnode("Imam Square"),a.getnode("Imamzadeh Abdollah Square"),"Babataher St",1.9,2);
    a.setnewedge(a.getnode("Imamzadeh Abdollah Square"),a.getnode("Shariati 4-way"),"Ayatolah Kashani Blvd",2,1);
    a.setnewedge(a.getnode("Imam Square"),a.getnode("Shariati 4-way"),"Ayatolah Kashani Blvd",2.1,3);
    a.setnewedge(a.getnode("Takhti Bridge"),a.getnode("Buali Sina Square"),"Madani Blvd",2.4,2);
    a.setnewedge(a.getnode("Shariati 4-way"),a.getnode("Buali Sina Square"),"Khajeh Rashid Blvd",1.9,2);
    a.setnewedge(a.getnode("Shariati 4-way"),a.getnode("Shariati Square"),"Khajeh Rashid Blvd",0.1,3);
    a.setnewedge(a.getnode("Shariati Square"),a.getnode("Shokrieh/Mirzade Eshghi Intersection"),"Mirzade Eshghi",0.1,1);
    a.setnewedge(a.getnode("Buali Sina Square"),a.getnode("Shokrieh/Mirzade Eshghi Intersection"),"Pastor St to Shokrieh",3,3);
    a.setnewedge(a.getnode("Shariati Square"),a.getnode("Javadieh/Pasdaran Intersection"),"Pasdaran to Javadieh St",0.1,2);
    a.setnewedge(a.getnode("Javadieh/Pasdaran Intersection"),a.getnode("Zamani/Pasdaran Intersection"),"Javadieh to Zamani St",1.1,1);
    a.setnewedge(a.getnode("Zamani/Pasdaran Intersection"),a.getnode("Zamani/Ahmadiroshan Intersection"),"Zamani St",1.8,2);
    a.setnewedge(a.getnode("Javadieh/Pasdaran Intersection"),a.getnode("Basu Enterance"),"Javadieh St",2,1);
    a.setnewedge(a.getnode("Shariati Square"),a.getnode("Pajuhesh Square"),"Mahdieh St",3.5,2);
    a.setnewedge(a.getnode("Shokrieh/Mirzade Eshghi Intersection"),a.getnode("Shokrieh/Besat Blvd Intersection"),"Shokrieh St",4.1,2);
    a.setnewedge(a.getnode("Shokrieh/Besat Blvd Intersection"),a.getnode("Pajuhesh Square"),"Besat Blvd",1.2,3);
    a.setnewedge(a.getnode("Pajuhesh Square"),a.getnode("Basu Enterance"),"Pajuhesh to Basu Enterance",0.8,3);
    a.setnewedge(a.getnode("Zamani/Ahmadiroshan Intersection"),a.getnode("Basu Enterance"),"Zamani to Basu Enterance",0.6,3);
    a.setnewedge(a.getnode("Basu Enterance"),a.getnode("Ghadir Dormitory"),"BASU",0.2,1);
}