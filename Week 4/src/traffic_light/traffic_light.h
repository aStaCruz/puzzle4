#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QDebug>
#include <QObject>
#include <QTimer>
#include "light.h"

class Traffic_Light : public QObject
{
    Q_OBJECT
public:
    Traffic_Light();

public slots:
    bool get_light_on(int index);
    void toggle_light(int index);
       void update();
private:
    Light m_light[3];
    int _stateCount;

};
#endif // TRAFFIC_LIGHT_H
