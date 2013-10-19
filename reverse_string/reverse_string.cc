#include <iostream>
#include <string.h>

using namespace std;

void reverse_string(char* str)
{
	char* end = str;
	char tmp;
	while (*end)
	{
		cout << "end: " << end << endl;
		end++;
	}
	end--;
	while (end > str)
	{
		tmp = *str;
		*str = *end;
		*end = tmp;	
		end--;
		str++;
	}
}

int main(int argc, char** argv)
{
	int n = strlen(argv[1]);
	if (n < 1) {
		cout << "error processing input" << endl;
		cout << "valid usage: a.out <str>" << endl;
		return 1;
	}
	char str[strlen(argv[1])];
	strcpy(str, argv[1]);
	cout << "reversing string :" << str << endl;
	reverse_string(str);
	cout << str << endl;
	return 0;
}
