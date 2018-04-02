#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <iostream>
#include <QLabel>
#include <QPixmap>
#include <Qpainter>
#include <QPoint>
#include <QPaintEvent>

#include "vertex.h"
#include "edge.h"
#include "graph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void drawVertex(int, int, QString);
    friend class Graph;

private slots:
    void on_pushButtonBuscar_clicked();

    void on_pushButtonMostrar_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *bird; //la imagen del pajaro de twitter
    Graph *graph;
    bool enabled; //esta variable regula cuando se manda a llamar el paint event
    QVector<QPoint> points1; //puntos de origen de las aristas
    QVector<QPoint> points2; //puntos de destino de las aristas


protected:
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOW_H
