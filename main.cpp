#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isDigits(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

int main() {
    std::string name, date, amount;
    std::ofstream file("C:\\20.5\\score.txt.txt", std::ios::app);

    if (!file) {
        std::cerr << "Error: Unable to open the file for writing!" << std::endl;
        return 1;
    }

    std::cout << "Enter name and surname: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cerr << "Error: Name and surname cannot be empty." << std::endl;
        return 1;
    }

    std::cout << "Enter date (DD.MM.YYYY): ";
    std::getline(std::cin, date);

    if (date.size() != 10 || date[2] != '.' || date[5] != '.') {
        std::cerr << "Error: Invalid date format. Use DD.MM.YYYY." << std::endl;
        return 1;
    }

    std::string dayStr = date.substr(0, 2);
    std::string monthStr = date.substr(3, 2);
    std::string yearStr = date.substr(6, 4);

    if (!isDigits(dayStr) || !isDigits(monthStr) || !isDigits(yearStr)) {
        std::cerr << "Error: Date should contain only digits." << std::endl;
        return 1;
    }

    int day = std::stoi(dayStr);
    int month = std::stoi(monthStr);
    int year = std::stoi(yearStr);

    if (month < 1 || month > 12) {
        std::cerr << "Error: Month must be between 1 and 12." << std::endl;
        return 1;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        std::cerr << "Error: Day is out of range for the given month." << std::endl;
        return 1;
    }

    std::cout << "Enter payment amount: ";
    std::getline(std::cin, amount);

    if (amount.empty() || !isDigits(amount)) {
        std::cerr << "Error: Amount must be a numeric value." << std::endl;
        return 1;
    }

    file << name << " " << date << " " << amount << "\n";
    file.close();

    std::cout << "Data successfully written to the record!" << std::endl;
    return 0;
}
