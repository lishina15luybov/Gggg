#pragma once
#include "Medicine.h"
#include <vector>
#include <memory>
#include <string>

class MedicineCatalog {
    std::vector<std::shared_ptr<Medicine>> medicines;
public:
    void addMedicine(std::shared_ptr<Medicine> med);
    std::vector<std::shared_ptr<Medicine>> getAll() const;
    std::vector<std::shared_ptr<Medicine>> findByDisease(const std::string& disease) const;
    std::vector<std::shared_ptr<Medicine>> findByName(const std::string& name) const;
    int getSalesForMedicine(const std::string& name, int period) const;
};
