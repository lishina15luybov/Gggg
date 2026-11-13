#pragma once
#include "Medicine.h"
#include <vector>
#include <string>

/**
 * @brief Класс, описывающий конкретный филиал аптеки.
 */
class PharmacyBranch {
protected:
    std::string name;    
    std::string address; 
    std::vector<Medicine> medicines; 

public:
    PharmacyBranch(const std::string& name, const std::string& address);
    ~PharmacyBranch() = default;

    std::string getName() const;
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
     * @brief Найти лекарства от болезни.
     */
    std::vector<Medicine> findByDisease(const std::string& disease) const;
    
    /**
     * @brief Найти лекарство по названию.
     */
    std::vector<Medicine> findByName(const std::string& name) const;
};
