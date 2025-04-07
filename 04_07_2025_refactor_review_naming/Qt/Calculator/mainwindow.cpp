#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::handleButton);
}
void MainWindow::handleButton() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString currentText = ui->lineEdit->text();
    QString buttonText = button->text();

    ui->lineEdit->setText(currentText + buttonText);
}
MainWindow::~MainWindow()
{
    delete ui;
}
