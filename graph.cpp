#include "graph.h"

Graph::Graph()
{
    vertexAmount = 0;
}

void Graph::addVertex(QString key, QLabel *label)
{
    vertices.push_back(new Vertex(key, label, vertexAmount));
    vertexAmount++;
}

void Graph::addEdge(QString vertex1, QString vertex2, int weight)
{
    int count = 0;
    int temp;
    Edge *edge = new Edge();
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->key == vertex1) {
            edge->origin = vertices[i];
            temp = i;
            count++;
        }
        if(vertices[i]->key == vertex2) {
            edge->destiny = vertices[i];
            count++;
        }
    }
    if(count < 2) {
        //cout << "Uno de los vertices ingresados (o los dos) no existen" << endl;
        //delete nuevo;
        return;
    }
    else {
        edge->weight = weight;
        vertices[temp]->edges.push_back(edge);
        //cout << "Union exitosa" << endl;
    }
}

void Graph::addEdge(Vertex *origin, Vertex *destiny, int weight)
{
    Edge *edge = new Edge();
    edge->origin = origin;
    edge->destiny = destiny;
    edge->weight = weight;
    origin->edges.push_back(edge);
}
