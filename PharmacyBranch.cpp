#include "PharmacyBranch.h"

PharmacyBranch::PharmacyBranch(const std::string& name, const std::string& address) 
    : name(name), address(address) {}

std::string PharmacyBranch::getName() const { return name; }
std::string PharmacyBranch::getAddress() const { return address; }

void PharmacyBranch::addMedicine(std::shared_ptr<Medicine> med) {
    medicines.push_back(med);
}

std::vector<std::shared_ptr<Medicine>> PharmacyBranch::getAllMedicines() const {
    return medicines;
}

std::vector<std::shared_ptr<Medicine>> PharmacyBranch::findByDisease(const std::string& disease) const {
    std::vector<std::shared_ptr<Medicine>> result;
    for (const auto& m : medicines) {
        if (m->getDisease() == disease) result.push_back(m);
    }
    return result;
}

std::vector<std::shared_ptr<Medicine>> PharmacyBranch::findByName(const std::string& name) const {
    std::vector<std::shared_ptr<Medicine>> result;
    for (const auto& m : medicines) {
        if (m->getName() == name) result.push_back(m);
    }
    return result;
}
