#include "PharmacyBranch.h"

/**
 * @brief Конструктор филиала.
 */
PharmacyBranch::PharmacyBranch(const std::string& name, const std::string& address) 
    : name(name), address(address) {}

/**
 * @brief Получить название филиала.
 */
std::string PharmacyBranch::getName() const { return name; }

/**
 * @brief Получить адрес филиала.
 */
std::string PharmacyBranch::getAddress() const { return address; }

/**
 * @brief Добавить лекарство в ассортимент.
 */
void PharmacyBranch::addMedicine(Medicine& med) {
    medicines.push_back(med);
}

/**
 * @brief Получить все лекарства в филиале.
 */
std::vector<std::reference_wrapper<Medicine>> PharmacyBranch::getAllMedicines() const {
    return medicines;
}

/**
 * @brief Найти лекарства от конкретной болезни.
 */
std::vector<std::reference_wrapper<Medicine>> PharmacyBranch::findByDisease(const std::string& disease) const {
    std::vector<std::reference_wrapper<Medicine>> result;
    for (auto m : medicines) {
        if (m.get().getDisease() == disease) result.push_back(m);
    }
    return result;
}

/**
 * @brief Найти лекарство по названию.
 */
std::vector<std::reference_wrapper<Medicine>> PharmacyBranch::findByName(const std::string& name) const {
    std::vector<std::reference_wrapper<Medicine>> result;
    for (auto m : medicines) {
        if (m.get().getName() == name) result.push_back(m);
    }
    return result;
}
