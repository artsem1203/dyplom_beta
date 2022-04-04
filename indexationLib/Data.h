#pragma once
#include <array>
#include "Memory.h"
#include "Dimentions.h"
#include "Traits.h"
#include "Const_Handler.h"
#include "Handler.h"

template<typename T, size_t N>
class Data {
public:

	Data() = delete;

	template<typename ...Dims>
	Data(Dims ... dims): dims_(dims...), memr_(dims_.size_calc()) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
	}

	size_t size_calc() const {
		return dims_.size_calc();
	}

	void init(const std::initializer_list<T> init_list) {
		for (auto i = std::cbegin(init_list); i != std::cend(init_list); i++) {
			memr_.add_value(*i);
		}
	}

	template<typename Tx, size_t Dims_num, typename ...Dims>
	Handler<Tx, Dims_num> get_handler(T* memr_pointer, Dims ...dims) {
		static_assert(sizeof...(Dims) <= Dims_num, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};

		return Handler<Tx, Dims_num>(memr_pointer, dims...);
	}

	template<typename Tx, size_t Dims_num, typename ...Dims>
	Const_Handler<Tx, Dims_num> get_const_handler(const T* memr_pointer, Dims ...dims) const {
		static_assert(sizeof...(Dims) <= Dims_num, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};

		return Const_Handler<Tx, Dims_num>(memr_pointer, dims...);
	}

	template<typename ...Dims>
	T* get_element(Dims ... dims) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
		return memr_.get_pointer(dims_.position_calc(dims...));
	}

	template<typename ...Dims>
	const T* get_element(Dims ... dims) const {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
		return memr_.get_pointer(dims_.position_calc(dims...));
	}

	void show() {
		this->memr_.show();
	}
private:
	Dimentions<N> dims_;
	Memory<T> memr_;
};

