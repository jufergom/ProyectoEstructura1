#include "edge.h"

Edge::Edge() {}

Edge::~Edge() {}

Vertex *Edge::getOrigin()
{
    return origin;
}

Vertex *Edge::getDestiny()
{
    return destiny;
}
