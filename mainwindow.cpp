#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_Plus_Minus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_Percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_Plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));


    ui->pushButton_Plus->setChecked(true);
    ui->pushButton_Minus->setChecked(true);
    ui->pushButton_Divide->setChecked(true);
    ui->pushButton_Multiply->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){

    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    labelNumber = (ui->label->text() + button->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);

    ui->label->setText(newLabel);

}

void MainWindow::on_pushButton_Decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed(){

    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if(button->text()=="+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text()=="%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

}

void MainWindow::on_pushButton_clear_released()
{

}


void MainWindow::on_pushButton_Equal_released()
{

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    firstNum = ui->label->text().toDouble();

    button->setChecked(true);

}
