#include "arduino.h"

Arduino::Arduino()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort();
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort* Arduino::getserial()
{
    return serial;
}

int Arduino::connect_arduino()
{
    // chercher Arduino
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.hasVendorIdentifier() && info.hasProductIdentifier()) {
            if (info.vendorIdentifier() == arduino_uno_vendor_id &&
                info.productIdentifier() == arduino_uno_product_id) {
                arduino_port_name = info.portName();
                arduino_is_available = true;
            }
        }
    }

    qDebug() << "Arduino trouvé sur :" << arduino_port_name;

    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);

        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            return 0;  // OK
        }

        return 1; // port trouvé mais impossible d'ouvrir
    }

    return -1; // Arduino introuvable
}

int Arduino::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }

    return 1;
}

QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable())
        data = serial->readAll();

    return data;
}

void Arduino::write_to_arduino(QByteArray d)
{
    if (serial->isWritable()) {
        serial->write(d);
    } else {
        qDebug() << "Impossible d'écrire dans le port série.";
    }
}
