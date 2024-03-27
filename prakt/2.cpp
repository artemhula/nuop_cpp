#include <iostream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    int quantity;
    int year;
    bool available;

public:
    Book(const std::string& _author, const std::string& _title, int _quantity, int _year, bool _available)
            : author(_author), title(_title), quantity(_quantity), year(_year), available(_available) {}

    bool isAvailable() const {
        return available && quantity > 0;
    }

    void issueBook() {
        if (isAvailable()) {
            --quantity;
            if (quantity == 0) {
                available = false;
            }
        } else {
            std::cout << "Book is not available.\n";
        }
    }

    void increaseQuantity(int amount) {
        quantity += amount;
        if (quantity > 0) {
            available = true;
        }
    }

    void decreaseQuantity(int amount) {
        if (quantity >= amount) {
            quantity -= amount;
            if (quantity == 0) {
                available = false;
            }
        } else {
            std::cout << "Not enough books to decrease.\n";
        }
    }

    void print() const {
        std::cout << "Author: " << author << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
    }
};