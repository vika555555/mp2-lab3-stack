#pragma once

#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 100000000;

template <typename T>
class TStack {
private:
	int top_i, size;
	T* pMem;
public:
	TStack(int s = 10) {
		size = s;
		if (size <= 0)
			throw out_of_range("Stack size should be greater than zero");
		if (size >= MAX_STACK_SIZE)
			throw out_of_range("Stack size should be less than MaxSize");
		pMem = new T[size];
		top_i = -1;
	}

	TStack(const TStack& s) {
		size = s.size;
		top_i = s.top_i;
		pMem = new T[size];
		for (int i = 0; i <= top_i; i++) {
			pMem[i] = s.pMem[i];
		}
	}

	TStack(TStack&& s) noexcept{
		size = s.size;
		top_i = s.top_i;
		pMem = s.pMem;
		s.size = 0;
		s.top_i = -1;
		s.pMem = nullptr;
	}

	~TStack() {
		delete[] pMem;
		pMem = nullptr;
		top_i = -1;
		size = 0;
	}

	TStack& operator=(const TStack& s) {
		if (this != &s) {
			if (size != s.size) {
				size = s.size;
				delete[] pMem;
				pMem = new T[size];
			}top_i = s.top_i;
		}for (int i = 0; i <= top_i; i++) {
			pMem[i] = s.pMem[i];
		}return *this;
	}

	TStack& operator=(TStack&& s) noexcept {
		if (this != &s) {
			delete[] pMem; 
			size = s.size;   
			top_i = s.top_i;
			pMem = s.pMem;   
			s.size = 0;
			s.top_i = -1;
			s.pMem = nullptr;
		}
		return *this;
	}

	bool operator==(const TStack& s) const {
		if (size != s.size) return 0;
		if (top_i != s.top_i) return 0;
		for (int i = 0; i <= top_i; i++) {
			if (pMem[i] != s.pMem[i]) return 0;
		}
		return 1;
	}

	bool operator !=(const TStack& s) const {
		return !(*this == s);
	}

	bool IsFull() const {
		return top_i == size - 1;
	}
	bool IsEmpty() const {
		return top_i == -1;
	}

	void push(T el) {
		if (IsFull()) throw "Stack is full";
		else {
			top_i++;
			pMem[top_i] = el;
		}
	}

	T pop() {
		if (IsEmpty()) throw "Stack is empty";
		else return pMem[top_i--];
	}

	T top() const {
		if (IsEmpty()) throw "Stack is empty";
		return pMem[top_i];
	}

	void Clr() { top_i = -1; }
};