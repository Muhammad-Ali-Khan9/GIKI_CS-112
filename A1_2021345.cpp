// A1_2021345.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include <conio.h>

using namespace std;

struct book
{// book structure
	int ID;
	int price;
	int pages;
	string Bookname;
	string author;
	string ISBN;
};//book structure

struct BookList
{//booklist structure
	book books[5] = { {0,0,0,"n/a","n/a","n/a"},
					  {0,0,0,"n/a","n/a","n/a"},
	                  {0,0,0,"n/a","n/a","n/a"},
		              {0,0,0,"n/a","n/a","n/a"},
	                  {0,0,0,"n/a","n/a","n/a"}
	                };
	
	void printall()
	{//printall function

		cout << "Purticulars of books entered are:- " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << i+1 << ". ";
			cout << "Book name: " << books[i].Bookname << endl;
			cout << " ID: " << books[i].ID << endl;
			cout << " Author: " << books[i].author << endl;
			cout << " ISBN: " << books[i].ISBN << endl;
			cout << " Price: " << books[i].price << endl;
			cout << " Pages: " << books[i].pages << endl<<endl;
		}

	}//printall function

	void print_specific(int num)
	{
		cout << "Particulars of book entered are:- " << endl;

		for (int i = 0; i < 5; i++)
		{
			if (books[i].ID == num)
			{
				cout << "Book name: " << books[i].Bookname << endl;
				cout << "ID: " << books[i].ID << endl;
				cout << "Author: " << books[i].author << endl;
				cout << "ISBN: " << books[i].ISBN << endl;
				cout << "Price: " << books[i].price << endl;
				cout << "Pages: " << books[i].pages << endl << endl;
				break;
			}

			else if (books[i].ID != num && i == 4)
				cout << "Book not found in the list" << endl;
		}

	}

	void sort_acending()
	{
		for(int i=0;i<4;i++)
			for (int j = 0; j < 4 - i; j++)
			{
				if (books[j].ID > books[j + 1].ID)
				{
					swap(books[j], books[j + 1]);
				}
			}
	}

	void sort_decending()
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4 - i; j++)
			{
				if (books[j].ID < books[j + 1].ID)
				{
					swap(books[j], books[j + 1]);
				}
			}
	}

	void deleteall()
	{
		for (int i = 0; i < 5; i++)
		{
			books[i].ID = 0;
			books[i].price = 0;
			books[i].pages = 0;
			books[i].Bookname = "n/a";
			books[i].author = "n/a";
			books[i].ISBN = "n/a";

		}
		cout << "All Books data deleted successfully" << endl << endl;
	}

	void add_book()
	{
		srand(time(0));

		for (int i = 0; i < 5; i++)
		{
			if (books[i].ID == 0)
			{
				cout << "Enter name of book: ";
				cin.ignore();
				getline(cin, books[i].Bookname);

				cout << "Enter name of author of book: ";
				getline(cin, books[i].author);

				cout << "Enter ISBN Issued by National Libraray Building,Islamabad,Pakistan: ";
				getline(cin, books[i].ISBN);

				cout << "Enter Price of book: ";
				cin >> books[i].price;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "INVALID COMMAND " << endl << "Enter a number: ";
					cin >> books[i].price;
				}
				cout << "Enter total pages in the Book: ";
				cin >> books[i].pages;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "INVALID COMMAND " << endl << "Enter a number: ";
					cin >> books[i].pages;
				}
				books[i].ID = 1+rand()%99;
				cout << "ID alloted to the book is: " <<books[i].ID << endl << endl;
				
				break;
			}

			else if (i == 4 && books[i].ID != 0)
				cout << "Sorry all slots are full try again later" << endl;
		}
	}

	void del_book(int num)
	{
		for (int i = 0; i < 5; i++)
		{
			if (books[i].ID == num)
			{
				books[i].ID = 0;
				books[i].price = 0;
				books[i].pages = 0;
				books[i].Bookname = "n/a";
				books[i].author = "n/a";
				books[i].ISBN = "n/a";
				cout << "Book deleted successfully" << endl << endl;
				break;
			}
			else if (i == 4 && books[i].ID != num)
				cout << "Sorry the books is not registered " << endl<<endl;
		}
	}

};//booklist structure

struct student
{
	int rollno;
	string stdname;
	int ID;
};

struct studentList
{
	student std[5] = { {0,"n/a",0},
		               {0,"n/a",0},
	                   {0,"n/a",0},
		               {0,"n/a",0},
	                   {0,"n/a",0}
	                 };
	           
	void printAll()
	{//printAll function

		cout <<endl<< "Purticulars of all students entered are:- " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << i+1 << ".";
			cout << " Name: " << std[i].stdname << endl;
			cout << " ID: " << std[i].ID << endl;
			cout << " Roll Number: " << std[i].rollno << endl<<endl;
		}

	}//printAll function

	void print_spec(int num)
	{
		for (int i = 0; i < 5; i++)
		{
			if (std[i].rollno == num)
			{
				cout << "The purticulars of the student are:- " << endl<<endl;
				cout << "Name of student : " << std[i].stdname << endl;
				cout << "Student ID: " << std[i].ID << endl;
				cout << "Roll Number: " << std[i].rollno << endl;
				break;
			}

			else if (i == 4 && std[i].rollno != num)
				cout << "The Student is not registered" << endl;
		}
		cout << endl;
	}
	 
	void del_student(int num)
	{
		for (int i = 0; i < 5; i++)
		{
			if (std[i].rollno == num)
			{
				std[i].ID = 0;
				std[i].rollno = 0;
				std[i].stdname = "n/a";
				cout << "Student Deleted successfully" << endl<<endl;
				break;
			}

			else if (i == 4 && std[i].rollno != num)
				cout << "The Student is not registered" << endl<<endl;
		}
	}

	void add_student()
	{
		srand(time(0));
		for (int i = 0; i < 5; i++)
		{
			if (std[i].ID == 0)
			{
				cout << "Enter your name: ";
				cin.ignore();
				getline(cin, std[i].stdname);
				cout << "Enter your Registartion/Admit card number: ";
				cin >> std[i].ID;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "INVALID COMMAND " << endl << "Enter a number: ";
					cin >> std[i].ID;
				}
				std[i].rollno = 1 + rand() % 99;
				cout << "your Roll number is: " << std[i].rollno << "  Remember it or note it down at any page" << endl << endl;
				
				break;
			}

			else if (i == 4 && std[i].rollno != 0)
				cout << "Sorry all slots are full. Come again later " << endl << endl;
		}

	}

};

int main()
{
			BookList c;
			studentList c1;

	string opt;
	while (1)
	{
		cout << "MAIN MENU" << endl;
		cout << "Enter a specific number to perform the following function:- " << endl;
		cout << "1. Add New Student" << endl;
		cout << "2. Delete Existing student" << endl;
		cout << "3. Show All Students" << endl;
		cout << "4. Add New Book" << endl;
		cout << "5. Delete Existing Book" << endl;
		cout << "6. Show Purticular Book" << endl;
		cout << "7. Show All Books" << endl;
		cout << "8. Sort Books In Acending Order" << endl;
		cout << "9. Sort Books In Decending Order" << endl;
		cout << "10. Delete All Books " << endl;
		cout << "11. Exit" << endl << endl;

		cout << "Enter a number : ";
		cin >> opt;

		while (opt != "1" && opt != "2" && opt != "3" && opt != "4" && opt != "5" && opt != "6" && opt != "7" && opt != "8" && opt != "9" && opt != "10" && opt!="11")
		{
			cout << "\a INVALID COMMAND! " << endl;
			cout << "Please Enter correct command(Enter Numbers from 1-11 to perform the designated function): ";
			cin >> opt;
		}
		if (opt.compare("1") == 0)
		{
			c1.add_student(); 
			cout << endl << "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		if (opt.compare("2") == 0)
		{
			int num;
			
			cout << "Enter your Roll number: ";
			cin >> num;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid command " << endl << "Enter a number";
				cin >> num;
			}

			while (1)
			{
				if (num > 100)
				{
					cout << "INVALID Roll number ENTERED! " << endl;
					cout << "All Roll numbers are less then or equal to 100 " << endl;
					cout << "PLease enter Roll number again: ";
					cin >> num;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid command " << endl << "Enter a number";
						cin >> num;
					}
				}
				else if (num < 0)
				{
					cout << "Invalid Roll number Entered" << endl;
					cout << "Roll numbers are not negative " << endl;
					cout << "Please Enter correct Roll number again: ";
					cin >> num;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid command " << endl << "Enter a number";
						cin >> num;
					}
				}
				else
				{
					cout << endl;
					break;
				}
			}
			c1.del_student(num);
			cout << endl << "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("3") == 0)
		{
			c1.printAll();
			cout << endl << "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("4") == 0)
		{
			c.add_book();
			cout << endl << "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("5") == 0)
		{
			int num;
			cout << "Enter ID of Book: ";
			cin >> num;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "INVALID COMMAND " << endl << "Enter a number: ";
				cin >> num;
			}
			while (1)
			{
				if (num > 100)
				{
					cout << "INVALID ID ENTERED! " << endl;
					cout << "All IDs are less then 100 and greater then 0 " << endl;
					cout << "Please enter ID again: ";
					cin >> num;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "INVALID COMMAND " << endl << "Enter a number: ";
						cin >> num;
					}
				}
				else if (num < 1)
				{
					cout << "INVALID COMMAND" << endl;
					cout << "Roll numbers are not negative" << endl;
					cout << "Please enter a valid Roll number (which is less then 100 but greater then 0): "; 
					cin >> num;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "INVALID COMMAND " << endl << "Enter a number: ";
						cin >> num;
					}
				}
				else
				{
					cout << endl;
					break;
				}
			}
			c.del_book(num);
			cout <<endl<< "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("6") == 0)
		{
			int num;
			cout << "Enter ID of Book: ";
			cin >> num;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "INVALID COMMAND " << endl << "Enter a number: ";
				cin >> num;
			}
			while (1)
			{
				if (num > 100)
				{
					cout << "INVALID ID ENTERED! " << endl;
					cout << "All IDs are less then or equal to 100 " << endl;
					cout << "PLease enter ID again: ";
					cin >> num;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid command " << endl << "Enter a number: ";
						cin >> num;
					}
				}
				else if(num<1)
				{
					{
						cout << "INVALID COMMAND" << endl;
						cout << "IDs are not negative" << endl;
						cout << "Please enter a valid ID (which is less then 100 but greater then 0): ";
						cin >> num;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "INVALID COMMAND " << endl << "Enter a number: ";
							cin >> num;
						}
					}
				}
				else
				{
					cout << endl;
					break;
				}
			}

			c.print_specific(num);
			cout <<endl<< "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("7") == 0)
		{
			c.printall();
			cout <<endl<< "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("8") == 0)
		{
			cout << "Books before sorting in acending order: " << endl << endl;
			c.printall();
			cout << endl << "NOTE:- books will be arranged with respect to their IDs " << endl;
			c.sort_acending();
			cout << "Books after sorting in acending order: " << endl << endl;
			c.printall();
			cout <<endl<< "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("9") == 0)
		{
			cout << endl << "NOTE:- books will be arranged with respect to their IDs " << endl;
			c.sort_decending();
			cout << "Books after sorting in decending order: " << endl<<endl;
			c.printall();
			cout << endl;

			cout << "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("10") == 0)
		{
			c.deleteall();
			cout << "Press any key to continue to main menu"<<endl;
			system("pause");
			system("CLS");
		}
		else if (opt.compare("11") == 0)
			break;

	}


	cout << endl << "Thank you for coming. Please come again \n";
	cout << "GOOD BYE!!! " << endl << endl;
	system("pause");

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
