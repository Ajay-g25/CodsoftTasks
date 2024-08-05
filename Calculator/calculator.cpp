#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

void printAsciiArt() {

std::cout<< "     ## ##     ##     ####      ## ##   ##  ###  ####       ##     #######   ## ##   ######  \n ";
std::cout<< "    ##   ##   ####     ##      ##   ##  ##   ##   ##       ####    #######  ##   ##   ##  ## \n "; 
std::cout<< "    ##        ## ##    ##      ##       ##   ##   ##       ## ##     ##     ##   ##   ##  ## \n ";
std::cout<< "    ##        ##  ##   ##      ##       ##   ##   ##       ##  ##    ##     ##   ##   ## ##  \n ";
std::cout<< "    ##        ## ###   ##      ##       ##   ##   ##       ## ###    ##     ##   ##   ## ##  \n ";
std::cout<< "    ##   ##   ##  ##   ##  ##  ##   ##  ##   ##   ##  ##   ##  ##    ##     ##   ##   ##  ## \n ";
std::cout<< "     ## ##   ###  ##  ### ###   ## ##    ## ##   ### ###  ###  ##   ####     ## ##   #### ## \n ";

}


// Function to perform addition
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to perform subtraction
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to perform multiplication
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to perform division
double divide(double num1, double num2) {
    if (num2 == 0) {
        throw runtime_error("Cannot divide by zero!");
    }
    return num1 / num2;
}

int main() {
    double op1, op2;
    char operation;

    printAsciiArt();        
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    
    // Get user input for operands
    cout << "Enter Operand 1: ";
    cin >> op1;
    cout << "Enter Operand 2: ";
    cin >> op2;

    // Get user input for operation
    cout<< "Enter only the operator \n";
    cout << "Choose an operation from : \n + (Addition) \n - (Subtraction) \n * (Multiplication) \n / (Division) \n ";
    cout << "Enter the operation you want to perform on the operands: ";
    cin >> operation;

    std::cout << "\n";


    //perform calculation using switch statement
    try {
        switch (operation) {
            case '+':
                cout << "Result: " << add(op1, op2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(op1, op2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(op1, op2) << endl;
                break;
            case '/':
                cout << "Result: " << divide(op1, op2) << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
        }
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}