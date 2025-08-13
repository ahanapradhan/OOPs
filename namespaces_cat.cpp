#include <iostream>

// Namespace for wild cats
namespace WildCats {
    class Cat {
        std::string species;
    public:
        Cat(const std::string& s) : species(s) {}
        void speak() const {
            std::cout << species << " says: ROAR!" << std::endl;
        }
    };
}

// Namespace for domestic cats
namespace DomesticCats {
    class Cat {
        std::string name;
    public:
        Cat(const std::string& n) : name(n) {}
        void speak() const {
            std::cout << name << " says: Meow!" << std::endl;
        }
    };

    namespace Persian {
        class Cat {
        public:
            void info() const {
                std::cout << "I am a fluffy Persian cat." << std::endl;
            }
        };
    }
}



int main() {
    // Fully qualified names
    DomesticCats::Cat tom("Tom");
    tom.speak();

    WildCats::Cat lion("Lion");
    lion.speak();

    // Nested namespace class
    DomesticCats::Persian::Cat persian;
    persian.info();

    // Using a namespace for shorter syntax
    using namespace WildCats;
    Cat tiger("Tiger");
    tiger.speak();
}
