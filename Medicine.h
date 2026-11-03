#pragma once
#include <string>
#include <map>

/**
 * @brief Базовый абстрактный класс, описывающий лекарственное средство.
 */
class Medicine {
protected:
    std::string name;          /// Название лекарства
    std::string form;          /// Форма выпуска (таблетки, сироп и т.д.)
    std::string manufacturer;  /// Производитель
    std::string annotation;    /// Краткая аннотация
    std::string disease;       /// Болезнь, от которой применяется
    int shelfLifeMonths;       /// Срок годности в месяцах
    double price;              /// Цена в рублях
    std::map<int, int> sales;  /// Статистика продаж: ключ - день года (1-365), значение - количество

public:
    /**
     * @brief Конструктор базового класса Medicine.
     * @param name Название
     * @param form Форма выпуска
     * @param manufacturer Изготовитель
     * @param annotation Аннотация
     * @param disease Болезнь
     * @param shelfLifeMonths Срок годности
     * @param price Цена
     */
    Medicine(const std::string& name, const std::string& form,
             const std::string& manufacturer, const std::string& annotation,
             const std::string& disease, int shelfLifeMonths, double price);
             
    virtual ~Medicine() = default;

    /// @return Название лекарства
    std::string getName() const;
    
    /// @return Болезнь, от которой помогает лекарство
    std::string getDisease() const;
    
    /// @return Цена лекарства
    double getPrice() const;

    /**
     * @brief Добавить информацию о продажах.
     * @param dayOfYear День года 
     * @param qty Количество проданных упаковок
     */
    void addSale(int dayOfYear, int qty);
    
    /**
     * @brief Получить количество продаж за определенный период.
     * @param period Период: 1 - неделя, 2 - месяц, 3 - год
     * @return Количество проданных упаковок за период
     */
    int getSalesForPeriod(const int period) const; 

    /// @brief Получить строковое представление информации о лекарстве 
    virtual std::string getInfo() const;
    
    /// @brief Получить тип лекарства
    virtual std::string getType() const = 0;
};
