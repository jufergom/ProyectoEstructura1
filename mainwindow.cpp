#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    while (!in.atEnd()) {
        QString line = in.readLine();
        //ui->textEditTweets->append(line);
    }
    file.close();
}
