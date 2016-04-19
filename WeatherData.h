#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <vector>

//// **************** Abstract classes - Pure virtual functions *************************
class Observer
{
    float temperature;
    float pressure;
    float humidity;
    public:
        Observer();
        void virtual update(float, float, float) = 0;
};

class Subject
{
    public:
        Subject();
        virtual ~Subject();
        void virtual addObserver(Observer* o) = 0;
        void virtual notifyObservers() = 0;
};

// *************************** -----------------

class WeatherData: public Subject
{
    std::vector<Observer*> oberserverList;
    float temp;
    float press;
    float hum;
    public:
        WeatherData();
        WeatherData(float, float, float);
        virtual ~WeatherData();
        void addObserver(Observer*);
        void notifyObservers();
        void measurementsChanged();
        void setMeasurements(float, float, float);
    protected:
    private:
};

// ********* Display class ********************************
class AndroidDisplay: public Observer
{
    float temperature_ad;
    float pressure_ad;
    Subject* weatherData;
    public:
        AndroidDisplay();
        AndroidDisplay(Subject*);
        void update(float, float, float);
        void display();
};

#endif // WEATHERDATA_H
