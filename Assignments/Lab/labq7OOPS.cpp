#include <iostream>
using namespace std;

template <typename A>
class Rectangle {
    A length;
    A width;
public:
    Rectangle(A l, A w) : length(l), width(w) {}

    A area() {
        return length * width;
    }

    A perimeter() {
        return 2 * (length + width);
    }
};

template <typename B>
B findMax(B arr[], int size) {
    B max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Maximum in integer array: " << findMax(intArr, intSize) << endl;

    float floatArr[] = {1.7, 5.6, 2.4, 8.2, 6.34, 9.12, 0.71};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "Maximum in float array: " << findMax(floatArr, floatSize) << endl;

    char charArr[] = {'B', 'a', 'Z', 'c', 'E'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "Maximum in character array: " << findMax(charArr, charSize) << endl;

    Rectangle<int> rectInt(17, 21);
    cout << "Area of integer rectangle: " << rectInt.area() << endl;
    cout << "Perimeter of integer rectangle: " << rectInt.perimeter() << endl;

    Rectangle<float> rectFloat(19.5, 23.8);
    cout << "Area of float rectangle: " << rectFloat.area() << endl;
    cout << "Perimeter of float rectangle: " << rectFloat.perimeter() << endl;

    return 0;
}