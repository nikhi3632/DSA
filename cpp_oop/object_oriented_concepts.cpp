/* 
    g++ -o object_oriented_concepts object_oriented_concepts.cpp
    ./object_oriented_concepts

    Classes: A class is a blueprint or template for creating objects. It defines the properties 
    (data members) and behaviors (member functions) that objects of the class will have.

    Objects: An object is an instance of a class. It represents a specific occurrence of the class and 
    has its own set of data members and member functions.

    Encapsulation: Encapsulation is the process of hiding the internal details of an object and 
    providing an interface to interact with the object. It combines data and functions into a 
    single unit (class) and restricts access to the internal implementation details.

    Abstraction: Abstraction involves simplifying complex systems by providing only essential details to 
    the outside world. It focuses on the behavior of objects rather than their implementation. 
    In C++, abstraction is achieved through classes and abstract data types.

    Inheritance: Inheritance allows you to create new classes (derived classes) based on existing 
    classes (base classes). The derived classes inherit the properties and behaviors of the base class, 
    allowing code reuse and specialization. C++ supports single and multiple inheritance.

    Polymorphism: Polymorphism means the ability of objects to take on many forms. 
    It allows you to use a single interface to represent different types of objects. 
    C++ supports two types of polymorphism: compile-time (function overloading) and 
    runtime (function overriding using virtual functions).

    Overloading: Function overloading allows you to have multiple functions with the same name but 
    different parameter lists. The appropriate function is selected based on the number and 
    types of arguments provided.

    Overriding: Function overriding occurs when a derived class provides its own implementation of a 
    member function that is already defined in the base class. It allows objects of the derived class 
    to be treated as objects of the base class but with specialized behavior.

    Polymorphic (virtual) functions: Virtual functions are functions declared in the base class and 
    overridden in derived classes. They allow the correct function to be called based on the actual type 
    of the object, rather than the type of the pointer or reference used to access it. 
    Virtual functions enable runtime polymorphism.

    Data abstraction: Data abstraction involves the separation of the logical properties of an object from 
    its concrete implementation. It allows you to define abstract data types (ADTs) 
    that provide a high-level view of data and operations without exposing implementation details.

    Message passing: In OOP, objects communicate with each other by sending and receiving messages. 
    A message is a request for an object to perform a certain operation. The object that receives 
    the message determines which method to execute based on the message content.

    Access Specifiers:
    Access specifiers in C++ determine the accessibility or visibility of class members 
    (data members and member functions) from different parts of the program. 
    C++ provides three access specifiers:

    Public: Members declared as public are accessible from anywhere in the program. 
    They can be accessed by objects of the class, as well as from outside the class.

    Private: Members declared as private are only accessible within the class itself. 
    They cannot be accessed directly by objects of the class or from outside the class. 
    Private members are typically accessed through public member functions (getters and setters) or 
    friend functions.

    Protected: Members declared as protected are similar to private members but have one difference: they are 
    accessible in derived classes. Derived classes can access protected members inherited from the base class.

    Access specifiers provide encapsulation and control over the accessibility of class members, 
    allowing you to enforce data hiding and ensure proper encapsulation.

    Constructors and Destructors:
    Constructors and destructors are special member functions in a class that are responsible for 
    initializing and destroying objects, respectively.

    Constructors: Constructors are called when an object of a class is created. They have the same name 
    as the class and do not have a return type (not even void). Constructors can be overloaded to 
    provide different ways of initializing objects. They are often used to set initial values to data members 
    or allocate resources.

    Destructors: Destructors are called when an object goes out of scope or is explicitly deleted using the 
    delete keyword. They have the same name as the class preceded by a tilde (~). Destructors are mainly 
    used to release resources acquired by the object during its lifetime, such as freeing memory or closing 
    file handles.

    Aggregation and Composition:
    Aggregation and composition are two forms of relationships between classes in object-oriented programming.

    Aggregation: Aggregation represents a "has-a" relationship between classes, 
    where one class is composed of one or more instances of another class. 
    The aggregated objects can exist independently, and the relationship is typically represented by a 
    member variable in the containing class. For example, a car class may have a member variable of 
    type Engine.

    Composition: Composition is a strong form of aggregation that represents a "whole-part" 
    relationship between classes. In composition, the lifetime of the contained objects is tightly 
    coupled with the containing object. The contained objects are created and destroyed along with 
    the containing object. For example, a House class may have Room objects as its composition.

    Association is a fundamental concept in OOP and is used to model relationships between objects. 
    It allows classes to collaborate and exchange information, enabling the creation of complex systems by 
    composing simpler classes together.

    Key characteristics of association in OOP include:

    Relationship: Association represents a relationship between two or more classes. 
    It defines that objects of one class are connected to objects of another class.

    Multiplicity: Multiplicity specifies the number of objects involved in the association. 
    It can be one-to-one, one-to-many, many-to-one, or many-to-many, indicating the cardinality 
    of the association.

    Directionality: Association can be unidirectional or bidirectional. In a unidirectional association, 
    objects of one class are aware of the other class, but not vice versa. In a bidirectional association, 
    objects of both classes are aware of each other.

    Navigation: Navigation refers to the ability to traverse an association from one object to another. 
    It allows accessing the associated objects and invoking their methods.

    Association Role: Each class involved in the association plays a role, which represents its 
    participation in the relationship. The role describes the purpose or responsibility of the class 
    in the context of the association.

    Dependency: Associations can create dependencies between classes. Changes in one class may affect 
    the behavior or state of the other class, leading to a dependency between them.

    Associations can be represented in UML (Unified Modeling Language) diagrams using various notations, 
    such as solid lines with arrows, multiplicity indicators, and role names.

    Dynamic dispatch, also known as dynamic binding or late binding, is a mechanism in 
    object-oriented programming (OOP) that allows the selection of the appropriate function implementation 
    at runtime based on the actual object type rather than the declared type. It enables polymorphism and 
    is a fundamental concept in OOP languages.

    In OOP, objects are instances of classes, and classes can have hierarchies through inheritance. 
    Dynamic dispatch is primarily associated with polymorphism, where objects of different classes 
    can be treated as objects of a common base class. It allows the code to be written in a more generic
     and flexible way, without being aware of the specific subclass types.

    Here's how dynamic dispatch works:

    Inheritance and Overriding: In a class hierarchy, a derived class can override a method from 
    its base class. When a method is declared as "virtual" in the base class and overridden in a 
    derived class, it indicates that the method's implementation can vary based on the actual object type.

    Virtual Function Table (VTable): To support dynamic dispatch, most OOP languages use a mechanism 
    called the virtual function table or VTable. It is a data structure associated with each class that 
    contains pointers to its virtual functions.

    Object Pointers and References: When a derived class object is accessed through a pointer or reference 
    to the base class, dynamic dispatch comes into play. The compiler treats the pointer or reference as 
    the base class type but keeps track of the actual object type at runtime.

    Runtime Polymorphism: When a virtual function is called through a base class pointer or reference, 
    dynamic dispatch determines which implementation of the function to invoke based on the actual object type. 
    It looks up the appropriate function pointer in the VTable associated with the object's class and 
    calls the corresponding implementation.

    By using dynamic dispatch, the correct implementation of a virtual function is selected at runtime, 
    allowing objects of different classes to respond appropriately to the same method invocation. 
    This enables polymorphism and facilitates code reuse, as a common interface can be defined in the 
    base class, and derived classes can provide specialized implementations.

    Dynamic dispatch is crucial for achieving the Open-Closed Principle (OCP) in OOP, which states 
    that classes should be open for extension but closed for modification. It allows new classes to be 
    added to the system without modifying existing code, as long as they conform to the common interface
    defined by the base class.

    Overall, dynamic dispatch is a key mechanism in OOP that enables 
    runtime polymorphism, flexibility, and extensibility in object-oriented systems. 
    It allows objects to be treated generically, while their specific behaviors are determined based on 
    their actual types at runtime.
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
    // Virtual function for overriding
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }

    virtual ~Animal() {
        std::cout << "Animal destructor called for " << name << "." << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    Dog(const std::string& _name) : Animal(_name) {}

    // Overriding the base class's makeSound() function
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

     // Overloading the walkDog() function
    void walkDog() {
        std::cout << name << " is walking his dog " << dog.getName() << "." << std::endl;
        dog.makeSound();
    }

    // Overloading the walkDog() function with a const-qualified version
    void walkDog() const {
        std::cout << name << " is taking a stroll with " << dog.getName() << "." << std::endl;
    }

    // Destructor
    ~Person() {
        std::cout << "Person destructor called for " << name << std::endl;
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

    const Person constPerson("Alice", dog1);
    // Invoking the const version of walkDog()
    constPerson.walkDog();

    delete dog2;
    return 0;

    /* 
        Classes:
        Animal: Base abstract class representing an animal. 
        It has a protected member variable name and a pure virtual function makeSound().
        Dog: Derived class from Animal. It has a constructor, a member function makeSound(), 
        a member function getName(), and a destructor.
        Person: Class representing a person. It has a private member variable name, a composition 
        relationshipwith Dog through a private member variable dog, a constructor, and two member functions 
        introduce() and walkDog().
        Zoo: Class representing a zoo. It has a private member variable animals, which is a vector of pointers
        to const Animal, demonstrating aggregation. It has member functions to add animals to the collection 
        and make sounds of all animals.

        Objects:
        dog1: An object of the Dog class representing a dog named "Buddy".
        person: An object of the Person class representing a person named "John" with a 
        dog object dog1 as a member.
        zoo: An object of the Zoo class representing a zoo. It contains a collection of animal objects.

        Inheritance: 
        The Dog class inherits from the Animal class using the 
        public "access specifier". This relationship is established through the line class Dog : public Animal.

        Encapsulation: 
        Encapsulation is the mechanism of bundling data and methods that operate on that 
        data within a class, hiding the internal implementation details and providing controlled access to 
        the data. In the given code, encapsulation is achieved as follows:
        The member variables name in the Animal class and dog in the Person class are declared as protected 
        access specifiers. This means that they are accessible within the class and its derived classes but not 
        from outside the class, promoting encapsulation by encapsulating the data within the class hierarchy.
        The member variables name in the Animal class and Person class are not directly accessible from the 
        main function or any other external code. Instead, access to these member variables is provided 
        through appropriate member functions (getName() in the Dog class) and member functions 
        (introduce() and walkDog()) in the Person class. This encapsulation ensures that the internal data is 
        accessed and modified in a controlled manner, preserving data integrity and providing a level of abstraction.

        Abstraction: 
        Abstraction is the process of hiding the complex implementation details and exposing only
        the essential features or behavior to the outside world. In the given code, abstraction is achieved 
        through the use of an abstract base class:
        The Animal class is an abstract base class that defines a pure virtual function makeSound(). 
        By having a pure virtual function, the Animal class becomes an abstract class, which means it cannot 
        be instantiated directly. It serves as a blueprint or interface for deriving concrete animal classes, 
        such as the Dog class.
        The Animal class provides an abstraction for different types of animals by declaring the makeSound() 
        function as a pure virtual function. This abstracts the behavior of making a sound, allowing derived 
        classes to provide their own implementation. This way, the client code can interact with different 
        animal objects using a common interface without worrying about the specific details of each animal's 
        sound.

        The virtual functions play a crucial role in achieving polymorphism and dynamic dispatch, 
        which are essential concepts in object-oriented programming.

        Polymorphism: 
        Polymorphism allows objects of different classes to be treated as objects of a 
        common base class, enabling code reuse and flexibility. In the code, the Animal class has a 
        pure virtual function makeSound(), which makes it an abstract base class. The Dog class derives 
        from Animal and overrides the makeSound() function. By marking the makeSound() function as virtual 
        in the base class and providing an implementation in the derived class, we achieve polymorphism. 
        This allows objects of Dog to be treated as objects of Animal, providing a uniform interface 
        for different types of animals.

        Dynamic Dispatch: 
        Dynamic dispatch enables the selection of the appropriate function implementation 
        at runtime based on the actual object type rather than the declared type. In the code, the 
        makeSound() function is declared as virtual in the Animal class and overridden in the Dog class. 
        When a derived class object is accessed through a pointer or reference to the base class 
        (e.g., Animal* animal = &dog2;), dynamic dispatch ensures that the correct implementation of the 
        virtual function is called based on the actual object type. This allows for runtime polymorphism, where 
        the appropriate makeSound() function of the specific animal type (e.g., Dog in this case) is invoked.

        Data Abstraction:
        In the given example, data abstraction is achieved through the use of classes and member functions. 
        The Animal class acts as an abstract base class that provides a blueprint for deriving 
        concrete animal classes. It contains a pure virtual function makeSound(), which defines 
        an abstract behavior without providing an implementation. This abstracts the concept of 
        making a sound for different types of animals.  By making makeSound() a pure virtual function, 
        the Animal class becomes an abstract class, which cannot be instantiated directly. 
        It serves as an abstraction that defines a common interface for all animal objects, 
        hiding the specific implementation details of each animal's sound. This allows client code to 
        interact with different animal objects using a common interface, without needing to know the 
        specific details of each animal class.

        Message Passing:
        Message passing is a way of communication between objects in which objects communicate by 
        sending messages to each other. In the given code, message passing is demonstrated through the 
        interaction between objects. For example, when person.walkDog() is called, the walkDog() 
        member function of the Person class is invoked. Inside this function, a message is passed 
        to the dog object (which is a member of the Person class) by calling dog.makeSound(). This message 
        triggers the makeSound() function of the Dog class, causing the dog to make a sound specific to 
        it's type. Similarly, the Zoo class demonstrates message passing when the makeAnimalSounds() member 
        function is called. This function sends a message to each Animal object in the animals vector by 
        calling their makeSound() function. The specific implementation of makeSound() in each derived class 
        is invoked based on the actual object type at runtime, achieving dynamic dispatch. In both cases, the 
        message passing mechanism allows objects to interact with each other and trigger specific behaviors 
        based on the type of the receiving object, promoting encapsulation and polymorphism in the code.

        Composition: 
        Composition represents a "has-a" relationship, where a class contains objects of other
        classes as member variables, and the lifetime of the contained objects is tightly coupled with the 
        containing object. In the code, the Person class demonstrates composition with the Dog class.
        Inside the Person class, there is a member variable dog of type Dog. This means that a Person object 
        has a Dog object as a part of its state. The Dog object is created and destroyed along with the 
        Person object. The Dog object is initialized in the Person constructor using the provided Dog object 
        as an argument. This demonstrates composition, where the Person class composes a Dog object.

        Aggregation: 
        Aggregation represents a "has-a" relationship as well, where a class contains objects of 
        other classes as member variables, but the lifetime of the contained objects is independent of the 
        containing object. In the code, the Zoo class demonstrates aggregation with the Animal class.
        Inside the Zoo class, there is a vector animals of type const Animal*. This vector holds pointers to 
        Animal objects, but the Zoo class doesn't have ownership or responsibility for creating or destroying 
        those Animal objects. It is an aggregation because the Zoo class holds a collection of Animal objects,
        but the lifetime of the Animal objects is managed externally.

        Association: 
        Association is a relationship between two classes where an object of one class is 
        related to objects of another class. It represents a "has-a" relationship.
        There is an example of association between the Person class and the Dog class. 
        In the Person class, there is a private member variable dog of type const Dog&, 
        which represents a reference to a Dog object. This member variable establishes an association 
        between the Person class and the Dog class. It means that a Person object has a Dog object as 
        part of its state. In the Person constructor, a Dog object is passed as an argument and assigned 
        to the dog member variable, establishing the association between a Person and a Dog.
        This association allows a Person object to interact with the associated Dog object through member 
        functions like walkDog() or dog.getName(). The Person class can access and use the functionality 
        provided by the Dog class through the associated Dog object. It's important to note that in this case,
        the association is implemented using a reference (const Dog&) rather than object composition. 
        This means that the Person class does not own or manage the lifetime of the Dog object. 
        The responsibility for creating and destroying the Dog object lies outside the Person class.

        The Dog objects dog1 and dog2 are regular objects with automatic storage duration. 
        When the program execution reaches the end of the main function, the destructors for 
        dog1 and dog2 are automatically invoked in reverse order of their creation.
        Since the Dog class inherits from the Animal class, 
        the Dog destructor is called first, and then the Animal destructor is 
        automatically invoked as part of the destruction process.

        The destructor ~Person() is added to the Person class. Inside the destructor, you can include any 
        cleanup or release logic specific to the Person class. It simply outputs a message indicating that 
        the destructor is called for a particular Person object.
        The Person class in the provided code does not required a destructor explicitly defined.
        It's important to note that in this case, since the Person class does not own the Dog object and 
        is not responsible for its destruction, there is no need to explicitly handle the destruction 
        of the Dog object within the Person destructor. The destruction of the Dog object will be 
        automatically handled by the destructor of the Dog class or by the code that created the Dog object.
        A destructor is typically necessary when a class manages resources that need to be explicitly 
        released or cleaned up when an object of that class is destroyed. For example, if the Person class 
        had dynamically allocated memory or owned resources that need to be released a destructor would be 
        required to handle the cleanup. The Person class does not own any resources that require explicit 
        cleanup. It has a composition relationship with a Dog object, but the responsibility for managing the 
        Dog object's memory lies outside the Person class. The Dog object is either passed as a 
        reference or created as a local object in the main() function, and its destruction is automatically 
        handled when it goes out of scope or when explicitly deleted. Since the Person class does not 
        require any additional cleanup beyond what is automatically handled for it's member variables, it 
        does not need a destructor. The compiler-generated default destructor will be sufficient in this case.
        Similarly, the Zoo class does not require a destructor to be explicitly defined. The reason is that 
        the Zoo class does not have any member variables that require explicit cleanup or deallocation.
        The Zoo class contains a vector of pointers to const Animal objects (std::vector<const Animal*> animals),
        but it does not own or manage the lifetime of these objects. It is assumed that the responsibility 
        for creating and destroying the Animal objects lies outside the Zoo class. When the Zoo object goes 
        out of scope or is explicitly deleted, the vector animals will be automatically destroyed, and the 
        destructors of the Animal objects, if any, will be called. The destruction of the Animal objects 
        should be handled by the code that created those objects, and it is not the responsibility of the 
        Zoo class. Therefore, in this case, it is not necessary to provide a destructor explicitly for the 
        Zoo class. The compiler-generated default destructor will be sufficient to handle the destruction of 
        the Zoo object and its member variables.

        Other concepts like overriding, overloading and access specifiers are also incorporated.
    */
}
