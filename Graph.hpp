// Id: 207199282
// Mail: Roniharpaz1@gmail.com
#include <vector>
#include <stdexcept>
#include <iostream>
#ifndef GRAPH_HPP
#define GRAPH_HPP
/*
"Graph" class:
This class represents a graph with edges of integer weight, represented by a adjacency matrix.
A graph can be directed, undirected, weighted and unweighted.
In this assignment, a large number of operators were added which can be performed on a single graph or operations between 2 graphs.
In the "README" file there is a detail on how the result of the operator is determined.
Operations will be performed only on matrices of the same size, and likewise on graphs of the same family - directed or undirected.
The only result that you can "mix" between these 2 families is when performing a matrix multiplication operation
which can make symmetric matrices unsymmetrical and vice versa.
*/
namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix; // the matrix that represents the graph
        bool is_directed;                              // is this matrix symmetric? if yes- the graph is not directed
        bool HasNegativeVertices;                      // does this graph have negative vertices
        // Helper functions
        void check1graph(Graph &g);
        bool boolCheck(Graph &g);
        std::vector<std::vector<int>> createMatrix();
        int numOfEdges();
        int numOfEdges(Graph &g);
        bool isSubGraph(Graph &g);

    public:
        Graph(); // Constructor
        void loadGraph(const std::vector<std::vector<int>> &graph); // Method to load a graph-+decided if this graph is directed\not
        void printGraph() const; // Method to print the graph and the settings of the graph
        std::string printGraph2test() const;
        const bool getIsDirected() const;
        bool getHasNegativeVertices() const;
        const std::vector<std::vector<int>> &getAdjacencyMatrix() const; // Method to get the adjacency matrix
        /////////////////////////////////////////////////////////////
        ///////////////////////// OPERATORS /////////////////////////
        /////////////////////////////////////////////////////////////
        void operator+=(Graph &g); // +=
        void operator+();          // + unary
        void operator-();          // - unary
        void operator-=(Graph &g); // -=
        void operator++(int);      // g++
        void operator++();         // ++g
        void operator--(int);      // g--
        void operator--();         // --g
        void operator*=(int);      // *=
        void operator/=(int);      // /=
        bool operator==(Graph &g); // ==
        bool operator!=(Graph &g); // !=
        bool operator<(Graph &g);  // <
        bool operator<=(Graph &g); // <=
        bool operator>(Graph &g);  // >
        bool operator>=(Graph &g); // >=
        friend std::ostream &operator<<(std::ostream &out, const Graph &graph)
        {
            for (size_t i = 0; i < graph.getAdjacencyMatrix().size(); i++)
            {
                out << "[";
                for (size_t j = 0; j < graph.getAdjacencyMatrix()[i].size(); j++)
                {
                    out << graph.adjacencyMatrix[i][j];
                    if (j < graph.getAdjacencyMatrix()[i].size() - 1)
                    {
                        out << ", ";
                    }
                }
                out << "]";
                out << std::endl;
            }
            return out;
        } // cout<<
    };
    // Function declarations for operators defined outside the class
    Graph operator+(Graph &g1, Graph &g2); // +
    Graph operator-(Graph &g1, Graph &g2); // -
    Graph operator*(Graph &g1, Graph &g2); // *
}

#endif // GRAPH_HPP