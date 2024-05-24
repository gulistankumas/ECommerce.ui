#pragma once

#include <QObject>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QDataStream>
#include "Musteri.h"
#include "Magaza.h"
#include "SiparisUrunu.h"
#include "UrunKategori.h"

class SiparisBilgileri : public QObject {
    Q_OBJECT

private:
    Musteri _musteriBilgileri;
    Magaza _firmaBilgileri;
    QString _siparisTarihi;
    QVector<SiparisUrunu> _urunler;

public:
    explicit SiparisBilgileri(const Musteri& musteri, const Magaza& firma, const QString& siparisTarihi, QObject* parent = nullptr)
        : QObject(parent), _musteriBilgileri(musteri), _firmaBilgileri(firma), _siparisTarihi(siparisTarihi) {}

    Musteri getMusteriBilgileri() const { return _musteriBilgileri; }
    Magaza getFirmaBilgileri() const { return _firmaBilgileri; }
    QString getSiparisTarihi() const { return _siparisTarihi; }
    QVector<SiparisUrunu> getUrunler() const { return _urunler; }

    void urunEkle(const SiparisUrunu& siparisUrunu) {
        _urunler.append(siparisUrunu);
        emit urunEklendi(siparisUrunu);
    }

    void siparisDetaylariniYazdir() const {
        qDebug() << "Sipariş Tarihi: " << _siparisTarihi;
        qDebug() << "Müşteri Bilgileri: ";
        _musteriBilgileri.musteriBilgileriniGoster();
        qDebug() << "Firma Bilgileri: ";
        _firmaBilgileri.magazaBilgileriniGoster();
        qDebug() << "Ürünler: ";
        for (const auto& urun : _urunler) {
            urun.urunBilgileriniYazdir();
        }
    }

public slots:
    void setSiparisTarihi(const QString& newSiparisTarihi) {
        if (_siparisTarihi != newSiparisTarihi) {
            _siparisTarihi = newSiparisTarihi;
            emit siparisTarihiDegisti(_siparisTarihi);
        }
    }

signals:
    void urunEklendi(const SiparisUrunu& siparisUrunu);
    void siparisTarihiDegisti(const QString& newSiparisTarihi);

private:
    Q_PROPERTY(Musteri musteriBilgileri READ getMusteriBilgileri CONSTANT)
    Q_PROPERTY(Magaza firmaBilgileri READ getFirmaBilgileri CONSTANT)
    Q_PROPERTY(QString siparisTarihi READ getSiparisTarihi WRITE setSiparisTarihi NOTIFY siparisTarihiDegisti)
    Q_PROPERTY(QVector<SiparisUrunu> urunler READ getUrunler CONSTANT)

    friend QDataStream &operator<<(QDataStream &stream, const SiparisBilgileri &data);
    friend QDataStream &operator>>(QDataStream &stream, SiparisBilgileri &data);
};

// Serileştirme operatörü
QDataStream &operator<<(QDataStream &stream, const SiparisBilgileri &data) {
    stream << data._musteriBilgileri << data._firmaBilgileri << data._siparisTarihi << data._urunler;
    return stream;
}

// Geri yükleme operatörü
QDataStream &operator>>(QDataStream &stream, SiparisBilgileri &data) {
    stream >> data._musteriBilgileri >> data._firmaBilgileri >> data._siparisTarihi >> data._urunler;
    return stream;
}
