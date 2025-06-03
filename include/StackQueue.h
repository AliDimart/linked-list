#pragma once

#include "Stack.h"

class StackQueue {
public:
	// Очередь, реализованная на двух стеках, поддерживающая минимум  
	StackQueue() = default;
	~StackQueue() = default;
	void push(const int value);
	int pop();
	bool empty();
	int get_min();

private:
	Stack<int> in, out;
};

void StackQueue::push(const int value) {
	// Добавляем элемент во входной стэк 
	in.push(value);
}

int StackQueue::pop() {
	// Достаём элементы из стека out. Если он пуст, перекладываем элементы из стека in в стек out 
	if (out.empty()) {
		while (!in.empty()) {
			out.push(in.pop());
		}
	}
	return out.pop();
}

bool StackQueue::empty() {
	return (out.empty() && in.empty());
}

int StackQueue::get_min() {
	int min = std::min(out.get_min(), in.get_min());
	if (min == 9e7)
		throw std::exception("Queue is empty");
	return min;
}
