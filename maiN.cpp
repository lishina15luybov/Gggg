#include <iostream>
#include <memory>
#include "Medicine.h"
#include "Tablet.h"
#include "Syrup.h"
#include "MedicineCatalog.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<std::shared_ptr<Medicine>> collection;
    collection.push_back(std::make_shared<Tablet>(
        "Аспирин", "Bayer", "Жаропонижающее", "Простуда", 24, 150.0, 20));
    collection.push_back(std::make_shared<Syrup>(
        "Гербион", "KRKA", "От кашля", "Простуда", 18, 320.0, 150));
    collection.push_back(std::make_shared<Tablet>(
        "Анальгин", "Фармстандарт", "Обезболивающее", "Головная боль", 24, 60.0, 10));

    collection[0]->addSale(360, 50);
    collection[0]->addSale(364, 30);
    collection[1]->addSale(350, 10);

  
    std::cout << "=== Ассортимент ===" << std::endl;
    for (const auto& med : collection) {
        std::cout << med->getInfo() << std::endl; 
    }

    // Список от болезни
    std::cout << "\n=== От простуды ===" << std::endl;
    for (const auto& med : collection)
        if (med->getDisease() == "Простуда")
            std::cout << med->getInfo() << std::endl;


    std::cout << "\n=== Продажи Аспирина ===" << std::endl;
    std::cout << "За неделю: " << collection[0]->getSalesForPeriod(1) << std::endl;
    std::cout << "За год:    " << collection[0]->getSalesForPeriod(3) << std::endl;

    return 0;
}
