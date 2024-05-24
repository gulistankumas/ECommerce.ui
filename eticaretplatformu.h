#pragma once

#include <QObject>
#include <QVector>
#include <QDebug>
#include "Musteri.h"

class ETicaretPlatformu : Musteri

{
      Q_OBJECT
public:
    explicit ETicaretPlatformu(QObject *parent = nullptr) : QObject(parent) {}

     QVector<Musteri> getMusteriler() const { return musteriler; }

public slots:
        void musteriEkle(const Musteri &musteri) {
        musteriler.append(musteri);
        emit musteriEklendi(musteri); // musteriEklendi sinyalini yayınla
    }




signals:

    void musteriEklendi(const Musteri &musteri);

private:
    QVector<Musteri> musteriler; //! Müşteri listesini tutan QVector.

    friend QDataStream &operator<<(QDataStream &stream, const ETicaretPlatformu &data){
        stream<< data.musteriler;
    };
    friend QDataStream &operator>>(QDataStream &stream,  ETicaretPlatformu &data){
        stream>> data.musteriler;
    };;

};
