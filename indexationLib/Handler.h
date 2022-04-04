#pragma once
#include "Dimentions.h"
#include "Memory.h"
#include "Const_Handler.h"
#include "Traits.h"

template<typename T, size_t N>
class Handler : private Handler_Base<Handler<T, N>>
{
public:

	//Handler() = delete;
	Handler() {};
	template<typename ...Dims>
	Handler(T* memr_pointer, Dims ... dims) : dims_(dims...), memory_pointer(memr_pointer) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
	}

	Handler(T* memr_pointer, Dimentions<N> dims) : dims_(dims), memory_pointer(memr_pointer) {};

	Handler(const Handler_Base& handl) {
		memory_pointer = handl.derived().memory_pointer;
		dims_ = handl.derived().dims_;
	}

	const Handler & operator =(const Handler_Base &handl) const {
		memory_pointer = handl.derived().memory_pointer;
		dims_ = handl.derived().dims_;
		return *this;
	}

	size_t size_calc() const {
		return dims_.size_calc();
	}

	void show() const {
		for (int i = 0; i < this->size_calc(); i++) {
			std::cout << *(memory_pointer + i) << std::endl;
		}
	}

	template<typename ...Dims>
	T* get_element(Dims ... dims) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
		return (memory_pointer + dims_.position_calc(dims...));
	}

	template<typename ...Dims>
	const T* get_element(Dims ... dims) const {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
		return (memory_pointer + dims_.position_calc(dims...));
	}

	Const_Handler<T, N> get_const_handler() const {
		return Const_Handler<T, N>(memory_pointer, dims_);
	}

	Handler_Base<Handler<T, N>>* operator ->() {
		return this;
	}

	Handler_Base<Handler<T, N>>& operator *() {
		return *this;
	}

	const T* get_pointer() const {
		return memory_pointer;
	}
	
	T* get_pointer() {
		return memory_pointer;
	}

private:
	mutable T* memory_pointer;
	mutable Dimentions<N> dims_;
	//Memory<T> memr_;
};

