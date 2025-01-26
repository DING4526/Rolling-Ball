#ifndef PORTAL_H
#define PORTAL_H

#include <QWidget>
#include <QLabel>

class portal : public QLabel
{
    Q_OBJECT
public:
    portal(portal*,QWidget* parent=0);

    double vn,vt;

signals:
};

#endif // PORTAL_H
