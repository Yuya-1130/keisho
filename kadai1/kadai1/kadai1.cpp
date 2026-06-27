
#include <iostream>
class Animal {
public:
   virtual void call() {
        std::cout << "鳴き声" << std::endl;
    }

};
class Dog : public Animal {

public:

    void call() override {
        std::cout << "ワン" << std::endl;
    }
};

class Cat : public Animal {

public:

    void call() override {
        std::cout << "にゃん" << std::endl;
    }
};

int main()
{
    Animal* animals[] = {new Dog,new Cat};

    for (int i = 0; i < 2; ++i) {
        animals[i]->call();
    }
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
        animals[i] = nullptr;
    }

}
