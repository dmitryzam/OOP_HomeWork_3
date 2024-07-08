#include "Tree.hpp"
// Конструктора:
Tree::Tree() : Tree(" ", 0) {}
Tree::Tree(std::string name, time_t age) : name_(name), age_(age){
	fruit_count = 0;
	fruit_arr = nullptr;
}
Tree::Tree(const Tree& other) : name_(other.name_), age_(other.age_){	
	if (other.fruit_arr == nullptr) {		
		fruit_count = 0;
		fruit_arr = nullptr;
		return;
	}	
	fruit_count = other.fruit_count;
	fruit_arr = new Fruit[fruit_count];
	for (int i = 0; i < fruit_count; ++i) {
		fruit_arr[i] = other.fruit_arr[i];
	}
}
// Геттеры:
std::string Tree::GetTreeName()const { return name_; }
time_t Tree::GetAge()const { return age_; }
size_t Tree::GetFruitCount()const { return fruit_count; }
std::string Tree::GetFruitName()const { return (fruit_arr[0]).GetName(); }
// Методы:
void Tree::CreateFruit(const Fruit& other){
	if (fruit_arr == nullptr) {
		fruit_arr = new Fruit[1];
		fruit_count = 1;
		fruit_arr[0] = other;
		return;
	}
	Fruit* tmp = new Fruit[fruit_count + 1];
	for (int i{ 0 }; i < fruit_count; ++i) {
		tmp[i] = fruit_arr[i];
	}
	tmp[fruit_count] = other;
	delete[] fruit_arr;
	fruit_arr = tmp;
	++fruit_count;
}
Fruit Tree::DropFruit(int index){	
	Fruit fruit_drop = fruit_arr[index];
	if (fruit_count == 1) {		// если срываем последний фрукт
		delete[] fruit_arr;
		fruit_arr = nullptr;
		--fruit_count;
		return fruit_drop;
	}
	Fruit* tmp = new Fruit[fruit_count - 1];
	for (int i{ 0 }; i < index; ++i) {
		tmp[i] = fruit_arr[i];
	}
	if (index != fruit_count - 1) {		// если index не последний элемент, то...
		for (int i{ index }; i < fruit_count - 1; ++i) {
			tmp[i] = fruit_arr[i + 1];
		}
	}
	delete[] fruit_arr;
	fruit_arr = tmp;
	--fruit_count;
	return fruit_drop;		// возвращаем фрукт с index
}
void Tree::Print()const{
	if (fruit_arr != nullptr) {
		std::cout << "На " << GetTreeName() << " возрастом " << GetAge() << 
			" лет, растут фрукты (" << GetFruitName() << ") в количестве " << 
			GetFruitCount() << " шт.\nВес каждого фрукта:\n";
		for (int i{ 0 }; i < fruit_count; ++i) {
			fruit_arr[i].Print();
		}
		return;
	}
	std::cout << "На " << GetTreeName() << " отсутсвуют фрукты\n";
}
