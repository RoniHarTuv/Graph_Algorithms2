// Id: 207199282
// Mail: Roniharpaz1@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace ariel;
/*
This demo class shows in a "taste" all the operators that can be performed on graphs.
*/
int main()
{
    cout << "/////////////////////////////////" << endl;
    cout << "/////////// GRAPH #1 ////////////" << endl;
    cout << "/////////////////////////////////" << endl;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0, 4, 0, 0}, // a not directed graph and connected
        {2, 0, 2, 0, 0, 0},
        {0, 2, 0, 0, 0, 4},
        {4, 0, 0, 0, 2, 0},
        {0, 0, 0, 2, 0, 2},
        {0, 0, 4, 0, 2, 0}};
    g1.loadGraph(graph);
    cout << g1 <<endl;
    ariel::Graph g2;
    graph = {
        {0, 5, 0, 0, 0, 0}, // a not directed graph and not connected
        {5, 0, 5, 0, 0, 0},
        {0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 10, 0},
        {0, 0, 0, 10, 0, 10},
        {0, 0, 0, 0, 10, 0}};
    g2.loadGraph(graph);
    cout << "/////////////////////////////////" << endl;
    cout << "/////////// GRAPH #2 ////////////" << endl;
    cout << "/////////////////////////////////" << endl;
    cout<< g2<<endl;;
    ariel::Graph g3;
    g3= g1+g2;
    cout << "///GRAPH#3= GRAPH #1+GRAPH #2///" << endl;
    cout <<g3 <<endl;
    cout << "///GRAPH#3= GRAPH #1*GRAPH #2///" << endl;
    g3= g1*g2;
    cout <<g3 <<endl;
    cout << "///OPERATIONS ON UNDIRECTED GRAPHS///" << endl;
    g1 += g2;
    cout <<"////// GRAPH #1 += GRAPH #2//////" << endl;
    cout << g1 << endl;
    cout <<"/////////// +GRAPH #1 ///////////" << endl;
    +g1;
    cout << g1 << endl;
    cout <<"/////////// -GRAPH #1 ///////////" << endl;
    -g1;
    cout << g1 << endl;
    cout <<"////// GRAPH #1 -= GRAPH #2//////" << endl;
    g1-=g2;
    cout << g1 << endl;
    cout <<"/////////// GRAPH #1++ ///////////" << endl;
    g1++;
    cout << g1 << endl;
    cout <<"///////// GRAPH #1++(*3)/////////" << endl;
    for(int i=0;i<=2; i++){
            g1++;
        }
    cout << g1 << endl;
    cout <<"/////////// GRAPH #1-- ///////////" << endl;
    g1--;
    cout << g1 << endl;
    cout <<"/////////// --GRAPH #1 ///////////" << endl;
    --g1;
    cout << g1 << endl;
    cout <<"///////// GRAPH #1*=(-2) /////////" << endl;
    g1*=(-2);
    cout << g1 << endl;
    cout <<"///////// GRAPH #1/=(5) /////////" << endl;
    g1/=(5);
    cout << g1 << endl;
    cout << "0 == false, 1== true. " << endl;
    cout <<"////////GRAPH #1<GRAPH #2? ///////" << endl;
    cout<< (g1<g2) <<endl;
    cout <<"////////GRAPH #1>GRAPH #2? ///////" << endl;
    cout<<(g1>g2) <<endl;
    cout <<"////////GRAPH #1==GRAPH #2? ///////" << endl;
    cout<<(g1==g2) <<endl;
    cout <<"////////GRAPH #1!=GRAPH #2? ///////" << endl;
    cout<< (g1!=g2) <<endl;
    cout <<"////////GRAPH #<=GRAPH #2? ///////" << endl;
    cout<< (g1<=g2) <<endl;
    cout <<"////////GRAPH #1>=GRAPH #2? ///////" << endl;
    cout<<(g1>=g2) <<endl;

}