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
};

template<typename T>
List<T>::List() {
	head = nullptr;
	size = 0;
}

template<typename T>
void List<T>::push_front(T data) {
	head = new Node(data, head);
	size++;
}

template<typename T>
void List<T>::Print() {
	Node* currunt = head;
	while (currunt != nullptr) {
		std::cout << currunt->data << std::endl;
		currunt = currunt->ptrNext;
	}
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {

		head = new Node(data);
	}
	else {
		Node* currunt = head;

		while (currunt->ptrNext != nullptr) {
			currunt = currunt->ptrNext;
		}
		currunt->ptrNext = new Node(data);
	}
	size++;
}

template<typename T>
void List<T>::pop_back() {
	remove(size - 1);
}

template<typename T>
void List<T>::pop_front() {
	if (head == nullptr) return;
	Node* temp = head->ptrNext;
	delete head;
	head = temp;
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

	Node* currunt = head; int curruntIndex = 0;

	while (curruntIndex != index) {

		currunt = currunt->ptrNext;
		curruntIndex++;
	}
	return currunt;
}

template<typename T>
T& List<T>::operator[](const int index) {
	return GetNode(index)->data;
}

template<typename T>
void List<T>::insert(T data, const int index) {

	if (index < 0 || index >= size) throw std::exception("Index out of range");

	if (index == 0) push_front(data);
	else {
		Node* currunt = GetNode(index - 1);

		currunt->ptrNext = new Node(data, currunt->ptrNext);
		size++;
	}
}

template<typename T>
void List<T>::remove(const int index) {
	if (index < 0 || index >= size) throw std::exception("Index out of range");

	if (index == 0) pop_front();
	else {
		Node* currunt = GetNode(index - 1);
		Node* toDelete = currunt->ptrNext;

		currunt->ptrNext = toDelete->ptrNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
List<T>::~List() {
	clear();
}

int main()
{
	//int(*searchPtr)(const std::vector<int> arr, const int target); //указатель на функцию 

	List<int> lst;

	lst.push_back(17);
	lst.push_back(10);
	lst.push_back(9);

	lst.Print();
	std::cout << std::endl << "Insert" << std::endl;

	lst.insert(15, 1);
	lst.Print();

	std::cout << std::endl << "pop_back" << std::endl;

	lst.pop_back();
	lst.Print();

	return 0;
}