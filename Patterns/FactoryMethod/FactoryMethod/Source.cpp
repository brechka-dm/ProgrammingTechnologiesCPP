#include <iostream>
#include <list>
using namespace std;

class Pizza {
protected:
    string name;
    string dough;
    string sauce;
    list<string> toppings;

public:
    virtual void prepare() {
        cout << "Preparing " << name << endl;
        cout << "Tossing dough... " << endl;
        cout << "Adding sauce... " << endl;
        cout << "Adding toppings:" << endl;
        for (auto t : toppings) cout << "    " << t << endl;
    }

    virtual void bake() {
        cout << "Bake for 25 min at 350" << endl;
    }

    virtual void cut() {
        cout << "Cutting the pizza into diagonal slices" << endl;
    }

    virtual void box() {
        cout << "Place pizza in official box" << endl;
    }

    string getName() { return name; }
};

class NYStyleCheesePizza :public Pizza {
public:
    NYStyleCheesePizza() {
        name = "NY Style Sause and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Grated Reggiano Cheese");
    }
};

class ChicagoStyleCheesePizza :public Pizza {
public:
    ChicagoStyleCheesePizza() {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shradded Mozzarella Cheese");
    }

    void cut() override {
        cout << "Cutting the pizza into square slices" << endl;
    }
};

class PizzaStore {
public:
    shared_ptr<Pizza> orderPizza(const string& type) {
        shared_ptr<Pizza> pizza = nullptr;
        pizza = createPizza(type);
        if (pizza) {
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
            return pizza;
        }
        else {
            return nullptr;
        }
    }
    virtual shared_ptr<Pizza> createPizza(const string& type) = 0; // Factory method.
};

class NYPizzaStore : public PizzaStore {
    shared_ptr<Pizza> createPizza(const string& type) override {
        if (type == "cheese") {
            return make_shared<NYStyleCheesePizza>();
        }
        else {
            cout << "Have no this pizza type yet" << endl;
            return nullptr;
        }
    }
};

class ChicagoPizzaStore : public PizzaStore {
    shared_ptr<Pizza> createPizza(const string& type) override {
        if (type == "cheese") {
            return make_shared<ChicagoStyleCheesePizza>();
        }
        else {
            cout << "Have no this pizza type yet" << endl;
            return nullptr;
        }
    }
};

int main() {
    unique_ptr<PizzaStore> nyStore = make_unique<NYPizzaStore>();
    unique_ptr<PizzaStore> chicagoStore = make_unique<ChicagoPizzaStore>();
    shared_ptr<Pizza> pizza = nyStore->orderPizza("cheese");
    if (pizza) cout << "Your pizza " << pizza->getName() << endl;
    else cout << "We'r so sorry" << endl;
    cout << endl;
    pizza = chicagoStore->orderPizza("cheese");
    if (pizza) cout << "Your pizza " << pizza->getName() << endl;
    else cout << "We'r so sorry" << endl;
    cout << endl;
    pizza = chicagoStore->orderPizza("pepperony");
    if (pizza) cout << "Your pizza " << pizza->getName() << endl;
    else cout << "We'r so sorry" << endl;

	return 0;
}