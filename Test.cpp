// Id: 207199282
// Mail: Roniharpaz1@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace ariel;

/**
 * This class represents the tests class of the project.
 * There are 150 tests which examine edge cases for different graphs.
 * Each test examines a different function/operations on graphs with different characteristics
 * (directed, undirected, with circles, without circles, with negative sides, etc...)
 */

TEST_CASE("Test operations- undirected graphs,connected/not connected")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0, 4, 0, 0}, // a not directed graph and connected
        {2, 0, 2, 0, 0, 0},
        {0, 2, 0, 0, 0, 4},
        {4, 0, 0, 0, 2, 0},
        {0, 0, 0, 2, 0, 2},
        {0, 0, 4, 0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    graph = {
        {0, 5, 0, 0, 0, 0}, // a not directed graph and not connected
        {5, 0, 5, 0, 0, 0},
        {0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 10, 0},
        {0, 0, 0, 10, 0, 10},
        {0, 0, 0, 0, 10, 0}};
    g2.loadGraph(graph);
    SUBCASE("Test operations: (<<)(+=)(+)(-)(-=)(g++)(++g)(g--)(--g)(*=)(/=)")
    {
        g1 += g2;
        CHECK(g1.printGraph2test() == "[0704007070000700044000120000120120040120]");
        +g1;
        CHECK(g1.printGraph2test() == "[0704007070000700044000120000120120040120]");
        -g1;
        CHECK(g1.printGraph2test() == "[0-70-400-70-70000-7000-4-4000-120000-120-1200-40-120]");
        g1 -= g2;
        CHECK(g1.printGraph2test() == "[0-120-400-120-120000-12000-4-4000-220000-220-2200-40-220]");
        g1++;
        CHECK(g1.printGraph2test() == "[0-110-300-110-110000-11000-3-3000-210000-210-2100-30-210]");
        for (int i = 0; i <= 2; i++)
        {
            g1++;
        } // when edges is become 0, it dissaperd.
        CHECK(g1.printGraph2test() == "[0-80000-80-80000-800000000-180000-180-180000-180]"); // some edges will dissapear
        g1--;
        CHECK(g1.printGraph2test() == "[0-90000-90-90000-900000000-190000-190-190000-190]");
        --g1;
        CHECK(g1.printGraph2test() == "[0-100000-100-100000-1000000000-200000-200-200000-200]");
        g1 *= (-2);
        CHECK(g1.printGraph2test() == "[02000002002000002000000000400000400400000400]");
        g1 /= (5);
        CHECK(g1.printGraph2test() == "[040000404000040000000080000808000080]");
    }
    SUBCASE("Test operations: (==)(!=)(<)(<=)(>)(>=)")
    {
        // g1>g2
        CHECK(g1.printGraph2test() == "[020400202000020004400020000202004020]");
        CHECK(g2.printGraph2test() == "[0500005050000500000000100000100100000100]");
        CHECK((g1 == g2) == false);
        CHECK((g1 != g2) == true);
        CHECK((g1 < g2) == false);
        CHECK((g1 > g2) == true);
        CHECK((g1 <= g2) == false);
        CHECK((g1 >= g2) == true);

        // g1<g2
        g1--;
        g1--; // some edges deleted
        CHECK((g1 == g2) == false);
        CHECK((g1 != g2) == true);
        CHECK((g1 < g2) == true);
        CHECK((g1 > g2) == false);
        CHECK((g1 <= g2) == true);
        CHECK((g1 >= g2) == false);

        // g1==g1
        CHECK((g1 == g1) == true);
        CHECK((g1 != g1) == false);
        CHECK((g1 < g1) == false);
        CHECK((g1 > g1) == false);
        CHECK((g1 <= g1) == true);
        CHECK((g1 >= g1) == true);
    }
    SUBCASE("Test operations: (g1+g2)(g1-g2)(g1*g2)")
    {
        ariel::Graph g3;
        g3 = g1 + g2;
        CHECK(g3.printGraph2test() == "[0704007070000700044000120000120120040120]");
        g3 = g1 - g2;
        CHECK(g3.printGraph2test() == "[0-30400-30-30000-300044000-80000-80-80040-80]");
        g3 = g1 * g2;
        CHECK(g3.printGraph2test() == "[00100400000000100004000200002000000002002000]");
    }
}
TEST_CASE("Test operations- directed graphs,connected/not connected")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 8, 0, 0, 0, 0}, // a not directed graph and connected
        {0, 0, 8, 0, 0, 0},
        {0, 0, 0, 7, 0, 0},
        {6, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 8},
        {7, 0, 6, 0, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    graph = {
        {0, 3, 0, 0, 0, 0}, // a not directed graph and not connected
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}};
    g2.loadGraph(graph);
    SUBCASE("Test operations: (+=)(+)(-)(-=)(g++)(++g)(g--)(--g)(*=)(/=)")
    {
        g1 += g2;
        CHECK(g1.printGraph2test() == "[0110000001100000070060001100000011706000]");
        +g1;
        CHECK(g1.printGraph2test() == "[0110000001100000070060001100000011706000]");
        -g1;
        CHECK(g1.printGraph2test() == "[0-11000000-11000000-700-6000-11000000-11-70-6000]");
        g1 -= g2;
        CHECK(g1.printGraph2test() == "[0-14000000-14000000-700-6000-14000000-14-70-6000]");
        g1++;
        CHECK(g1.printGraph2test() == "[0-13000000-13000000-600-5000-13000000-13-60-5000]");
        for (int i = 0; i <= 4; i++)
        {
            g1++;
        } // when edges is become 0, it dissaperd.
        CHECK(g1.printGraph2test() == "[0-8000000-8000000-1000000-8000000-8-100000]"); // some edges will dissapear
        g1--;
        CHECK(g1.printGraph2test() == "[0-9000000-9000000-2000000-9000000-9-200000]");
        --g1;
        CHECK(g1.printGraph2test() == "[0-10000000-10000000-3000000-10000000-10-300000]");
        g1 *= (-2);
        CHECK(g1.printGraph2test() == "[0200000002000000060000002000000020600000]");
        g1 /= (5);
        CHECK(g1.printGraph2test() == "[040000004000000100000040000004100000]");
    }
    SUBCASE("Test operations: (==)(!=)(<)(<=)(>)(>=)")
    {
        // g1>g2
        CHECK(g1.printGraph2test() == "[080000008000000700600080000008706000]");
        CHECK(g2.printGraph2test() == "[030000003000000000000030000003000000]");
        CHECK((g1 == g2) == false);
        CHECK((g1 != g2) == true);
        CHECK((g1 < g2) == false);
        CHECK((g1 > g2) == true);
        CHECK((g1 <= g2) == false);
        CHECK((g1 >= g2) == true);

        // g1<g2
        g1--; // some edges deleted
        g1--;
        g1--;
        g1--;
        g1--;
        g1--;
        g1--;
        CHECK((g1 == g2) == true);
        CHECK((g1 != g2) == false);
        CHECK((g1 < g2) == false);
        CHECK((g1 > g2) == false);
        CHECK((g1 <= g2) == true);
        CHECK((g1 >= g2) == true);

        // g1==g1
        CHECK((g1 == g1) == true);
        CHECK((g1 != g1) == false);
        CHECK((g1 < g1) == false);
        CHECK((g1 > g1) == false);
        CHECK((g1 <= g1) == true);
        CHECK((g1 >= g1) == true);
    }
    SUBCASE("Test operations: (g1+g2)(g1-g2)(g1*g2)")
    {
        ariel::Graph g3;
        g3 = g1 + g2;
        CHECK(g3.printGraph2test() == "[0110000001100000070060001100000011706000]");
        g3 = g1 - g2;
        CHECK(g3.printGraph2test() == "[050000005000000700600050000005706000]");
        g3 = g1 * g2;
        CHECK(g3.printGraph2test() == "[00240000000000000210018000240000000210000]");
    }
}
TEST_CASE("Test invalid operations on graphs")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 8, 0, 0, 0, 0}, // a not directed graph and connected
        {0, 0, 8, 0, 0, 0},
        {0, 0, 0, 7, 0, 0},
        {6, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 8},
        {7, 0, 6, 0, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    graph = {
        {0, 5, 0, 0, 0, 0}, // a not directed graph and not connected
        {5, 0, 5, 0, 0, 0},
        {0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 10, 0},
        {0, 0, 0, 10, 0, 10},
        {0, 0, 0, 0, 10, 0}};
    g2.loadGraph(graph);
    //operstions on directed+undirected graphs
    CHECK_THROWS(g1+=g2);
    CHECK_THROWS(g1-=g2);
    CHECK_THROWS(g1<g2);
    CHECK_THROWS(g1<=g2);
    CHECK_THROWS(g1>g2);
    CHECK_THROWS(g1>=g2);
    CHECK_THROWS(g1==g2);
    CHECK_THROWS(g1!=g2);
    ariel::Graph g3;
    graph = {
        {0, 5, 0, 0, 0}, // a not directed graph and not connected
        {5, 0, 5, 0, 0},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 0, 10, 0},
        };
    //operstions on not same size graphs
    g3.loadGraph(graph);
    CHECK_THROWS(g1+=g3);
    CHECK_THROWS(g1-=g3);
    CHECK_THROWS(g1<g3);
    CHECK_THROWS(g1<=g3);
    CHECK_THROWS(g1>g3);
    CHECK_THROWS(g1>=g3);
    CHECK_THROWS(g1==g3);
    CHECK_THROWS(g1!=g3);
}
TEST_CASE("Test matrix mul")
{
    //two undirected graphs that after multiplication becomes a directed graphs(not symetrick matrix)
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 1, 6}, // a not directed graph and connected
        {1, 0, 0, 0, 0, 6},
        {1, 0, 0, 0, 0, 6},
        {1, 0, 0, 0, 0, 6},
        {1, 0, 0, 0, 0, 6},
        {6, 6, 6, 6, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    graph = {
        {0, 1, 1, 1, 1, 4}, // a not directed graph and not connected
        {1, 0, 0, 0, 0, 8},
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {4, 8, 0, 0, 0, 0}};
    g2.loadGraph(graph);
    ariel::Graph g3;
    g3.loadGraph(graph);
    g3= g1*g2;
    CHECK(g3.getIsDirected()==true);
}
TEST_CASE("Test cycle after operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 1, 6}, // a not directed graph and connected
        {1, 0, 0, 0, 0, 6},
        {1, 0, 0, 0, 0, 6},
        {1, 0, 0, 0, 0, 6},
        {1, 0, 0, 0, 0, 6},
        {6, 6, 6, 6, 6, 0}};
    g1.loadGraph(graph);
    -g1; // all the positive edges become nagative
    CHECK(ariel::Algorithms::negativeCycle(g1) == "Is contain negative cycle: Yes: 0->1->5->0");
    g1++;//delete edges
    CHECK(ariel::Algorithms::negativeCycle(g1) == "Is contain negative cycle: No");
}

//Tests on Algorithms and operations:
TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {// a not directed graph and connected
                                 {0, 1, 0},
                                 {1, 0, 1},
                                 {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    g--;
    CHECK(ariel::Algorithms::isConnected(g) == false);


    vector<vector<int>> graph2 = {// a not directed graph and not connected
                                  {0, 1, 1, 0, 0},
                                  {1, 0, 1, 0, 0},
                                  {1, 1, 0, 1, 0},
                                  {0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    g++;
    CHECK(ariel::Algorithms::isConnected(g) == false);


    vector<vector<int>> graph3 = {// a directed graph, connected
                                  {0, 1, 0, 0, 1},
                                  {1, 0, 1, 0, 0},
                                  {2, 3, 0, 4, 0},
                                  {0, 0, 4, 0, 5},
                                  {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    g--;
    g--;
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {// a directed graph, not connected
                                  {0, 6, 0, 0},
                                  {0, 0, 2, 0},
                                  {0, 0, 0, 2},
                                  {0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    g++;
    ++g;
    g*=-4;
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph5 = {// no edges graph- not directed
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    g++;
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph6 = {// a directed and connected graph
                                  {0, 1, 0, 0, 0, 0, 0, 1},
                                  {1, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 1, 0, 1, 0, 0, 0, 0},
                                  {0, 0, 1, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 1, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 1, 0},
                                  {0, 0, 0, 0, 0, 1, 0, 1},
                                  {1, 0, 0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph7 = {// directed, not connected, negative cycle
                                  {0, 0, 0, 0, 0, 0, 7},
                                  {8, 0, 0, 10, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 5},
                                  {0, -30, 0, 0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph11 = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, -9, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "Shortest Path from 0 to 2 is: 0->1->2");

    vector<vector<int>> graph2 = {// a not connected and not directed graph
                                  {0, 1, 1, 0, 0},
                                  {1, 0, 1, 0, 0},
                                  {1, 1, 0, 1, 0},
                                  {0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Shortest Path: No way between 0 to 4");

    vector<vector<int>> graph3 = {// a connected and directed graph
                                  {0, 1, 0, 0, 1},
                                  {1, 0, 1, 0, 0},
                                  {2, 3, 0, 4, 0},
                                  {0, 0, 4, 0, 5},
                                  {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "Shortest Path from 0 to 1 is: 0->1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Shortest Path from 0 to 4 is: 0->4");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 0) == "Shortest Path from 3 to 0 is: 3->2->0");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "Shortest Path from 2 to 0 is: 2->0");
    CHECK(ariel::Algorithms::shortestPath(g, 4, 1) == "Shortest Path from 4 to 1 is: 4->3->2->1");

    vector<vector<int>> graph4 = {// a connected and not directed graph
                                  {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                  {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                                  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                  {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "Shortest Path from 0 to 3 is: 0->5->6->3");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Shortest Path from 0 to 4 is: 0->7->8->9->4");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "Shortest Path from 0 to 2 is: 0->7->8->9->4->2");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 1) == "Shortest Path from 2 to 1 is: 2->4->9->8->7->0->1");
    CHECK(ariel::Algorithms::shortestPath(g, 6, 2) == "Shortest Path from 6 to 2 is: 6->5->0->7->8->9->4->2");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 6) == "Shortest Path from 0 to 6 is: 0->5->6");

    vector<vector<int>> graph5 = {// no edges graph
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "Shortest Path: No way between 0 to 3");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Shortest Path: No way between 0 to 4");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "Shortest Path: No way between 0 to 2");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 1) == "Shortest Path: No way between 2 to 1");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "Shortest Path: No way between 1 to 2");
    CHECK(ariel::Algorithms::shortestPath(g, 4, 3) == "Shortest Path: No way between 4 to 3");

    vector<vector<int>> graph6 = {// a directed graph, with negative edges
                                  {0, 10, -5, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 1, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "Shortest Path from 0 to 1 is: 0->2->1");

    vector<vector<int>> graph7 = {// graph with negative cycle into the shortest path
                                  {0, 10, -5, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {1, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "No Shortest Path- Graph contains a negative cycle");

    vector<vector<int>> graph8 = {// directed, not connected, negative cycle
                                  {0, 0, 0, 0, 0, 0, 7},
                                  {8, 0, 0, 10, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 5},
                                  {0, -30, 0, 0, 0, 0, 0}};
    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "No Shortest Path- Graph contains a negative cycle");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {// no cycle graph, not directed
                                 {0, 1, 0},
                                 {1, 0, 1},
                                 {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: No");

    vector<vector<int>> graph2 = {// a not directed graph with cycle
                                  {0, 1, 1, 0, 0},
                                  {1, 0, 1, 0, 0},
                                  {1, 1, 0, 1, 0},
                                  {0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: Yes: 0->1->2->0");

    vector<vector<int>> graph3 = {// a directed graph with many cycles and neative edges
                                  {0, -87, 0, 0, 1},
                                  {1, 0, 1, 0, 0},
                                  {2, 3, 0, 4, 0},
                                  {0, 0, 4, 0, 5},
                                  {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: Yes: 0->1->0");

    vector<vector<int>> graph4 = {// a not directed graph with many edges and no cycle
                                  {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                  {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                                  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                  {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: No");

    vector<vector<int>> graph5 = {// no edges graph
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: No");

    vector<vector<int>> graph6 = {// directed, not connected, negative cycle
                                  {0, 0, 0, 0, 0, 0, 7},
                                  {8, 0, 0, 10, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 5},
                                  {0, -30, 0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: Yes: 0->6->1->0");

    vector<vector<int>> graph11 = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, -9, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Is contain cycle: Yes: 0->23->22->21->0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0,2}{1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: No");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 0, 0, 0},
        {2, 0, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0,3}{1,2,4}");

    vector<vector<int>> graph4 = {
        {0, 2, 0, 4},
        {0, 0, 2, 0},
        {0, 0, 0, 2},
        {0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0,2}{1,3}");

    vector<vector<int>> graph5 = {// no edges graph
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0,1,2,3,4}{}");

    vector<vector<int>> graph6 = {// only one vertex in set A
                                  {0, 1, 1, 1, 1},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0}{1,2,3,4}");

    vector<vector<int>> graph7 = {
        {0, 6, 0, 0},
        {7, 0, 2, 0},
        {0, 0, 0, 2},
        {0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0,2}{1,3}");

    vector<vector<int>> graph11 = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, -9, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::isBipartite(g) == "Is bipartite: Yes, {0,1,3,4,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,24}{2,5,21,23}");
}
TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: No");

    vector<vector<int>> graph2 = {
        {0, 6, 0, 0},
        {7, 0, 2, 0},
        {0, 0, 0, 2},
        {0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: No");

    vector<vector<int>> graph3 = {// a directed graph thet the cycle from all vertex
                                  {0, -2, 0, 0},
                                  {0, 0, -7, 0},
                                  {0, 0, 0, -4},
                                  {10, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: Yes: 0->1->2->3->0"); // 0->1->2->3->0

    vector<vector<int>> graph4 = {// a directed graph with -1 cycle
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, -100},
                                  {0, 0, 99, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: Yes: 2->3->2"); // 2->3->2

    vector<vector<int>> graph5 = {// a not directed graph
                                  {0, -2, -7, 0},
                                  {-2, 0, -6, 0},
                                  {-7, -6, 0, 0},
                                  {0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: Yes: 0->1->2->0"); // 0->1->2->0

    vector<vector<int>> graph6 = {// directed, not connected, negative cycle
                                  {0, 0, 0, 0, 0, 0, 7},
                                  {8, 0, 0, 10, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 5, 0, 0},
                                  {0, 0, 0, 0, 0, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 5},
                                  {0, -30, 0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: Yes: 1->4->5->6->1"); // 0->1->2->0

    vector<vector<int>> graph11 = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, -9, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Is contain negative cycle: Yes: 1->2->1");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {// a not square matrix
                                 {0, 1, 2, 0},
                                 {1, 0, 3, 0},
                                 {2, 3, 0, 4},
                                 {0, 0, 4, 0},
                                 {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {// not only 0 in the diagonal
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1}};
    CHECK_THROWS(g.loadGraph(graph2));

    vector<vector<int>> graph3 = {
        // a not square matrix
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0, 9},
    };
    CHECK_THROWS(g.loadGraph(graph3));

    vector<vector<int>> graph4 = {
        // shortest path to not exiting vertex.
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
    };
    (g.loadGraph(graph4));
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 7));

    vector<vector<int>> graph5 = {
        // shortest path from not exiting vertex.
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
    };
    (g.loadGraph(graph5));
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 4, 2));
}