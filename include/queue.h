﻿#pragma once

#include <iostream>

const size_t MAX_VECTOR_SIZE = 100000000;

template <class T>

class Vector
{
protected:
	T* data;
	size_t vsize;
	size_t vcapacity;
public:

	// конструктор по умолчанию
	Vector()
	{
		data = NULL;
		vsize = 0;
		vcapacity = 0;
	}

	// конструктор с параметром
	Vector(size_t n)
	{
		if ((n >= 0) && (n <= MAX_VECTOR_SIZE))
		{
			data = new T[n];
			vsize = n;
			vcapacity = n;
			for (size_t i = 0; i < n; i++)
				data[i] = 0;
		}
		else throw "Incorrect size of vector!";
	}

	// конструктор копирования
	Vector(const Vector& v)
	{
		data = new T[v.vsize];
		size = v.vsize;
		vcapacity = v.vcapacity;
		for (size_t i = 0; i < size; i++)
			data[i] = v.data[i];
	}

	// деструктор
	~Vector()
	{
		if (data != NULL)
		{
			delete[] data;
			data = NULL;
		}
		vsize = 0;
		vcapacity = 0;
	}

	// количество элеметов в векторе
	size_t size()
	{
		return vsize;
	}

	//  количество элементов, которое может содержать вектор до того, как ему потребуется выделить память
	size_t capacity()
	{
		return vcapacity;
	}

	// вставка элемента в конец вектора
	void push_back(const T& Elem)
	{
		if (vsize + 1 <= MAX_VECTOR_SIZE)
		{
			if (vsize >= vcapacity)
			{
				vcapacity = 1.3 * vsize + 1;
				T* b = new T[vcapacity];
				for (size_t i = 0; i < vsize; i++)
					b[i] = data[i];
				if (data != NULL)
					delete[] data;
				data = b;
			}
			data[vsize++] = Elem;
		}
		else throw "Impossible to push back";
	}

	// удаление последниего элемента вектора
	void pop_back()
	{
		if (vsize != 0)
		{
			vsize--;
		}
		else throw "Impossible to pop back!";
	}

	// вставка элемента в вектор
	void insert(const T& Elem, const size_t index)
	{
		if ((index >= 0) && (index < vsize))
			if (vsize + 1 > vcapacity)
			{
				vcapacity = 1.3 * vsize + 1;
				T* b = new T[vcapacity];
				size_t i;
				for (size_t i = 0; i < index; i++)
					b[i] = data[i];
				b[index] = Elem;
				for (i = index; i < vsize; i++)
					b[i + 1] = data[i];
				if (data != NULL)
					delete[] data;
				data = b;
				vsize++;
			}
			else
			{
				for (size_t i = vsize; i >= index; i--)
					data[i] = data[i - 1];
				data[index] = Elem;
				vsize++;
			}
		else throw "Incorrect index!";
	}

	// удаление элемента вектора
	void erase(const size_t index)
	{
		if ((index >= 0) && (index < vsize))
		{
			for (size_t i = index + 1; i < vsize; i++)
				data[i - 1] = data[i];
			vsize--;
		}
		else throw "Incorrect index!";
	}

	// вставка элемента в начало вектора
	void push_front(const T& Elem)
	{
		if (vsize + 1 <= MAX_VECTOR_SIZE)
		{
			insert(Elem, 0);
		}
		else throw "Impossible to push front!";
	}

	// удаление элемента из начала вектора
	void pop_front()
	{
		if (vsize != 0)
		{
			erase(0);
		}
		else throw "Impossible to pop front!";
	}

	// изменение размера вектора на заданную величину
	void resize(const size_t n)
	{
		if (n <= MAX_VECTOR_SIZE)
		{
			T* b = new T[n];
			size_t i;
			if (n > vsize)
			{
				for (i = 0; i < vsize; i++)
					b[i] = data[i];
				for (i = vsize; i < n; i++)
					b[i] = 0;
			}
			else
				for (i = 0; i < n; i++)
					b[i] = data[i];
			if (data != NULL)
				delete[] data;
			data = b;
			vsize = n;
			vcapacity = n;
		}
		else throw "Too big size of vector!";
	}

	// доступ к элементу вектора
	T& operator[](const size_t index)
	{
		if ((index >= 0) && (index < vsize))
			return data[index];
		else throw "Incorrect index!";
	}

	T operator[](const size_t index) const
	{
		if ((index >= 0) && (index < vsize))
			return data[index];
		else throw "Incorrect index!";
	}
};

template <class T>

class Stack : public Vector<T>
{
public:
	// конструктор по умолчанию
	Stack() : Vector() {};

	// конструктор с параметром
	Stack(size_t n) : Vector(n) {};

	// конструктор копирования
	Stack(const Stack& s) : Vector(s) {};

	// получение верхнего элемента стека
	virtual T top()
	{
		if (vsize != 0)
			return data[vsize - 1];
		else throw "Stack is empty!";
	}

	// запись в стек
	virtual void push(const T& Elem)
	{
		Vector<T>::push_back(Elem);
	}

	// удаление из стека
	virtual void pop()
	{
		Vector<T>::pop_back();
	}

	// проверка стека на пустоту
	bool empty()
	{
		if (vsize == 0)
			return true;
		else
			return false;
	}

	// проверка стека на заполненность
	bool full()
	{
		if (vsize == vcapacity)
			return true;
		else
			return false;
	}

	//Получение минимального элемента стека
	T get_min()
	{
		Stack<T> min_stack (vsize);
		T min = *data;
		min_stack.push(*data);
		for (size_t i = 1; i < vsize; i++)
			if (*(data + i) < min)
				min = *(data + i);
		min_stack.push(min);
		return min;
	}
};

template <class T>

class Queue : public Vector<T>
{
protected:
	T* Hi;
	T* Li;
public:
	// конструктор по умолчанию
	Queue() : Vector()
	{
		Hi = NULL;
		Li = NULL;
	}

	// конструктор с параметром
	Queue(size_t n) : Vector(n)
	{
		Hi = data;
		Li = data + vsize - 1;
	}

	// конструктор копирования
	Queue(const Queue& q) : Vector(q)
	{
		Hi = s.Hi;
		Li = s.Li;
	}

	// получение первого элемента очереди
	T front()
	{
		if (vsize != 0)
			return *Hi;
		else throw "Queue is empty!";
	}
	// получение последнего элемента очереди
	T back()
	{
		if (vsize != 0)
			return *Li;
		else throw "Queue is empty!";
	}

	// добавление элемента в конец очереди
	void push(const T& Elem)
	{
		if (vsize + 1 <= MAX_VECTOR_SIZE)
		{
			if (this->full())
			{
				size_t ncapacity = 1.3 * vcapacity + 1;
				size_t Hd = Hi - data;
				size_t i;
				size_t counter = 0;
				vcapacity = ncapacity;
				T* b = new T[vcapacity];
				for (i = Hd; i < vcapacity; i++)
					b[counter++] = data[i];
				if (Hi != data)
					for (i = 0; i < Hd; i++)
						b[counter++] = data[i];
				delete[] data;
				data = b;
				Hi = data;
				Li = data + vsize - 1;
			}
			if (Li == data + vcapacity - 1)
				Li == data;
			else
				Li++;
			*Li = Elem;
			vsize++;
		}
		else throw "The memory is end!";
	}

	// извлечение элемента из начала очереди
	void pop()
	{
		if (vsize != 0)
		{
			if (Hi == data + vcapacity - 1)
				Hi = data;
			else
				Hi++;
			vsize--;
		}
		else throw "Queue is empty!";
	}

	// проверка очереди на пустоту
	bool empty()
	{
		if (vsize == 0)
			return true;
		else
			return false;
	}

	// проверка очереди на заполненность
	bool full()
	{
		if (((Hi == data) || (Hi == Li + 1)) && (vsize == vcapacity))
			return true;
		else
			return false;
	}
};