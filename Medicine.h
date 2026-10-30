#pragma once
#include <string>
#include <vector>
#include <map>

// Базовый класс
class Medicine {
protected:
    std::string name;
    std::string form;
    std::string manufacturer;
    std::string annotation;
    std::string disease;
    int shelfLifeMonths;
    double price;
    // продажи: дата (день от начала года) - количество
    std::map<int, int> sales; // ключ: 1..365, значение: штук продано

public:
    Medicine(const std::string& name, const std::string& form,
             const std::string& manufacturer, const std::string& annotation,
             const std::string& disease, int shelfLifeMonths, double price);
    virtual ~Medicine() = default;

    std::string getName() const;
    std::string getDisease() const;
    double getPrice() const;

    void addSale(int dayOfYear, int qty);
    // период: 1=неделя, 2=месяц, 3=год
    int getSalesForPeriod(int period) const;

    virtual std::string getInfo() const;      
    virtual std::string getType() const = 0;  
};
