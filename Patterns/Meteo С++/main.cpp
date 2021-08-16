//#include <QCoreApplication>
#include <iostream>
#include <list>

using namespace std;


/*---Описание интерфейсов---*/

class iObserver{ //Этот интерфейс реализуется всеми наблюдателями
public:
    virtual void update(float temp, float humidity, float pressure) = 0; //У всех наблюдателей должен быть метод update
};

class iSubject{
public:
    virtual void registerObserver(iObserver& o) = 0;//Следующие 2 метода получают на вход ссылку на наблюдателя
    virtual void removeObserver(iObserver& o) = 0;
    virtual void notifyObservers() = 0;
};

class iDisplayElement { //Этот интерфейс содержит метод display, реализация этого метода зависит от выбранного подхода к отображению информации
public:
    virtual void display() = 0;
};


/*---Реализация субъекта---*/
class WeatherData: public iSubject{ // WeatherData - это субъект
private:
    list<iObserver*> observers; // список указателей на наблюдателей (см. stl::list)
    float temperature;
    float humidity;
    float pressure;
public:
    void registerObserver(iObserver &o) override{ //регистрация наблюдателя
        observers.push_back(&o); //добавляем наблюдателя в список
    }
    void removeObserver(iObserver &o) override{ //удаление наблюдателя
        observers.remove(&o); //удаляем наблюдателя из списка
    }
    void notifyObservers() override{ //уведомление наблюдателей
        for (auto it = observers.begin(); it!=observers.end(); it++){ //перебираем всех наблюдателей из списка (см. stl::list)
            (*it)->update(temperature, humidity, pressure); // у каждого вызываем метод update
        }
    }
    void measurementsChanged(){ //оповещение наблюдателей при появлении новых данных
        notifyObservers();
    }
    void setMeasurements(float temperature, float humidity, float pressure){ //Здесь должны быть получены данные с метиостанции (можете доработать метод, чтобы он принимал данные из интернета)
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};

/*---Реализация наблюдателей---*/
//Здесь реализован только один наблюдатель, при желании можно добавить другие
class CurrentConditionsDisplay: public iObserver, iDisplayElement{ //множественное наследование (реализация) интерфейсов
private:
    float temperature;
    float humidity;
    float pressure;
    iSubject &weatherData; //ссылка на субъект
public:
    CurrentConditionsDisplay(iSubject &weatherData):weatherData(weatherData){ //конструктор инициализирует внутренний субъект
        weatherData.registerObserver(*this); //и вызывает метод регистрации наблюдателя
    }
    void update(float temperature, float humidity, float pressure) override{ //обновление информации
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        display(); //отображение информации
    }
    void display() override{ //метод display выводит информацию на консоль
        cout<<"Current conditions: "<<temperature<<"C degrees and "<<humidity<<"% humidity"<<endl;
    }
    void unregister(){ //можно вызвать этот метод в случае, если хотим отписаться от рассылки
        weatherData.removeObserver(*this);
    }

};


/*---Тестирование системы---*/
int main()
{
    WeatherData weatherData; // создаем метеостанцию
    CurrentConditionsDisplay currentDisplay(weatherData);// создаем экран наблюдения (здесь можно создать другие экраны наблюдения)
    // изменяем состояние метеостанции
    weatherData.setMeasurements(25, 65, 30.4f);
    weatherData.setMeasurements(27, 70, 29.2f);
    weatherData.setMeasurements(23, 90, 29.2f);
    return 0;
}
