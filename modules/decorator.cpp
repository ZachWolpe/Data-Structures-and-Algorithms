

#include <iostream>

/**
 * The base Compenent interface defines operations that can be altered by decorators.
*/
class Component {
    public:
        virtual ~Component() {}
        virtual std::string Operation() const = 0;
};


/**
 * Concrete Components provide default implementations of the operations.
 * There might be serveral variations of these classes.
*/


class ConcreteComponent: public Component {
    public:
        std::string Operation() const override {
            // the `override` keyword is optional, but it's a good practice to use it. 
            // It will make the compiler check if the base class actually has a method with the same signature.
            return "ConcreteComponent";
        }
};
/**
 * The base Decorator class follows the same interface as the other components.
 * The primary purpose of this class is to define the wrapping interface for all
 * concrete decorators. The default implementation of the wrapping code might include
 * a field for storing a wrapped component and the means to initialize it.
*/


class Decorator: public Component {
    /**
     * @var Component
    */
   protected:
    Component* component_;
   public:
    Decorator(Component* component): component_(component) {}
    /**
         * The Decorator delegates all work to the wrapped component.
    */
    std::string Operation() const override {
        return this->component_->Operation();
    };
};
/**
 * Concrete Decorators call the wrapped object and alter its result in some way.
*/
class Concrete_Decorator_A: public Decorator {
    /**
     * Decorators may call parent implementation of the operation, instead of calling the wrapped object directly.
     * This approach simplifies extension of decorator classes.
    */
};




int Fucntion(int a, int b) {
 int result = a * b;
 std::cout << result << std::endl;

};

// declaration vs definition
// declaration: tells the compiler about the existence of a function
// definition: provides the actual body of the function


// Header files  vs Compilation units
// Header files: contain declarations of functions, classes, and other entities




// update the memory address directly

void Increment(int* value) {
    (*value)++; // dereference the pointer
    // oder of operations: ++ has higher precedence than *
}

// pass by reference(aka pass by pointer)
void Increment(int& value) {
    value++;
}
int main() {
    int a = 5;
    Increment(&a);

}

class Player {
    public:
        int x, y;
        int speed;

};

