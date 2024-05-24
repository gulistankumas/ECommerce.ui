#pragma once
#include <QString>
#include "UrunOzellikleri.h"

class UrunBilgileri
{
public:
    explicit Urun_bilgileri(const QString& adi, const QString& kodu, const QString& aciklama, double fiyat, const UrunOzellikleri& ozellikler, const QString& kategoriadi, QObject *parent = nullptr);


    QString getAdi() const { return _adi; }
    QString getKodu() const { return _kodu; }
    QString getAciklama() const { return _aciklama; }
    double getFiyat() const { return _fiyat; }
    UrunOzellikleri getOzellikler() const { return ozellikler; }
    QString getKategoriadi() const { return _kategoriadi; }


    void urun_bilgilerini_goster() const;

    // == operatörü
    bool operator==(const UrunBilgileri& other) const {
        return this->getAdi() == other.getAdi() && this->getKategoriadi() == other.getKategoriadi();
    }

    // != operatörü
    bool operator!=(const UrunBilgileri& other) const {
        return !(*this == other);
    }


public slots:

    void setAdi(const QString &newAdi) {
        if (_adi != newAdi) {
            _adi = newAdi;
            emit adiDegisti(_adi);
        }
    }
    void resetAdi() {
        _adi.clear();
        emit adiDegisti(_adi);
    }


    void setkodu(const QString &newkodu) {
        if (_kodu != newkodu) {
            _kodu = newkodu;
            emit koduDegisti(_kodu);
        }
    }

    void resetkodu() {
        _kodu.clear();
        emit koduDegisti(_kodu);
    }

    void setAciklama(const QString &newAciklama) {
        if (_aciklama != newAciklama) {
            _aciklama                = newAciklama;
            emit aciklamaDegisti(_aciklama);
        }
    }
    void resetAciklama() {
        _aciklama.clear();
        emit aciklamaDegisti(_aciklama);
    }
    void setfiyat( double &newFiyat) {
        if (_fiyat != newFiyat) {
            _fiyat = newFiyat;
            emit fiyatDegisti(_fiyat);
        }

    void resetfiyat() {
        _fiyat.clear();
        emit fiyatDegisti(_fiyat);
    }
    }
    void resetOzellikler() {
        _ozellikler.clear();
        emit ozelliklerDegisti(_ozellikler);
    }
    void setKategoriadi(const QString &newKategoriadi) {
        if (_kategoriadi != newKategoriadi) {
            _kategoriadi = newKategoriadi;
            emit kategoriadiDegisti(_kategoriadi);
        }
    }
    void resetKategoriadi() {
        _kategoriadi.clear();
        emit kategoriadiDegisti(_kategoriadi);
    }

signals:
    void adiDegisti(const QString &adi);
    void koduDegisti(const QString &kodu);
    void aciklamaDegisti(const QString &aciklama);
    void fiyatDegisti( double &fiyat);
    void ozelliklerDegisti(const QString &ozellikler);
    void kategoriadiDegisti(const QString &kategoriadi);


private:
    QString _adi;
    QString _kodu;
    QString _aciklama;
    double _fiyat;
    UrunOzellikleri ozellikler;
    QString _kategoriadi;

    Q_PROPERTY(QString adi READ getAdi WRITE setAdi RESET resetAdi NOTIFY adiDegisti FINAL)
    Q_PROPERTY(QString kodu READ getKodu WRITE setKodu RESET resetKodu NOTIFY KoduDegisti FINAL)
    Q_PROPERTY(QString aciklama READ getAciklama WRITE setAciklama RESET resetAciklama NOTIFY AciklamaDegisti FINAL)
    Q_PROPERTY(double fiyat READ getFiyat WRITE setFiyat RESET resetFiyat NOTIFY FiyatDegisti FINAL)
    Q_PROPERTY(QString ozellikler READ getOzellikler WRITE setOzellikler RESET resetOzellikler NOTIFY OzelliklerDegisti FINAL)
    Q_PROPERTY(QString kategoriadi READ getKategoriadi WRITE setKategoriadi RESET resetKategoriadi NOTIFY KategoriadiDegisti FINAL)


    friend QDataStream &operator<<(QDataStream &stream, const UrunBilgileri &data) {
        stream << data._adi << data._kodu << data._aciklama << data._fiyat<< data._ozellikler << data._kategoriadi;
        // Özelliklerin serileştirilmesi için gerekli işlemleri burada yapın
        return stream;
    }


    friend QDataStream &operator>>(QDataStream &stream, UrunBilgileri &data) {
        stream >> data._adi >> data._kodu >> data._aciklama >> data._fiyat >> data._ozellikler >> data._kategoriadi;
        // Özelliklerin geri yüklenmesi için gerekli işlemleri burada yapın
        return stream;
    }

};
