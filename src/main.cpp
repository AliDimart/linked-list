#include <iostream>

template<typename T>
class List {
public:

	List();
	~List();
	void pop_front();
	void pop_back();
	void push_front(T data);
	void push_back(T data);
	void insert(T data, const int index);
	void remove(const int index);
	int GetSize() const { return size; }
	void Print();
	void clear();
	T& operator[](const int index);

private:
	class Node {
	public:

		Node(T data = T(), Node* ptr = nullptr) {
			this->data = data;
			this->ptrNext = ptr;
		}

		~Node() = default;

		Node* ptrNext;
		T data;
	};

	Node* GetNode(const int index);

	int size;
	Node* head;
	Node* tail; // Для константного добавления элементов не только в начало, но и в конец 
};

template<typename T>
List<T>::List() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
void List<T>::push_front(T data) {
	head = new Node(data, head);
	if (tail == nullptr) tail = head;
	size++;
}

template<typename T>
void List<T>::Print() {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data << std::endl;
		current = current->ptrNext;
	}
}

template<typename T>
void List<T>::push_back(T data) {
	if (tail == nullptr) {
		head = tail = new Node(data);
	}
	else {
		tail->ptrNext = new Node(data);
		tail = tail->ptrNext;
	}
	size++;
}

template<typename T>
void List<T>::pop_front() {
	if (head == nullptr) return;
	Node* temp = head->ptrNext;
	delete head;
	head = temp;
	if (head == nullptr) tail = nullptr;
	size--;
}

template<typename T>
void List<T>::clear() {
	while (size) {
		pop_front();
	}
}

template<typename T>
typename List<T>::Node* List<T>::GetNode(const int index) {

	if (index < 0 || index >= size) throw std::exception("Index out of range");

	Node* current = head; int currentIndex = 0;

	while (currentIndex != index) {

		current = current->ptrNext;
		currentIndex++;
	}
	return current;
}

template<typename T>
T& List<T>::operator[](const int index) {
	return GetNode(index)->data;
}

template<typename T>
void List<T>::insert(T data, const int index) {

	if (index < 0 || index > size) throw std::exception("Index out of range");

	if (index == 0) push_front(data);
	else {
		Node* current = GetNode(index - 1);

		current->ptrNext = new Node(data, current->ptrNext);
		size++;
	}
}

template<typename T>
void List<T>::remove(const int index) {
	if (index < 0 || index >= size) throw std::exception("Index out of range");

	if (index == 0) pop_front();
	else {
		Node* current = GetNode(index - 1);
		Node* toDelete = current->ptrNext;

		current->ptrNext = toDelete->ptrNext;
		delete toDelete;
		if (current->ptrNext == nullptr) tail = current; // Если удалили последний элемент 
		size--;
	}
}

template<typename T>
void List<T>::pop_back() {
	remove(size - 1);
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
class Queue {
public:

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


int main()
{
	List<int> lst;

	lst.push_back(17);
	lst.push_back(10);
	lst.push_back(9);

	lst.Print();
	std::cout << std::endl << "Insert" << std::endl;

	lst.insert(15, 3);
	lst.Print();

	std::cout << std::endl << "pop_back" << std::endl;

	lst.pop_back();
	lst.Print();

	return 0;
}