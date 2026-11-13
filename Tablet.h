#pragma once
#include "Medicine.h"

/**
 * @brief Класс-наследник, описывающий таблетки.
 */
class Tablet : public Medicine {
    int pillsPerPack; ///< Количество таблеток в упаковке
public:
    /**
     * @brief Конструктор таблеток.
     * @param name Название
     * @param manufacturer Изготовитель
     * @param annotation Аннотация
     * @param disease Болезнь
     * @param shelfLifeMonths Срок годности
     * @param price Цена
     * @param pillsPerPack Количество таблеток в упаковке
     */
    Tablet(const std::string& name, const std::string& manufacturer,
           const std::string& annotation, const std::string& disease,
           const int shelfLifeMonths, const double price, const int pillsPerPack);
           
    /**
     * @brief Получить тип лекарства.
     * @return Строка "Таблетки"
     */
    std::string getType() const override;
    
    /**
     * @brief Получить полную информацию о таблетках.
     * @return Строка с информацией
     */
    std::string getInfo() const override;
};
