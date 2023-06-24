/* 
    g++ -o object_oriented_concepts object_oriented_concepts.cpp
    ./object_oriented_concepts 
*/


#include <iostream>
#include <vector>

// Base class
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& _name) : name(_name) {}

    // Pure virtual function for abstraction
    virtual void makeSound() const = 0;

    virtual ~Animal() {
        std::cout << "Animal destructor called for " << name << "." << std::endl;
    }
};

// Derived class
class Dog : public Animal {
    /*
        Inheritance Relationship: The Dog class inherits from the Animal class using the 
        public access specifier. This relationship is established through the line class Dog : public Animal.
    */
public:
    Dog(const std::string& _name) : Animal(_name) {}

    // Implementation of the pure virtual function
    void makeSound() const override {
        std::cout << "Dog " << name << " says woof!" << std::endl;
    }

    // Getter function to retrieve the dog's name
    std::string getName() const {
        return name;
    }

    // Destructor
    ~Dog() {
        std::cout << "Dog destructor called for " << getName() << std::endl;
    }
};

// Composition
class Person {
private:
    std::string name;
    const Dog& dog;

public:
    // Constructor with composition
    Person(const std::string& _name, const Dog& _dog) : name(_name), dog(_dog) {}

    // Public member functions for interaction
    void introduce() const {
        std::cout << "Hello, my name is " << name << "." << std::endl;
    }

    void walkDog() const {
        std::cout << name << " is walking his dog " << dog.getName() << "." << std::endl;
        dog.makeSound();
    }
};

// Aggregation
class Zoo {
private:
    std::vector<const Animal*> animals;

public:
    // Add animal to the collection
    void addAnimal(const Animal* animal) {
        animals.push_back(animal);
    }

    // Make sounds of all animals
    void makeAnimalSounds() const {
        for (const Animal* animal : animals) {
            animal->makeSound();
        }
    }
};

int main() {
    
    Dog dog1("Buddy");
    Person person("John", dog1);

    person.introduce();

    person.walkDog();

    Dog* dog2 = new Dog("Max");
    Animal* animal = dog2;

    Zoo zoo;
    zoo.addAnimal(animal);

    zoo.makeAnimalSounds();

    delete dog2;

    return 0;

    /* 
        Encapsulation: Data members are encapsulated within 
        classes using access specifiers (protected and private).
        Abstraction: The Animal class with a pure virtual function 
        provides an abstraction for different types of animals.
        The Dog objects dog1 and dog2 are regular objects with automatic storage duration. 
        When the program execution reaches the end of the main function, the destructors for 
        dog1 and dog2 are automatically invoked in reverse order of their creation.
        Since the Dog class inherits from the Animal class, 
        the Dog destructor is called first, and then the Animal destructor is 
        automatically invoked as part of the destruction process.
        The virtual functions play a crucial role in achieving polymorphism and dynamic dispatch, 
        which are essential concepts in object-oriented programming.
        Polymorphism: Polymorphism allows objects of different classes to be treated as objects of a 
        common base class, enabling code reuse and flexibility. In the code, the Animal class has a 
        pure virtual function makeSound(), which makes it an abstract base class. The Dog class derives 
        from Animal and overrides the makeSound() function. By marking the makeSound() function as virtual 
        in the base class and providing an implementation in the derived class, we achieve polymorphism. 
        This allows objects of Dog to be treated as objects of Animal, providing a uniform interface 
        for different types of animals.
        Dynamic Dispatch: Dynamic dispatch enables the selection of the appropriate function implementation 
        at runtime based on the actual object type rather than the declared type. In the code, the 
        makeSound() function is declared as virtual in the Animal class and overridden in the Dog class. 
        When a derived class object is accessed through a pointer or reference to the base class 
        (e.g., Animal* animal = &dog2;), dynamic dispatch ensures that the correct implementation of the 
        virtual function is called based on the actual object type. This allows for runtime polymorphism, where 
        the appropriate makeSound() function of the specific animal type (e.g., Dog in this case) is invoked.
    */
}
