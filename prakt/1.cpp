#include <iostream>

class Employee {
private:
    std::string surname;
    int workedHours;
    static double hourlyRate;
    static double taxThresholds[3];
    static double taxRates[3];

public:
    Employee(const std::string& _surname, int _workedHours)
            : surname(_surname), workedHours(_workedHours) {}

    static void setHourlyRate(double rate) {
        hourlyRate = rate;
    }

    static void setTaxThresholds(double thresholds[3]) {
        for (int i = 0; i < 3; ++i)
            taxThresholds[i] = thresholds[i];
    }

    static void setTaxRates(double rates[3]) {
        for (int i = 0; i < 3; ++i)
            taxRates[i] = rates[i];
    }

    double calculateSalary() const {
        return workedHours * hourlyRate;
    }

    double calculateTax() const {
        double salary = calculateSalary();
        if (salary <= taxThresholds[0])
            return 0;
        else if (salary <= taxThresholds[1])
            return (salary - taxThresholds[0]) * taxRates[0];
        else if (salary <= taxThresholds[2])
            return (taxThresholds[1] - taxThresholds[0]) * taxRates[0] + (salary - taxThresholds[1]) * taxRates[1];
        else
            return (taxThresholds[1] - taxThresholds[0]) * taxRates[0] + (taxThresholds[2] - taxThresholds[1]) * taxRates[1] + (salary - taxThresholds[2]) * taxRates[2];
    }

    void displayInfo() const {
        std::cout << "Surname: " << surname << std::endl;
        std::cout << "Worked Hours: " << workedHours << std::endl;
        std::cout << "Salary: " << calculateSalary() << std::endl;
        std::cout << "Tax: " << calculateTax() << std::endl;
    }
};

double Employee::hourlyRate = 10.0;
double Employee::taxThresholds[3] = {1000, 2000, 3000};
double Employee::taxRates[3] = {0.1, 0.15, 0.2};