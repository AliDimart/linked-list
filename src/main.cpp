#include "Queue.h"
#include "StackQueue.h"

void Print(StackQueue& queue) {
	while (!queue.empty()) {
		std::cout << queue.pop() << '\t';
	}
	std::cout << std::endl;
}

int main()
{
	StackQueue queue;

	queue.push(3);
	std::cout << "Min: " << queue.get_min() << '\n';
	queue.push(2);
	std::cout << "Min: " << queue.get_min() << '\n';
	queue.push(5);
	std::cout << "Min: " << queue.get_min() << '\n';

	Print(queue);

	return 0;
}