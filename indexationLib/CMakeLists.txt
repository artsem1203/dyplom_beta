project(indexationLib)

set(indexationLib_Src
	Data.h
	Data.cpp
	Dimentions.h
	Dimentions.cpp
	Handler.h
	Handler.cpp
	Memory.h
	Memory.cpp
	Const_Handler.h
	Const_Handler.cpp
	Handler_Base.h
	Handler_Base.cpp
	Traits.h
	Traits.cpp
)

add_library(indexationLib ${indexationLib_Src})