#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonBuscar_clicked();

    void on_pushButtonMostrar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
