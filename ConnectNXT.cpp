#include "ConnectNXT.h"
#include "ui_ConnectNXT.h"

#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothAddress>
#include <iostream>

using std::cout;
using std::endl;

ConnectNXT::ConnectNXT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectNXT)
{
    ui->setupUi(this);

    m_discoveryAgent = NULL;

    this->searchForDevices();
}

ConnectNXT::~ConnectNXT()
{
    m_discoveryAgent->stop();
    m_discoveryAgent->deleteLater();
    delete ui;
}

void ConnectNXT::searchForDevices()
{
    if(m_discoveryAgent == NULL)
    {
        setStatus("Started searching for devices...");
        m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
        connect(m_discoveryAgent, SIGNAL(deviceDiscovered(const QBluetoothDeviceInfo&)),
                              this, SLOT(deviceDiscovered(const QBluetoothDeviceInfo&)));
        connect(m_discoveryAgent, SIGNAL(finished()),
                this, SLOT(finished()));
        m_discoveryAgent->start();
    }
}

void ConnectNXT::setStatus(const QString &status)
{
    ui->status->setText(status);
}

void ConnectNXT::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    setStatus("Found device!");
    ui->availableDevices->insertRow(0);
    ui->availableDevices->insertColumn(0);
    ui->availableDevices->insertColumn(1);
    ui->availableDevices->setItem(0, 0, new QTableWidgetItem(info.address().toString()));
    ui->availableDevices->setItem(0, 1, new QTableWidgetItem(info.name()));
}

void ConnectNXT::finished()
{
    setStatus("Finished.");
    delete m_discoveryAgent;
    m_discoveryAgent = NULL;
}

void ConnectNXT::on_pushButton_clicked()
{
    searchForDevices();
}

void ConnectNXT::on_availableDevices_itemDoubleClicked(QTableWidgetItem *item)
{
    QString address;
    if(item->column() == 0)
    {
        address = item->text();
    }
    else
    {
        address = ui->availableDevices->item(item->row(), 0)->text();
    }
    QBluetoothAddress btAddress(address);
    this->adressSelected(btAddress);
    setStatus(QString("Emitted Adress: ").append(address));
}
