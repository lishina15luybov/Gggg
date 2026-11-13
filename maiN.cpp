#include <iostream>
#include "Tablet.h"
#include "Syrup.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

/**
 * @brief Точка входа в демонстрационную программу.
 * @return Код возврата (0 - успех)
 */
int main() {
    setlocale(LC_ALL, "Russian");

    // 1. Создаем лекарства 
    Tablet aspirin("Аспирин", "Bayer", "Жаропонижающее", "Простуда", 24, 150.0, 20);
    Syrup herbion("Гербион", "KRKA", "От кашля", "Простуда", 18, 320.0, 150);
    Tablet analgin("Анальгин", "Фармстандарт", "Обезболивающее", "Головная боль", 24, 60.0, 10);

    // Добавляем продажи
    aspirin.addSale(360, 50);

    // 2. Создаем филиалы аптек 
    PharmacyBranch branch1("Аптека №1 (Центр)", "ул. Ленина, 10");
    PharmacyBranch branch2("Аптека №2 (Спальный район)", "ул. Мира, 5");

    // 3. Кладем лекарства в аптеки (передаем ссылки)
    branch1.addMedicine(aspirin);
    branch2.addMedicine(herbion);
    branch2.addMedicine(analgin);

    // 4. Создаем сеть и добавляем филиалы
    PharmacyNetwork network("Сеть аптек 'Здоровье+'");
    network.addBranch(branch1);
    network.addBranch(branch2);

    //ВЫВОД ИНФЫ
    std::cout << "=== Сеть аптек: " << network.getNetworkName() << " ===\n";
    
    // Итерируемся по сети
    for (auto branch : network.getBranches()) {
        std::cout << "\n[Филиал]: " << branch.getName() << " (" << branch.getAddress() << ")\n";
        
        // Итерируемся по лекарствам
        for (auto med : branch.getAllMedicines()) {
            std::cout << "  " << med.get().getInfo() << "\n";
        }
    }

    // Демонстрация поиска по болезни в конкретной аптеке
    std::cout << "\n=== Лекарства от простуды в Аптеке №2 ===\n";
    for (auto med : branch2.findByDisease("Простуда")) {
        std::cout << "  " << med.get().getInfo() << "\n";
    }

    // Демонстрация продаж
    std::cout << "\n=== Продажи Аспирина за год (Аптека №1) ===\n";
    std::cout << "  Продано: " << branch1.getAllMedicines()[0].get().getSalesForPeriod(3) << " шт.\n";

    return 0;
}
