#include <iostream>
#include <vector>

using namespace std;

class FoodApp {
public:
    virtual void some_changes_() {}
    virtual void display_info() {}
};

class FoodAppManager {
private:
    vector<FoodApp*> food_apps;

public:
    void add_food_app(FoodApp* food_app) {
        food_apps.push_back(food_app);
    }

    void display_all_apps_info() {
        for (vector<FoodApp*>::iterator it = food_apps.begin(); it != food_apps.end(); ++it) {
            (*it)->display_info();
            cout << endl;
        }
    }
};

class FoodPanda : public FoodApp {
public:
    FoodPanda() {
        cout << "food_panda added" << endl;
    }

    void some_changes_() override {
        cout << "Some features added in food_panda" << endl;
        cout << "New payment options added" << endl;
    }

    void display_info() override {
        cout << "Food App: food_panda" << endl;
        cout << "Available cuisines: Chinese, Indian, Italian" << endl;
    }
};

class Zomato : public FoodApp {
public:
    Zomato() {
        cout << "zomato added" << endl;
    }

    void some_changes_() override {
        cout << "Some features added in zomato" << endl;
        cout << "Live order tracking implemented" << endl;
    }

    void display_info() override {
        cout << "Food App: zomato" << endl;
        cout << "Available cuisines: Indian, Mexican, Thai" << endl;
    }
};

class Swiggy : public FoodApp {
public:
    Swiggy() {
        cout << "swiggy added" << endl;
    }

    void some_changes_() override {
        cout << "Some features added in swiggy" << endl;
        cout << "Group ordering functionality added" << endl;
    }

    void display_info() override {
        cout << "Food App: swiggy" << endl;
        cout << "Available cuisines: Indian, Continental, Fast Food" << endl;
    }
};

int main() {
    FoodAppManager app_manager;
    app_manager.add_food_app(new Zomato());
    app_manager.add_food_app(new Swiggy());
    app_manager.add_food_app(new FoodPanda());
    app_manager.display_all_apps_info();

    return 0;
}

