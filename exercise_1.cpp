#include <iostream>
using namespace std;

// prototypes of my fuctions
int *sort(int *, int);
int correct_input();
int *massive_filling();
bool cheak_bsearch(int *mass, int number);
int bsearch(int *mass, int number);

int main()
{
	int *mass = massive_filling(); 
	cout << "Input number for check:";
	int just_number = correct_input();//this variable i give in fucthion "bsearch"
	if (cheak_bsearch(mass, just_number)==true)
	{
		cout << "First element in massiv,that less than input number:" << bsearch(mass, just_number)<<endl;
	}
	else
	{
		cout << "Massiv don't have element,that less than input number!!!"<<endl;
	}
	system("pause");
}
int correct_input()
{
	int input_number;
	while (true)
	{
		//this block-code help me fill variable only int type(without str type)
		cin >> input_number;//input int variable
		if (!cin)
		{
			cout << "Error!!!Incorrect input!" << endl;
			cout << "Please,input number again:";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
			return input_number;
	}
}
int *massive_filling()
{
	cout << "Please,input size your massive:";
	int size_mass = correct_input();
	int *mass = new int[size_mass];//create dinamic massiv
	for (int i = 0; i < size_mass; i++)
	{
		//massiv filling
		cout << "Input " << i + 1 << " element:";
		mass[i] = correct_input();//call func for correct filling massiv
	}
	mass = sort(mass, size_mass);//reinitialization pointer mass and call function for sort massive
	return mass;
}
int *sort(int *mass, int size_mass)//this func make sort by massiv descending
{
	//for this i use buble sort
	for (int i = 1; i < size_mass; i++)
	{
		int number = mass[i];

		for (int j = 0; j < size_mass - i; j++)
		{
			if (mass[j] < mass[j + 1])
			{
				int time_var = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = time_var;
			}
		}
	}
	return mass;//return pointer of descending massiv
}
bool cheak_bsearch(int *mass, int number)
{
	for (int i = 0; i <= sizeof(mass); i++)
	{
		if (number > mass[i])
		{
			return true;
		}
	}
	return false;
}
int bsearch(int *mass, int number)
{

	for (int i = 0; i <= sizeof(mass); i++)

	{
		if (number > mass[i])
		{
			return mass[i];
		}
	}
}