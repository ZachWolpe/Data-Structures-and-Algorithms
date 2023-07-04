#include <iostream>

using namespace std;

class Cookie {
    private:
        string colour;
    public:
        Cookie (string colour) {
            this -> colour = colour;
        }
        string getColour () {
            return colour;
        }
        void setColour (string colour) {
            this -> colour = colour;
        }
};

int main() {
    Cookie* cookieOne = new Cookie("green");
    Cookie* cookieTwo = new Cookie("blue");
    cookieOne -> setColour("yellow");
    cout << "C1: " << cookieOne -> getColour() << endl;
    cout << "C2: " << cookieTwo -> getColour() << endl;

}