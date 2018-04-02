#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enabled = false;
    graph = NULL;
    bird = ui->labelTwitterBird;
    QPixmap pixmap("C:/Users/jufer/Documents/Proyecto/twitter.png");
    bird->setPixmap(pixmap);
    bird->setScaledContents(true);
    bird->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBuscar_clicked()
{
    /*
    Lo primero que voy a hacer es guardar la palabra que se escribio en el line edit,
    para luego poder leer esa palabra desde el programa en java
    */

    QFile write("C:/Users/jufer/Documents/Proyecto/JavaApplicationTwitter/word.txt");
    if(!write.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //ui->textEditTweets->append("No sirve escribir");
        return;
    }
    QTextStream out(&write);
    out << ui->lineEditWord->text();
    write.close();

    //listo, ya se guardo la palabra en word.txt, ahora a llamar el .jar
    system("java -jar C:/Users/jufer/Documents/Proyecto/JavaApplicationTwitter/dist/JavaApplicationTwitter.jar");

}

void MainWindow::on_pushButtonMostrar_clicked()
{
    //ahora que ya se ha ejecutado el .jar, vamos a leer los tweets que se guardaron en tweets.txt
    QFile file("C:/Users/jufer/Documents/Proyecto/JavaApplicationTwitter/tweets.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //ui->textEditTweets->append("No sirve leer");
        return;
    }

    QTextStream in(&file);
    //verificamos si ya existe un grafo
    if(graph == NULL)
        graph = new Graph();
    else {
        delete graph;
        graph = new Graph();
    }
    QString line = in.readLine(); //se lee la linea
    int size = line.size(); //size del QString
    QByteArray array = line.toLatin1();
    QString word = ""; //a esta variable se le ira agregando caracter por caracter lo leido en el txt
    char *hola = array.data();
    //con estas variables x,y regulo las posiciones de los labels
    int x = 20;
    int y = 20;
    for(int i = 0; i < size; i++) {
        QChar ch(hola[i]);
        word += ch;
        //si esta condicion se cumple, significa que ya se ha leido una palabra completa
        if(ch == " ") {
            QLabel *label1 = new QLabel(this);
            QLabel *label2 = new QLabel(this);
            QPixmap pixmap("C:/Users/jufer/Documents/Proyecto/Circle.png");
            label1->setPixmap(pixmap);
            label2->setText(word);
            label1->setGeometry(x, y, 70, 70);
            label2->setGeometry(x+25, y, 70, 70);
            label1->setScaledContents(true);
            label1->setVisible(true);
            label2->setVisible(true);
            graph->addVertex(word, label2);
            if(graph->getVertexAmount() >= 2) {
                Vertex *origin = graph->getVertices()[graph->getVertexAmount()-2];
                Vertex *destiny = graph->getVertices()[graph->getVertexAmount()-1];
                graph->addEdge(origin, destiny, 0);
            }
            word = "";
            x+=55;
            y+=55;
        }


    }
    file.close();
    enabled = true;
    update();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!enabled) {
        for(int i = 0; i < points1.size(); i++)
            painter.drawLine(points1[i], points2[i]);
        e->accept();
        return;
    }
    QPoint p1;
    QPoint p2;
    for(int i = 0; i < graph->getVertexAmount() - 1; i++) {
        p1.setX(graph->getVertices()[i]->getX()+10);
        p1.setY(graph->getVertices()[i]->getY()+40);
        p2.setX(graph->getVertices()[i]->getEdges()[0]->getDestiny()->getX()-10);
        p2.setY(graph->getVertices()[i]->getEdges()[0]->getDestiny()->getY()+5);
        points1.push_back(p1);
        points2.push_back(p2);
    }
    for(int i = 0; i < points1.size(); i++)
        painter.drawLine(points1[i], points2[i]);
    enabled = false;
    e->accept();
}
