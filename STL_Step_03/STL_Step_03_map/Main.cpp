#include <iostream>
#include <string>
#include <map>

using namespace std;

class Object
{
public:
	int Kor;
	int Eng;
	int Math;

	int Mean;
};

int main(void)
{
	// ** vector<value>
	// ** list<value>
	// ** map<key, value>

	// ** map<key, value*>

	map<int, string> names;

	names.insert(make_pair(1, "È«±æµ¿"));
	names.insert(make_pair(2, "ÀÓ²©Á¤"));
	names.insert(make_pair(3, "ÀÌ¸ù·æ"));
	names.insert(make_pair(4, "¼ºÃáÇâ"));

	for (map<int, string>::iterator iter = names.begin();
		iter != names.end(); ++iter)
	{
		// (*iter).first; = key
		// (*iter).second; = value

		cout << (*iter).first << " : " << (*iter).second << endl;
	}

	cout << names[1] << endl;
	cout << names[2] << endl;
	cout << names[3] << endl;
	cout << names[4] << endl;


	//***********************************************************
	// map<string, int> numbers;
	//***********************************************************
	map<string, int> numbers;

	numbers["È«±æµ¿"] = 1;
	numbers["ÀÓ²©Á¤"] = 2;
	numbers["ÀÌ¸ù·æ"] = 3;
	numbers["¼ºÃáÇâ"] = 4;

	//***********************************************************
	// map<int, list<string> >
	// map<int, vector<string> >
	//***********************************************************
}