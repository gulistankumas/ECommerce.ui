#pragma once

#include "urunbilgileri.h"
#include "qdebug.h"
#include "qtmetamacros.h"
#include <QObject>
#include <QString>
#include <QVector>

class Magaza
{ 
public:
    explicit Magaza(const QString& adres, const QString& telefon, const QString& yetkiliKisi, const QString& magazaAdi, QObject *parent = nullptr)
        : QObject(parent), _adres(adres), _telefon(telefon), _yetkiliKisi(yetkiliKisi), _magazaAdi(magazaAdi) {}

    QString getAdres() const { return _adres; }
    QString getTelefon() const { return _telefon; }
    QString getYetkiliKisi() const { return _yetkiliKisi; }
    QString getMagazaAdi() const { return _magazaAdi; }



    void magazaBilgileriniGoster() const {
        // Bu metot mağaza bilgilerini gösterir, örneğin bir dialog veya konsolda
        qDebug() << "Mağaza Adı: " << _magazaAdi;
        qDebug() << "Adres: " << _adres;
        qDebug() << "Telefon: " << _telefon;
        qDebug() << "Yetkili Kişi: " << _yetkiliKisi;
    }

    QVector<UrunBilgileri> urunler; // Ürün bilgilerini tutan vektör


public slots:
    // Slotlar burada tanımlanabilir
    void setAdres(const QString& newadres) {
        if (_adres != newadres) {
            _adres = newadres;
            emit adresDegisti(_adres); // adresDegisti sinyalini yayınla
        }
    }

    void resetMagazaAdresi() {
        if (!_adres.isEmpty()) {
            _adres = "";
            emit adresDegisti(_adres); // adresDegisti sinyalini yayınla
        }
    }

    void setTelefon(const QString& newtelefon) {
        if (_telefon != newtelefon) {
            _telefon = newtelefon;
            emit telefonDegisti(_telefon); // telefonDegisti sinyalini yayınla
        }
    }

    void resetMagazaTelefon() {
        if (!_telefon.isEmpty()) {
            _telefon = "";
            emit telefonDegisti(_telefon); // telefonDegisti sinyalini yayınla
        }
    }

    void setYetkiliKisi(const QString& newyetkiliKisi) {
        if (_yetkiliKisi != newyetkiliKisi) {
            _yetkiliKisi = newyetkiliKisi;
            emit yetkiliKisiDegisti(_yetkiliKisi); // yetkiliKisiDegisti sinyalini yayınla
        }
    }

    void resetYetkiliKisi() {
        if (!_yetkiliKisi.isEmpty()) {
            _yetkiliKisi = "";
            emit yetkiliKisiDegisti(_yetkiliKisi); // yetkiliKisiDegisti sinyalini yayınla
        }
    }

    void setMagazaAdi(const QString& newmagazaAdi) {
        if (_magazaAdi != newmagazaAdi) {
            _magazaAdi = newmagazaAdi;
            emit magazaAdiDegisti(_magazaAdi); // magazaAdiDegisti sinyalini yayınla
        }
    }

    void resetMagazaAdi() {
        if (!_magazaAdi.isEmpty()) {
            _magazaAdi = "";
            emit magazaAdiDegisti(_magazaAdi); // magazaAdiDegisti sinyalini yayınla
        }
    }

signals:
         // Sinyaller burada tanımlanabilir
    void adresDegisti(const QString &newAdres);
    void telefonDegisti(const QString &newTelefon);
    void yetkiliKisiDegisti(const QString &newYetkiliKisi);
    void magazaAdiDegisti(const QString &newMagazaAdi);

private:
    Q_OBJECT
    QString _adres;
    QString _telefon;
    QString _yetkiliKisi;
    QString _magazaAdi;

    Q_PROPERTY(QString adres READ getAdres WRITE setAdres RESET resetAdres NOTIFY adresDegisti FINAL)
    Q_PROPERTY(QString telefon READ getTelefon WRITE setTelefon RESET resetTelefon NOTIFY telefonDegisti FINAL)
    Q_PROPERTY(QString yetkiliKisi READ getYetkiliKisi WRITE setYetkiliKisi RESET resetYetkiliKisi NOTIFY yetkiliKisiDegisti FINAL)
    Q_PROPERTY(QString magazaAdi READ getMagazaAdi WRITE setMagazaAdi RESET resetMagazaAdi NOTIFY magazaAdiDegisti FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const Magaza &data);

    friend QDataStream &operator>>(QDataStream &stream, Magaza &data);



};
