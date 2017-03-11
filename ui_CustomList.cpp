#include "gtest\gtest.h"
#include <exception>
#include "ui_CustomList.h"

TEST_F(ui_CustomList, should_pass_if_constructor_with_value_work)
{
	int value_to_insert = 3;
	CustomList test(value_to_insert);
	ASSERT_EQ(value_to_insert, test.GetFirstValue());
	ASSERT_EQ(1, test.Size());

}


TEST_F(ui_CustomList, should_pass_if_AddFirst_add_one_new_node_to_first_list_root)
{
	int value_to_insert = 3;
	ASSERT_TRUE(sut.AddFirst(value_to_insert));
	ASSERT_EQ(value_to_insert, sut.GetFirstValue());
	ASSERT_EQ(1, sut.Size());

}


TEST_F(ui_CustomList, should_pass_if_AddFirst_add_new_node_to_first_list_root)
{
	int value_to_insert = 3;
	int should_be_on_root = 5;

	ASSERT_TRUE(sut.AddFirst(value_to_insert));
	ASSERT_TRUE(sut.AddFirst(should_be_on_root));
	ASSERT_EQ(should_be_on_root, sut.GetFirstValue());
	ASSERT_EQ(2, sut.Size());

}

TEST_F(ui_CustomList, should_pass_when_we_can_delete_first_element_in_list_with_one_element)
{
	int value_to_insert = 3;
	ASSERT_TRUE(sut.AddFirst(value_to_insert));
	ASSERT_TRUE(sut.DeleteByValue(value_to_insert));
	ASSERT_EQ(0, sut.Size());
}

TEST_F(ui_CustomList, should_pass_when_delete_first_element_in_list)
{
	int value_to_insert = 3;
	ASSERT_TRUE(sut.AddFirst(value_to_insert));
	ASSERT_TRUE(sut.AddFirst(value_to_insert));
	ASSERT_TRUE(sut.DeleteByValue(value_to_insert));
	ASSERT_EQ(value_to_insert, sut.GetFirstValue());
	ASSERT_EQ(1, sut.Size());
}

TEST_F(ui_CustomList, should_pass_when_delete_secound_element_in_list)
{
	int value_to_insert = 3;
	int value_to_insert2 = 33;
	int value_to_insert3 = 34;
	ASSERT_TRUE(sut.AddFirst(value_to_insert));
	ASSERT_TRUE(sut.AddFirst(value_to_insert2));
	ASSERT_TRUE(sut.AddFirst(value_to_insert3));
	ASSERT_TRUE(sut.DeleteByValue(value_to_insert2));
	ASSERT_EQ(value_to_insert3, sut.GetFirstValue());
	ASSERT_EQ(2, sut.Size());

}