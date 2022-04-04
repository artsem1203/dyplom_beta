#include "gtest/gtest.h"
#include "../indexationLib/Data.h"

TEST(GetterTestCase, DataTest) {

	Data<int, 5> data(3, 3, 3, 3, 3);
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });

	EXPECT_EQ(*data.get_element(0, 0, 0, 1, 2), 98);
	EXPECT_EQ(*data.get_element(0, 0, 0, 2, 2), 36);
	EXPECT_EQ(*data.get_element(0, 0, 0, 2), 23);
}

TEST(GetterTestCase, Const_HandlerTest) {
	Data<int, 5> data(3, 3, 3);
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36});
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });

	Const_Handler<int, 2> ch = data.get_const_handler<int, 2>(data.get_element(1, 1), 3, 3);
	
	EXPECT_EQ(*ch.get_element(0, 0), 8);
	EXPECT_EQ(*ch.get_element(1, 1), 36);
}

TEST(GetterTestCase, HandlerTest) {
	Data<int, 5> data(3, 3, 3);
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });

	Const_Handler<int, 2> ch = data.get_const_handler<int, 2>(data.get_element(1, 1), 3, 3);

	EXPECT_EQ(*ch.get_element(0, 1), 98);
	EXPECT_EQ(*ch.get_element(2, 1), 34);
}

TEST(LogicTestCase, Const_to_handleTest) {
	Data<int, 5> data(3, 3, 3);
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });

	Const_Handler<int, 2> ch = data.get_const_handler<int, 2>(data.get_element(1, 1), 3, 3);
	const Handler<int, 2> h;
	h = *ch;

	EXPECT_EQ(*ch.get_element(1, 1), *h.get_element(1, 1));
	EXPECT_EQ(*ch.get_element(0, 1), *h.get_element(0, 1));
}

TEST(LogicTestCase, Handle_to_constTest) {
	Data<int, 5> data(3, 3, 3);
	data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });
	//data.init({ 4, 45, 34, 3, 8 , 98, 23, 76, 36 });

	Handler<int, 2> h = data.get_handler<int, 2>(data.get_element(1, 1), 3, 3);
	Const_Handler<int, 2> ch = h.get_const_handler();

	EXPECT_EQ(*ch.get_element(1, 1), *h.get_element(1, 1));
	EXPECT_EQ(*ch.get_element(0, 1), *h.get_element(0, 1));
}



