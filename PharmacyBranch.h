#pragma once
#include "Medicine.h"
#include <vector>
#include <string>

/**
 * @brief Класс, описывающий конкретный филиал аптеки.
 * @details Содержит название филиала, адрес и ассортимент лекарственных средств.
 */
class PharmacyBranch {
protected:
    /** @brief Название филиала. */
    std::string name;
    /** @brief Адрес филиала. */
    std::string address;
    /** @brief Ассортимент лекарств в филиале. */
    std::vector<Medicine> medicines;

public:
    /**
     * @brief Конструктор филиала аптеки.
     * @param name Название филиала
     * @param address Адрес филиала
     */
    PharmacyBranch(const std::string& name, const std::string& address);

    /** @brief Деструктор по умолчанию. */
    ~PharmacyBranch() = default;

    /** @brief Получить название филиала. */
    std::string getName() const;
    /** @brief Получить адрес филиала. */
    std::string getAddress() const;

    /**
     * @brief Добавить лекарство в ассортимент.
     * @param med Копия лекарства
     */
    void addMedicine(const Medicine& med); 
    
    /**
     * @brief Получить все лекарства.
     * @return Вектор лекарств 
     */
    std::vector<Medicine> getAllMedicines() const;
    
    /**
     * @brief Найти лекарства от указанной болезни.
     * @param disease Название болезни
     * @return Вектор подходящих лекарств
     */
    std::vector<Medicine> findByDisease(const std::string& disease) const;
    
    /**
     * @brief Найти лекарство по названию.
     * @param name Название лекарства
     * @return Вектор найденных лекарств
     */
    std::vector<Medicine> findByName(const std::string& name) const;
};
