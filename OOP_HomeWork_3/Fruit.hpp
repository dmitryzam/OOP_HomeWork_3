#pragma once
#include<iostream>

class Fruit {
public:
	Fruit();
	Fruit(std::string name_, size_t weight_);
	Fruit(const Fruit& other);
	std::string GetName()const;
	size_t GetWeight()const;
	void Print()const;
private:
	std::string name_;
	size_t weight_;
};