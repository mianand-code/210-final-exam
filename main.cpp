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

// creation of another struct with no pointer (for non-linked-list data structures)
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
const int ARRAY_SIZE = 5;
const int INITIAL_CUSTOMERS = 3;

// function prototypes
void createCoffeeCustomer(CoffeeCustomer*&, string[], string[], int);

int main()
{
    srand(time(0)); // first line in main() for randomization purposes

    // creation of data arrays with names and drink orders from which to randomly create customer data
    string names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    string drinks[] = {"Latte", "Espresso", "Cappuccino", "Mocha", "Americano"};

    CoffeeCustomer* coffeeBoothQueue = nullptr; // initialization of the coffee booth queue

    for (int i = 0; i < INITIAL_CUSTOMERS; i++) // initialize the queue with 3 customers
    {
        string name = names[rand() % ARRAY_SIZE]; // randomly choose a name
        string drinkOrder = drinks[rand() % ARRAY_SIZE]; // randomly choose a drink

    }

    return 0;
}

void createCoffeeCustomer(CoffeeCustomer*& head, string names[], string drinks[], int arraySize)
{
    int prob = rand() % 100 + 1;
    if (prob <=)
}