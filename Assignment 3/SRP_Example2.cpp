#include <iostream>
#include <fstream>
using namespace std;

class RectangleCalculator {
public:
    static double calculateArea(double length, double width) {
        return length * width;
    }
};

class FileAreaWriter {
public:
    static void writeToFile(double area, const string& fileName) {
        ofstream outputFile(fileName);
        if (outputFile.is_open()) {
            outputFile << "Area: " << area;
            outputFile.close();
        } else {
            cerr << "Error writing to file: Unable to open file.\n";
        }
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

    void writeAreaToFile(const string& fileName) const {
        double area = calculateArea();
        FileAreaWriter::writeToFile(area, fileName);
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    double area = rectangle.calculateArea();
    cout << "Calculated Area: " << area << endl;

    rectangle.writeAreaToFile("area.txt");

    return 0;
}
