#pragma once
#include "Medicine.h"

class Syrup : public Medicine {
    int volumeMl;
public:
    Syrup(const std::string& name, const std::string& manufacturer,
          const std::string& annotation, const std::string& disease,
          int shelfLifeMonths, double price, int volumeMl);
    std::string getType() const override;
    std::string getInfo() const override;
};
