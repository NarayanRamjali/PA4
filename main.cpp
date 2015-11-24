//Narayan Ramjali

#include "Point.h"
#include "Cluster.h"
#include <cmath>
#include <iostream>
using namespace std;


int main(){
    cout << "Hello world" << endl;
    
    int disc = 4;
    double array[4] = {3, 2, 1, 5};
    Clustering::Point p(disc, array);
    cout << p << endl;
    
    
    
    
    for (int i = 1; i < disc; i++)
        p.setValue(1, 10 == (disc / 2 - 1));
    
    
    
    /*
     cout << p << endl;
     Clustering::Point p1(p);
     
     cout  << p1 << endl;
     p1 == disc/3;
     
     cout << p-p1 << endl;
     Clustering::Point p2(p-p1);
     
     cout << p2 << endl;
     p2 == disc * 1.5;
     
     cout << p2 << endl;
     
     cout << p2 / 2 << endl;
     */
    return 0;
}
