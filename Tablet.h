#pragma once
#include "Medicine.h"

class Tablet : public Medicine {
    int pillsPerPack;
public:
    Tablet(const std::string& name, const std::string& manufacturer,
           const std::string& annotation, const std::string& disease,
           int shelfLifeMonths, double price, int pillsPerPack);
    std::string getType() const override;
    std::string getInfo() const override;
};
