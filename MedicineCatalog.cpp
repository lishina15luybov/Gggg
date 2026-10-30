#include "MedicineCatalog.h"

void MedicineCatalog::addMedicine(std::shared_ptr<Medicine> med) {
    medicines.push_back(med);
}

std::vector<std::shared_ptr<Medicine>> MedicineCatalog::getAll() const {
    return medicines;
}

std::vector<std::shared_ptr<Medicine>> MedicineCatalog::findByDisease(const std::string& disease) const {
    std::vector<std::shared_ptr<Medicine>> result;
    for (const auto& m : medicines)
        if (m->getDisease() == disease) result.push_back(m);
    return result;
}

std::vector<std::shared_ptr<Medicine>> MedicineCatalog::findByName(const std::string& name) const {
    std::vector<std::shared_ptr<Medicine>> result;
    for (const auto& m : medicines)
        if (m->getName() == name) result.push_back(m);
    return result;
}

int MedicineCatalog::getSalesForMedicine(const std::string& name, int period) const {
    for (const auto& m : medicines)
        if (m->getName() == name) return m->getSalesForPeriod(period);
    return 0;
}
