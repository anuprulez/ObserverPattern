#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include "WeatherData.h"

using namespace std;

WeatherData::WeatherData()
{

}

WeatherData::~WeatherData()
{
    //dtor
}

Observer::Observer()
{

}

Subject::Subject()
{

}

Subject::~Subject()
{
    //dtor
}

void Observer::update(float, float, float)
{

}

void Subject::addObserver(Observer* o)
{

}

void Subject::notifyObservers()
{

}

void WeatherData::addObserver(Observer* o)
{
    oberserverList.push_back(o);
}


void WeatherData::notifyObservers()
{
    for (vector<Observer*>::iterator it=oberserverList.begin() ; it!=oberserverList.end() ; it++)
    {
        (*it)->update(temp, press, hum);
    }
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(float t, float p, float h)
{
    temp = t;
    press = p;
    hum = h;
    measurementsChanged();
}

AndroidDisplay::AndroidDisplay()
{

}

AndroidDisplay::AndroidDisplay(Subject* wd)
{
    weatherData = wd;
    wd->addObserver(this);
}

void AndroidDisplay::update(float t, float p, float h)
{
    temperature_ad = t;
    pressure_ad = p;
    display();
}

void AndroidDisplay::display()
{
    std::cout << "Temperature: " << temperature_ad << " Pressure: " << pressure_ad << std::endl;
}

int main()
{
    WeatherData wd;
    Subject *subject = &wd;
    AndroidDisplay ad(subject);
    wd.setMeasurements(100, 200, 300);
    return 0;
}
