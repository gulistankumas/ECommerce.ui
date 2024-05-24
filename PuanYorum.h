#pragma once
#include <QObject>
#include <QVector>
#include <QString>

class PuanYorum
{
     Q_OBJECT
public:
    explicit PuanYorum(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE void puanEkle(double yeniPuan, const QString& yeniYorum);
    Q_INVOKABLE double ortalamaPuan() const;
    Q_INVOKABLE void puanYorumlariGoster() const;

public slots:
    void setPuanlar(const QVector<double>& newPuanlar) {
        if (puanlar != newPuanlar) {
            puanlar = newPuanlar;
            emit puanlarDegisti(puanlar);
        }
    }

    void setYorumlar(const QVector<QString>& newYorumlar) {
        if (yorumlar != newYorumlar) {
            yorumlar = newYorumlar;
            emit yorumlarDegisti(yorumlar);
        }
    }

    void resetPuanlar() {
        puanlar.clear();
        emit puanlarDegisti(puanlar);
    }

    void resetYorumlar() {
        yorumlar.clear();
        emit yorumlarDegisti(yorumlar);
    }


signals:

    void puanlarDegisti(const QVector<double>& puanlar);
    void yorumlarDegisti(const QVector<QString>& yorumlar);

private:

    QVector<double> puanlar; //! Puanları tutan vektör.
    QVector<QString> yorumlar; //! Yorumları tutan vektör.

    Q_PROPERTY(QVector<double> puanlar READ getPuanlar WRITE setPuanlar RESET resetPuanlar NOTIFY puanlarDegisti FINAL)
    Q_PROPERTY(QVector<QString> yorumlar READ getYorumlar WRITE setYorumlar RESET resetYorumlar NOTIFY yorumlarDegisti FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const PuanYorum &data){
        stream << data.puanlar <<data.yorumlar;
        return stream;
    };

    friend QDataStream &operator>>(QDataStream &stream, PuanYorum &data){
        stream >> data.yorumlar >> data.puanlar ;
        return stream;
    };
};
