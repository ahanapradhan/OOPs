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

    virtual void run() {
        cout << name << " is running at speed " << speed << endl;
    }

    string getName() const { return name; }
    int getSpeed() const { return speed; }
};

// --- Tom Class ---
class Tom : public Character {
public:
    Tom(int s) : Character("Tom", s) {}

    void chase(Character& target) {
        cout << name << " is chasing " << target.getName() << "!\n";
        if (speed > target.getSpeed())
            cout << name << " caught " << target.getName() << "!\n";
        else
            cout << target.getName() << " escaped!\n";
    }

    void placeTrap(class Trap* trap, Character& target);
};

// --- Jerry Class ---
class Jerry : public Character {
public:
    Jerry(int s) : Character("Jerry", s) {}
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
        cout << "A MouseTrap snaps near " << target.getName() << "!\n";
        if (target.getSpeed() < 6)
            cout << target.getName() << " gets caught!\n";
        else
            cout << target.getName() << " dodges the trap!\n";
    }
};

// --- BananaPeel (derived from Trap) ---
class BananaPeel : public Trap {
public:
    void activate(Character& target) override {
        cout << target.getName() << " slips on a Banana Peel!\n";
        cout << target.getName() << "'s speed is reduced!\n";
    }
};

// Tom placing traps
void Tom::placeTrap(Trap* trap, Character& target) {
    cout << name << " places a trap for " << target.getName() << "...\n";
    trap->activate(target);
}

int main() {
    Tom tom(5);
    Jerry jerry(7);

    tom.run();
    jerry.run();
    tom.chase(jerry);

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
