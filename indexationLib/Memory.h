#pragma once
#include <iostream>
template<typename T>
class Memory {
public:

	Memory() = delete;

	Memory(size_t chunk_size) : size_(chunk_size) {
		memory_pointer_ = new T[size_];
	}
	~Memory() {
		delete[] memory_pointer_;
	}

	void add_value(T val) {
		memory_pointer_[counter_++] = val;
	}

	T* get_pointer(size_t element_number) {
		return &memory_pointer_[element_number];
	}

	const T* get_pointer(size_t element_number) const {
		return &memory_pointer_[element_number];
	}

	Memory(const Memory& temp_mem) {
		memory_pointer_ = temp_mem.memory_pointer_;
	}

	Memory(const T& memory_pointer) {
		memory_pointer_ = memory_pointer;
	}

	void show() const {
		for (size_t i = 0; i < size_; i++) {
			std::cout << memory_pointer_[i] << std::endl;
		}
	}

	

	Memory operator=(const Memory& temp_mem) {
		return Memory(temp_mem.memory_pointer_);
	}

private:
	T* memory_pointer_;
	size_t size_;
	size_t counter_ = 0;
};
