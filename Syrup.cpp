#include "Syrup.h"
#include <sstream>

Syrup::Syrup(const std::string& name, const std::string& manufacturer,
             const std::string& annotation, const std::string& disease,
             int shelfLifeMonths, double price, int volumeMl)
    : Medicine(name, "сироп", manufacturer, annotation, disease, shelfLifeMonths, price),
      volumeMl(volumeMl) {}

std::string Syrup::getType() const { return "Сироп"; }

std::string Syrup::getInfo() const {
    std::ostringstream oss;
    oss << Medicine::getInfo() << " | Объём: " << volumeMl << " мл";
    return oss.str();
}
