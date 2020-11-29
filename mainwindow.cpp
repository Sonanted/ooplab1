#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_changechastota->setEnabled(false);
    ui->pushButton_changeresist->setEnabled(false);
    ui->pushButton_changenumber->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->lineEdit_changenumber->setEnabled(false);
    ui->lineEdit_changeresist->setEnabled(false);
    ui->lineEdit_changechastota->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cols_ = ui->lineEdit_stolbci->text().toInt();
    rows_ = ui->lineEdit_stroki->text().toInt();
    Collection col(rows_, cols_);
    ui->pushButton_changechastota->setEnabled(true);
    ui->comboBox->setEnabled(true);

    col_ = col;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            QString s = "Resistor No." + QString::number(i*cols_+j+1);
            QString ij = QString::number(i) + QString::number(j);
            ui->comboBox->addItem(s, ij);
        }
    }
    ui->label_chastota->setText(QString::number(col_.getFreq()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox->currentIndex())));
    ui->comboBox->setEditText("<Резисторы>");
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->label_r_number->setText(QString::fromStdString(col_.getResistor(index / cols_,index % cols_).getNumber()));
    ui->label_r_resist->setText(QString::number(col_.getResistor(index / cols_,index % cols_).getResist()));
    ui->label_potential->setText(QString::number(col_.getPotential(index)));
    ui->pushButton_changeresist->setEnabled(true);
    ui->pushButton_changenumber->setEnabled(true);
}

void MainWindow::on_pushButton_changechastota_clicked()
{
    col_.setFreq(ui->lineEdit_changechastota->text().toDouble());
    ui->label_chastota->setText(QString::number(col_.getFreq()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox->currentIndex())));
}

void MainWindow::on_pushButton_changenumber_clicked()
{
    int index = ui->comboBox->currentIndex();
    Resistor temp = col_.getResistor(index / cols_,index % cols_);
    temp.setNumber(ui->lineEdit_changenumber->text().toStdString());
    col_.setResistor(index / cols_,index % cols_, temp);
    ui->label_r_number->setText(QString::fromStdString(col_.getResistor(index / cols_,index % cols_).getNumber()));
}

void MainWindow::on_pushButton_changeresist_clicked()
{
    int index = ui->comboBox->currentIndex();
    Resistor temp = col_.getResistor(index / cols_,index % cols_);
    temp.setResist(ui->lineEdit_changeresist->text().toDouble());
    col_.setResistor(index / cols_,index % cols_, temp);
    ui->label_r_resist->setText(QString::number(col_.getResistor(index / cols_,index % cols_).getResist()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox->currentIndex())));
}
