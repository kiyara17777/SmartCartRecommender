#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Global vectors for products and prices
vector<string> products;
vector<int> prices;

// ---------------------------
// USER LOGIN & REGISTRATION
// ---------------------------
bool login(string username, string password) {
    ifstream file("data/users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password)
            return true;
    }
    return false;
}

void registerUser(string username, string password) {
    ofstream file("data/users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "User registered successfully!\n";
}

// ---------------------------
// LOAD PRODUCTS & PRICES
// ---------------------------
void loadProducts() {
    ifstream prodFile("data/products.txt");
    ifstream priceFile("data/prices.txt");
    string name;
    int price;

    while (getline(prodFile, name)) {
        products.push_back(name);
    }
    while (priceFile >> price) {
        prices.push_back(price);
    }
}

// ---------------------------
// DISPLAY PRODUCTS
// ---------------------------
void showProducts() {
    cout << "\n--- Available Products ---\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i] << " - ₹" << prices[i] << endl;
    }
}

// ---------------------------
// ADD TO CART
// ---------------------------
void addToCart() {
    int choice;
    ofstream cartFile("data/cart.txt", ios::app);

    while (true) {
        showProducts();
        cout << "Enter product number to add to cart (0 to finish): ";
        cin >> choice;

        if (choice == 0) break;

        if (choice > 0 && choice <= products.size()) {
            cartFile << products[choice - 1] << " " << prices[choice - 1] << endl;
            cout << products[choice - 1] << " added to cart!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// ---------------------------
// VIEW CART CONTENTS
// ---------------------------
void viewCart() {
    ifstream cartFile("data/cart.txt");
    string name;
    int price, total = 0;

    cout << "\n--- Your Cart ---\n";
    while (cartFile >> name >> price) {
        cout << name << " - ₹" << price << endl;
        total += price;
    }

    cout << "------------------\n";
    cout << "Total Price: ₹" << total << endl;
}

// ---------------------------
// RECOMMENDATION SYSTEM
// ---------------------------
void showRecommendations() {
    ifstream cartFile("data/cart.txt");
    ifstream rulesFile("data/rules.txt");

    vector<string> cartItems;
    string item, ruleLine;

    // Read items from cart
    while (cartFile >> item) {
        string price;
        cartFile >> price; // skip price
        cartItems.push_back(item);
    }

    cout << "\n--- Recommended for You ---\n";

    // Read rules and match
    while (getline(rulesFile, ruleLine)) {
        size_t pos = ruleLine.find("=>");
        if (pos != string::npos) {
            string trigger = ruleLine.substr(0, pos - 1);
            string recommend = ruleLine.substr(pos + 3);

            for (string cartItem : cartItems) {
                if (cartItem == trigger) {
                    cout << "- " << recommend << " (because you bought " << trigger << ")\n";
                }
            }
        }
    }
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int choice;
    string username, password;

    cout << "===============================\n";
    cout << " Welcome to SmartCart System!\n";
    cout << "===============================\n";
    cout << "1. Login\n2. Register\nEnter your choice: ";
    cin >> choice;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (choice == 1) {
        if (login(username, password)) {
            cout << "Login successful!\n";
            loadProducts();

            int action;
            do {
                cout << "\nWhat would you like to do?\n";
                cout << "1. Show Products\n";
                cout << "2. Add to Cart\n";
                cout << "3. View Cart & Get Recommendations\n";
                cout << "0. Exit\n";
                cout << "Enter choice: ";
                cin >> action;

                switch (action) {
                    case 1: showProducts(); break;
                    case 2: addToCart(); break;
                    case 3: 
                        viewCart();
                        showRecommendations();
                        break;
                    case 0: cout << "Thank you for shopping!\n"; break;
                    default: cout << "Invalid option.\n"; break;
                }
            } while (action != 0);
        } else {
            cout << "Login failed. Try again.\n";
        }
    } else if (choice == 2) {
        registerUser(username, password);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}