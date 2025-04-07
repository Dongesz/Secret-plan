#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnadd_clicked();

    void on_btnsub_clicked();

    void on_btnmul_clicked();

    void on_btndev_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
