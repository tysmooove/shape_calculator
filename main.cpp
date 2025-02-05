/* Name: Tyler Hawkins
Date: 01/28/25
Assignment: Assignment #2
Due Date: 02/04/2025
About this project: a C++ program that calculates the area and perimeter of different geometric shapes.
Assumptions: user always enter positive, non zero numerical values, assumes the user only enter single characters */
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout, std::cin, std::setprecision, std::fixed;

int main() {
    const double PI {3.14159265359};
    char letter;
    double radius, length, width, side1, side2, side3, semiperimeter, area;


    cout << "Choose a shape: \n";
    cout << "C  - Circle \n";
    cout << "T  - Triangle \n";
    cout << "R  - Rectangle \n";



    cin >> letter;

    if (letter == 'C' || letter == 'c'){
        cout << "Radius: \n";
        cin >> radius;
        cout << "PERIMITER: " << fixed << setprecision(1) << 2 * PI * radius << "\n";
        cout << "AREA: " << fixed << setprecision(1) << PI * pow(radius,2) << "\n";}

    else if (letter == 'R' || letter == 'r') {
        cout << "Length: \n";
        cin >> length;
        cout << "Width: \n";
        cin >> width;
        cout << "PERIMETER: " << fixed << setprecision(1) << 2 * (length + width) << "\n";
        cout << "AREA: " << fixed << setprecision(1) << length * width << "\n";}

    else if (letter == 'T' || letter == 't') {
        // Getting the side lengths
        cout << "Enter the length of the biggest side: \n";
        cin >> side1;
        cout << "Enter the length of the two smaller sides: \n";
        cin >> side2 >> side3;

        // if statement to check the biggest side is larger than both smaller sides
        if (side1 <= side2 || side1 <= side3) {
            cout << "Invalid entries, make sure you enter the biggest side value first. \n";
            return 0; // Exit if not correct
        }

        // if statement to check the to see if the sides form a valid triangle
        if (side2 + side3 <= side1) {
            cout << "It is impossible for the side lengths of " << fixed << setprecision(1) << side2 << " " << fixed << setprecision(1) << side3 << " and " << fixed << setprecision(1) << side1 << " to form the sides of a triangle. \n" ;
            return 0; // Exit if the sides can't form a valid triangle
        }

        // calculate area and perimeter
        semiperimeter = (side1 + side2 + side3) / 2;
        area = sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));

        // cout perimeter and area
        cout << "PERIMETER: " << fixed << setprecision(1) << side1 + side2 + side3 << "\n";
        cout << "AREA: " << fixed << setprecision(1) << area << "\n";
    }

    // else statement to exit program if character entered is invalid
        else { cout << "Invalid menu choice. Exiting program. \n";
        return 0;
        }
    }
