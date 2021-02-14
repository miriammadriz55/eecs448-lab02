/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

//added
template <typename T>
int LinkedList<T>::size() const
{
	int count=0;
	Node<T>* temp = m_front;
	while(temp != nullptr)
	{
		count++;
		temp=temp -> getNext();
	}
	return(count);
}

//added
template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	if(temp != nullptr)
	{
		for(int i=0; i < size; i++)
		{
			if(temp->getValue()==value)
			{
				isFound=true;
			}
			temp= temp -> getNext();
		}
	}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	//lastNode to point to the front
	lastNode= m_front;
	//edge case
	if(m_size== 0)
	{
		//returns fasle because it is empty
		return(isRemoved);
	}
	else if(m_size==1)
	{
		secondintoLast = m_front;
		delete secondintoLast;
		m_size--;
		m_front=nullptr;
		isRemoved= true;
		return(isRemoved);
	}
	else
	{
		for(int i=0; i<size; i++)
		{
			//within the same loop update "secondintoLast"
			secondintoLast=LastNode;
			//within a loop used a node function to update last node
			lastNode= lastNode-> getNext();
		}
		//delete last node
		delete lastNode;
		//update m_size
		m_size--;
		isRemoved= true;
		//set next node to nullptr
		secondintoLast-> setNext(nullptr);
		return(isRemoved);
	}
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
