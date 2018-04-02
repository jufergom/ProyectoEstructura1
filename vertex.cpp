#include "vertex.h"

Vertex::Vertex(QString key, QLabel *label, int number)
{
    this->key = key;
    this->label = label;
    this->number = number;
}

Vertex::~Vertex() {}

int Vertex::getX() {
    return label->x();
}

int Vertex::getY() {
    return label->y();
}

QVector<Edge *> Vertex::getEdges()
{
    return edges;
}
