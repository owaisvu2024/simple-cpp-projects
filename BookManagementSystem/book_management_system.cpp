#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class temp
{
    string bookname, bookcode, author, searchcode;
    fstream file;

public:
    void banner();
    void addbook();
    void showbook();
    void extract();

} obj;
int main()
{

    char choice;
    obj.banner();
    cout << "1 ADD BOOK " << endl;
    cout << "2 SHOWBOOK " << endl;
    cout << "3 EXTRACT " << endl;

    cout << "ENTER THE CHOICE " << endl;

    cin >> choice;
    switch (choice)
    {
    case '1':
        obj.addbook();
        break;

    case '2':
        obj.showbook();
        break;
    case '3':
        obj.extract();
        break;

    default:
        cout << " invalid selection " << endl;
        break;
    }

    return 0;
}
void temp::banner()
{
    cout << "! ----------------------------------------------------------------- !" << endl;
    cout << "! --------------------THE HOUSE OF BOOKS LIBRARYS------------ !" << endl;
    cout << "! ----------------------------------------------------------------- !" << endl;
}
void temp::addbook()
{
    system("cls");
    obj.banner();
    cin.ignore();
    cout << "ENTER THE ADD BOOK :: ";
    getline(cin, bookname);
    cout << "ENTER THE  BOOK CODE :: ";
    getline(cin, bookcode);
    cout << "ENTER THE ADD AUTHOR NAME :: ";
    getline(cin, author);
    char save;
    cout << "SAVE (Y/N)" << endl;
    cin >> save;

    if (save == 'y'|| save == 'Y')
    {
        file.open("library.txt", ios::out | ios::app);
        file << bookname << "*" << bookcode << "*" << author << endl;
        file.close();
    }
    char more;
    cout << "ADD MORE BOOKS (Y/N)" << endl;
    cin >> more;
    if (more == 'y' || more == 'Y')
    {
        addbook();
    }

    else
    {
        cout << " !-----YOUR BOOKS IS ADDED SUCCESSFULLY------! " << endl;
    }
}
void temp::showbook()
{
    system("cls");
     banner();
    file.open("library.txt", ios::in);
    if (!file)
    {
        cout << "Error: library.txt file not found or could not open. " << endl;
        return;
    }

    bool found = false;
    cout << " CODE\tBOOK NAME\tAUTHOR NAME \n ";
    while (getline(file, bookname, '*') && getline(file, bookcode, '*') && getline(file, author))
    {
        cout << bookcode << "\t" << bookname << "\t" << author << "\n";
        found = true;
    }
    if (!found)
    {
        cout << "FILE ERRORS \n";
    }

    file.close();
}
void temp::extract()


{
	char again;
	do{
		system("cls");
    obj.banner();
    cin.ignore();
    cout << "ENTER THE BOOKCODE " << endl;
    getline(cin, searchcode);
    file.open("library.txt", ios::in);
    if (!file)
    {
        cout << "NO INPUT FILE AVAILABLE HERE " << endl;
        return;
    }

    bool found = false;
    cout << "CODE\tBOOK NAME\tAUTHOR NAME\n";
    while (getline(file, bookname, '*') && getline(file, bookcode, '*') && getline(file, author))
    {
        if (bookcode == searchcode)
        {
            cout << bookcode << "\t" << bookname << "\t\t" << author << endl;
             found = true;
             break;
        }
       
    }
    

    if (!found)
    {
        cout << "INVALID SELECTION " << endl;
    }
    file.close();
    
    cout<<"Do you want to search another book? (Y/N):"<<endl;
    cin>>again;
		
	}while(again=='y'||again=='Y');
    
    
}
