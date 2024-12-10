// COMSC-210 | Final Exam | Mira Anand
// Module 16 - Final Exam
// IDE used: Visual Studio Code for Mac

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
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
const int PROBABILITY = 50;
const int ROUNDS = 10;

// function prototypes
void coffeeBooth(CoffeeCustomer*&, string[], string[], int);
void muffinBooth(deque<OtherVendorCustomer>&, string[], string[], int);
void friendshipBraceletBooth(vector<OtherVendorCustomer>&, string[], string[], int);
void foodBooth(stack<OtherVendorCustomer>&, string[], string[], int);

int main()
{
    srand(time(0)); // first line in main() for randomization purposes

    // creation of data arrays from which to randomly create customer data
    string names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"}; // names
    string drinks[] = {"Latte", "Espresso", "Cappuccino", "Mocha", "Americano"}; // coffee drinks
    string muffins[] = {"Blueberry", "Chocolate Chip", "Banana Nut", "Oatmeal Raisin", "Cinnamon"}; // muffins
    string friendshipBracelets[] = {"Silver", "Gold", "Beaded", "Leather", "Charm"}; // friendship bracelets
    string foodItems[] = {"Pizza", "Burger", "Pasta", "Sushi", "Salad"}; // food items

    CoffeeCustomer* coffeeBoothQueue = nullptr; // initialization of the coffee booth queue
    deque<OtherVendorCustomer> muffinBoothQueue; // initialization of the muffin booth queue
    vector<OtherVendorCustomer> friendshipBraceletBoothQueue; // initialization of the friendship bracelet booth queue
    stack<OtherVendorCustomer> foodBoothQueue; // initialization of the food booth queue

    for (int i = 0; i < INITIAL_CUSTOMERS; i++) // initialize the queue with 3 customers
    {
        string name = names[rand() % ARRAY_SIZE]; // randomly choose a name
        string drinkOrder = drinks[rand() % ARRAY_SIZE]; // randomly choose a drink
        CoffeeCustomer* customerJoins = new CoffeeCustomer(name, drinkOrder);

        if (!coffeeBoothQueue)
        {
            coffeeBoothQueue = customerJoins;
        }
        else
        {
            CoffeeCustomer* temp = coffeeBoothQueue;
            while (temp->next)
            {
                temp = temp->next;
            }

            temp->next = customerJoins;
        }

        cout << "Initial coffee customer joining the queue: " << name << ", Drink order: " << drinkOrder << endl;

        string muffinName = names[rand() % ARRAY_SIZE];
        string muffinOrder = muffins[rand() % ARRAY_SIZE];
        muffinBoothQueue.push_back(OtherVendorCustomer(muffinName, muffinOrder));
        cout << "Initial muffin customer joining the queue: " << muffinName << ", Muffin order: " << muffinOrder << endl;

        string friendshipBraceletName = names[rand() % ARRAY_SIZE];
        string friendshipBraceletOrder = friendshipBracelets[rand() % ARRAY_SIZE];
        friendshipBraceletBoothQueue.push_back(OtherVendorCustomer(friendshipBraceletName, friendshipBraceletOrder));
        cout << "Initial friendship bracelet customer joining the queue: " << friendshipBraceletName << ", Friendship bracelet order: " << friendshipBraceletOrder << endl;

        string foodName = names[rand() % ARRAY_SIZE];
        string foodOrder = foodItems[rand() % ARRAY_SIZE];
        foodBoothQueue.push(OtherVendorCustomer(foodName, foodOrder));
        cout << "Initial food booth customer joining the queue: " << foodName << ", Food order: " << foodOrder << endl;
    }

    // run the simulation for 10 rounds
    for (int round = 1; round <= ROUNDS; round++)
    {
        cout << endl << "Round: " << round << endl;
        coffeeBooth(coffeeBoothQueue, names, drinks, ARRAY_SIZE);
        muffinBooth(muffinBoothQueue, names, muffins, ARRAY_SIZE);
        friendshipBraceletBooth(friendshipBraceletBoothQueue, names, friendshipBracelets, ARRAY_SIZE);
        foodBooth(foodBoothQueue, names, foodItems, ARRAY_SIZE);
    }

    return 0;
}

void coffeeBooth(CoffeeCustomer*& customerLine, string names[], string drinks[], int arraySize)
{
    int prob = rand() % 100 + 1;
    // 50% probability that someone will join the queue
    if (prob <= PROBABILITY)
    {
        string name = names[rand() % ARRAY_SIZE]; // randomly choose a name
        string drinkOrder = drinks[rand() % ARRAY_SIZE]; // randomly choose a drink
        CoffeeCustomer* customerJoins = new CoffeeCustomer(name, drinkOrder);

        if (!customerLine) 
        {
            customerLine = customerJoins; 
        } 
        else 
        {
            CoffeeCustomer* temp = customerLine;
            while (temp->next) 
            {
                temp = temp->next;
            }
            
            temp->next = customerJoins;
        }

        cout << "Customer joins the coffee booth queue: " << name << ", Drink order: " << drinkOrder << endl;
    }

    if (customerLine)
    {
        cout << "Serving the head customer their drink: " << customerLine->name << ", Drink order: " << customerLine->drinkOrder << endl;
        CoffeeCustomer* temp = customerLine;
        customerLine = customerLine->next;
        delete temp;
    }
    else
        cout << "The coffee queue is empty. No customer being served." << endl;
}

void muffinBooth(deque<OtherVendorCustomer>& customerLine, string names[], string muffins[], int arraySize)
{
    int prob = rand() % 100 + 1;
    if (prob <= PROBABILITY)
    {
        string name = names[rand() % ARRAY_SIZE]; 
        string muffinOrder = muffins[rand() % ARRAY_SIZE];
        customerLine.push_back(OtherVendorCustomer(name, muffinOrder));
        cout << "Customer joins the muffin booth queue: " << name << ", Muffin order: " << muffinOrder << endl;
    }

    if (!customerLine.empty())
    {
        OtherVendorCustomer customer = customerLine.front();
        customerLine.pop_front();
        cout << "Serving the head customer their muffin: " << customer.name << ", Muffin order: " << customer.order << endl;
    }
    else
    {
        cout << "The muffin queue is empty. No customer being served." << endl;
    }
}

void friendshipBraceletBooth(vector<OtherVendorCustomer>& customerLine, string names[], string bracelets[], int arraySize)
{
    int prob = rand() % 100 + 1;
    if (prob <= PROBABILITY)
    {
        string name = names[rand() % ARRAY_SIZE]; 
        string friendshipBraceletorder = bracelets[rand() % ARRAY_SIZE];
        customerLine.push_back(OtherVendorCustomer(name, friendshipBraceletorder));
        cout << "Customer joins the friendship bracelet booth queue: " << name << ", Friendship bracelet order: " << friendshipBraceletorder << endl;
    }

    if (!customerLine.empty())
    {
        OtherVendorCustomer customer = customerLine.front();
        customerLine.erase(customerLine.begin()); 
        cout << "Serving the head customer their friendship bracelet: " << customer.name << ", Friendship bracelet order: " << customer.order << endl;
    }
    else
    {
        cout << "The friendship bracelet queue is empty. No customer being served." << endl;
    }
}

void foodBooth(stack<OtherVendorCustomer>& customerLine, string names[], string foodItems[], int arraySize)
{
    int prob = rand() % 100 + 1;
    if (prob <= PROBABILITY)
    {
        string name = names[rand() % ARRAY_SIZE]; 
        string foodOrder = foodItems[rand() % ARRAY_SIZE];
        customerLine.push(OtherVendorCustomer(name, foodOrder));
        cout << "Customer joins the food booth queue: " << name << ", Food order: " << foodOrder << endl;
    }

    if (!customerLine.empty())
    {
        OtherVendorCustomer customer = customerLine.top();
        customerLine.pop();
        cout << "Serving the head customer their food: " << customer.name << ", Food order: " << customer.order << endl;
    }
    else
    {
        cout << "The food booth queue is empty. No customer being served." << endl;
    }
}