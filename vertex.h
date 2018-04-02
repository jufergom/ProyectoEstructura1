#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include <QVector>
#include <QLabel>

class Edge;

class Vertex
{
private:
    QString key;
    int number;
    QLabel *label;
    QVector<Edge *> edges;
    friend class Edge;
    friend class Graph;
public:
    Vertex(QString, QLabel *, int);
    ~Vertex();
    int getX();
    int getY();
};

#endif // VERTEX_H
