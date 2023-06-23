#include <iostream>
#include <string>
#include<cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
int main();
void Contact();
void handler(char d)
{
    while (1)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Worng input  Try again : ";
            cin >> d;
            continue;
        }

        break;
    }
}
class LinkedList
{
    struct Node
    {
        string fname;
        string lname;
        int tel;
        Node* next;
    };
    Node* head =  NULL;
public:
    void append(string valfn,string valln,int valt) // valn = value of name ,, valt = value of tel
    {
        ofstream wr;
        wr.open("emp.txt", ios::app);
        Node* newNode = new Node;
        newNode->fname = valfn;
        wr << valfn << endl;     // save in file
        newNode->lname = valln;
        wr << valln << endl;     // save in file
        newNode->tel = valt;
        wr << valt << endl;     // save in file
        newNode->next = NULL;
        // spacial cases
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void remova(string val)
    {
        if (head == NULL)
            return;
        //make the data of delete func that have prev pointer ant temp
        Node* temp, *prev;
        prev = temp = head;
        if(temp->fname == val)
        {
            head = temp->next;
            delete temp;
            return;
        }
        while(temp != NULL && temp->fname != val )
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL)
            return;
        else
        {
            prev->next = temp->next;
            delete temp;
        }
    }
    void display()
    {

        Node* temp = head;
        wfile(temp);
        if( head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        while(temp != NULL)
        {

            cout << "-------------------------------------------\n";
            cout << temp->fname << " " << temp->lname << "  | 0"<< temp->tel << "  |\n";
            temp = temp->next;
            cout << "-------------------------------------------\n";
        }
        cout << endl;
    }
    void Reverse()
    {
        if(head == NULL)
            return;
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void search(string val)
    {

        Node* current = head;
        while(current != NULL)
        {
            if(current->fname == val || current->lname == val)
                wfile(current);
                cout << current->fname << " " << current->lname << "  | 0"<< current->tel << "  |\n";
            current = current->next;
        }
        cout << "error not found\n";
    }
    void find_edit(string val)
    {
        Node* current = head;
        while(current != NULL)
        {
            if(current->fname == val || current->lname == val)
            {
                cout << "\n-----------------------------------------------\n";
                cout << current->fname << " " << current->lname << "  | 0"<< current->tel << "  |\n";
                cout << "---------------------------------------------\n";
                cout << "1-delete\n2-edit\n3-back\n";
                cout << "enter value here :- ";
                int ch;
                cin >> ch;
                if(ch == 1)
                {
                    remova(val);
                }
                else if(ch == 2)
                {
                    edit(val);
                }
                else if (ch == 3)
                {
                    Contact();
                }
                else
                {
                    cout << "wrong value please check you value!!!\n";

                }
            }
            else
                current = current->next;
        }

    }
    void edit(string eval)
    {
        Node* current = head;
        while(current != NULL)
        {
            if(current->fname == eval || current->lname == eval)
            {
                cout << "\n-------------------------------------\n";
                cout << "1-change name\n2-change number\n3-back\n";
                cout << "enter you choies here :- ";
                int a;
                cin >> a;
                if(a == 1)
                {
                    string nfname, nlname;
                    cout << "\n--------------------------------------------";
                    cout << "\nenter your new first name and last :- ";
                    cin >> nfname >> nlname;
                    current->fname = nfname;
                    current->lname = nlname;
                    cout << "\n-----------------------------------------------\n";
                }
                else if (a == 2)
                {
                    int n_num;
                    cout << "\n--------------------------------------------";
                    cin >> n_num;
                    current->tel = n_num;
                    cout << "\n-----------------------------------------------\n";
                }
                else if(a==3)
                {
                    find_edit(eval);
                }
                else
                {
                    cout << "wrong input please enter again :- ";
                }
            }
            current = current->next;
        }
    }

    void wfile(Node* temp)
    {
        ifstream  re;
        re.open("emp.txt",ios::out);
        temp = head;
        if( head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        while(temp != NULL)
        {
            re >> temp->fname;
            re >> temp->lname;
            re >> temp->tel;
            temp = temp->next;
        }
        re.close();
    }
};

void Contact()
{
    system("cls");
    char Quit = 'q';
    LinkedList contacT;
    //contacT.append("Zkaria","Gamal",1809642898);  // until learn how to display file
    //contacT.append("Hazem","Gamal",1494358430);   // until learn how to display file
    //contacT.append("Adham","Fawzy",1911134775);   // until learn how to display file
    do
    {
        cout << "----------*** hello again ***----------\n";
        cout << "a-Add\nd-Delete\ns-Search\np-Print all\nf-Find and edit\nb-Back\n";
        cout << "enter here :- " ;
        char var;
        cin >> var;
        cin.ignore(256, '\n');
        cin.clear();
        if (var == 'a' || var == 'A')
        {
            int num ;
            string fname, lname;
            cout << "-------------------------\n";
            cout << "enter your first and last name :- ";
            cin >> fname;
            cin >> lname;
            cout << "-------------------------------\n";
            cout << "enter your phone number :- 0";
            cin >> num;
            contacT.append(fname,lname,num);
        }
        else if (var == 'd' || var == 'D')
        {
            cout << "enter the value you wanna to delete :-";
            string dval;
            cin >> dval;
            contacT.remova(dval);
        }
        else if (var == 's' || var == 'S')
        {
            cout << "-----------------------------------------\n";
            cout << "enter the value you wanna to search :-";
            string sval;
            cin >> sval;
            contacT.search(sval);
            cout << "---------------------------------------\n";
        }
        else if (var == 'p' || var == 'P')
        {
            contacT.display();
        }
        else if (var == 'f' || var == 'F')
        {
            cout << "\n------------------------------------------------------------\n";
            cout << "enter the first or last name you want to search and edit :- ";
            string nam;
            cin >> nam;
            contacT.find_edit(nam);
        }
        else if (var == 'b' || var == 'B')
        {
            main();
        }
        else
        {
            cout << "Worng input  Try again \n";
            handler(var);
        }
    }
    while(Quit != 'q' || Quit != 'Q');
    main();
}
int main()
{
    system("cls");
    char c = 'q';
    do
    {
        cout << "------------------------------------------------------------------\n";
        cout << "hello user --- Welcome --- to your contact \n";
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\nplease enter:-\n";
        cout << "c-continue \nq-quit";
        cout << "\nenter here :- ";
        char op;
        cin >> op;
        cin.clear();
        cin.ignore('\n',10);
        switch(op)
        {
        case 'c':
        case 'C':
            Contact();
            break;
        case 'Q':
        case 'q':
            exit(0);
            break;
        default:
            cout << "Please try again !!! \n ";
            handler(op);
        }

    }
    while (c != 'Q' || c != 'q');    // Exit

    return 0;
}
