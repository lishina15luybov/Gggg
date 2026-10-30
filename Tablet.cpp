#include "Tablet.h"
#include <sstream>

Tablet::Tablet(const std::string& name, const std::string& manufacturer,
               const std::string& annotation, const std::string& disease,
               int shelfLifeMonths, double price, int pillsPerPack)
    : Medicine(name, "таблетки", manufacturer, annotation, disease, shelfLifeMonths, price),
      pillsPerPack(pillsPerPack) {}

std::string Tablet::getType() const { return "Таблетки"; }

std::string Tablet::getInfo() const {
    std::ostringstream oss;
    oss << Medicine::getInfo() << " | Таблеток в упаковке: " << pillsPerPack;
    return oss.str();
}
