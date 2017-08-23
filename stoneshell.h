#ifndef STONESHELL_H
#define STONESHELL_H

#include <QObject>

class StoneShell : public QObject
{
    Q_OBJECT
public:
    explicit StoneShell(QObject *parent = 0);

signals:
    void openAppRequest(const QString &type, const QString &url);

public slots:
    void openApp(const QString &type, const QString &url);
};

#endif // STONESHELL_H
