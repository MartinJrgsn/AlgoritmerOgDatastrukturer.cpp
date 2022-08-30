#pragma once
#include <iostream>

namespace enkeltLenkedeListe {

	template <typename T>
	class Node {
	public:
		Node(T value)
			:m_value{ value }, m_next{ nullptr } {}

		T getValue() {
			return m_value; // O(1)
		}

		std::shared_ptr<Node<T>> getNext() {
			return m_next; // O(1)
		}

		void setNext(std::shared_ptr<Node<T>> next) {
			m_next = { next }; // O(1)
		}

	private:
		T m_value{};
		std::shared_ptr<Node<T>> m_next{ nullptr };
	};

	template <typename T>
	class singlyLinkedList
	{
	public:
		singlyLinkedList(T value)
		{
			m_node = std::make_shared<Node<T>>(value); // O(1)
		}

		void printList() {
			auto newNode = m_node; // O(1)
			while (newNode != NULL) { // O(n) {
				std::cout << newNode->Node<T>::getValue() << "->"; // O(1)
				newNode = newNode->Node<T>::getNext(); // O(1)
			}
			std::cout << std::endl; // O(1)
		}

		void insertNode(T value) {
			auto head = m_node; // O(1)
			auto nextNode = std::make_shared<Node<T>>(value); // O(1)

			while (head->getNext() != NULL) { // O(n) {
				head = head->Node<T>::getNext(); // O(1)
			}

			head->Node<T>::setNext(nextNode); // O(1)
		}

		/*std::shared_ptr<Node<t>> removeNode() {
			T data = heads getVal()
				head = head->getNext()
				--size;
			return data;
		}*/

	private:
		std::shared_ptr<Node<T>> m_node{ nullptr };
	};


	void presetRun() {
		std::cout << "Linked list with integers\n\n";

		auto linkedList = std::make_shared<singlyLinkedList<int>>(100); // Initializing the linked list with it's first value.

		linkedList->insertNode(200);
		linkedList->insertNode(300);
		linkedList->insertNode(400);
		linkedList->insertNode(500);
		linkedList->insertNode(600);
		linkedList->insertNode(700);

		linkedList->printList();

		std::cout << "\n\n\nlinked list with strings\n\n";
		auto linkedListString = std::make_shared<singlyLinkedList<std::string>>("Head");

		linkedListString->insertNode("second");
		linkedListString->insertNode("third");
		linkedListString->insertNode("fourth");
		linkedListString->insertNode("fifth");
		linkedListString->insertNode("sixth");
		linkedListString->insertNode("tail");

		linkedListString->printList();
	}

}