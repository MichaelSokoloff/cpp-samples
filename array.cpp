#include <iostream>
#include <cstdlib>
#include <ctime>

class Figure {
public:
    virtual void draw() const = 0;
    virtual ~Figure() {}
};

class Circle : public Figure {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Figure {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

class Triangle : public Figure {
public:
    void draw() const override {
        std::cout << "Drawing a triangle." << std::endl;
    }
};

int main() {
    srand(time(nullptr));

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    Figure** figures = new Figure*[n];

    for (int i = 0; i < n; ++i) {
        int randNum = rand() % 3;

        if (randNum == 0) {
            figures[i] = new Circle();
        } else if (randNum == 1) {
            figures[i] = new Square();
        } else {
            figures[i] = new Triangle();
        }
    }

    for (int i = 0; i < n; ++i) {
        figures[i]->draw();
    }

    for (int i = 0; i < n; ++i) {
        delete figures[i];
    }
    delete[] figures;

    return 0;
}
