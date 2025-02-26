#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    std::string productName;
    int productID;
    double pricePerUnit;
    int availableStock;
    std::string supplierName;

public:
    // Constructor to initialize the product object
    Product(std::string name, int id, double price, int stock, string supplier) 
        : productName(name), productID(id), pricePerUnit(price), availableStock(stock), supplierName(supplier) {}

    // Method to display product details
    void displayProductDetails() const {
        cout << "Product ID: " << productID << "\n";
        cout << "Product Name: " << productName << "\n";
        cout << "Price per Unit: $" << pricePerUnit << "\n";
        cout << "Available Stock: " << availableStock << "\n";
        cout << "Supplier: " << supplierName << "\n\n";
    }

    // Method to get the total value of the product stock
    double getTotalValue() const {
        return pricePerUnit * availableStock;
    }

    // Method to check if the stock is low
    bool isStockLow() const {
        return availableStock < 10;
    }

    // Method to get the product name
    string getProductName() const {
        return productName;
    }
};

// Function to calculate the total inventory value
double calculateTotalInventoryValue(const vector<Product> &inventory) {
    double totalValue = 0;
    for (const Product &product : inventory) {
        totalValue += product.getTotalValue();
    }
    return totalValue;
}

// Function to display products that need restocking
void displayLowStockProducts(const vector<Product> &inventory) {
    cout << "\nProducts that need restocking:\n";
    bool found = false;
    for (const Product &product : inventory) {
        if (product.isStockLow()) {
            cout << product.getProductName() << " (Stock: " << product.getTotalValue() / product.getTotalValue() << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "All products have sufficient stock.\n";
    }
}

int main() {
    vector<Product> inventory;
    int numProducts;

    // Taking input for the number of products
    cout << "Enter the number of products: ";
    cin >> numProducts;

    // Taking input for each product
    for (int i = 0; i < numProducts; ++i) {
        string name, supplier;
        int id, stock;
        double price;

        cout << "Enter details for product " << i + 1 << ":\n";
        cout << "Product Name: ";
        cin >> ws; // to consume any leading whitespace
        getline(cin, name);
        cout << "Product ID: ";
        cin >> id;
        cout << "Price per Unit: ";
        cin >> price;
        cout << "Available Stock: ";
        cin >> stock;
        cout << "Supplier Name: ";
        cin >> ws; // to consume any leading whitespace
        getline(cin, supplier);

        // Adding the product to the inventory
        inventory.emplace_back(name, id, price, stock, supplier);
    }

    // Displaying product details
    cout << "Product Details:\n";
    for (const Product &product : inventory) {
        product.displayProductDetails();
    }

    // Calculating and displaying the total inventory value
    cout << "Total Inventory Value: $" << calculateTotalInventoryValue(inventory) << "\n";

    // Displaying products that need restocking
    displayLowStockProducts(inventory);

    return 0;
}
