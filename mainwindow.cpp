#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_lineEdit_stolbci_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_stroki_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_clicked()
{

}
