#include "stdafx.h"
#include "CppUnitTest.h"
#include "E:\Вера\учёба\АиСД\4 семестр\Map_RB_tree\Map_RB_tree\Tree.h"
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
		// GET_SIZE TESTS
		TEST_METHOD(empty_map)
		{
			size_t size;
			Assert::AreEqual(size_t(0), map.get_size());
		}
		TEST_METHOD(one_element)
		{
			map.insert(8, 'a');
			Assert::AreEqual(size_t(1), map.get_size());
		}
		TEST_METHOD(two_elements)
		{
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
		{
			Assert::AreEqual(true, map.is_empty());
		}
		TEST_METHOD(one_element)
		{
			map.insert(7, 'a');
			Assert::AreEqual(false, map.is_empty());
		}
		TEST_METHOD(two_elements)
		{
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
		TEST_METHOD(clear_empty_map)
		{
			map.insert(7, 'a');
			map.clear();
			Assert::AreEqual(size_t(0), map.get_size());
		}
		TEST_METHOD(clear_map_with_2_elements)
		{
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
		{
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
		{
			map.insert(7, 'a');
			map.insert(1, 'z');
			Assert::AreEqual(size_t(2), map.get_size());
		}
		TEST_METHOD(is_map_not_empty_after)
		{
			map.insert(7, 'a');
			Assert::AreEqual(false, map.is_empty());
		}
		TEST_METHOD(is_root_correct)
		{// 5 must become a root. get_keys returns root last so it'll be 3 at keys_list
			map.insert(7, 'a');
			map.insert(5, 'c');
			map.insert(3, 'b');
			keys_list = *map.get_keys();
			Assert::AreEqual(5, keys_list.at(3));
		}
	};

	TEST_CLASS(remove)
	{
		map_rb_tree<int, char> map;
		list<int> keys_list;
		list<char> values_list;
	public:
		/*TEST_METHOD(remove_key_doesnt_exist)
		{
			map.insert(7, 'a');
			try
			{
				map.remove(0);
			}
			catch (Element_doesnt_exist error)
			{
				error.what();
			}
		}*/
		/*TEST_METHOD(remove_1_element_is_empty_after)
		{
			map.insert(1, 'z');
			map.remove(1);
			Assert::AreEqual(true, map.is_empty());
		}*/
		/*TEST_METHOD(remove_leaf_is_size_right)
		{
			map.insert(7, 'a');
			map.insert(5, 'z');
			map.insert(1, 'z');
			map.remove(1);
			Assert::AreEqual(2, map.get_size());
		}*/
		/*TEST_METHOD(remove_root_is_size_right)
		{
			map.insert(7, 'a');
			map.insert(5, 'z');
			map.insert(1, 'z');
			map.remove(5);
			Assert::AreEqual(2, map.get_size());
		}*/
	};

	TEST_CLASS(get_keys)
	{
		map_rb_tree<int, char> map;
		
	public:
		TEST_METHOD(get_keys_not_empty)
		{
			list<int> keys_list;
			map.insert(4, 'a');
			keys_list = *map.get_keys();
			Assert::AreEqual(false, keys_list.is_empty());
		}
		TEST_METHOD(get_keys_empty)
		{
			list<int> keys_list;
			keys_list =* map.get_keys();
			Assert::AreEqual(true, keys_list.is_empty());
		}
		TEST_METHOD(get_keys_size)
		{
			list<int> keys_list;
			map.insert(4, 'a');
			map.insert(5, 'a');
			keys_list = *map.get_keys();
			Assert::AreEqual(2, keys_list.get_size());
		}
		TEST_METHOD(get_keys_at)
		{
			list<int> keys_list;
			map.insert(0, 'a');
			map.insert(1, 'b');
			map.insert(2, 'b');
			map.insert(3, 'a');
			map.insert(4, 'b');
			map.insert(5, 'b');
			map.insert(6, 'b');
			map.insert(7, 'b');
			keys_list = *map.get_keys();
			Assert::AreEqual(0, keys_list.at(1));
		}
	};

	TEST_CLASS(get_values)
	{
		map_rb_tree<int, char> map;
		list<char> values_list;
	public:
		TEST_METHOD(get_values_not_empty)
		{
			map.insert(4, 'a');
			values_list = *map.get_values();
			Assert::AreEqual(false, values_list.is_empty());
		}
		TEST_METHOD(get_values_empty)
		{
			values_list = *map.get_values();
			Assert::AreEqual(true, values_list.is_empty());
		}
		TEST_METHOD(get_values_size)
		{
			map.insert(4, 'a');
			map.insert(5, 'a');
			values_list = *map.get_values();
			Assert::AreEqual(2, values_list.get_size());
		}
		TEST_METHOD(get_keys_at)
		{
			for (int i = 0; i < 8; i++)
			{
				map.insert(i, 'a' + i);
			}
			values_list = *map.get_values();
			Assert::AreEqual('b', values_list.at(3));
		}
	};
	
	TEST_CLASS(remove_)
	{
		map_rb_tree<int, char> map;
		list<char> values_list;
		list<int> keys_list;
		char data;
	public:
		//++
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
		//++
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
		//++
		TEST_METHOD(red_leaf_is_size_right_after)
		{
			map.insert(1, 'q');
			map.insert(5, 'g');
			map.remove(5);
			Assert::AreEqual(size_t(1), map.get_size());
		}
		//++
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
		//++
		TEST_METHOD(leaf_root_is_empty_after)
		{
			map.insert(1, 'q');
			map.remove(1);
			Assert::AreEqual(true, map.is_empty());
		}
		//++
		TEST_METHOD(leaf_root_is_size_right_after)
		{
			map.insert(1, 'q');
			map.remove(1);
			Assert::AreEqual(size_t(0), map.get_size());
		}
		//++
		TEST_METHOD(root_has_left_child_is_size_right)
		{
			map.insert(8, 'q');
			map.insert(5, 'a');
			map.remove(8);
			Assert::AreEqual(size_t(1),map.get_size());
		}
		//++
		TEST_METHOD(root_has_left_child_does_removed_key_exist)
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
		//++
		TEST_METHOD(root_has_right_child_is_size_right)
		{
			map.insert(8, 'q');
			map.insert(10, 'a');
			map.remove(8);
			Assert::AreEqual(size_t(1), map.get_size());
		}
		//++
		TEST_METHOD(root_has_right_child_does_removed_key_exist)
		{
			char data;
			map.insert(8, 'q');
			map.insert(10, 'a');
			map.remove(8);
			keys_list = *map.get_keys();
			for (int i = 1; i < keys_list.get_size() + 1; i++)
			{
				Assert::AreNotEqual(8, keys_list.at(i));
			}
		}
		//++
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
		//++
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
		//++
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
		//++k
		TEST_METHOD(middle_has_two_children_max_is_red_is_size_right_after)
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
		//++
		TEST_METHOD(middle_has_two_children_max_is_red_does_removed_key_exist)
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
		//++
		TEST_METHOD(red_nephew_case_size)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.remove(30);
			Assert::AreEqual(size_t(3), map.get_size());
		}
		//++
		TEST_METHOD(red_nephew_case_key)
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

		TEST_METHOD(red_brother_case_size)
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

		TEST_METHOD(red_brother_case_key)
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
		TEST_METHOD(black_nephews_case_size)
		{
			map.insert(20, 'q');
			map.insert(10, 'b');
			map.insert(30, 'a');
			map.insert(5, ',');
			map.remove(5);
			map.remove(10);
			Assert::AreEqual(size_t(2), map.get_size());
		}

		TEST_METHOD(black_nephews_case_key)
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

	
}