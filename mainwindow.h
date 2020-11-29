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

    void on_lineEdit_stolbci_textChanged(const QString &arg1);

    void on_lineEdit_stroki_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_changechastota_clicked();

    void on_pushButton_changenumber_clicked();

    void on_pushButton_changeresist_clicked();

private:
    Ui::MainWindow *ui;
    Collection col_;
    int rows_, cols_;
};

#endif // MAINWINDOW_H
