#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge
{
private:
    Vertex *origin;
    Vertex *destiny;
    int weight;

    friend class Vertex;
    friend class Graph;
public:
    Edge();
    ~Edge();

};

#endif // EDGE_H
