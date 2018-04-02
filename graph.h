#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QString>
#include <QPainter>
#include <QPoint>

#include "vertex.h"
#include "edge.h"

class Graph
{
private:
    QVector<Vertex *> vertices;
    int vertexAmount;
    friend class Vertex;
    friend class Edge;
public:
    Graph();
    void addVertex(QString, QLabel *);
    void addEdge(QString vertex1, QString vertex2, int weight);
    void addEdge(Vertex *origin, Vertex *destiny, int weight);
    int getVertexAmount();
    QVector<Vertex *> getVertices();
    //void dibujarAristas(QPainter painter, QPoint p1, QPoint p2);
};

#endif // GRAPH_H
