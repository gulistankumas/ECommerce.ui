#pragma once

#include <QObject>
#include <QString>

class UrunOzellikleri : public QObject {
    Q_OBJECT
public:
    explicit UrunOzellikleri(const QString& _renk, const QString& _marka, QObject *parent = nullptr)
        : QObject(parent), renk(_renk), marka(_marka) {}

    QString getRenk() const {
        return renk;
    }

    QString getMarka() const {
        return marka;
    }

public slots:
    void setRenk(const QString& newRenk) {
        if (renk != newRenk) {
            renk = newRenk;
            emit renkDegisti(renk);
        }
    }

    void resetRenk() {
        renk.clear();
        emit renkDegisti(renk);
    }

    void setMarka(const QString& newMarka) {
        if (marka != newMarka) {
            marka = newMarka;
            emit markaDegisti(marka);
        }
    }

    void resetMarka() {
        marka.clear();
        emit markaDegisti(marka);
    }

signals:
    void renkDegisti(const QString& renk);
    void markaDegisti(const QString& marka);

private:
    QString renk;
    QString marka;

    Q_PROPERTY(QString renk READ getRenk WRITE setRenk RESET resetRenk NOTIFY renkDegisti FINAL)
    Q_PROPERTY(QString marka READ getMarka WRITE setMarka RESET resetMarka NOTIFY markaDegisti FINAL)
};
