#include "stoneshell.h"

StoneShell::StoneShell(QObject *parent) : QObject(parent)
{
}

void StoneShell::openApp(const QString &type, const QString &url)
{
    emit openAppRequest(type, url);
}
