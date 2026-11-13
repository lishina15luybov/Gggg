#include "Medicine.h"
#include <sstream>

/**
 * @brief Конструктор базового класса Medicine.
 */
Medicine::Medicine(const std::string& name, const std::string& form,
                   const std::string& manufacturer, const std::string& annotation,
                   const std::string& disease, const int shelfLifeMonths, const double price)
    : name(name), form(form), manufacturer(manufacturer), annotation(annotation),
      disease(disease), shelfLifeMonths(shelfLifeMonths), price(price) {}

/**
 * @brief Получить название лекарства.
 */
std::string Medicine::getName() const { return name; }

/**
 * @brief Получить болезнь, от которой помогает лекарство.
 */
std::string Medicine::getDisease() const { return disease; }

/**
 * @brief Получить цену лекарства.
 */
double Medicine::getPrice() const { return price; }

/**
 * @brief Добавить информацию о продажах.
 */
void Medicine::addSale(const int dayOfYear, const int qty) {
    sales[dayOfYear] += qty;
}

/**
 * @brief Получить количество продаж за определенный период.
 */
int Medicine::getSalesForPeriod(const int period) const {
    int days = 7;
    if (period == 2) days = 30;
    else if (period == 3) days = 365;

    int total = 0;
    int startDay = 365 - days + 1;
    for (const auto& p : sales) {
        if (p.first >= startDay) total += p.second;
    }
    return total;
}

/**
 * @brief Получить строковое представление информации о лекарстве.
 */
std::string Medicine::getInfo() const {
    std::ostringstream oss;
    oss << "[" << getType() << "] " << name
        << " | Изготовитель: " << manufacturer
        << " | Цена: " << price << " руб."
        << " | Болезнь: " << disease;
    return oss.str();
}
