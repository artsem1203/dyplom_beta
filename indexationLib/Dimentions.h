#pragma once
#include <array>
#include <type_traits>
#include "Traits.h"

template <size_t N>
class Dimentions
{
public:
	template<typename ...Dims>
	Dimentions(Dims ... dims) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};
		std::initializer_list<size_t> init_list{ size_t(dims)... };

		int counter = 0;
		for (auto i = std::cbegin(init_list); i != std::cend(init_list); i++, counter++) {
			if (counter < sizeof...(Dims))
				dims_[counter] = *i;
			else
				dims_[counter] = 1;
		}
	}

	Dimentions(const Dimentions& dims) {
		dims_ = dims.dims_;
	}

	size_t size_calc() const {
		size_t temp = 1;
		for (auto i = dims_.cbegin(); i != dims_.cend(); i++) {
			temp = temp * (*i);
		}
		return temp;
	}

	template<typename ...Dims>
	size_t position_calc(Dims ...dims) const {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		VariadicTemplate<Dims...> v0{};

		std::initializer_list<size_t> init_list{ size_t(dims)... };

		size_t temp = 0;
		size_t factor = 1;
		size_t counter = N;
		auto el = std::crbegin(init_list);

		for (int i = N-1; i >= 0; --i) {
			if (counter < sizeof...(Dims)) {
				counter--;
			}
			else {
				temp = temp + (*(el++)) * factor;
			}
			factor = factor * dims_[i];
		}
		return temp;
	}

	Dimentions & operator=(const Dimentions& dim) {
		dims_ = dim.dims_;
		return *this;
	}

private:
	std::array<size_t, N> dims_;
};

