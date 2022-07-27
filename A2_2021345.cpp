// A2_2021345.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

char* Mystrcpy(char* s1,const char* s2)
{
	int i = 0, j = 0;
	while (*s1 != '\0')
	{
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		j++;
		s2++;
	}
	s2 = s2 - j;
	s1 = s1-i;
	if (i < j)
	{
		cout <<endl<< "ERROR! cannot copy strings the destination string size is less then source string size" << endl;
		cout << "Destination string cannot hold source string!" << endl;
		return nullptr;
	}
	else
	{
		for (int k = 0; k < i; k++)
		{
			*s1 = *s2;
			s1++; s2++;
		}

		return s1;
	}
}

char* Mystrncpy(char* s1,const char* s2, size_t n)
{
	int i = 0, j = 0;
	while (*s1 != '\0')
	{
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		j++;
		s2++;
	}
	s2 = s2 - j;
	s1 = s1 - i;
	
		if (j < n)
		{
			cout << endl << "INVALID COMMAND! The number is greater then the size of string " << endl;
			cout << "Pass numbers of terms less then or equal to string size";
			return nullptr;
		}

	for (int i = 0; i < n; i++)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}

	return s1;
}

char* Mystrcat(char* s1, const char* s2)
{
	int i = 0, j = 0;
	while (*s1 != '\0')
	{
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		j++;
		s2++;
	}
	s2 = s2 - j;

	for (int k = 0; k < j; k++)
	{
		*s1 = *s2;
		s1++; s2++;
	}

	return s1;
}

char* Mystrncat(char* s1, const char* s2, size_t n)
{
	
		int i = 0, j = 0;
		while (*s1 != '\0')
		{
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			j++;
			s2++;
		}
		s2 = s2 - j;

		if (j < n)
		{
			cout << endl << "INVALID COMMAND! The number is greater then the size of string " << endl;
			cout << "Pass numbers of terms less then or equal to string size";
			return nullptr;
		}

		for (int k = 0; k < n; k++)
		{
			*s1 = *s2;
			s1++; s2++;
		}
		s1++;
		*s1 = '\0';
		return s1;

}

int Mystrcmp(const char* s1,const char* s2)
{
	int i = 0, j = 0;
	while (*s1 != '\0')
	{
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		j++;
		s2++;
	}

	s2 = s2 - j;
	s1 = s1 - i;

	int count=0;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			count++;
		else if (*s1 < *s1)
			count--;
		s1++; s2++;
	}

return count;
}

int Mystrncmp(const char* s1,const char* s2, size_t n)
{
	int i = 0;
	while (*s1 != '\0')
	{
		i++;
		s1++;
	}

	while (i < n)
	{
		cout << endl << "INVALID COMMAND! The number is greater then the size of string " << endl;
		cout << "Enter number of terms to append";
		cin >> n;
		while (cin.fail())
		{
			cout << endl << "INVALID COMMAND!!!" << endl;
			cout << "Enter a number: ";
			cin >> n;
		}
		while (n < 0)
		{
			cout << "Index Number of term cannot be negative";
			cout << "Enter number of terms to append again: ";
			cin >> n;
		}
	}

	s1 = s1 - i;

	int count = 0;

	for(int i=0;i<n;i++)
	{
		if (*s1 > *s2)
			count++;
		else if (*s1 < *s1)
			count--;

		s1++; s2++;
	}

	return count;
}

size_t Mystrlen(const char* s)
{
	size_t n=0 ;
	while (*s != '\0')
	{
		n++;
		s++;
	}

	return n;
}

char* Mystrtok(char* s1, const char* s2)
{	
	static char* p;

	if (!s1)
	{
		s1 = p + 1;
		char* s = s1;

		char* sa = s1;
		size_t n = 0;
		while (*sa != '\0')
		{
			n++;
			sa++;
		}

		size_t a = 0;
		while (*s != *s2)
		{
			if (a > n)
				return nullptr;

			s++;
			a++;
		}
		if (*s == *s2)
			*s = '\0';

		p = s;

		return s1;

	}
	else
	{
		char* s = s1;

		char* sa = s1;
		size_t n = 0;
		while (*sa != '\0')
		{
			n++;
			sa++;
		}

		size_t a = 0;
		while (*s != *s2)
		{
			if (a > n)
				return nullptr;

			s++;
			a++;
		}
		if (*s == *s2)
			*s = '\0';

		p = s;

		return s1;
	}

}

int main()
{
	/* HERE in main function you can call thess functions as regular but becareful of the names and letters of the of functions*/
	string s1 ;
	string s2 ;

	cout << "Enter 1st string: ";
	getline(cin, s1);
	cout << "Enter 2nd string: ";
	getline(cin,s2);

	char* a1 = &s1[0];
	char* a2 = &s2[0];

	cout << "You Entered :" << endl;

	cout << "String 1:" << a1 << endl;
	cout << "String 2:" << a2;

			//Mystrcpy(a1, a2);					//CHECK 1 COMPLETE
			//Mystrncpy(a1, a2, 6);				//CHECK 2 COMPLETE
			//Mystrcat(a1, a2);					//CHECK 3 COMPLETE
		    Mystrncat(a1, a2, 2);				//CHECK 4 COMPLETE
			//cout <<endl<<a1;

			cout <<endl<< a1;
	/*int i = Mystrcmp(a1, a2);
	cout << endl;
	if (i < 0)
	{
		cout << a1 << " Is less then " << a2;
	}
	else if (i > 0)
	{												//CHECK 5 COMPLETE
		cout << a1 << " Is less then  " << a2;
	}
	else if(i==0)
	{
		cout << a1 << " is equal to " << a2;
	}*/

/*	int i = Mystrncmp(a1, a2, 6);

	cout << endl;
	if (i < 0)
	{
		cout << a1 << " Is less then " << a2;
	}
	else if (i > 0)
	{												//CHECK 6 COMPLETE
		cout << a1 << " Is less then  " << a2;
	}
	else if (i == 0)
	{
		cout << a1 << " is equal to " << a2;
	}*/

	/*int i = Mystrlen(a2);
	cout <<endl<< "Length of string is: " << i;*/	//CHECK 7 COMPLETE
/*char* word = Mystrtok(a1, a2);

cout << endl << "token 1: " << word << endl;

 word=	Mystrtok(NULL, a2);							//CHECK 8 COMPLETE

 if (!word)
	 cout << "NULL POINTER RECIEVED";
 else
	 cout << "token 2: " << word;*/

 return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
