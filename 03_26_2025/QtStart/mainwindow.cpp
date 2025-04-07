#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
double firstNum, secondNum, result;

void MainWindow::on_btnadd_clicked()
{
    firstNum = ui->txtnum1->text().toInt();
    secondNum = ui->txtnum2->text().toInt();
    result = firstNum+secondNum;
    ui->txtresult->setText(QString::number(result));
}


void MainWindow::on_btnsub_clicked()
{
    firstNum = ui->txtnum1->text().toInt();
    secondNum = ui->txtnum2->text().toInt();
    result = firstNum-secondNum;
    ui->txtresult->setText(QString::number(result));
}


void MainWindow::on_btnmul_clicked()
{
    firstNum = ui->txtnum1->text().toInt();
    secondNum = ui->txtnum2->text().toInt();
    result = firstNum*secondNum;
    ui->txtresult->setText(QString::number(result));
}


void MainWindow::on_btndev_clicked()
{
    firstNum = ui->txtnum1->text().toInt();
    secondNum = ui->txtnum2->text().toInt();
    if (firstNum == 0 || secondNum == 0){
        ui->txtresult->setText(QString("Cannot devide by 0!!!"));
        return;
    }
    else{
        result = firstNum/secondNum;
        ui->txtresult->setText(QString::number(result));
    }
}

