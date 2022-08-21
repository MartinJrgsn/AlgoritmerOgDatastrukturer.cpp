#pragma once
#include <iostream>

template <typename T>
class Node {
public:
	Node(T value)
		:m_value{ value }
	{
		if (!m_next) {
			std::cout << "Node created, value " << m_value << std::endl;
		}
	}

	T getValue() {
		return m_value;
	}

	void setValue(T value) {
		m_value = { value };
	}

	std::shared_ptr<Node<T>> getNext() {
		return m_next;
	}

	void setNext(std::shared_ptr<Node<T>> next) {
		m_next = { next };
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
		:m_value{ value }
	{
		newNode = std::make_shared<Node<T>>(m_value);
		std::cout << "Singly linked list created\nRoot node value: " << newNode->Node<T>::getValue() << std::endl;
	}

	void printList(std::shared_ptr<singlyLinkedList<T>> list) {
		std::cout << std::endl;
	}

	void insertNode(T value) {
		auto nextNode = std::make_shared<Node<T>>(value);
	}

private:
	T m_value;
	std::shared_ptr<Node<T>> newNode{ nullptr };
};

namespace enkeltLenkedeListe {

	void presetRun() {
		auto linkedList = std::make_shared<singlyLinkedList<int>>(100);
		linkedList->insertNode(200);
		linkedList->insertNode(300);

		//auto newNode = std::make_shared<Node<int>>(100);
		/*newNode->setNext(200);
		newNode->setNext(300);*/

		//std::cout << newNode->getValue();
	}
}

