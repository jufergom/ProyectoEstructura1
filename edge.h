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
    Vertex *getOrigin();
    Vertex *getDestiny();
};

#endif // EDGE_H
