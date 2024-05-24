#pragma once

#include <QObject>
#include <QString>
#include <QVector>
#include "ETicaretPlatformu.h"
#include "UrunBilgileri.h"

class UrunKategori : public  {
    Q_OBJECT
public:
    explicit UrunKategori(const QString& adi, QObject *parent = nullptr) : QObject(parent), _adi(adi) {}

    QString getAdi() const {
        return _adi;
    }

    void setAdi(const QString& yeniAdi) {
        if (_adi != yeniAdi) {
            _adi = yeniAdi;
            emit adiDegisti(_adi);
        }
    }

    void resetAdi() {
        _adi.clear();
        emit adiDegisti(_adi);
    }

    Q_PROPERTY(QString adi READ getAdi WRITE setAdi RESET resetAdi NOTIFY adiDegisti FINAL)

    QVector<UrunBilgileri> ozelliklereGoreAra(const UrunOzellikleri& arananOzellikler) const {
        QVector<UrunBilgileri> bulunanUrunler;
        for (const auto& urun : urunler) {
            if (urun.getOzellikler() == arananOzellikler) {
                bulunanUrunler.append(urun);
            }
        }
        return bulunanUrunler;
    }

signals:
    void adiDegisti(const QString& adi);
    void urunlerDegisti(const QVector<UrunBilgileri>& urunler);


public slots:
    void urunEkle(const UrunBilgileri& urun) {
        urunler.append(urun);
        emit urunlerDegisti(urunler);
    }

    void urunleriListele() const {
        for (const auto& urun : urunler) {
            qDebug() << urun.getAdi() << urun.getKodu() << urun.getAciklama() << urun.getFiyat();
        }
    }



private:
    QString _adi;
    QVector<UrunBilgileri> urunler;
};
