#pragma once

#include <iostream>
#include <algorithm>

using namespace std;
using std::copy;

template <typename T>
class Vector
{
public:

	//default constructor
	Vector();

	//overloaded constructor
	Vector(int s);

	//destructor
	~Vector();

	// copy constructor
	Vector(const Vector &otherVector);

	// copy assignment
	const Vector<T>& operator=(const Vector<T> &otherVector);

	//overloading the []
	const T& operator[](int n)const;

	//returns the size of the vector
	int size() const;

	//returns the capacity
	int capacity() const;

	//increase the Vector_capacity
	void reserve(int newalloc);

	// make the vector have newsize elements
	void resize(int newsize);

	// add one element to the back of the vector
	void push_back(double d);


	template <typename T>
	using iterator = T * ;

	template <typename T>
	using const_iterator = const T *;

	template <typename T>
	iterator<T> begin() // points to first element
	{
		if (size_v == 0)
			return nullptr;
		return &elem[0];
	}

	template <typename T>
	const_iterator<T> begin() const
	{
		if (size_v == 0)
			return nullptr;
		return &elem[0];
	}

	template <typename T>
	iterator<T> end() // points to one beyond the last element
	{
		if (size_v == 0)
			return nullptr;
		return &elem[size_v];
	}

	template <typename T>
	const_iterator<T> end() const
	{
		if (size_v == 0)
			return nullptr;
		return &elem[size_v];
	}

	template <typename T>
	iterator<T> insert(iterator<T> p, const double &val) // insert a new element val before p
	{
		// make sure we have space

		// the place to put value

		// copy element one position to the right
		// insert value

		return nullptr; // temp remove & replace
	}

	template <typename T>
	iterator<T> erase(iterator<T> p) // remove element pointed to by p
	{
		if (p == end())
			return p;
		for (iterator pos = p + 1; pos != end(); ++pos)
			*(pos - 1) = *pos; // copy element one position to the left
		//delete (end() - 1);
		--size_v;
		return p;
	}

private:
	
	int size_v;                // the size
	int vectorCapacity;        // number of elements plus number of free slots
	T *elem;
};

template <typename T>
Vector<T>::Vector()
{
	size_v = 0;
	vectorCapacity = 0;
	elem = nullptr;
}

template <typename T>
Vector<T>::Vector(int s)
{
	size_v = s;
	vectorCapacity = s;
	elem = new T[size_v];

	for (int i = 0; i < size_v; i++)
	{
		elem[i] = T{};
	}
	
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}

template <typename T>
Vector<T>::Vector(const Vector &otherVector)
{
	size_v = otherVector.size_v;
	elem = new T[otherVector.size_v]; 
	vectorCapacity = otherVector.vectorCapacity;
	copy(otherVector.elem, otherVector.elem + size_v, elem); // copy elements - std::copy() algorithm
}



template<typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T> &otherVector) // copy assignment
{
	double *p = new double[otherVector.size_v];       // allocate new space
	copy(otherVector.elem, otherVector.elem + otherVector.size_v, p); // copy elements - std::copy() algorithm
	delete[] elem;                            // deallocate old space
	elem = p;                                 // now we can reset elem
	size_v = otherVector.size_v;
	return *this;                             // return a self-reference
}

template<typename T>
const T &Vector<T>::operator[](int n) const 
{
	return elem[n];
}

template <typename T>
int Vector<T>::size() const 
{
	return size_v;
}

template <typename T>
int Vector<T>::capacity() const 
{
	return vectorCapacity;
}

template <typename T>
void Vector<T>::reserve(int newalloc)
{
	int newCapacity;
	T *temp;
	// never decrease allocation

	newCapacity = (vectorCapacity / 2) + vectorCapacity;
	vectorCapacity = newCapacity;

	// allocate new space
	temp = new T[size_v];
	for (int i = 0; i < size_v; i++)
	{
		temp[i] = elem[i];
	}

	delete[] elem;
	elem = new T[vectorCapacity];
	// copy old elements
	for (int i = 0; i < vectorCapacity; i++)
	{
		elem[i] = temp[i];
	}
	// deallocate old space
	delete[] temp;
}

template<typename T>
void Vector<T>::resize(int newsize) // growth
	                                // make the vector have newsize elements
	                                // initialize each new element with the default value 0.0
{
	reserve(newsize);
	for (int i = size_v; i < newsize; ++i)
		elem[i] = 0; // initialize new elements
	size_v = newsize;
}

template <typename T>
void Vector<T>::push_back(double d)
// increase vector size by one; initialize the new element with d
{
	if (vectorCapacity == 0)
		reserve(8);         // start with space for 8 elements
	else if (size_v == vectorCapacity)
		reserve(2 * vectorCapacity); // get more space
	elem[size_v] = d;       // add d at end
	++size_v;               // increase the size (size_v is the number of elements)
}




