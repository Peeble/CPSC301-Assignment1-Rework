// Anthony Galustyan
// Section 3

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;


struct person {
    char name[20];
    float balance;
};

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int lines()
{
    int N = 0;
    string line;
    ifstream data("data.txt");
    while(getline(data,line))
    {
        N++;
    }
    //cout << "Number of lines: " << N << endl;
    data.close();
    return N;
}

person * readData(int & N) {
    person *p;
    p = new person[N];
    string firstname;
    string lastname;
    string fullname;
    double balance;
    string custName;

    ifstream data("data.txt");

    if (data.is_open()) {
        for (int i = 0; i < N; i++) {

            data >> firstname >> lastname >> p[i].balance;

            if (firstname.size() > 9) {
                firstname.resize(9);
            } else if (lastname.size() > 10) {
                lastname.resize(10);
            }


            fullname = firstname + " " + lastname;

            //cout << fullname << endl;

            strcpy(p[i].name, fullname.c_str());
        }

        return p;
    }
}

void Display(person arr[], int N)
{
   // cout << "    " << "Name" << "      " << "Balance" << endl << "---------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].name << " " << arr[i].balance << endl;

    }
}
void FindRichest(person arr[], int N)
{
    double temp = 0;
    string name;

    for (int i = 0; i < N;i++)
    {
        if(arr[i].balance > temp){
            temp = arr[i].balance;
            name = arr[i].name;

        }
    }
    cout << "Highest balance: " << name << endl;

}

void Deposit(person arr[], int N, string custName, double amount)
{
    int flag;

    double newbal;
    for (int i = 0; i <= N; i++) {
        if (custName == arr[i].name) {

            arr[i].balance += amount;

            cout << "New balance: " << arr[i].balance << endl;

            flag = 1;

        }

        else if (flag != 1 && i == N)

        {
            cout << "Record not found" << endl;
        }




    }
}

string NameInput()
{
    string custName;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin,custName);


    return custName;

}

double AmountInput()
{
    double amount;
    cout << "Amount: ";
    cin >> amount;

    return amount;

}

void NewCopy(string filename, person arr[], int N)
{
    ofstream data(filename);
    if (data.is_open())
    {

        for (int i = 0; i < N; i++)
        {
            data << arr[i].name << " " << arr[i].balance << endl;
        }

    }

    cout << "File Updated..." << endl;
    data.close();
}

int main() {
    string custName;
    double deposit;

    int N = lines();
    person * p = readData(N);

    int choice;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                Display(p,N);
                // Act on display
                break;

            case 2:
                custName = NameInput();
                deposit = AmountInput();
                Deposit(p,N, custName, deposit);
                // Act on deposit

                break;

            case 3:
                FindRichest(p, N);
                // Act highest balance
                break;

            case 4:
                NewCopy("data.txt", p, N);
                // Act on update records
                break;

            case 5:
                NewCopy("data.txt", p, N);
                exit(0);
                // Must call update records here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
    } while(choice != 5);
    return 0;

    Display(p,N);
    FindRichest(p, N);
 //   cout << "Enter name: ";
 //   getline(cin,custName);
 //   cout << "Amount: ";
 //   cin >> deposit;
    custName = NameInput();
    deposit = AmountInput();
    Deposit(p,N, custName, deposit);
    cout << endl;
 //   cout << "Enter name: ";
 //   cin.ignore();
 //   getline(cin,custName);
 //   cout << "Amount: ";
 //   cin >> deposit;
    custName = NameInput();
    deposit = AmountInput();
    Deposit(p,N, custName, deposit);
    FindRichest(p, N);
    NewCopy("data.txt", p, N);

    /*int N = lines();
    string firstname;
    string lastname;
    string fullname;
    double balance;
    string custName;

    string a[N][2];

    person p[N];

    ifstream data("data.txt");

    if (data.is_open())


    {
        for (int i = 0; i < N; i++){

            data >> firstname >> lastname >> p[i].balance;

            fullname = firstname + " " + lastname;

            strcpy(p[i].name,fullname.c_str());
        }

        for (int j = 0; j < N; j++){
            a[j][0] = p[j].name;
            a[j][1] = to_string(p[j].balance);
        }

        Display(a, N);
        FindRichest(a, N);

        cout << "enter customer name" << endl;
        getline(cin,custName);
        Deposit(custName, a, N);
        NewCopy("data.txt", a, N);



    }

    else
        cout << "no work";





    data.close();
     */
}
