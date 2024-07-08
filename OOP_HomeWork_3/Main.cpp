#include<iostream>
#include<string>
#include"Fruit.hpp"
#include"Tree.hpp"

int main() {
	setlocale(LC_ALL, "RU");
	// Создадим объекты класса Fruit:
	Fruit fruit1 ("яблоко", 50);
	Fruit fruit2 ("яблоко", 70);
	Fruit fruit3 ("яблоко", 100);
	// Создадим объект класса Tree:
	Tree tree1("яблоне", 5);
	tree1.Print();
	std::cout << "==========\n";
	// Добавим фрукты к дереву:
	tree1.CreateFruit(fruit1);
	tree1.CreateFruit(fruit2);
	tree1.CreateFruit(fruit3);
	tree1.Print();
	std::cout << "==========\n";
	// Сорвем второе яблоко с яблони:
	std::cout << "Уставший и проголодавшийся Бильбо Беггинс сделал привал у " <<
		tree1.GetTreeName() << " и сорвал второе снизу ";
	(tree1.DropFruit(1)).Print();
	std::cout << "==========\n";
	tree1.Print();
	std::cout << "==========\n";
	std::cout << "Утром на завтрак Бильбо Беггинс сорвал два последних плода на дереве.\n";
	tree1.DropFruit(0);
	tree1.DropFruit(0);
	std::cout << std::endl;
	tree1.Print();
	std::cout << "\nxxxxxxxxxxxxxxxx\n";
	// Применим конструктор копирования.
	Tree tree2("яблоне", 3);
	tree2.Print();
	tree2.CreateFruit(fruit1);
	tree2.CreateFruit(fruit2);	
	tree2.Print();
	std::cout << "==========\n";
	
	Tree tree3(tree2);
	tree3.Print();
	

	return 0;
}