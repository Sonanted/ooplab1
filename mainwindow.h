#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include "collection.h"

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

private:
    Ui::MainWindow *ui;
    Collection col_;
    int rows_, cols_;
};

#endif // MAINWINDOW_H
