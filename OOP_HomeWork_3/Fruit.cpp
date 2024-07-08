#include "Fruit.hpp"

Fruit::Fruit() : Fruit("", 0) {}

Fruit::Fruit(std::string name, size_t weight) : name_(name), weight_(weight){}

Fruit::Fruit(const Fruit& other) : name_(other.name_), weight_(other.weight_){}

std::string Fruit::GetName()const{ return name_; }

size_t Fruit::GetWeight()const{ return weight_; }

void Fruit::Print() const{
	std::cout << GetName() << " весом " << GetWeight() << " грамм;\n";
}

