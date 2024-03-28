#include <iostream>
using namespace std;

class Book {
private:
    const string author;
    const string title;
    int quantity;
    const int year;
    bool available;

public:
    Book(string  _author, string  _title, int _quantity, int _year, bool _available)
            : author(std::move(_author)), title(std::move(_title)), quantity(_quantity), year(_year), available(_available) {}

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
            cout << "Book is not available.\n";
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
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Year: " << year << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }
};

int main() {
    Book book1("Author1", "Title1", 10, 2000, true);
    Book book2("Author2", "Title2", 5, 2010, true);

    book1.print();
    book2.print();

    book1.issueBook();
    book1.print();

    book2.decreaseQuantity(3);
    book2.print();

    book1.increaseQuantity(5);
    book1.print();

    return 0;
}
