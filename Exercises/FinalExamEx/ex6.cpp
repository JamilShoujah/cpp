#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string sound;

public:
    Animal(string s = "Hi") : sound(s) {}

    virtual void makeSound() {
        cout << sound << endl;
    }

    string getSound() const {
        return sound;
    }

    // Operator overloading to compare two animals by sound
    bool operator==(const Animal& other) const {
        return this->sound == other.sound;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("Bark") {}

    void makeSound() override {
        cout << sound << endl;
    }
};

class Cat : public Animal {
public:
    Cat() : Animal("Meow") {}

    void makeSound() override {
        cout << sound << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    Animal* a3 = new Dog();

    a1->makeSound();  // Bark
    a2->makeSound();  // Meow
    a3->makeSound();  // Bark

    // Compare by sound
    if (*a1 == *a2)
        cout << "a1 and a2 sound the same.\n";
    else
        cout << "a1 and a2 sound different.\n";

    if (*a1 == *a3)
        cout << "a1 and a3 sound the same.\n";
    else
        cout << "a1 and a3 sound different.\n";

    delete a1;
    delete a2;
    delete a3;

    return 0;
}
