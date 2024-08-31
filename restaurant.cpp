#include<iostream>
#include<vector>
using namespace std;

// Kitchen interface
class Kitchen {
public:
    virtual void prepareFood() = 0;
    virtual ~Kitchen() {}
};

class Fooditems {
private:
    string name;

public:
    Fooditems(const string& name) : name(name) {}

    string getName() const {
        return name;
    }
};

// Concrete implementation of Kitchen
class ItalianKitchen : public Kitchen {
public:
    void prepareFood() override {
        // Implementation for preparing Italian food
        // ...
        cout << "Italian food is being prepared." << endl;
    }
};

// Concrete implementation of Kitchen
class IndianKitchen : public Kitchen {
public:
    void prepareFood() override {
        // Implementation for preparing Indian food
        // ...
        std::cout<<"indian food is being prepared"<<endl;
    }
};

vector<Fooditems*> createFoodItems() {
        vector<Fooditems*> foodItems;
        foodItems.push_back(new Fooditems("Biryani"));
        foodItems.push_back(new Fooditems("Butter Chicken"));
        foodItems.push_back(new Fooditems("Dosa"));
        return foodItems;
}

class KumaoniKitchen : public Kitchen {
public:
    void prepareFood() override {
        // Implementation for preparing Kumaoni food
        // ...
        cout << "The Tasty Kumaoni food is being prepared." << endl;
    }
};

// Serving interface
class Serving {
public:
    virtual void serveFood() = 0;
    virtual ~Serving() {}
};

// Concrete implementation of Serving
class DineInServing : public Serving {
public:
    void serveFood() override {
        // Implementation for serving food in a dine-in scenario
        // ...
        cout << "Food is being served to the table." << endl;
    }
};

// Concrete implementation of Serving
class TakeAwayServing : public Serving {
public:
    void serveFood() override {
        // Implementation for serving food in a take-away scenario
        // ...
        cout << "Food is being packed for take-away." << endl;
    }
};

// Waiter class
class Waiter {
private:
    Serving* serving;

public:
    Waiter(Serving* serving) : serving(serving) {}

    void serveFood() {
        serving->serveFood();
    }
};

// Chef class
class Chef {
private:
    Kitchen* kitchen;

public:
    Chef(Kitchen* kitchen) : kitchen(kitchen) {}

    void prepareFood() {
        kitchen->prepareFood();
    }
};

int main() {
    // Create instances of the dependencies
    Kitchen* italianKitchen = new ItalianKitchen();
    Kitchen* indianKitchen = new IndianKitchen();
    Kitchen* kumaoniKitchen = new KumaoniKitchen();
    Serving* dineInServing = new DineInServing();
    Serving* takeAwayServing = new TakeAwayServing();

    // Create instances of Waiter and Chef with appropriate dependencies
    Waiter waiter(dineInServing);
    Chef chef2(kumaoniKitchen);
	Chef chef(indianKitchen);
    // Get the food items from the IndianKitchen
    std::vector<Fooditems*> foodItems = createFoodItems();

    std::cout << "Indian Menu:" << std::endl;
    for (Fooditems* foodItem : foodItems) {
        std::cout << foodItem->getName() << std::endl;
    }


    

    // Use the Waiter and Chef objects
    waiter.serveFood();
    chef.prepareFood();
    chef2.prepareFood();

    // Clean up the dependencies
    delete italianKitchen;
    delete indianKitchen;
    delete kumaoniKitchen;
    delete dineInServing;
    delete takeAwayServing;

    // Clean up the food items
    

    return 0;
}
