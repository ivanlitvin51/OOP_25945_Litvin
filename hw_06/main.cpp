#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <algorithm>

class Product {
private:
    std::string name;
    double price;
    int* ratings;
    int ratingsCount;

    // функция нормализации данных для сохранения инварианта
    void normalize() {
        // Форматирование названия: первая буква заглавная, остальные строчные
        if (!name.empty()) {
            name[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(name[0])));
            for (size_t i = 1; i < name.size(); ++i) {
                name[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(name[i])));
            }
        } else {
            name = "Unnamed";
        }

        // Цена не может быть отрицательной или чрезмерно завышенной
        if (price < 0.0) price = 0.0;
        if (price > 1'000'000.0) price = 1'000'000.0;

        for (int i = 0; i < ratingsCount; ++i) {
            if (ratings[i] < 1) ratings[i] = 1;
            if (ratings[i] > 5) ratings[i] = 5;
        }
    }

public:
    Product()
        : name("Default"), price(0.0), ratings(nullptr), ratingsCount(0) {
        std::cout << "default constructor" << std::endl;
    }

    // Инициализирующий конструктор с динамическим массивом
    Product(const std::string& n, double p, const int* r, int count)
        : name(n), price(p), ratingsCount(count < 0 ? 0 : count), ratings(nullptr) {
        if (ratingsCount > 0 && r != nullptr) {
            ratings = new int[ratingsCount];
            for (int i = 0; i < ratingsCount; ++i) {
                ratings[i] = r[i];
            }
        } else {
            ratingsCount = 0;
        }
        normalize();
        std::cout << "initialization constructor" << std::endl;
    }

    // Конструктор копирования (глубокое копирование)
    Product(const Product& other)
        : name(other.name), price(other.price), ratingsCount(other.ratingsCount), ratings(nullptr) {
        if (ratingsCount > 0 && other.ratings != nullptr) {
            ratings = new int[ratingsCount];
            for (int i = 0; i < ratingsCount; ++i) {
                ratings[i] = other.ratings[i];
            }
        }
        std::cout << "copy constructor" << std::endl;
    }

    // Оператор присваивания
    Product& operator=(const Product& other) {
        std::cout << "assignment operator" << std::endl;
        if (this == &other) {
            return *this;
        }

        name = other.name;
        price = other.price;

        delete[] ratings;
        ratings = nullptr;
        ratingsCount = other.ratingsCount;

        if (ratingsCount > 0 && other.ratings != nullptr) {
            ratings = new int[ratingsCount];
            for (int i = 0; i < ratingsCount; ++i) {
                ratings[i] = other.ratings[i];
            }
        }

        return *this;
    }

    // Деструктор для очищения динамической памяти
    ~Product() {
        delete[] ratings;
    }

    // Геттеры
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getRatingsCount() const { return ratingsCount; }
    int getRating(int index) const {
        if (index < 0 || index >= ratingsCount) {
            throw std::out_of_range("index out of range");
        }
        return ratings[index];
    }

    // Сеттеры
    void setName(const std::string& n) {
        name = n;
        normalize();
    }

    void setPrice(double p) {
        price = p;
        normalize();
    }
};

// 6.II.3: Демонстрация вызова конструктора копирования и оператора присваивания
int main() {
    int initialRatings[] = {5, 6, 0, 4}; // 6 станет 5, 0 станет 1
    
    std::cout << "--- 1. Создание через инициализирующий конструктор ---" << std::endl;
    Product item1("kEtTlE", 2500.0, initialRatings, 4);

    std::cout << "\n--- 2. Конструктор копирования (создание нового объекта из существующего) ---" << std::endl;
    Product item2 = item1;          // Синтаксис инициализации -> copy constructor
    Product item3(item1);           // Прямая инициализация -> copy constructor

    std::cout << "\n--- 3. Оператор присваивания (оба объекта уже существуют) ---" << std::endl;
    Product item4;                  // default constructor
    item4 = item1;                  // assignment operator

    return 0;
}