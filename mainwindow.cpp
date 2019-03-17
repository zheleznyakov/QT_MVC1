#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);

QStringListModel *model= new QStringListModel(this);

model->setStringList(QStringList()<<"Элемент1"<<"Элемент2"<<"Элемент3");
ui->treeView->setModel(model);
ui->listView->setModel(model);
ui->tableView->setModel(model);

QItemSelectionModel *selection = new QItemSelectionModel(model);
ui->listView->setSelectionModel(selection);
ui->treeView->setSelectionModel(selection);
ui->tableView->setSelectionModel(selection);

QModelIndex index = model->index(1,0);//программно выбираем вторую строку

selection->select(index,QItemSelectionModel::Select);
}

MainWindow::~MainWindow()
{
delete ui;
}
