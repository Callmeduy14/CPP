#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int N = 4;
    Animal* zoo[N];

    for (int i = 0; i < N; ++i) {
        if (i < N/2) zoo[i] = new Dog();
        else         zoo[i] = new Cat();
    }

    // Deep copy test
    Dog a;
    a.setIdea(0, "Chase the ball");
    Dog b = a; // copy-ctor
    a.setIdea(0, "Sleep");
    std::cout << "Dog a idea0 = " << a.getIdea(0) << std::endl;
    std::cout << "Dog b idea0 = " << b.getIdea(0) << std::endl; // should still be "Chase the ball"

    for (int i = 0; i < N; ++i) {
        delete zoo[i];
    }
    return 0;
}
