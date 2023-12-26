#include <iostream>
using namespace std;

class RectangleCalculator {
public:
    static double calculateArea(double length, double width) {
        return length * width;
    }
};

class RectanglePrinter {
public:
    static void printArea(double area) {
        std::cout << "Area: " << area << std::endl;
    }
};

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double calculateArea() const {
        return RectangleCalculator::calculateArea(length, width);
    }

    void printArea() const {
        double area = calculateArea();
        RectanglePrinter::printArea(area);
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    rectangle.printArea();

    return 0;
}
