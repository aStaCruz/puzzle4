#include "traffic_light.h"

Traffic_Light::Traffic_Light()
{
    for(int i = 0; i < 3; i++)
    {
        m_light[i].set_color(static_cast<Color>(i));
        m_light[i].set_light(false);

    }
    _stateCount = 0;
    m_light[0].set_light(true); // Red light

    qDebug() << "Traffic light ctor.";

    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);
}

void Traffic_Light::update()
{
    ++_stateCount;
    if(_stateCount == 15)//at red light for 0s
        toggle_light(1);//yellow light
    else if(_stateCount == 20)
    {
        toggle_light(0);
        _stateCount -= 40; //account for 20s
    }
    else if(_stateCount == 0)
        toggle_light(2); //green
}
bool Traffic_Light::get_light_on(int index)
{
    return m_light[index].get_light();
}

void Traffic_Light::toggle_light(int index)
{
    for(int i = 0; i < 3; i++)
    {
        if(i == index)
            m_light[i].set_light(true);
        else
            m_light[i].set_light(false);
    }
}

