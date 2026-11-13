#include "Syrup.h"
#include <sstream>

/**
 * @brief Конструктор сиропа.
 */
Syrup::Syrup(const std::string& name, const std::string& manufacturer,
             const std::string& annotation, const std::string& disease,
             const int shelfLifeMonths, const double price, const int volumeMl)
    : Medicine(name, "сироп", manufacturer, annotation, disease, shelfLifeMonths, price),
      volumeMl(volumeMl) {}

/**
 * @brief Получить тип лекарства.
 */
std::string Syrup::getType() const { return "Сироп"; }

/**
 * @brief Получить полную информацию о сиропе.
 */
std::string Syrup::getInfo() const {
    std::ostringstream oss;
    oss << Medicine::getInfo() << " | Объём: " << volumeMl << " мл";
    return oss.str();
}
