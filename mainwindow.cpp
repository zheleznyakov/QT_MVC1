#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);

//объявляем новую модель данных
QStringListModel *model= new QStringListModel(this);
//добавляем данные в созданную модель
model->setStringList(QStringList()<<"Элемент1"<<"Элемент2"<<"Элемент3");
//каждому элементу представления присваиваем созданную модель данных
ui->treeView->setModel(model);
ui->listView->setModel(model);
ui->tableView->setModel(model);

/* следующий код создаёт общую модель для выделения элементов
 * если мы выделим какой - либо элемент в одном из представлений,
 * он автоматически выделится в остальных представлениях
*/
QItemSelectionModel *selection = new QItemSelectionModel(model);
ui->listView->setSelectionModel(selection);
ui->treeView->setSelectionModel(selection);
ui->tableView->setSelectionModel(selection);

// программный выбор одного из элементов модели(в нашем случае вторая строка)
QModelIndex index = model->index(1,0); //находим индекс второй строки
selection->select(index,QItemSelectionModel::Select);//выделяем соответствующую строку
}

MainWindow::~MainWindow()
{
delete ui;
}
