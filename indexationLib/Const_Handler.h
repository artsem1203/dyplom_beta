#pragma once
#include "Dimentions.h"
#include "Handler_Base.h"
#include "Traits.h"

template<typename T, size_t N>
class Handler;

template<typename T, size_t N>
class Const_Handler;

template<typename T, size_t N>
class Const_Handler : private Handler_Base<Handler<T, N>>
{
public:

	Const_Handler() = delete;

	template<typename ...Dims>
	Const_Handler(const T* memr_pointer, Dims ... dims) : dims_(dims...), 
		memory_pointer(memr_pointer) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
	}

	Const_Handler(const T* memr_pointer, Dimentions<N> dims) : dims_(dims), memory_pointer(memr_pointer) {};

	size_t size_calc() const {
		return dims_.size_calc();
	}

	void show() const {
		for (int i = 0; i < this->size_calc(); i++) {
			std::cout << *(memory_pointer + i) << std::endl;
		}
	}
	/*
	const Handler<T, N> get_handler() {
		return Handler<T, N>(memory_pointer, dims_);
	}
	*/
	template<typename ...Dims>
	const T* get_element(Dims ... dims) const {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
		return (memory_pointer + dims_.position_calc(dims...));
	}
	
	const Handler_Base<Handler<T, N>> * operator ->() const {
		return this;
	}

	const Handler_Base<Handler<T, N>> & operator *() const {
		return *this;
	}
	
	const T* get_pointer() const {
		return memory_pointer;
	}

private:

	const T* memory_pointer;
	Dimentions<N> dims_;
};
