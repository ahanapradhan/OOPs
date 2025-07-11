// tom_and_jerry_traps.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --- Character Base Class ---
class Character {
protected:
    string name;
    int speed;

public:
    Character(string n, int s) : name(n), speed(s) {}

    virtual void doRun() {
        cout << name << " is running at speed " << speed << endl;
    }

    string tellYourName() const { return name; }
    int tellYourSpeed() const { return speed; }
};

// --- Tom Class ---
class Cat : public Character {
public:
    Cat(int s) : Character("Tom", s) {}

    void doChase(Character& target) {
        cout << name << " is chasing " << target.tellYourName() << "!\n";
        if (speed > target.tellYourSpeed())
            cout << name << " caught " << target.tellYourtName() << "!\n";
        else
            cout << target.tellYourName() << " escaped!\n";
    }

    void placeTrap(class Trap* trap, Character& target);
};

// --- Jerry Class ---
class Mouse : public Character {
public:
    Mouse(int s) : Character("Jerry", s) {}
};

// --- Trap Base Class ---
class Trap {
public:
    virtual void activate(Character& target) = 0; // pure virtual
    virtual ~Trap() {}
};

// --- MouseTrap (derived from Trap) ---
class MouseTrap : public Trap {
public:
    void activate(Character& target) override {
        cout << "A MouseTrap snaps near " << target.tellYourName() << "!\n";
        if (target.tellYourSpeed() < 6)
            cout << target.tellYourName() << " gets caught!\n";
        else
            cout << target.tellYourName() << " dodges the trap!\n";
    }
};

// --- BananaPeel (derived from Trap) ---
class BananaPeel : public Trap {
public:
    void activate(Character& target) override {
        cout << target.tellYourName() << " slips on a Banana Peel!\n";
        cout << target.tellYourName() << "'s speed is reduced!\n";
    }
};

// Tom placing traps
void Tom::placeTrap(Trap* trap, Character& target) {
    cout << name << " places a trap for " << target.tellYourName() << "...\n";
    trap->activate(target);
}

int main() {
    Cat tom(5);
    Mouse jerry(7);

    tom.doRun();
    jerry.doRun();
    tom.doChase(jerry);

    // Create traps
    MouseTrap mt;
    BananaPeel bp;

    // Use polymorphism: base pointer -> derived objects
    vector<Trap*> traps = { &mt, &bp };

    // Tom sets traps for Jerry
    for (Trap* t : traps) {
        tom.placeTrap(t, jerry);
    }

    return 0;
}
