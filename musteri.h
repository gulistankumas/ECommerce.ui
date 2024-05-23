#pragma once

#include <QObject>
#include <QString>
#include <QVector>
#include <QSet>
#include <QDebug>
#include <QDataStream>
#include "urunbilgileri.h"

class Musteri : public UrunBilgileri
{
     Q_OBJECT
public:
     explicit Musteri(const QString& adi, const QString& soyadi, const QString& telefon, const QString& adres, QObject *parent = nullptr)
         : QObject(parent), _adi(adi), _soyadi(soyadi), _telefon(telefon), _adres(adres) {}

     QString getAdi() const { return _adi; }
     QString getSoyadi() const { return _soyadi; }
     QString getTelefon() const { return _telefon; }
     QString getAdres() const { return _adres; }

public slots:
     void setAdres(const QString &newAdres) {
         if (_adres != newAdres) {
             _adres = newAdres;
             emit adresDegisti(_adres); // adresDegisti sinyalini yayınla
         }
     }

     void resetAdres() {
         if (!_adres.isEmpty()) {
             _adres = "";
             emit adresDegisti(_adres); // adresDegisti sinyalini yayınla
         }
     }

     void setAdi(const QString &newAdi) {
         if (_adi != newAdi) {
             _adi = newAdi;
             emit adiDegisti(_adi); // adiDegisti sinyalini yayınla
         }
     }

     void setSoyadi(const QString &newSoyadi) {
         if (_soyadi != newSoyadi) {
             _soyadi = newSoyadi;
             emit soyadiDegisti(_soyadi); // soyadiDegisti sinyalini yayınla
         }
     }

     void setTelefon(const QString &newTelefon) {
         if (_telefon != newTelefon) {
             _telefon = newTelefon;
             emit telefonDegisti(_telefon); // telefonDegisti sinyalini yayınla
         }
     }

     void resetTelefon() {
         if (!_telefon.isEmpty()) {
             _telefon = "";
             emit telefonDegisti(_telefon); // telefonDegisti sinyalini yayınla
         }
     }


 signals:
     void adiDegisti(const QString &newAdi);
     void soyadiDegisti(const QString &newSoyadi);
     void telefonDegisti(const QString &newTelefon);
     void adresDegisti(const QString &newAdres);


 private:
     QString _adi;
     QString _soyadi;
     QString _telefon;
     QString _adres;

     Q_PROPERTY(QString adi READ getAdi WRITE setAdi NOTIFY adiDegisti FINAL)
     Q_PROPERTY(QString soyadi READ getSoyadi WRITE setSoyadi NOTIFY soyadiDegisti FINAL)
     Q_PROPERTY(QString telefon READ getTelefon WRITE setTelefon RESET resetTelefon NOTIFY telefonDegisti FINAL)
     Q_PROPERTY(QString adres READ getAdres WRITE setAdres NOTIFY adresDegisti FINAL)

     friend QDataStream &operator<<(QDataStream &stream, const Musteri &data) {
         // Ata sınıfı serileştirme işlemleri (eğer varsa) burada yapılmalıdır.
         stream << data._adi << data._soyadi << data._telefon << data._adres;
         return stream;
     }

     friend QDataStream &operator>>(QDataStream &stream, Musteri &data) {
         // Ata sınıfı geri yükleme işlemleri (eğer varsa) burada yapılmalıdır.
         stream >> data._adi >> data._soyadi >> data._telefon >> data._adres;
         return stream;
     }

};

