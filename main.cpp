// COMSC-210 | Final Exam | Mira Anand
// Module 16 - Final Exam
// IDE used: Visual Studio Code for Mac

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// creation of a struct (for linked list)
struct CoffeeCustomer
{
    string name; // to hold the customer's name
    string drinkOrder; // to hold the customer's drink order
    CoffeeCustomer* next; // pointer to next node (customer)

    // constructor
    CoffeeCustomer(string n, string d)
    {
        name = n;
        drinkOrder = d;
        next = nullptr;
    }
};

// creation of a struct (for non-linked-list data structures)
struct OtherVendorCustomer
{
    string name;
    string order;

    // constructor
    OtherVendorCustomer(string n, string o)
    {
        name = n;
        order = o;
    }
};

// global const variables

// function prototypes

int main()
{
    srand(time(0)); // first line in main() for randomization purposes

    // creation of data arrays with names and drink orders from which to randomly create customer data
    string names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    string drinks[] = {"Latte", "Espresso", "Cappuccino", "Mocha", "Americano"};

    return 0;
}