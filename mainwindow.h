#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include "collection.h"
#include "inductance.h"
#include <vector>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_create_matrix_clicked();

    void on_comboBox_resistor_activated(int index);

    void on_pushButton_changechastota_clicked();

    void on_pushButton_changenumber_clicked();

    void on_pushButton_changeresist_clicked();

    void on_pushButton_new_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_changecapacity_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_changenumber_2_clicked();

    void on_pushButton_changeresist_2_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::MainWindow *ui;
    Collection col_;
    int rows_, cols_;
    vector<Inductance> ind_;
};

#endif // MAINWINDOW_H
