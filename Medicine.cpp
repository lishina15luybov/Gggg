#include "Medicine.h"
#include <sstream>
#include <algorithm>

Medicine::Medicine(const std::string& name, const std::string& form,
                   const std::string& manufacturer, const std::string& annotation,
                   const std::string& disease, int shelfLifeMonths, double price)
    : name(name), form(form), manufacturer(manufacturer), annotation(annotation),
      disease(disease), shelfLifeMonths(shelfLifeMonths), price(price) {}

std::string Medicine::getName() const { return name; }
std::string Medicine::getDisease() const { return disease; }
double Medicine::getPrice() const { return price; }

void Medicine::addSale(int dayOfYear, int qty) {
    sales[dayOfYear] += qty;
}

int Medicine::getSalesForPeriod(int period) const {
    int days = 7;
    if (period == 2) days = 30;
    else if (period == 3) days = 365;

    // считаем продажи
    int total = 0;
    int startDay = 365 - days + 1;
    for (const auto& p : sales) {
        if (p.first >= startDay) total += p.second;
    }
    return total;
}

std::string Medicine::getInfo() const {
    std::ostringstream oss;
    oss << "[" << getType() << "] " << name
        << " | Форма: " << form
        << " | Изготовитель: " << manufacturer
        << " | Срок: " << shelfLifeMonths << " мес."
        << " | Цена: " << price << " руб."
        << " | Болезнь: " << disease;
    return oss.str();
}
