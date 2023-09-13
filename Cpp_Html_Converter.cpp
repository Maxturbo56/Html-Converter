#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string page_name;

void Input_Anchor()
{	
	int user_Input;
	string user_String;
	
	ofstream stranica;
	stranica.open(page_name + ".html", ios::app);
	stranica << "<a ";
	
	cout << "What do you wish to anchor to your page? \n\t 1. Link"<<endl<<endl;
	cin>>user_Input;
	switch(user_Input)
	{
		case 1:
		{
			stranica << "href=\'";
			cout << "Please paste the link you wish to anchor to : " << endl;
			cin>>user_String;
			cout<<"Press ENTER to continue."<<endl<<endl;
			cin.ignore();
			stranica << user_String <<"\'>";
			cout<<"Do you wish to have a text box as your link? (y / n)"<<endl;
			cin>>user_String;
			if(user_String == "y")
			{
				cout<<"Please provide the text for the link box : "<<endl;
				cin.ignore();
				getline(cin, user_String);
				cin.ignore();
				stranica<<user_String;
				break;		
			}
			
			stranica<<"</a>\n"<<endl;
			
			break;		
		}
	}
	
	system("CLS");
	
	stranica.close();	
		
	//<a href="https://www.w3schools.com">Visit W3Schools.com!</a> 
}

void Hot_Reload(string name_of_page)
{
	//Prtvori Ime stranice u drugu var
	string one = name_of_page;
	
	//Dodaj extenziju
	string operational = one + ".html";
	
	//Vadi broj charova
	int limit = operational.length();
	
	//Pravi ime stranice za otvoriti u vidu niza charova (ima ih koliki je limit)
	char imec[limit];
	
	//Pretvara ime u charove
	for(int i = 0; i < limit; i++)
	{
		imec[i] = operational[i];
	}
	
	system("CLS");
	
	//Output u konzolu ...
	cout<<"Opening ";
	for(int i = 0; i < limit; i++)
	{
		cout<<imec[i];
	}
	cout<<" ..."<<endl<<endl;
	
	system(imec);
}

void Input_Paragraph()
{
	string paragraph;
	ofstream stranica;
	stranica.open(page_name + ".html", ios::app);
	//init paragraph part
	stranica << "<p>";
	cout << "Write something in your paragraph : " << endl;
	cin.ignore();
	getline(cin, paragraph);
	cin.ignore();
	stranica << paragraph;
	stranica << "</p>\n"<<endl;
	stranica.close();
	
	system("CLS");
}

void Input_Picture()
{
	cout << "Please put the picture you wish to add to any of the projects in the same folder as the .html file to use this functionality. Thank you!" << endl << endl;
	ofstream stranica;
	stranica.open(page_name + ".html", ios::app);
	string user_Input;
	
	//1.
	cout << "Please provide the name of your picture as a fully complete file name (ex : img_dog.png)" << endl;
	cin >> user_Input;
	stranica << "<img src = \'" << user_Input << "\' ";

	//2.
	cout << "Now provide the alt naming for your picture for web view :  (ex : A_dog_on_a_hill)" << endl;
	cin >> user_Input;
	stranica << "alt = \'" << user_Input << "\' ";

	//3.
	cout << "Provide the width of the picture : (in pixels)" << endl;
	cin >> user_Input;
	stranica << "width = \'" << user_Input << "\' ";

	//4.
	cout << "Provide the height of the picture : (in pixels)" << endl;
	cin >> user_Input;
	stranica << "height = \'" << user_Input << "\'>\n";

	//<img src = "img_girl.jpg" //		1.
	//alt = "Girl in a jacket" //		2.
	//width = "500" //					3.
	//height = "600"> //				4.

	stranica.close();
}

void End_Page()
{
	ofstream stranica;
	stranica.open(page_name + ".html", ios::app);
	stranica << "\n"<< "<" << "/" << "body>" << endl << "<" << "/" << "html>" << endl;
	stranica.close();
}

void Input_Heading()
{
	string heading;
	cout << "Provide a heading for your page : " << endl;
	cin.ignore();
	getline(cin, heading);
	cin.ignore();
	ofstream stranica;
	stranica.open(page_name + ".html", ios::app);
	stranica << "<h1>" << heading << "</h1>" << endl;
	stranica.close();
}

void New_Page()
{
	int user_Input;

	//------------------------------------------------------------ CREATES THE PAGE 
	ofstream fileOut;
	fileOut.open(page_name + ".html");
	fileOut << "<html>\n<body>\n";
	fileOut << "<title>" << page_name << "</title>\n";
	fileOut.close();
	//------------------------------------------------------------

	do {
		cout << "What do you wish to add to your new page : \n\t1. A Heading \n\t2. A Paragraph \n\t3. A Picture \n\t4. End Page \n\t5. An Anchor \n\t7. Hot Reload\n\n\n\t9. End Editing" << endl;
		cin >> user_Input;
		switch (user_Input)
		{
			case 1: 
			{
				Input_Heading();
				break;
			}
			case 2:
			{
				Input_Paragraph();
				break;
			}
			case 3:
			{
				Input_Picture();
				break;
			}
			case 4:
			{
				End_Page();
				break;
			}
			case 5:
			{
				Input_Anchor();
				break;
			}
			case 9:
			{
				cout << "Terminating Edit..." << endl;
				break;
			}
			case 7: 
			{
				Hot_Reload(page_name);
				break;
			}
			default:
			{
				cout << "Do you really have time for this?" << endl;
				break;
			}
		}
	} while (user_Input != 9);
}

void Resume_Work(string name_to_resume) 
{
	int user_Input;
	page_name = name_to_resume;
	do {
		cout<<"	Currently working on : "<<page_name<<endl<<endl;
		
		cout << "What do you wish to add to "<<page_name<<" : \n\n\t1. A Heading \n\t2. A Paragraph \n\t3. A Picture \n\t4. End Page \n\t5. An Anchor \n\t7. Hot Reload\n\n\n\t9. End Editing" << endl;
		cin >> user_Input;
		switch (user_Input)
		{
			case 1:
			{
				Input_Heading();
				break;
			}
			case 2:
			{
				Input_Paragraph();
				break;
			}
			case 3:
			{
				Input_Picture();
				break;
			}
			case 4:
			{
				End_Page();
				break;
			}
			case 5:
			{
				Input_Anchor();
				break;
			}
			case 9:
			{
				cout << "Terminating Edit..." << endl;
				break;
			}
			case 7: 
			{
				Hot_Reload(page_name);
				break;
			}
			default:
			{
				cout << "Do you really have time for this?" << endl;
				break;
			}
		}
	} while (user_Input != 9);
	End_Page();
}

int main()
{
	int user_Input;
	do {
		cout<<"Welcome to IndexCreator version 1.0.0"<<endl<<endl;
		cout << "Select an option you wish : \n\t1. Create a new Page \n\t2. Resume work on a Page \n\t3. Exit" << endl;
		cin >> user_Input;
			switch (user_Input)
			{
				case 1: 
				{
					cout << "What do you want to name your page : \n\n\tWARNING!!! If you name your page without an underscore ' _ ' it will crash please follow this convention. Thank you." << endl;
					cin >> page_name;
					ofstream stranice;
					string line;
					stranice.open("page_dll.txt", ios::app);
					stranice << page_name << endl;
					stranice.close();
					New_Page();
					system("CLS");
					break;
				}
				case 2: 
				{
					cout << "On which page would you like to resume work?" << endl;
					
					cout << "Pages available are : " << endl;
					ifstream stranice;
					string line;
					stranice.open("page_dll.txt", ios::out);
					while (getline(stranice, line))
					{
						cout << "\t" << line << endl;
					}

					string name_To_Resume;
					cin >> name_To_Resume;
					Resume_Work(name_To_Resume);
					
					system("CLS");
					
					break;
				}
				case 3:	
					return 0;	
					break;
					
				default: 
				{
					cout << "Please Input a valid character value!" << endl;
					break;
				}
			}
	} while (1);
	return 0;
}
