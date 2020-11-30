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
    ui->pushButton_changecapacity->setEnabled(false);
    ui->pushButton_changenumber_2->setEnabled(false);
    ui->pushButton_changeresist_2->setEnabled(false);
    ui->comboBox_resistor->setEnabled(false);
    ui->lineEdit_changenumber->setEnabled(false);
    ui->lineEdit_changeresist->setEnabled(false);
    ui->lineEdit_changechastota->setEnabled(false);
    ui->lineEdit_changecapacity->setEnabled(false);
    ui->lineEdit_changenumber_2->setEnabled(false);
    ui->lineEdit_changeresist_2->setEnabled(false);
    ui->pushButton_new->setEnabled(false);
    ui->pushButton_delete->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_create_matrix_clicked()
{
    cols_ = ui->lineEdit_columns->text().toInt();
    rows_ = ui->lineEdit_rows->text().toInt();
    Collection col(rows_, cols_);
    ui->comboBox_resistor->clear();
    ui->pushButton_changechastota->setEnabled(true);
    ui->lineEdit_changechastota->setEnabled(true);
    ui->comboBox_resistor->setEnabled(true);

    col_ = col;

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            QString s = "Resistor No." + QString::number(i*cols_+j+1);
            QString ij = QString::number(i) + QString::number(j);
            ui->comboBox_resistor->addItem(s, ij);
        }
    }
    ui->label_freq->setText(QString::number(col_.getFreq()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox_resistor->currentIndex())));
    ui->comboBox_resistor->setCurrentIndex(-1);
}

void MainWindow::on_comboBox_resistor_activated(int index)
{
    ui->label_r_number->setText(QString::fromStdString(col_.getResistor(index / cols_,index % cols_).getNumber()));
    ui->label_r_resist->setText(QString::number(col_.getResistor(index / cols_,index % cols_).getResist()));
    ui->label_potential->setText(QString::number(col_.getPotential(index)));
    ui->pushButton_changeresist->setEnabled(true);
    ui->pushButton_changenumber->setEnabled(true);
    ui->lineEdit_changenumber->setEnabled(true);
    ui->lineEdit_changeresist->setEnabled(true);
    ui->pushButton_new->setEnabled(true);
}

void MainWindow::on_pushButton_changechastota_clicked()
{
    col_.setFreq(ui->lineEdit_changechastota->text().toDouble());
    ui->label_freq->setText(QString::number(col_.getFreq()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox_resistor->currentIndex())));
    ui->lineEdit_changechastota->setText("");
}

void MainWindow::on_pushButton_changenumber_clicked()
{
    int index = ui->comboBox_resistor->currentIndex();
    Resistor temp = col_.getResistor(index / cols_,index % cols_);
    temp.setNumber(ui->lineEdit_changenumber->text().toStdString());
    col_.setResistor(index / cols_,index % cols_, temp);
    ui->label_r_number->setText(QString::fromStdString(col_.getResistor(index / cols_,index % cols_).getNumber()));
    ui->lineEdit_changenumber->setText("");
}

void MainWindow::on_pushButton_changeresist_clicked()
{
    int index = ui->comboBox_resistor->currentIndex();
    Resistor temp = col_.getResistor(index / cols_,index % cols_);
    temp.setResist(ui->lineEdit_changeresist->text().toDouble());
    col_.setResistor(index / cols_,index % cols_, temp);
    ui->label_r_resist->setText(QString::number(col_.getResistor(index / cols_,index % cols_).getResist()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox_resistor->currentIndex())));
    ui->lineEdit_changeresist->setText("");
}


void MainWindow::on_pushButton_new_clicked()
{
    int index = ui->comboBox_resistor->currentIndex();
    string number = col_.getResistor(index / cols_,index % cols_).getNumber();
    QString str_tmp = "Inductance from Resistor No." + QString::number(index + 1);
    QString str_index = QString::number(index);
    int resist = col_.getResistor(index / cols_,index % cols_).getResist();
    Inductance temp(number, resist);
    ind_.push_back(temp);
    ui->listWidget->addItem(str_tmp);
}

void MainWindow::on_pushButton_delete_clicked()
{
    int index = ui->listWidget->currentRow();
    delete ui->listWidget->takeItem(index);
}

void MainWindow::on_pushButton_changecapacity_clicked()
{
    int index = ui->listWidget->currentRow();
    ind_[index].setCapacity(ui->lineEdit_changecapacity->text().toInt());
    ui->label_capacity->setText(QString::number(ind_[index].getCapacity()));
    ui->lineEdit_changecapacity->setText("");
    int freq = col_.getFreq();
    QString result = QString::number(ind_[index].calculateFreq(freq));
    ui->label_inductance->setText(result);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if (currentRow != -1) {
        QString tmp_capacity = QString::number(ind_[currentRow].getCapacity());
        ui->label_capacity->setText(tmp_capacity);
        cout << ind_[currentRow].getCapacity() << '\n';
        QString tmp_number = QString::fromStdString(ind_[currentRow].getNumber());
        ui->label_number->setText(tmp_number);
        cout << ind_[currentRow].getNumber() << '\n';
        QString tmp_resist = QString::number(ind_[currentRow].getResist());
        ui->label_resist->setText(tmp_resist);
        ui->pushButton_changecapacity->setEnabled(true);
        ui->pushButton_changenumber_2->setEnabled(true);
        ui->pushButton_changeresist_2->setEnabled(true);
        ui->lineEdit_changecapacity->setEnabled(true);
        ui->lineEdit_changenumber_2->setEnabled(true);
        ui->lineEdit_changeresist_2->setEnabled(true);
        ui->pushButton_delete->setEnabled(true);
    }
    else {
        ui->label_capacity->setText("");
        ui->label_number->setText("");
        ui->label_resist->setText("");
        ui->pushButton_changecapacity->setEnabled(false);
        ui->pushButton_changenumber_2->setEnabled(false);
        ui->pushButton_changeresist_2->setEnabled(false);
        ui->lineEdit_changecapacity->setEnabled(false);
        ui->lineEdit_changenumber_2->setEnabled(false);
        ui->lineEdit_changeresist_2->setEnabled(false);
        ui->pushButton_delete->setEnabled(false);
    }
}

void MainWindow::on_pushButton_changenumber_2_clicked()
{
    int index = ui->listWidget->currentRow();
    ind_[index].setNumber(ui->lineEdit_changenumber_2->text().toStdString());
    ui->label_number->setText(QString::fromStdString(ind_[index].getNumber()));
    ui->lineEdit_changenumber_2->setText("");
}

void MainWindow::on_pushButton_changeresist_2_clicked()
{
    int index = ui->listWidget->currentRow();
    ind_[index].setResist(ui->lineEdit_changeresist_2->text().toInt());
    ui->label_resist->setText(QString::number(ind_[index].getResist()));
    ui->lineEdit_changeresist_2->setText("");
    int freq = col_.getFreq();
    QString result = QString::number(ind_[index].calculateFreq(freq));
    ui->label_inductance->setText(result);
}

string createname() {
    time_t now = time(0);
    char *n = ctime(&now);
    string name;
    n = strtok(n, " ");
    vector<string> temp;
    while (n != NULL) {
        temp.push_back(n);
        n = strtok(NULL, " :");
    }
    for (auto i : temp) {
        name += i;
    }
    name = name.substr(0, name.size()-1);
    name +=".txt";
    return name;
}

void MainWindow::on_pushButton_load_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
    tr("file"), "", tr("Text files (*.txt)"));
    int rows, cols;
    double res, freq;
    ifstream file;
    file.open(filename.toStdString());
    string str;
    if(!file) {
        cout << "File error";
    }
    else {
        file >> freq >> rows >> cols;
        rows_ = rows;
        cols_ = cols;
        Collection col(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file >> str >> res;
                const double ress = res;
                Resistor temp(str, ress);
                col.setResistor(i, j, temp);
            }
        }
        col_ = col;
        col_.setFreq(freq);
    }
    ui->comboBox_resistor->clear();
    ui->pushButton_changechastota->setEnabled(true);
    ui->lineEdit_changechastota->setEnabled(true);
    ui->comboBox_resistor->setEnabled(true);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            QString s = "Resistor No." + QString::number(i*cols_+j+1);
            QString ij = QString::number(i) + QString::number(j);
            ui->comboBox_resistor->addItem(s, ij);
        }
    }
    ui->label_freq->setText(QString::number(col_.getFreq()));
    ui->label_potential->setText(QString::number(col_.getPotential(ui->comboBox_resistor->currentIndex())));
    ui->comboBox_resistor->setCurrentIndex(-1);
}

void MainWindow::on_pushButton_save_clicked() {
     string name = createname();
    col_.saveCollection(name);
}



