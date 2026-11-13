#pragma once
#include "Medicine.h"
#include <vector>
#include <string>
#include <functional>

/**
 * @brief Класс, описывающий конкретный филиал аптеки.
 */
class PharmacyBranch {
protected:
    std::string name;    ///< Название аптеки
    std::string address; ///< Адрес аптеки
    std::vector<std::reference_wrapper<Medicine>> medicines; ///< Список лекарств в наличии (без указателей)

public:
    /**
     * @brief Конструктор филиала.
     * @param name Название
     * @param address Адрес
     */
    PharmacyBranch(const std::string& name, const std::string& address);
    
    /// @brief Деструктор по умолчанию.
    ~PharmacyBranch() = default;

    /**
     * @brief Получить название филиала.
     * @return Название
     */
    std::string getName() const;
    
    /**
     * @brief Получить адрес филиала.
     * @return Адрес
     */
    std::string getAddress() const;

    /**
     * @brief Добавить лекарство в ассортимент.
     * @param med Ссылка на лекарство
     */
    void addMedicine(Medicine& med); 
    
    /**
     * @brief Получить все лекарства в филиале.
     * @return Вектор ссылок на лекарства
     */
    std::vector<std::reference_wrapper<Medicine>> getAllMedicines() const;
    
    /**
     * @brief Найти лекарства от конкретной болезни.
     * @param disease Название болезни
     * @return Вектор подходящих лекарств
     */
    std::vector<std::reference_wrapper<Medicine>> findByDisease(const std::string& disease) const;
    
    /**
     * @brief Найти лекарство по названию.
     * @param name Название лекарства
     * @return Вектор найденных лекарств
     */
    std::vector<std::reference_wrapper<Medicine>> findByName(const std::string& name) const;
};
