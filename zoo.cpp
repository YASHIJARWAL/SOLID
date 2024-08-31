#include<iostream>
using namespace std;

class animal {
protected:
    string name;
public:
    animal(const string &name) : name(name) {}
    string get_name() const {
        return name;
    }
    virtual void make_sound() const = 0;
};

class egglayer { //egglayer interface
public:
    virtual void egg_layer() const = 0;
    virtual void make_sound() const = 0; // Add a virtual make_sound function here
};

class milkproducer {//milkproducer interface
public:
    virtual void milk_producer() const = 0;
    virtual void make_sound() const = 0; // Add a virtual make_sound function here
};
class reptile:public animal, public egglayer{
    public:
    reptile(const string &name):animal(name){}
    virtual void egg_layer() const override{
        cout<<get_name()<<"lays egg";
    }
    virtual void make_sound() const override{
        cout<<get_name()<<"makes scary noise";
    }
};
class bird : public animal, public egglayer {
public:
    bird(const string &name) : animal(name) {}
    void egg_layer() const override {
        cout << get_name() << " lays eggs" << endl;
    }
    void make_sound() const override {
        cout << get_name() << " chirps" << endl;
    }
};

class mammal : public animal, public milkproducer {
public:
    mammal(const string &name) : animal(name) {}
    void milk_producer() const override {
        cout << get_name() << " produces milk" << endl;
    }
    void make_sound() const override {
        cout << get_name() << " produces mammal sound" << endl;
    }
};

int main() {
    bird myBird("Sparrow");
    mammal myMammal("Cow");
    reptile myreptile("alligator");

    myBird.egg_layer();
    myBird.make_sound();

    myreptile.egg_layer();
    myreptile.make_sound();

    myMammal.milk_producer();
    myMammal.make_sound();

    return 0;
}
