#include "stdafx.h"
#include "CppUnitTest.h"
#include "E:\Вера\учёба\АиСД\4 семестр\Map_RB_tree\Map_RB_tree\Map.h"
#include "E:\Вера\учёба\АиСД\4 семестр\Map_RB_tree\Map_RB_tree\Errors.h"
#include "E:\Вера\учёба\АиСД\4 семестр\Map_RB_tree\Map_RB_tree\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Map_tests
{
	TEST_CLASS(get_size)
	{
		map_rb_tree<int, char> map;
		list<int> keys_list;
		list<char> values_list;
	public:
		TEST_METHOD(empty_map)
		{ // map is empty, get_size() must return 0
			size_t size;
			Assert::AreEqual(size_t(0), map.get_size());
		}
		TEST_METHOD(one_element)
		{// map has 1 element, get_size() must return 1
			map.insert(8, 'a');
			Assert::AreEqual(size_t(1), map.get_size());
		}
		TEST_METHOD(two_elements)
		{// map has 2 element, get_size() must return 2
			map.insert(7, 'a');
			map.insert(5, 'q');
			Assert::AreEqual(size_t(2),map.get_size());
		}
	};

	TEST_CLASS(is_empty)
	{
		map_rb_tree<int, char> map;
		list<int> keys_list;
		list<char> values_list;
	public:
		TEST_METHOD(empty_map)
		{ // map is empty, is_empty() must return true
			Assert::AreEqual(true, map.is_empty());
		}
		TEST_METHOD(one_element)
		{// map has 1 element, is_empty() must return false
			map.insert(7, 'a');
			Assert::AreEqual(false, map.is_empty());
		}
		TEST_METHOD(two_elements)
		{// map has 2 elements, is_empty() must return false
			map.insert(7, 'a');
			map.insert(4, 'l');
			Assert::AreEqual(false, map.is_empty());
		}
	};

	TEST_CLASS(clear)
	{
		map_rb_tree<int, char> map;
		list<int> keys_list;
		list<char> values_list;
	public:
		TEST_METHOD(is_size_right_after_clear)
		{ // map has 1 element, after clear() get_size() must return 0 
			map.insert(7, 'a');
			map.clear();
			Assert::AreEqual(size_t(0), map.get_size());
		}
		TEST_METHOD(is_empty_after_clear)
		{// map has 2 elements, after clear() is_empty() must return true 
			map.insert(7, 'a');
			map.insert(8, 'q');
			map.clear();
			Assert::AreEqual(true, map.is_empty());
		}
	};

	TEST_CLASS(insert)
	{
		map_rb_tree<int, char> map;
		list<int> keys_list;
		list<char> values_list;
	public:
		TEST_METHOD(key_already_exists)
		{ // must catch Key_already_exists error
			map.insert(7, 'a');
			try
			{
				map.insert(7, 'q');
			}
			catch (Key_already_exists error)
			{
				error.what();
			}
		}
		TEST_METHOD(two_elements_is_size_right)
		{ // get_size() must return 2
			map.insert(7, 'a');
			map.insert(1, 'z');
			Assert::AreEqual(size_t(2), map.get_size());
		}
		TEST_METHOD(is_map_not_empty_after)
		{// is_empty() must return false
			map.insert(7, 'a');
			Assert::AreEqual(false, map.is_empty());
		}
		TEST_METHOD(is_root_correct)
		{// 5 must become a root. get_keys returns root last so it'll be 3rd at keys_list
			map.insert(7, 'a');
			map.insert(5, 'c');
			map.insert(3, 'b');
			keys_list = *map.get_keys();
			Assert::AreEqual(5, keys_list.at(3));
		}
	};

	TEST_CLASS(get_keys)
	{
		list<int> keys_list;
		map_rb_tree<int, char> map;
		
	public:
		TEST_METHOD(map_has_1_element_is_keys_list_not_empty)
		{//get_keys must return list with 1 element, is_empty() mist return false
			map.insert(4, 'a');
			keys_list = *map.get_keys();
			Assert::AreEqual(false, keys_list.is_empty());
		}
		TEST_METHOD(empty_map_is_keys_list_empty)
		{//get_keys must return empty list , is_empty() mist return true
			keys_list =* map.get_keys();
			Assert::AreEqual(true, keys_list.is_empty());
		}
		TEST_METHOD(map_has_2_elements_is_size_of_keys_list_right)
		{ // get_keys() must return list with 2 elements, get_size() must return 2
			map.insert(4, 'a');
			map.insert(5, 'a');
			keys_list = *map.get_keys();
			Assert::AreEqual(2, keys_list.get_size());
		}
		TEST_METHOD(are_keys_right)
		{// keys_list must have elements in order like in keys[]
			int keys[] = { 0,2,1,4,7,6,5,3 };
			for (int i = 0; i < 8; i++)
			{
				map.insert(i, 'a' + i);
			}
			keys_list = *map.get_keys();
			for (int i = 0; i < 8; i++)
			{
				Assert::AreEqual(keys[i], keys_list.at(i + 1));
			}
		}
	};

	TEST_CLASS(get_values)
	{
		map_rb_tree<int, char> map;
		list<char> values_list;
	public:
		TEST_METHOD(get_values_is_values_list_not_empty)
		{
			map.insert(4, 'a');
			values_list = *map.get_values();
			Assert::AreEqual(false, values_list.is_empty());
		}
		TEST_METHOD(get_values_empty_map)
		{
			values_list = *map.get_values();
			Assert::AreEqual(true, values_list.is_empty());
		}
		TEST_METHOD(get_values_is_size_right)
		{
			map.insert(4, 'a');
			map.insert(5, 'a');
			values_list = *map.get_values();
			Assert::AreEqual(2, values_list.get_size());
		}
		TEST_METHOD(get_values_are_values_right)
		{
			char values[] = { 'a','c','b','e','h','g','f','d' };
			for (int i = 0; i < 8; i++)
			{
				map.insert(i, 'a' + i);
			}
			values_list = *map.get_values();
			for (int i = 0; i < 8; i++)
			{
				Assert::AreEqual(values[i], values_list.at(i + 1));
			}
		}
	};
	
	TEST_CLASS(remove)
	{
		map_rb_tree<int, char> map;
		list<char> values_list;
		list<int> keys_list;
		char data;
	public:
	
		TEST_METHOD(empty_list)
		{
			try
			{
				map.remove(7);
			}
			catch (Element_doesnt_exist error)
			{
				error.what();
			}
		}

		TEST_METHOD(nonexistent_key)
		{
			map.insert(1, 'q');
			try
			{
				map.remove(7);
			}
			catch (Element_doesnt_exist error)
			{
				error.what();
			}
		}

		TEST_METHOD(red_leaf_is_size_right_after)
		{
			map.insert(1, 'q');
			map.insert(5, 'g');
			map.remove(5);
			Assert::AreEqual(size_t(1), map.get_size());
		}

		TEST_METHOD(red_leaf_does_removed_key_exist)
		{
			char data;
			map.insert(1, 'q');
			map.insert(5, 'g');
			map.insert(0, 'z');
			map.remove(5);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(5, keys_list.at(i));
			}
		}

		TEST_METHOD(leaf_root_is_empty_after)
		{
			map.insert(1, 'q');
			map.remove(1);
			Assert::AreEqual(true, map.is_empty());
		}

		TEST_METHOD(leaf_root_is_size_right_after)
		{
			map.insert(1, 'q');
			map.remove(1);
			Assert::AreEqual(size_t(0), map.get_size());
		}

		TEST_METHOD(root_has_one_child_is_size_right)
		{
			map.insert(8, 'q');
			map.insert(5, 'a');
			map.remove(8);
			Assert::AreEqual(size_t(1),map.get_size());
		}

		TEST_METHOD(root_has_one_child_does_removed_key_exist)
		{
			char data;
			map.insert(8, 'q');
			map.insert(5, 'a');
			map.remove(8);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(8, keys_list.at(i));
			}
		}

		TEST_METHOD(root_has_two_children_does_removed_key_exist)
		{
			
			map.insert(8, 'q');
			map.insert(10, 'a');
			map.insert(5, 'a');
			map.remove(8);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(8, keys_list.at(i));
			}
		}
	
		TEST_METHOD(middle_has_one_child_is_size_right_after)
		{
			map.insert(10, 'q');
			map.insert(5, 'a');
			map.insert(15, 'a');
			map.insert(1, 'q');
			map.insert(6, 'a');
			map.insert(20, 'a');
			map.remove(15);
			Assert::AreEqual(size_t(5), map.get_size());
		}

		TEST_METHOD(middle_has_one_child_does_removed_key_exist)
		{
			map.insert(10, 'q');
			map.insert(5, 'a');
			map.insert(15, 'a');
			map.insert(1, 'q');
			map.insert(6, 'a');
			map.insert(20, 'a');
			map.remove(15);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(15, keys_list.at(i));
			}
		}

		TEST_METHOD(middle_has_two_children_is_size_right_after)
		{
			map.insert(10, 'q');
			map.insert(5, 'a');
			map.insert(15, 'a');
			map.insert(1, 'q');
			map.insert(6, 'a');
			map.insert(11, 'a');
			map.insert(20, 'a');
			map.remove(15);
			Assert::AreEqual(size_t(6), map.get_size());
		}

		TEST_METHOD(middle_has_two_children_does_removed_key_exist)
		{
			map.insert(10, 'q');
			map.insert(5, 'b');
			map.insert(15, 'a');
			map.insert(1, ',');
			map.insert(6, 'j');
			map.insert(11, 'g');
			map.insert(20, 'w');
			map.remove(15);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size()+1; i++)
			{
				Assert::AreNotEqual(15,keys_list.at(i));
			}
		}

	};

	TEST_CLASS(double_black_cases)
	{
		map_rb_tree<int, char> map;
		list<char> values_list;
		list<int> keys_list;
		char data;
	public:
	
		TEST_METHOD(red_nephew_case_is_size_right_after)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.remove(30);
			Assert::AreEqual(size_t(3), map.get_size());
		}
		
		TEST_METHOD(red_nephew_case_does_removed_key_exist)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.remove(30);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(30, keys_list.at(i));
			}
		}

		TEST_METHOD(red_brother_case_is_size_right_after)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.insert(3, 'd');
			map.insert(2, 'y');
			map.remove(30);
			Assert::AreEqual(size_t(5), map.get_size());
		}

		TEST_METHOD(red_brother_case_does_removed_key_exist)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.insert(3, 'd');
			map.insert(2, 'y');
			map.remove(30);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(30, keys_list.at(i));
			}
		}
		TEST_METHOD(black_nephews_case_is_size_right_after)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.remove(5);
			map.remove(10);
			Assert::AreEqual(size_t(2), map.get_size());
		}

		TEST_METHOD(black_nephews_case_does_removed_key_exist)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.remove(5);
			map.remove(10);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(10, keys_list.at(i));
			}
		}
		
	};

	TEST_CLASS(find_value)
	{
		map_rb_tree<int, char> map;
		list<int> keys_list;
		list<char> values_list;
		char data;
	public:
		TEST_METHOD(element_doesnt_exist)
		{ // there is no element with requested key, find_value mast throw Element_doesnt_exist error 
			map.insert(7, 'q');
			try
			{
				data = map.find_value(8);
			}
			catch (Element_doesnt_exist error)
			{
				error.what();
			}
		}
		TEST_METHOD(is_returned_data_right)
		{ // element exists, find_value(10) must return data at 10 - 'a' 
			map.insert(7, 'q');
			map.insert(10, 'a');
			data = map.find_value(10);
			Assert::AreEqual('a', data);
		}
		
	};
}