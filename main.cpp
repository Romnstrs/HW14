
#include <iostream>

class MyVector {
	MyVector(const MyVector&) = delete;
	MyVector operator=(const MyVector&) = delete;
public:
	MyVector(const unsigned s = 10, const int valueByDefault = 0) {
		m_size = s;
		data = new int[m_size];
		for (unsigned int i = 0; i < m_size; ++i)
		{
			data[i] = valueByDefault;
		}
	}

	~MyVector() {
		clear();
	}
	
	void clear() {
		if (data) {
			delete[] data;
		data = nullptr;
		}
	}

	int& operator[](const unsigned index) {
		return data[index];
	}

	void push_back(const unsigned s, const int newValue) {
		MyVector copy;
		copy.clear();
		copy.m_size = m_size + 1;
		copy.data = new int[copy.m_size];
		for (unsigned int i = 0; i < m_size; ++i)
		{
			copy.data[i] = 0;
		}
		copy_vector(copy.data, data, s);
		copy[s] = newValue;
		clear();
		data = copy.data;
	}

	void copy_vector(int*& to, const int* from, const unsigned size) {
		for (unsigned int i = 0; i < size; ++i)
		{
			to[i] = from[i];
		}
	}

	unsigned getSize() {
		return m_size;
	}

	int* getData() {
		return data;
	}

private:
	unsigned m_size = 0;
	int* data = nullptr;
};

void create_vector(int*& vec, const unsigned size, const int valueByDefault = 0);
int* create_vector(const unsigned size, const int valueByDefault = 0);
void delete_vector(int* vec);
void push_back_in_vector(int*& vec, const unsigned size, const int newValue);
void copy_vector(int*& to, const int* from, const unsigned size);
int& at_vector(int* const vec, const unsigned index);

void swap_items(int& a, int& b);
void swap_items(int* const a, int* const b);
void swap_items(int* const vec, const unsigned aIndex, const unsigned bIndex);


void create_vector(int*& vec, const unsigned size, const int valueByDefault) {
	if (vec) {
		delete[] vec;
	}
	vec = new int[size];
	for (unsigned int i = 0; i < size; ++i)
	{
		vec[i] = valueByDefault;
	}
}

int* create_vector(const unsigned size, const int valueByDefault) {
	int* vec = new int[size];
	for (unsigned int i = 0; i < size; ++i)
	{
		vec[i] = valueByDefault;
	}
	return vec;
}

void delete_vector(int* vec) {
	if (vec) {
		delete[] vec;
		vec = nullptr;
	}
}

void push_back_in_vector(int*& vec, const unsigned size, const int newValue) {
	int* copy = create_vector(size + 1);
	copy_vector(copy, vec, size);
	copy[size] = newValue;
	delete_vector(vec);
	vec = copy;
}

void copy_vector(int*& to, const int* from, const unsigned size) {
	for (unsigned int i = 0; i < size; ++i)
	{
		to[i] = from[i];
	}
}

int& at_vector(int* const vec, const unsigned index) {
	return vec[index];
}

void swap_items(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_items(int* const a, int* const b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_items(int* const vec, const unsigned aIndex, const unsigned bIndex) {
	int& a = at_vector(vec, aIndex);
	int& b = at_vector(vec, bIndex);
	swap_items(a, b);
}


int main() {
	MyVector dyVector;
}