#pragma once
#include <iostream>

namespace DobbeltLenketListe {

	//DLL Node:

	template <typename T>
	class Node {
		using nodePtr = std::shared_ptr<Node<T>>;
	public:
		Node(const T& value, nodePtr prev, nodePtr next);
		T getValue() const;
		nodePtr getNext() const;
		nodePtr getPrev() const;

	private:
		nodePtr m_prev{ nullptr };
		T m_value{};
		nodePtr m_next{ nullptr };
	};

	template<typename T>
	inline DobbeltLenketListe::Node<T>::Node(const T& value, nodePtr prev, nodePtr next)
		:m_value{ value }, m_prev{ prev }, m_next{ next }
	{
		std::cout << "Node constructor called\n";
	}

	template<typename T>
	inline T Node<T>::getValue() const
	{
		return m_value;
	}

	template <typename T>
	inline std::shared_ptr<Node<T>> Node<T>::getNext() const
	{
		return m_next;
	}

	template<typename T>
	inline std::shared_ptr<Node<T>> Node<T>::getPrev() const
	{
		return m_prev;
	}

	// Doubly Linked List












	template <typename T>
	class DoublyLinkedList
	{
		using nodePtr = std::shared_ptr<Node<T>>;
	public:
		DoublyLinkedList();

		void insertHead(T data);
		void insertTail(T data);

		void removeTail();

		T getHead();
		T getTail();

	private:

		nodePtr m_head{};
		nodePtr m_tail{};
	};

	void presetRun() {
		std::cout << "newTEST\n";
		auto DLL = std::make_shared<DoublyLinkedList<T>>();

		std::cout << "Testing doubly\n";
	}
}





















/*
		void printList() {
			auto newNode = m_node; // O(1)
			//while (newNode != NULL) { // O(n) {
			//	std::cout << newNode->Node<T>::getValue() << "->"; // O(1)
			//	newNode = newNode->Node<T>::getNext(); // O(1)
			//}

			std::cout << std::endl; // O(1)
		}

		void insertHead(T value) {
			setHead();
			auto node = m_node; // O(1)
			auto head = std::make_shared<Node<T>>(value); // O(1)

			while (node->getPrev() != NULL) { // O(n) {
				node = node->Node<T>::getPrev(); // O(1)
			}

			node->Node<T>::setPrev(head); // O(1)
			head->Node<T>::setNext(node);
		}

		void insertTail(T value) {
			auto head = m_node; // O(1)
			auto nextNode = std::make_shared<Node<T>>(value); // O(1)

			while (head->getNext() != NULL) { // O(n) {
				head = head->Node<T>::getNext(); // O(1)
			}

			head->Node<T>::setNext(nextNode); // O(1)
			nextNode->Node<T>::setPrev(head);
		}

		//	auto linkedList = std::make_shared<DoublyLinkedList<int>>(100); // Initializing the linked list with it's first value.

	//	linkedList->insertLast(200);
	//	linkedList->insertFront(300);
	//	//linkedList->insertNode(400);
	//	//linkedList->insertNode(500);
	//	//linkedList->insertNode(600);
	//	//linkedList->insertNode(700);

	//	linkedList->printList();
*/