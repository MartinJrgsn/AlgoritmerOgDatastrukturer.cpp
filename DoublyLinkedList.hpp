#pragma once
#include <iostream>

namespace dobbeltLenketListe {
	template <typename T>
	class Node {
		using nodePtr = std::shared_ptr<Node<T>>;
	public:
		Node(const T& data, nodePtr prev, nodePtr next);

		nodePtr getPrev() const;
		T getValue() const;
		nodePtr getNext() const;

		void setNext(nodePtr node);
		void setPrev(nodePtr node);

	private:
		nodePtr m_prev{ nullptr };
		T m_data{};
		nodePtr m_next{ nullptr };
	};

	template<typename T>
	inline dobbeltLenketListe::Node<T>::Node(const T& data, nodePtr prev, nodePtr next)
		:m_data{ data }, m_prev{ prev }, m_next{ next }
	{
		std::cout << "Node constructor called\nValue: " << m_data << std::endl;
	}

	template<typename T>
	inline std::shared_ptr<Node<T>> Node<T>::getPrev() const
	{
		return m_prev;
	}

	template<typename T>
	inline T Node<T>::getValue() const
	{
		return m_data;
	}

	template <typename T>
	inline std::shared_ptr<Node<T>> Node<T>::getNext() const
	{
		return m_next;
	}

	template<typename T>
	inline void Node<T>::setNext(nodePtr node)
	{
		m_next = node;
	}

	template<typename T>
	inline void Node<T>::setPrev(nodePtr node)
	{
		m_prev = node;
	}

	template <typename T>
	class DoublyLinkedList
	{
		using nodePtr = std::shared_ptr<Node<T>>;
	public:
		DoublyLinkedList();

		nodePtr getHead();
		nodePtr getTail();

		void insertHead(T data);
		void insertTail(T data);

		void removeHead();
		void removeTail();

		void printList();

	private:
		nodePtr m_head{};
		nodePtr m_tail{};
	};

	template<typename T>
	inline DoublyLinkedList<T>::DoublyLinkedList()
		:m_head{ nullptr }, m_tail{ nullptr }
	{
		std::cout << "DLL constructor called\n";
	}

	template<typename T>
	inline std::shared_ptr<Node<T>> DoublyLinkedList<T>::getHead()
	{
		return m_head;
	}

	template<typename T>
	inline std::shared_ptr<Node<T>> DoublyLinkedList<T>::getTail()
	{
		return m_tail;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::insertHead(T data)
	{
		m_head = std::make_shared<Node<T>>(data, nullptr, m_head);
		if (m_head->getNext() != nullptr) {
			m_head->getNext()->setPrev(m_head);
		}
		else {
			m_tail = m_head;
		}
	}

	template<typename T>
	inline void DoublyLinkedList<T>::insertTail(T data)
	{
		m_tail = std::make_shared<Node<T>>(data, m_tail, nullptr);
		if (m_tail->getPrev() != nullptr) {
			m_tail->getPrev()->setNext(m_tail);
		}
		else {
			m_head = m_tail;
		}
	}

	template<typename T>
	inline void DoublyLinkedList<T>::printList()
	{
		std::shared_ptr<Node<T>> node = m_head;

		while (node != NULL)
		{
			std::cout << node->Node<T>::getValue() << "<->"; // O(1)
			node = node->Node<T>::getNext();
		}
	}

	void presetRun() {
		auto testingDLL = std::make_shared<DoublyLinkedList<std::string>>();

		testingDLL->insertHead("1");
		testingDLL->insertHead("2");
		testingDLL->insertTail("3");
		testingDLL->insertTail("4");

		testingDLL->printList();
	}
}