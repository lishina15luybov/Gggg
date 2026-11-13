#include "Tablet.h"
#include <sstream>

/**
 * @brief Конструктор таблеток.
 */
Tablet::Tablet(const std::string& name, const std::string& manufacturer,
               const std::string& annotation, const std::string& disease,
               const int shelfLifeMonths, const double price, const int pillsPerPack)
    : Medicine(name, "таблетки", manufacturer, annotation, disease, shelfLifeMonths, price),
      pillsPerPack(pillsPerPack) {}

/**
 * @brief Получить тип лекарства.
 */
std::string Tablet::getType() const { return "Таблетки"; }

/**
 * @brief Получить полную информацию о таблетках.
 */
std::string Tablet::getInfo() const {
    std::ostringstream oss;
    oss << Medicine::getInfo() << " | Таблеток: " << pillsPerPack;
    return oss.str();
}
