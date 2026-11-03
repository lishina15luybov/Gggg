#pragma once
#include "Medicine.h"
#include <vector>
#include <string>

/**
 * @brief Класс, описывающий конкретный филиал аптеки.
 */
class PharmacyBranch {
protected:
    std::string name;    ///Название аптеки
    std::string address; /// Адрес аптеки
    std::vector<Medicine*> medicines; /// Список лекарств в наличии

public:
    /**
     * @brief Конструктор филиала.
     * @param name Название
     * @param address Адрес
     */
    PharmacyBranch(const std::string& name, const std::string& address);
    
    ~PharmacyBranch();

    /// @return Название филиала
    std::string getName() const;
    
    /// @return Адрес филиала
    std::string getAddress() const;

    /**
     * @brief Добавить лекарство в ассортимент.
     * @param med Указатель на лекарство
     */
    void addMedicine(Medicine* med); 
    
    /// @return Вектор всех лекарств
    std::vector<Medicine*> getAllMedicines() const;
    
    /**
     * @brief Найти лекарства от конкретной болезни.
     * @param disease Название болезни
     * @return Вектор подходящих лекарств
     */
    std::vector<Medicine*> findByDisease(const std::string& disease) const;
    
    /**
     * @brief Найти лекарство по названию.
     * @param name Название лекарства
     * @return Вектор найденных лекарств
     */
    std::vector<Medicine*> findByName(const std::string& name) const;
};
