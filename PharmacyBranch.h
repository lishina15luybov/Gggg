#pragma once
#include "Medicine.h"
#include <vector>
#include <memory>

class PharmacyBranch {
protected:
    std::string name;
    std::string address;
    std::vector<std::shared_ptr<Medicine>> medicines;

public:
    PharmacyBranch(const std::string& name, const std::string& address);
    std::string getName() const;
    std::string getAddress() const;

    void addMedicine(std::shared_ptr<Medicine> med);
    std::vector<std::shared_ptr<Medicine>> getAllMedicines() const;
    std::vector<std::shared_ptr<Medicine>> findByDisease(const std::string& disease) const;
    std::vector<std::shared_ptr<Medicine>> findByName(const std::string& name) const;
};
