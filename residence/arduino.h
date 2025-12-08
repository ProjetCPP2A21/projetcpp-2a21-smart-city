#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino {
public:
    Arduino();
    ~Arduino();

    int connectArduino();      // connect to Arduino
    int closeArduino();        // disconnect
    bool writeToArduino(const QByteArray &data); // send data
    QByteArray readFromArduino();               // receive data

private:
    QSerialPort *serial;
    QString arduino_portname;
    bool arduino_is_available;
};

#endif // ARDUINO_H
