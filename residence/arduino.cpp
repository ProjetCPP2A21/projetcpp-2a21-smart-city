#include "arduino.h"
#include <QDebug>
#include "connection.h"

Arduino::Arduino() {
    serial = new QSerialPort;
    arduino_is_available = false;
    arduino_portname = "COM3";

    // Detect COM port automatically
    foreach(const QSerialPortInfo &port, QSerialPortInfo::availablePorts()) {
        if (port.vendorIdentifier() != 0) {
            arduino_portname = port.portName();
            arduino_is_available = true;
        }
    }
}

Arduino::~Arduino() {
    if (serial->isOpen())
        serial->close();
}

int Arduino::connectArduino() {
    if (arduino_is_available) {

        serial->setPortName(arduino_portname);
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (serial->open(QIODevice::ReadWrite)) {
            qDebug() << "Arduino connected on" << arduino_portname;
            return 0;
        } else {
            qDebug() << "Failed to open serial port";
            return 1;
        }
    }

    qDebug() << "Arduino not found";
    return -1;
}

int Arduino::closeArduino() {
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}


bool Arduino::writeToArduino(const QByteArray &data) {
    if (serial->isWritable()) {
        qint64 bytesWritten = serial->write(data);

        serial->flush();

        if (bytesWritten > 0) {
            qDebug() << " OK: Command sent:" << data;
            return true;
        } else {

            qDebug() << " ERREUR D'ÉCRITURE: " << serial->errorString();
            return false;
        }
    }
    qDebug() << " ERREUR: Serial port is NOT writable (closed or disconnected).";
    return false;
}

QByteArray Arduino::readFromArduino() {
    if (serial->isReadable()) {
        return serial->readAll();
    }
    return QByteArray();
}

