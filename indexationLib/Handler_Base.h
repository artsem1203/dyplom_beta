#pragma once
#include <iostream>

template<class DERIVED>
class Handler_Base {
public:

	const DERIVED & derived() const {
		return static_cast<const DERIVED &> (*this);
	}

	DERIVED& derived() {
		return static_cast<DERIVED &> (*this);
	}

};
