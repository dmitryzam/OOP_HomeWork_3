#pragma once
#include<iostream>
#include"Fruit.hpp"

class Tree {
public:
	Tree();
	Tree(std::string name_, time_t age_);
	Tree(const Tree& other);
	std::string GetTreeName()const;
	time_t GetAge()const;
	size_t GetFruitCount()const;
	std::string GetFruitName()const;
	void CreateFruit(const Fruit& other);		// метод добавления нового фрукта в массив плодов на дереве.
	Fruit DropFruit(int index);		// метод возвращает плод из массива плодов под
	// указанным индексом, после чего удаляет соответствующий плод из массива.
	void Print()const;
private:
	std::string name_;
	time_t age_;
	size_t fruit_count;
	Fruit* fruit_arr;
};
