/**
 * find the minimum spanning tree using kruskal algo
 * 
 * Time Complexity: O(E logE + E logV)
 * sorting edges take O(E logE)
 * find and union take at most O(LogV)
 * 
 * @author Hao Yu Hung
 * @date   2022/09/30
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet
{
private:
    int* parent;
    int* rank;
public:
    DisjointSet(int size): parent(new int[size]), rank(new int[size])
    {
        for(int i = 0; i < size; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int vertex)
    {
        if(parent[vertex] != vertex)
            parent[vertex] = find(parent[vertex]);
        return parent[vertex];
    }

    void unite(int root1, int root2)
    {
    
        if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else if(rank[root1] > rank[root2])
            parent[root2] = root1;
        else
        {
            parent[root2] = root1;
            ++rank[root1];
        }
    }
};


class Edge
{
public:
    int vertex1;
    int vertex2;
    int weight;
    Edge(int v1, int v2, int weight): vertex1(v1), vertex2(v2), weight(weight) {};
    ~Edge()
    {

    }
};

struct
{
    bool operator() (const Edge& edge1, const Edge& edge2)
    {
        return (edge1.weight < edge2.weight);
    }
} edgeLess;

class Graph
{
public:
    std::vector<Edge> edgeList;
    int vertexNum;
    void addEdge(Edge edge)
    {
        edgeList.push_back(edge);
    }

    void createGraph()
    {
        this->vertexNum = 4;
        this->addEdge(Edge(0,1,10));
        this->addEdge(Edge(1,3,15));
        this->addEdge(Edge(2,3,4));
        this->addEdge(Edge(2,0,6));
        this->addEdge(Edge(0,3,5));
    }

    void print()
    {
        for(int i = 0; i < edgeList.size(); ++i)
        {
            std::cout << edgeList[i].vertex1 << "->" << edgeList[i].vertex2 << " " << edgeList[i].weight << std::endl;
        }
    }

};

std::vector<Edge> kruskalMST(Graph graph)
{
    // sort all the edge base on there weight
    std::sort(graph.edgeList.begin(), graph.edgeList.end(), edgeLess);
 
    // Initialize the disjoint set
    DisjointSet set(graph.vertexNum);

    std::vector<Edge> result;
    for(int i = 0; i < graph.edgeList.size(); ++i)
    {
        if(set.find(graph.edgeList[i].vertex1) != set.find(graph.edgeList[i].vertex2))
        {
            set.unite(set.find(graph.edgeList[i].vertex1), set.find(graph.edgeList[i].vertex2));
            result.push_back(graph.edgeList[i]);
        }
    }
    return result;
}


int main(int argc, char** argv)
{
    Graph myGraph = Graph();
    myGraph.createGraph();
    myGraph.print();
    std::vector<Edge> MST = kruskalMST(myGraph);

    std::cout << "the edge of constructed MST" << std::endl;
    int totalWeight = 0;
    for(int i = 0; i < MST.size(); ++i)
    {
        std::cout << MST[i].vertex1 << "-" << MST[i].vertex2 << " " << MST[i].weight << std::endl;
        totalWeight = totalWeight + MST[i].weight;
    }
    std::cout << "Total weight:" << totalWeight << std::endl;
    return 0;
}