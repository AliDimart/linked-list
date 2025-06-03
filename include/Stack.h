#pragma once

#include "List.h"

template<typename T>
class Stack {
public:
	// Класс стека, реализованного на односвязном списке 
	Stack() = default;
	~Stack() = default;
	void push(const T value);
	T pop();
	bool empty();
	int get_min();

private:
	List<T> lst, minimums; 
};

template<typename T>
void Stack<T>::push(const T value) {
	lst.push_front(value);
	// Если данный элемент меньше настоящего минимума, тогда добавляем его в стек min, иначе дублируем настоящий минимум 
	if (minimums.GetSize() == 0 || minimums[minimums.GetSize() - 1] > value) 
		minimums.push_back(value);
	else 
		minimums.push_back(minimums[minimums.GetSize() - 1]);
}

template<typename T>
T Stack<T>::pop() {
	T temp = lst[0];
	lst.pop_front();
	minimums.pop_front();
	return temp;
}

template<typename T>
bool Stack<T>::empty() {
	return lst.GetSize() == 0;
}

int Stack<int>::get_min() {
	// Список минимумов содержит минимумы, которые обновляются при добавлении и удалении элементов из основного стека 
	if (minimums.GetSize() != 0) return minimums[minimums.GetSize() - 1];
	else return 9e7;
}
