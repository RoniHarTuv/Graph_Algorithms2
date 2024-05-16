// Id: 207199282
// Mail: Roniharpaz1@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;
using namespace ariel;
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

Graph::Graph() // Constructor
{
    // Initialize adjacencyMatrix as an empty vector
    adjacencyMatrix = {};
    is_directed = false;
    HasNegativeVertices = false;
}

void Graph::loadGraph(const vector<vector<int>> &matrix)
{
    // Check if the graph is a square matrix
    size_t rows = matrix.size();
    for (size_t i = 0; i < rows; ++i)
    {
        if (matrix[i].size() != rows)
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            return;
        }
    }
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < rows; ++j)
        {
            if (i == j)
            {
                if (matrix[i][j] != 0)
                {
                    throw invalid_argument("Invalid graph: not 0 in the diagonal.");
                    return;
                }
            }
        }
    }
    adjacencyMatrix = matrix;
    // check if the graph is directed\not directed
    //  The graph will be a directed graph when there is two different weights between 2 vertices. else- the graph not directed.
    is_directed = false; // Start by assuming the graph is not directed
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < rows; ++j)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                is_directed = true;
                break;
            }
        }
        if (is_directed)
        {
            break;
        }
    }
    HasNegativeVertices = false;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < rows; ++j)
        {
            if (matrix[i][j] < 0)
            {
                HasNegativeVertices = true;
            }
        }
    }
}

void Graph::printGraph() const
{
    if (is_directed == false) // isDirected== false
    {
        cout << "A Not Directed Graph" << endl;
        if (HasNegativeVertices == true)
        {
            cout << "This graph has negative edges." << endl;
        }
        if (HasNegativeVertices == false)
        {
            cout << "This graph without negative edges." << endl;
        }
        cout << "With " << adjacencyMatrix.size() << " vertices and "; // num of vertices is like the matrix size
        int edges = 0;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = i + 1; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    ++edges;
                }
            }
        }
        cout << edges << " edges." << endl;
        // Print adjacency matrix
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else // isDirected == true
    {
        cout << "A Directed Graph" << endl;
        if (HasNegativeVertices == true)
        {
            cout << "This graph has negative edges." << endl;
        }
        if (HasNegativeVertices == false)
        {
            cout << "This graph without negative edges." << endl;
        }
        cout << "With " << adjacencyMatrix.size() << " vertices and "; // num of vertices is like the matrix size
        int edges = 0;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    ++edges;
                }
            }
        }
        cout << edges << " edges:" << endl;
        // Print adjacency matrix
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

string Graph::printGraph2test() const
{
    stringstream ss;
    ss << "[";

    for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
    {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
        {
            ss << adjacencyMatrix[i][j];
        }
    }
    ss << "]";

    return ss.str();
}
const vector<vector<int>> &Graph::getAdjacencyMatrix() const
{
    return adjacencyMatrix;
}

const bool Graph::getIsDirected() const
{
    return is_directed;
}

bool Graph::getHasNegativeVertices() const
{
    return HasNegativeVertices;
}

void Graph::operator+=(Graph &g)
{
    check1graph(g);
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            mat[i][j] += g.getAdjacencyMatrix()[i][j];
        }
    }
    this->loadGraph(mat);
}

void Graph::operator+()
{
    // Implement unary operator +
}

void Graph::operator-()
{
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            mat[i][j] = mat[i][j] * (-1);
        }
    }
    this->loadGraph(mat);
}

void Graph::operator-=(Graph &g)
{
    check1graph(g);
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            mat[i][j] -= g.getAdjacencyMatrix()[i][j];
        }
    }
    this->loadGraph(mat);
}

Graph Graph::operator++(int)
{
    vector<vector<int>> mat = createMatrix();
    Graph new_copy = *this;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                this->adjacencyMatrix[i][j]++;
            }
        }
    }
    return new_copy;
}

Graph &Graph::operator++()
{
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                this->adjacencyMatrix[i][j]++;
            }
        }
    }
    return *this;
}

Graph Graph::operator--(int)
{
    vector<vector<int>> mat = createMatrix();
    Graph new_copy = *this;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                this->adjacencyMatrix[i][j]--;
            }
        }
    }
    return new_copy;
}

Graph &Graph::operator--()
{
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                this->adjacencyMatrix[i][j]--;
            }
        }
    }
    return *this;
}

void Graph::operator*=(int a)
{
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                mat[i][j] = mat[i][j] * a;
            }
        }
    }
    this->loadGraph(mat);
}

void Graph::operator/=(int a)
{
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                mat[i][j] = mat[i][j] / a;
            }
        }
    }
    this->loadGraph(mat);
}

bool Graph::operator==(Graph &g)
{
    if (boolCheck(g) == false)
    {
        throw invalid_argument("Invalid graphs cannot perform operation.");
    }
    bool b1 = *this < g;
    bool b2 = *this > g;
    if (b1 == false && b2 == false)
    {
        return true;
    }
    vector<vector<int>> mat = createMatrix();
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != g.getAdjacencyMatrix()[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Graph::operator!=(Graph &g)
{
    if (boolCheck(g) == false)
    {
        throw invalid_argument("Invalid graphs cannot perform operation.");
    }
    bool ans = (*this == g);
    return !ans;
}

bool Graph::operator<(Graph &g)
{
    if (g.getIsDirected() != this->getIsDirected())
    {
        throw invalid_argument("Invalid graphs: directed and undirected graphs cannot perform operations.");
    }
    if (this->isSubGraph(g))
    {
        return true;
    }
    else if (numOfEdges(g) > this->numOfEdges())
    {
        return true;
    }
    else
    {
        if (this->getAdjacencyMatrix().size() < g.getAdjacencyMatrix().size())
        {
            return true;
        }
    }
    return false;
}

bool Graph::operator<=(Graph &g)
{
    // Check if the graphs are equal
    if (*this == g)
    {
        return true;
    }
    // Check if the first graph is less than the second graph
    if (*this < g)
    {
        return true;
    }
    return false;
}

bool Graph::operator>(Graph &g)
{
    if (g.getIsDirected() != this->getIsDirected())
    {
        throw invalid_argument("Invalid graphs: directed and undirected graphs cannot perform operations.");
    }
    if (g.isSubGraph(*this))
    {
        return true;
    }
    else if (numOfEdges(g) < this->numOfEdges())
    {
        return true;
    }
    else
    {
        if (this->getAdjacencyMatrix().size() > g.getAdjacencyMatrix().size())
        {
            return true;
        }
    }
    return false;
}

bool Graph::operator>=(Graph &g)
{
    if (*this > g || *this == g)
    {
        return true;
    }
    return false;
}

Graph ariel::operator+(Graph &g1, Graph &g2)
{
    if (g1.getAdjacencyMatrix().size() != g2.getAdjacencyMatrix().size())
    {
        throw invalid_argument("Invalid graphs: The graphs size is different.");
    }
    if (g1.getIsDirected() != g2.getIsDirected())
    {
        throw invalid_argument("Invalid graphs: directed and undirected graphs cannot perform (+)operations.");
    }
    Graph g3;
    g3.loadGraph(g1.getAdjacencyMatrix());
    vector<vector<int>> mat = g3.getAdjacencyMatrix();
    size_t size = g1.getAdjacencyMatrix().size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            mat[i][j] = g1.getAdjacencyMatrix()[i][j] + g2.getAdjacencyMatrix()[i][j];
        }
    }
    g3.loadGraph(mat);
    return g3;
}

Graph ariel::operator-(Graph &g1, Graph &g2)
{
    if (g1.getAdjacencyMatrix().size() != g2.getAdjacencyMatrix().size())
    {
        throw invalid_argument("Invalid graphs: The graphs size is different.");
    }
    if (g1.getIsDirected() != g2.getIsDirected())
    {
        throw invalid_argument("Invalid graphs: directed and undirected graphs cannot perform (-) operations.");
    }
    Graph g3;
    g3.loadGraph(g1.getAdjacencyMatrix());
    vector<vector<int>> mat = g3.getAdjacencyMatrix();
    size_t size = g1.getAdjacencyMatrix().size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            mat[i][j] = g1.getAdjacencyMatrix()[i][j] - g2.getAdjacencyMatrix()[i][j];
        }
    }
    g3.loadGraph(mat);
    return g3;
}

Graph ariel::operator*(Graph &g1, Graph &g2)
{
    if (g1.getAdjacencyMatrix().size() != g2.getAdjacencyMatrix().size())
    {
        throw invalid_argument("Invalid graphs: The graphs size is different. cannot preform operation.");
    }
    if (g1.getIsDirected() != g2.getIsDirected())
    {
        throw invalid_argument("Invalid graphs: directed and undirected graphs cannot perform operations.");
    }
    Graph g3;
    g3.loadGraph(g1.getAdjacencyMatrix());
    vector<vector<int>> mat = g3.getAdjacencyMatrix();
    vector<vector<int>> mat1 = g1.getAdjacencyMatrix();
    vector<vector<int>> mat2 = g2.getAdjacencyMatrix();
    size_t size = g1.getAdjacencyMatrix().size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            mat[i][j] = 0;
            for (size_t k = 0; k < size; k++)
            {
                mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (j == i)
            {
                mat[i][j] = 0;
            }
        }
    }
    g3.loadGraph(mat);
    return g3;
}

// Helper functions
void Graph::check1graph(Graph &g)
{
    if (g.getAdjacencyMatrix().size() != this->getAdjacencyMatrix().size())
    {
        throw invalid_argument("Invalid graphs: The graphs size is different. cannot perform operation.");
    }
    if (g.getIsDirected() != this->getIsDirected())
    {
        throw invalid_argument("Invalid graphs: directed and undirected graphs cannot perform operations.");
    }
}

bool Graph::boolCheck(Graph &g)
{
    if (g.getAdjacencyMatrix().size() != this->getAdjacencyMatrix().size())
    {
        return false;
    }
    if (g.getIsDirected() != this->getIsDirected())
    {
        return false;
    }
    return true;
}

vector<vector<int>> Graph::createMatrix()
{
    return this->getAdjacencyMatrix();
}

int Graph::numOfEdges()
{
    vector<vector<int>> mat = createMatrix();
    int ans = 0;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                ans += 1;
            }
        }
    }
    if (this->getIsDirected())
    {
        return ans;
    }
    return (ans / 2);
}

int Graph::numOfEdges(Graph &g)
{
    vector<vector<int>> mat = g.getAdjacencyMatrix();
    int ans = 0;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] != 0)
            {
                ans += 1;
            }
        }
    }
    if (g.getIsDirected())
    {
        return ans;
    }
    return (ans / 2);
}

bool Graph::isSubGraph(Graph &g)
{
    // Calculate the number of edges in the given graph g and the current graph
    int eg = numOfEdges(g);      // Number of edges in graph g
    int et = this->numOfEdges(); // Number of edges in the current graph

    // If the number of edges in g is less than or equal to the number of edges in the current graph,
    // g cannot be a subgraph of the current graph
    if (eg <= et)
    {
        return false;
    }

    // Get the sizes of the adjacency matrices of both graphs
    size_t g_size = g.getAdjacencyMatrix().size();        // Size of the adjacency matrix of graph g
    size_t size_this = this->getAdjacencyMatrix().size(); // Size of the adjacency matrix of the current graph

    // If the size of the adjacency matrix of g is smaller than the size of the adjacency matrix of the current graph,
    // g cannot be a subgraph of the current graph
    if (g_size < size_this)
    {
        return false;
    }

    // Count the number of equal edges between the adjacency matrices of both graphs
    int num_of_equals_edges = 0;
    for (size_t i = 0; i < size_this; i++)
    {
        for (size_t j = 0; j < size_this; j++)
        {
            // If the corresponding edges in the adjacency matrices are equal, increment the counter
            if (this->getAdjacencyMatrix()[i][j] == g.getAdjacencyMatrix()[i][j])
            {
                num_of_equals_edges++;
            }
        }
    }
    // If the number of equal edges is not equal to the number of edges in the current graph,
    // g cannot be a subgraph of the current graph
    if (num_of_equals_edges != et)
    {
        return false;
    }
    return true;
}