#pragma once
#include <string>
#include <map>

class Medicine {
protected:
    std::string name;
    std::string form;
    std::string manufacturer;
    std::string annotation;
    std::string disease;
    int shelfLifeMonths;
    double price;
    std::map<int, int> sales; // день года -количество

public:
    Medicine(const std::string& name, const std::string& form,
             const std::string& manufacturer, const std::string& annotation,
             const std::string& disease, int shelfLifeMonths, double price);
    virtual ~Medicine() = default;

    std::string getName() const;
    std::string getDisease() const;
    double getPrice() const;

    void addSale(int dayOfYear, int qty);
    
    int getSalesForPeriod(const int period) const; 

    virtual std::string getInfo() const;
    virtual std::string getType() const = 0;
};
