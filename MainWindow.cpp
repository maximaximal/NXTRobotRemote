#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_connectNXT = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_connectNXT != NULL)
    {
        delete m_connectNXT;
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(m_connectNXT == NULL)
    {
        m_connectNXT = new ConnectNXT();
        m_connectNXT->show();
    }
}
