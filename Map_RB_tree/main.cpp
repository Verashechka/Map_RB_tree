#include <iostream>
#include <string>
#include "Errors.h"
#include "Tree.h"
using namespace std;

int main()
{
	char data;
	map_rb_tree<int, char> map;
	list<int> keys_list;
	list<char> values_list;
	int key;
	int menu;
	do
	{
		try
		{
			system("cls");
			cout << "0-output map\n1-insert\n2-remove\n3-clear\n4-get_keys \n5-insert\n6-at\n7-remove\n8-get_size\n9-clear\n10-set\n11-isEmpty\n\n12-Exit\n";
			cin >> menu;
			switch (menu)
			{
			case 0: // output map
				for (int i = 0; i < 8; i++)
				{
					map.insert(i, 'a'+i);
				}
				map.output_map();
				break;
			case 1: // insert
				map.insert(5, 'a');
				map.insert(7, 'b');
				map.insert(3, 'b');
				cout << map.get_size();
				system("pause");
				break;
			case 2: // remove
				/*map.insert(4, 'a');
				map.insert(45, 'a');
				map.insert(6, 'a');
				map.remove(6);
				cout << map.get_size();*/
				map.insert(20, 'q');
				map.insert(10, 'b');
				map.insert(30, 'a');
				map.insert(5, ',');
				map.remove(5);
				map.remove(10);
				
				map.output_map();
				cout << map.get_size();
				system("pause");
				break;
			case 3:
				map.insert(5, 'a');
				map.insert(7, 'a');
				map.clear();
				cout << map.get_size();
				system("pause");
				break;
			case 4://get_keys
				for (int i = 0; i < 8; i++)
				{
					map.insert(i, 'a' + i);
				}
				keys_list = *map.get_keys();
				cout << keys_list.get_size() << endl;
				for (size_t i = 1; i < 9; i++)
				{
					cout << i << " : " << keys_list.at(i) << endl;
				}
				system("pause");
				break;
			case 5://get_values
				for (int i = 0; i < 8; i++)
				{
					map.insert(i, 'a' + i);
				}
				values_list = *map.get_values();
				cout << values_list.get_size() << endl;
				for (size_t i = 1; i < 9; i++)
				{
					cout << i << " : " << values_list.at(i) << endl;
				}
				system("pause");
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				
				break;
			case 9:
				
				break;
			case 10:
				
				break;
			case 11:
				
				break;
			case 12:

				break;
			default:
				break;
			}
		}
		catch (Key_already_exists a)
		{
			cout << a.what();
		}
		catch (Element_doesnt_exist a)
		{
			cout << a.what();
		}
		system("pause");
	} while (menu != 12);
	return 0;
}