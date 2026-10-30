#include <iostream>
#include <cassert>
#include <memory>
#include "Tablet.h"
#include "Syrup.h"
#include "MedicineCatalog.h"

void testPolymorphism() {
    std::vector<std::shared_ptr<Medicine>> v;
    v.push_back(std::make_shared<Tablet>("A", "M", "-", "D", 12, 10.0, 10));
    v.push_back(std::make_shared<Syrup>("B", "M", "-", "D", 12, 20.0, 100));
    assert(v[0]->getType() == "Таблетки");
    assert(v[1]->getType() == "Сироп");
    std::cout << "[OK] testPolymorphism\n";
}

void testSales() {
    auto t = std::make_shared<Tablet>("A", "M", "-", "D", 12, 10.0, 10);
    t->addSale(360, 5);
    t->addSale(364, 3);
    assert(t->getSalesForPeriod(1) == 8);   // последняя неделя
    assert(t->getSalesForPeriod(3) == 8);   // год
    std::cout << "[OK] testSales\n";
}

void testCatalog() {
    MedicineCatalog c;
    c.addMedicine(std::make_shared<Tablet>("A", "M", "-", "Простуда", 12, 10.0, 10));
    c.addMedicine(std::make_shared<Syrup>("B", "M", "-", "Кашель", 12, 20.0, 100));
    assert(c.findByDisease("Простуда").size() == 1);
    assert(c.findByDisease("Простуда")[0]->getName() == "A");
    std::cout << "[OK] testCatalog\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    testPolymorphism();
    testSales();
    testCatalog();
    std::cout << "Все тесты пройдены!\n";
    return 0;
}
