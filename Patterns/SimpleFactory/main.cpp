#include <iostream>
#include <list>

using namespace std;

class Pizza{
protected:
    string name;
    string dough;
    string sauce;
    list<string> toppings;

public:
    void prepare(){
        cout << "Preparing " << name << endl;
        cout << "Tossing dough... " << endl;
        cout << "Adding sauce... " << endl;
        cout << "Adding toppings:" << endl;
        for (auto t: toppings) cout << "    " << t << endl;
    }

    void bake(){
        cout << "Bake for 25 min at 350" << endl;
    }

    void cut(){
        cout << "Cutting the pizza into diagonal slices" << endl;
    }

    void box(){
        cout << "Place pizza in official box" << endl;
    }

    string getName(){return name;}
};

class CheesePizza: public Pizza{
public:
    CheesePizza(){
        name = "Cheese Pizza";
        dough = "Thin crust dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Cheese");
    }
};

class PepperoniPizza: public Pizza{
public:
    PepperoniPizza(){
        name = "Pepperoni Pizza";
        dough = "Extra thick crust dough";
        sauce = "Plum tomato sauce";
        toppings.push_back("Pepperoni");
    }
};

class SimplePizzaFactory{
public:
    Pizza* createPizza(string type){
        Pizza *pizza = nullptr;
        if (type == "cheese") pizza = new CheesePizza();
        else if (type == "pepperoni") pizza = new PepperoniPizza();
        return pizza;
    }
};

class PizzaStore{
    SimplePizzaFactory &factory;
public:
    PizzaStore(SimplePizzaFactory &factory):factory(factory){}
    Pizza* orderPizza(string type){
        Pizza *pizza = nullptr;
        pizza = factory.createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};

int main()
{
    SimplePizzaFactory pizzaFactory;
    PizzaStore pizzaStore(pizzaFactory);
    Pizza *p = pizzaStore.orderPizza("cheese");
    cout << "Your pizza: " << p->getName() <<endl;
    delete p;
    return 0;
}
