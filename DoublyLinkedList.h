#pragma once

namespace DobbeltLenketListe {
	template <typename T>
	class Node {
	public:
		Node(T value)
			:m_value{ value }, m_next{ nullptr }, m_prev{ nullptr } {}

		T getValue() {
			return m_value; // O(1)
		}

		std::shared_ptr<Node<T>> getNext() {
			return m_next; // O(1)
		}

		void setNext(std::shared_ptr<Node<T>> next) {
			m_next = { next }; // O(1)
		}

		std::shared_ptr<Node<T>> getPrev() {
			return m_prev; // O(1)
		}

		void setPrev(std::shared_ptr<Node<T>> prev) {
			m_prev = { prev }; // O(1)
		}



	private:
		std::shared_ptr<Node<T>> m_prev{ nullptr };
		T m_value{};
		std::shared_ptr<Node<T>> m_next{ nullptr };
	};

	template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList(T value)
		{
			m_node = std::make_shared<Node<T>>(value); // O(1)
		}

		void printList() {
			auto newNode = m_node; // O(1)
			//while (newNode != NULL) { // O(n) {
			//	std::cout << newNode->Node<T>::getValue() << "->"; // O(1)
			//	newNode = newNode->Node<T>::getNext(); // O(1)
			//}

			std::cout << std::endl; // O(1)
		}

		void insertLast(T value) {
			auto head = m_node; // O(1)
			auto nextNode = std::make_shared<Node<T>>(value); // O(1)

			while (head->getNext() != NULL) { // O(n) {
				head = head->Node<T>::getNext(); // O(1)
			}

			head->Node<T>::setNext(nextNode); // O(1)
			nextNode->Node<T>::setPrev(head);
		}

		void insertFront(T value) {
			setHead();
			auto node = m_node; // O(1)
			auto head = std::make_shared<Node<T>>(value); // O(1)

			while (node->getPrev() != NULL) { // O(n) {
				node = node->Node<T>::getPrev(); // O(1)
			}

			node->Node<T>::setPrev(head); // O(1)
			head->Node<T>::setNext(node);
		}


	private:

		void setHead() {
			auto head = m_node;
			while (head->Node<T>::getPrev() != NULL) 
			{
				head = head->Node<T>::getPrev();
			}
			m_node = head;
		}

		std::shared_ptr<Node<T>> m_node{ nullptr };
	};

	void presetRun() {
		auto linkedList = std::make_shared<DoublyLinkedList<int>>(100); // Initializing the linked list with it's first value.

		linkedList->insertLast(200);
		linkedList->insertFront(300);
		//linkedList->insertNode(400);
		//linkedList->insertNode(500);
		//linkedList->insertNode(600);
		//linkedList->insertNode(700);

		linkedList->printList();
	}
}
