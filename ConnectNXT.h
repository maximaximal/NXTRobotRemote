#ifndef CONNECTNXT_H
#define CONNECTNXT_H

#include <QDialog>
#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothAddress>
#include <QTableWidgetItem>

namespace Ui {
class ConnectNXT;
}

class ConnectNXT : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConnectNXT(QWidget *parent = 0);
    virtual ~ConnectNXT();

    void searchForDevices();
    
private:
    Ui::ConnectNXT *ui;
    void setStatus(const QString &status);

    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;

signals:
    void adressSelected(QBluetoothAddress adress);

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &info);
    void finished();

    void on_pushButton_clicked();
    void on_availableDevices_itemDoubleClicked(QTableWidgetItem *item);
};

#endif // CONNECTNXT_H
