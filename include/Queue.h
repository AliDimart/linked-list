#pragma once

#include "List.h"

template<typename T>
class Queue {
public:
	// Класс очереди, реализованной на односвязном списке 
	Queue() = default;
	~Queue() = default;
	void push(const T value);
	T pop();

private:
	List<T> l;
};

template<typename T>
void Queue<T>::push(const T value) {
	l.push_back(value);
}

template<typename T>
T Queue<T>::pop() {
	T temp = l[0];
	l.pop_front();
	return temp;
}
