#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <limits>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
//to deal with bad input using exception handling
int input_num(string text)
{
    int ch;

    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << text;
    cin >> ch;
    while (true)
    {
        try
        {
            if (cin.fail())
            {
                throw("Invalid input. Try Again");
            }
            break;
        }
        catch (const char *c)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout
                << c << "\n"
                << text;
            cin >> ch;
        }
    }
    return ch;
}

//node for sent & received msg SLLs
class msg
{
public:
    bool starred; //true if msg is starred
    bool sent;    //true if msg has been sent to whom the user wishes to
    bool read;    //true if msg has been read by the logged-in user
    string date;  //date & time when msg was sent/received
    string to;    //username of user to whom msg is sent
    string from;  //username of user from whom msg is sent
    string text;  //the actual message
    msg *link;

    msg()
    {
        starred = false;
        sent = false;
        read = true;
        to = "";
        from = "";
        text = "";
        link = NULL;
    }
};
// abstract class for admin informations
class Admin
{
protected:
    char Admin_name[20] = "cheems";
    char Admin_password[20] = "1234gk";

public:
    virtual void Login() = 0;
};

//node for user DLL
class user
{
public:
    bool logged_in;
    string username;
    string password;
    msg *headS;          //sent msg SLL head
    msg *headR;          //received msg SLL head
    vector<msg *> trash; //vector of deleted msg
    user *next;
    user *prev;
    static int no_of_users;

    user()
    {
        logged_in = false;
        username = "";
        password = "";
        headS = NULL;
        headR = NULL;
        next = NULL;
        prev = NULL;
    }

    static int revenue();                                 //to calculate revenue
    void display_text(string title, msg *head);           //to display list of sent/inbox msg
    void text_choice(string title, msg **head);           //actions user can perform with displayed list of msg
    void read_text(msg *head);                            //to read a certain msg
    void delete_text(msg **head);                         //to delete a certain msg
    void starUnstar_msg(msg *m);                          //to mark an msg as important (star) or unstar
    void vec_read_text(vector<msg *> results);            //to read msg from search results
    void vec_del_text(vector<msg *> results, msg **head); //to delete msg from search results
    void vec_starUnstar(vector<msg *> results);           //to star/unstar msg from search results
    void search_msg(string title, msg **head);            //to search msg sent to/ received from a user
    void starred_msg(string title, msg **head);           //displays list of starred msg
    void trash_choice();                                  //actions to perform on deleted msg
    void delete_permanently();                            //to delete a msg from trash (permanently)
    void read_trashtext();                                //to read a msg in trash
};
int user::no_of_users;
class logininsystem : virtual private Admin, public user
{
    char Username[20];
    char Password[15];

public:
    void hello();   // options for admin login
    void Login();   // use for admin login
};

void logininsystem::hello()
{
    int ch;
    do
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "----------------------------------------";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "******** WELCOME TO ADMIN LOGIN ********";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Exit ";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Number of total users";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. Show me the Total revenue Generated";

        ch = input_num("Enter your choice: ");
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "----------------------------------------";
        cout << "\n\n";
        cout << "\t\t\t\t\t";

        switch (ch)
        {
        case 0:

            cout << "********* Exit **********";
            break;

        case 1:

            cout << "Total Number of users are :" << user::no_of_users << endl;
            break;

        case 2:
            cout << "Total Revenue Generated is Rs." << user::revenue() << endl;
            break;

        default:
            cout << "Invalid choice";
        }

    } while (ch != 0);
}

void logininsystem::Login()
{

    char key;
    int true1 = 1;
    int try1 = 0;
    int i = 0;

    do
    {
        system("clear");

        cout << "\n\n\n\n\n\n";
        int a;
        for (a = 0; a <= 100000000; a++)
        {
        }
        cout << "\t\t\t\t    ----------------------------------------\n";
        for (a = 0; a <= 100000000; a++)
        {
        }
        cout << "\t\t\t\t    |           ADMIN   LOGIN               |\n";
        for (a = 0; a <= 100000000; a++)
        {
        }
        cout << "\t\t\t\t    ----------------------------------------\n";
        for (a = 0; a <= 100000000; a++)
        {
        }
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Username : ";
        cin.clear();
        cin >> Username;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "Password : ";
        cin >> Password;
        // for (i = 0;;)
        // {
        //     // key=getch();
        //     if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9'))
        //     {
        //         Password[i] = key;
        //         ++i;
        //         cout << "*";
        //     }
        //     if (key == '\b' && i >= 1)
        //     {
        //         cout << "\b \b";
        //         --i;
        //     }
        //     if (key == '\r')
        //     {
        //         Password[i] = '\0';
        //         break;
        //     }
        // }

        if (strcmp(Username, Admin_name) == 0 && strcmp(Password, Admin_password) == 0)
        {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t";
            system("read -p '\n\n\t\t\t\t\tPress Enter to continue...' var");
            system("clear");
            hello();
            true1 = 0;
            try1 = 4;
        }
        else
        {
            system("clear");
            try1 = try1 + 1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << 3 - try1;
            cout << "\n\n";
            cout << "\t\t\t\t";
            system("read -p '\n\n\t\t\t\t\tPress Enter to continue...' var");

            if (try1 >= 3)
            {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!\n\n";
                cout << "\t\t\t\t";
                system("read -p '\n\n\t\t\t\t\tPress Enter to continue...' var");
                exit;
            }
        }
    } while (try1 < 3);
}
//function to calculate revenue
int user::revenue()
{
    int a = 10; //yearly charge per user
    return no_of_users * a;
}
//to display list of sent/inbox msg
void user::display_text(string title, msg *head)
{
    string R[] = {"unread", "read"};
    string S[] = {"unstarred", "starred"};
    system("clear");
    system("read -p '\n\n\t\t\t\t\tPress Enter to continue...' var");
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "******************************* " << title << " *******************************";

    if (head == NULL)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "No messages to display yet!";
    }

    else
    {
        int i = 1;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "-------------------------------------------------------------------------------------------------";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout
            << setw(5) << "No." << setw(15) << "From" << setw(15)
            << "To" << setw(15) << "Message" << setw(14) << "When"
            << setw(10) << "Status" << setw(14) << "Starred";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "-------------------------------------------------------------------------------------------------";

        msg *m = head;
        while (m != NULL)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout
                << setw(5) << i << setw(15) << m->from << setw(15)
                << m->to << setw(15) << m->text.substr(0, 8) << "..."
                << setw(14) << m->date.substr(4, 6) << setw(10) << R[m->read]
                << setw(14) << S[m->starred];
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "-------------------------------------------------------------------------------------------------";

            m = m->link;
            i++;
        }
    }
}

//actions user can perform with displayed list of msg
void user::text_choice(string title, msg **head)
{
    int ch;
    do
    {
        display_text(title, *head);
        if (*head == NULL)
            return;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "********* " << title << " OPTIONS **********";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Exit";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Read a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. Delete a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "3. Star/Unstar a message";

        ch = input_num("Enter your choice: ");
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "---------------------------------------------";

        switch (ch)
        {
        case 0:
            break;

        case 1:
            read_text(*head);
            break;

        case 2:
            delete_text(head);
            break;

        case 3:
            starUnstar_msg(*head);
            break;
        }
    } while (ch != 0);
}

//to read a certain msg
void user::read_text(msg *head)
{
    int no;
    no = input_num("Enter message no. to read: ");
    if (no < 1)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }
    msg *ptr = head;
    for (int i = 1; i < no; i++)
    {
        ptr = ptr->link;
        if (ptr == NULL)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Invalid message no.";
            return;
        }
    }
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "..................................................................";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "************** MESSAGE " << no << " **************";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "From : " << ptr->from;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "To : " << ptr->to;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "When : " << ptr->date;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Message : \n"
         << ptr->text;
    cout << "...................................................................\n";
    ptr->read = true;
}

//to delete a certain msg //it adds the deleted msg to trash
void user::delete_text(msg **head)
{
    if (*head == NULL)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "No messages found.";
        return;
    }

    int no = input_num("Enter message no. to delete: ");

    if (no < 1)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }

    msg *ptr = *head;
    msg *prev = *head;
    if (no == 1)
    {
        *head = (*head)->link;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Message deleted successfully!!";
        trash.push_back(ptr);
        return;
    }

    for (int i = 1; i < no; i++)
    {
        prev = ptr;
        ptr = ptr->link;
        if (ptr == NULL)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Invalid message no.";
            return;
        }
    }
    prev->link = ptr->link;
    trash.push_back(ptr);
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Message deleted successfully!!";
}

//to mark an msg as important (star) or unstar
void user::starUnstar_msg(msg *head)
{

    int no = input_num("\nEnter message no. to star/unstar: ");

    if (no < 1)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }
    msg *ptr = head;
    for (int i = 1; i < no; i++)
    {
        ptr = ptr->link;
        if (ptr == NULL)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Invalid message no.";
            return;
        }
    }
    if (ptr->starred == false)
    {
        ptr->starred = true;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Message no. " << no << " has been starred.";
    }
    else
    {
        ptr->starred = false;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Message no. " << no << " has been unstarred.";
    }
}

//to read msg from search results or from starred msg list
void user::vec_read_text(vector<msg *> results)
{
    unsigned int no = unsigned(input_num("\nEnter message no. to read: "));

    if (no < 1 || no > results.size())
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }

    msg *ptr = results.at(no - 1);
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "..................................................................";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "************** MESSAGE " << no << " **************";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "From : " << ptr->from;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "To : " << ptr->to;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "When : " << ptr->date;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Message : \n"
         << ptr->text;
    cout << "...................................................................\n";
    ptr->read = true;
}

//to delete msg from search results or from starred msg list
void user::vec_del_text(vector<msg *> results, msg **head)
{
    unsigned int no = unsigned(input_num("Enter message no. to delete: "));

    if (no < 1 || no > results.size())
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }

    msg *ptr = *head;
    msg *prev = *head;

    if (results.at(no - 1) == *head)
    {
        *head = (*head)->link;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Message deleted successfully!";
        trash.push_back(ptr);
        results.erase(results.begin() + no - 1);
        return;
    }
    for (ptr = *head; ptr != results.at(no - 1);)
    {
        prev = ptr;
        ptr = ptr->link;
        if (ptr == NULL)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Invalid message no.";
            return;
        }
    }
    prev->link = ptr->link;
    ptr = results.at(no - 1);
    trash.push_back(ptr);
    results.erase(results.begin() + no - 1);
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Message deleted successfully!!";
}

//to star/unstar msg from search results
void user::vec_starUnstar(vector<msg *> results)
{
    unsigned int no = unsigned(input_num("Enter message no. to star/unstar: "));

    if (no < 1 || no > results.size())
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }

    msg *ptr = results.at(no - 1);
    if (ptr->starred)
    {
        ptr->starred = false;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Message no. " << no << " has been unstarred.";
    }
    else
    {
        ptr->starred = true;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Message no. " << no << " has been starred.";
    }
}

//to search msg sent to/ received from a user
void user::search_msg(string title, msg **head)
{
    string un;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Enter the username: ";
    cin >> un;

    bool found = false;
    msg *m = *head;
    if (*head == NULL)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "No messages to display yet!";
        return;
    }

    string cmp;

    string R[] = {"unread", "read"};
    string S[] = {"unstarred", "starred"};

    int ch, i;
    do
    {
        i = 0;
        found = false;
        vector<msg *> results;

        for (m = *head; m != NULL; m = m->link)
        {
            if (title == "SENT TO ")
                cmp = m->to;
            else //"RECEIVED FROM "
                cmp = m->from;

            if (cmp == un)
            {
                if (!found)
                {
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "**************************** MESSAGES " << title << un << " ****************************";
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "-------------------------------------------------------------------------------------------------";
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout
                        << setw(5) << "No." << setw(15) << "From"
                        << setw(15) << "To" << setw(15) << "Message"
                        << setw(14) << "When" << setw(10) << "Status"
                        << setw(14) << "Starred";
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "-------------------------------------------------------------------------------------------------";
                }
                i++;
                found = true;
                results.push_back(m);

                cout
                    << setw(5) << i << setw(15) << m->from << setw(15)
                    << m->to << setw(15) << m->text.substr(0, 8) << "..."
                    << setw(14) << m->date.substr(4, 6) << setw(10)
                    << R[m->read] << setw(14) << S[m->starred];
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "-------------------------------------------------------------------------------------------------";
            }
        }

        if (m == NULL && !found)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "No messages found!";
            return;
        }
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "********* MESSAGE OPTIONS **********";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Exit";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Read a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. Delete a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "3. Star/Unstar a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        ch = input_num("Enter your choice: ");
        cout << "---------------------------------------------";

        switch (ch)
        {
        case 0:
            break;

        case 1:
            vec_read_text(results);
            break;

        case 2:
            vec_del_text(results, head);
            break;

        case 3:
            vec_starUnstar(results);
            break;
        }
    } while (ch != 0);
}

//displays list of starred msg
void user::starred_msg(string title, msg **head)
{

    string R[] = {"unread", "read"};
    string S[] = {"unstarred", "starred"};

    msg *m = *head;
    if (head == NULL)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "No messages to display yet!";
        return;
    }

    int ch, i;
    bool found;
    vector<msg *> results;
    do
    {
        i = 0;
        found = false;
        vector<msg *> results;

        for (m = *head; m != NULL; m = m->link)
        {

            if (m->starred == true)
            {

                if (!found)
                {
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "**************************** STARRED MESSAGES IN " << title << " ****************************";
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "-------------------------------------------------------------------------------------------------";
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout
                        << setw(5) << "No." << setw(15) << "From"
                        << setw(15) << "To" << setw(15) << "Message"
                        << setw(14) << "When" << setw(10) << "Status"
                        << setw(14) << "Starred";
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "-------------------------------------------------------------------------------------------------";
                }
                i++;
                found = true;
                results.push_back(m);
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout
                    << setw(5) << i << setw(15) << m->from << setw(15)
                    << m->to << setw(15) << m->text.substr(0, 8) << "..."
                    << setw(14) << m->date.substr(4, 6) << setw(10)
                    << R[m->read] << setw(14) << S[m->starred];
                cout << "-------------------------------------------------------------------------------------------------";
            }
        }

        if (m == NULL && !found)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "\nNo messages found!";
            return;
        }
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "********* MESSAGE OPTIONS **********";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Exit";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Read a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. Delete a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "3. Star/Unstar a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        ch = input_num("Enter your choice: ");
        cout << "---------------------------------------------";

        switch (ch)
        {
        case 0:
            break;

        case 1:
            vec_read_text(results);
            break;

        case 2:
            vec_del_text(results, head);
            break;

        case 3:
            vec_starUnstar(results);
            break;
        }
    } while (ch != 0);
}

//actions to perform on deleted msg
void user::trash_choice()
{
    int ch;
    do
    {
        string R[] = {"unread", "read"};
        string S[] = {"unstarred", "starred"};
        if (this->trash.size() == 0)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Trash empty";
            return;
        }
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "******************************* TRASH *******************************";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "-------------------------------------------------------------------------------------------------";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout
            << setw(5) << "No." << setw(15) << "From" << setw(15) << "To"
            << setw(15) << "Message" << setw(14) << "When" << setw(10)
            << "Status" << setw(14) << "Starred";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "-------------------------------------------------------------------------------------------------";

        for (unsigned int i = 0; i < this->trash.size(); i++)
        {
            msg *m = this->trash[i];
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout
                << setw(5) << i + 1 << setw(15) << m->from << setw(15)
                << m->to << setw(15) << m->text.substr(0, 8) << "..."
                << setw(14) << m->date.substr(4, 6) << setw(10) << R[m->read] << setw(14) << S[m->starred];
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "-------------------------------------------------------------------------------------------------";
        }
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "********* TRASH OPTIONS **********";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Exit";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Delete a message permanently";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. View a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        ch = input_num("Enter your choice: ");
        cout << "---------------------------------------------";

        switch (ch)
        {
        case 0:
            break;

        case 1:
            delete_permanently();
            break;

        case 2:
            read_trashtext();
            break;
        }
    } while (ch != 0);
}

//to delete a msg from trash (permanently)
void user::delete_permanently()
{
    unsigned int no = unsigned(input_num("\nEnter message no. to delete: "));
    if (no > trash.size() || no < 1)
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }

    msg *m = trash[no - 1];
    trash.erase(trash.begin() + no - 1);
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Message permanently deleted";
    delete m;
}

//to read a msg in trash
void user::read_trashtext()
{
    unsigned int no = unsigned(input_num("Enter message no. to read: "));

    if (no < 1 || no > trash.size())
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Invalid message no.";
        return;
    }
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "..................................................................";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "************** MESSAGE " << no << " **************";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "From : " << trash[no - 1]->from;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "To : " << trash[no - 1]->to;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "When : " << trash[no - 1]->date;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Message : \n"
         << trash[no - 1]->text;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "...................................................................\n";
    trash[no - 1]->read = true;
}

class messager : public user
{
    user *start; //start pointer of user DLL
    user *last;  //pointer to last node of user DLL
public:
    messager()
    {
        start = NULL;
        last = NULL;
    }

    bool is_empty();          //returns true if no user has created account yet
    user *accept();           //takes input required while creating a new account
    void create();            //creates new user account & adds it to user DLL(sign-up)
    void login();             //to login to an existing account
    void remove();            //to delete your account
    void change_pw();         //to change current password
    void activity(user *ptr); //actions that user can perform while logged in
    msg *msg_sent();          //takes input to send msg, updates receiver's inbox & returns pointer to sent msg
    void send_msg(user *ptr); //calls msg_sent() & updates user's sent msg sll
};

//returns true if no user has created account yet
bool messager::is_empty()
{
    if (start == NULL)
        return true;
    else
        return false;
}

//takes input required while creating a new account
user *messager::accept()
{
    bool un_exist = false;
    user *tmp = new user();
    user::no_of_users++;
    user *ptr;
    do
    {
        ptr = start;
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Enter username to create : ";
        cin >> tmp->username;
        while (ptr != NULL)
        {
            if (ptr->username == tmp->username)
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Entered username already exists.";
                un_exist = true;
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == NULL)
            un_exist = false;
    } while (un_exist);
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Create password: ";
    cin >> tmp->password;
    return tmp;
}

//creates new user account & adds it to user dll(sign-up)
void messager::create()
{
    user *tmp = accept();
    if (is_empty())
    {
        start = tmp;
        last = tmp;
    }
    else
    {
        last->next = tmp;
        tmp->prev = last;
        last = tmp;
    }
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Your account has been created successfully!";
    system("read -p '\n\n\t\t\t\t\tPress Enter to continue...' var");
    system("clear");
}

//to login to an existing account
void messager::login()
{
    string un, pw;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Enter username: ";
    cin >> un;
    for (user *ptr = start; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->username == un)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Enter password: ";
            cin >> pw;
            if (ptr->password == pw)
            {
                ptr->logged_in = true;
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Successfully logged in.";
                activity(ptr);
                return;
            }
            else
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Incorrect password. Try again.";
                return;
            }
        }
    }
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Username not found.";
}

//to delete your account //removes ptr from user dll
void messager::remove()
{
    char ch;
    string un, pw;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Enter username: ";
    cin >> un;

    if (is_empty())
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Currently no user accounts exist.";
    }

    for (user *curr = start; curr != NULL; curr = curr->next)
    {
        if (curr->username == un)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Enter the password: ";
            cin >> pw;

            if (curr->password == pw)
            {
                do
                {
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "Are you sure you want to delete your account?(Y/N): ";
                    cin >> ch;
                    if (ch == 'N')
                        return;
                    else if (ch == 'Y')
                        break;
                    else
                    {
                        cout << "\n\n";
                        cout << "\t\t\t\t\t";
                        cout << "Invalid choice. Try again.";
                    }
                } while (ch != 'Y' || ch != 'N');

                //if start node
                if (curr == start)
                    start = curr->next;

                //if curr is not last node
                if (curr->next != NULL)
                    (curr->next)->prev = curr->prev;

                //if curr is not 1st node
                if (curr->prev != NULL)
                    (curr->prev)->next = curr->next;

                delete curr;
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Your account has been deleted successfully!";
                return;
            }
            else
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Incorrect password....please try again.";
                return;
            }
        }
    }
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Username not found.";
}

//to change current password
void messager::change_pw()
{
    string un, pw, pw1;
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Enter username: ";
    cin >> un;

    for (user *ptr = start; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->username == un)
        {
            do
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Enter previous password: ";
                cin >> pw;
                if (ptr->password == pw)
                {
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "Enter new password : ";
                    cin >> pw1;
                    ptr->password = pw1;
                    cout << "\n\n";
                    cout << "\t\t\t\t\t";
                    cout << "Your password has been changed successfully!";
                    return;
                }
                else
                    cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Incorrect previous password.\n";
            } while (true);
        }
    }
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Username not found.";
}

//actions that user can perform while logged in
void messager::activity(user *ptr)
{
    int ch;
    do
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "************* HELLO @" << ptr->username << " ! *************";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Logout";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Check inbox messages";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. Send a message";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "3. View sent messages";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "4. Search messages sent to an user";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "5. Search messages received from an user";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "6. View deleted messages";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "7. View starred messages in Inbox";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "8. View starred messages in Sentbox";

        ch = input_num("Enter your choice: ");
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "------------------------------------------";

        switch (ch)
        {
        case 0:
            ptr->logged_in = false;
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Successfully logged out.";
            return;

        case 1:
            ptr->text_choice("INBOX", &ptr->headR);
            break;

        case 2:
            send_msg(ptr);
            break;

        case 3:
            ptr->text_choice("SENT", &ptr->headS);
            break;

        case 4:
            ptr->search_msg("SENT TO ", &ptr->headS);
            break;

        case 5:
            ptr->search_msg("RECEIVED FROM ", &ptr->headR);
            break;

        case 6:
            ptr->trash_choice();
            break;

        case 7:
            ptr->starred_msg("INBOX ", &ptr->headR);
            break;

        case 8:
            ptr->starred_msg("SENTBOX ", &ptr->headS);
            break;

        default:
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Invalid choice";
        }

    } while (ch != 0);
}

//takes input to send msg, updates receiver's inbox & returns pointer to sent msg
msg *messager::msg_sent()
{
    msg *m = new msg();
    user *ptrT; //pointer To whom user is sending msg
    bool un_exist = false;
    do
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Enter username of user to message : ";
        cin >> m->to;

        getchar(); //'\n'

        //updating receiver's received msg sll
        for (ptrT = start; ptrT != NULL; ptrT = ptrT->next)
        {
            if (ptrT->username == m->to)
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Enter message you want to send to @" << m->to << " :";
                cout << "\n";
                cout << "\t\t\t\t\t";
                getline(cin, m->text);

                m->read = false;
                time_t now = time(0);  // current date/time based on current system
                m->date = ctime(&now); // convert now to string form
                un_exist = true;
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Message sent successfully to @" << m->to;

                //insert new msg at beginning of ptrT's received msg sll
                m->link = ptrT->headR;
                ptrT->headR = m;
                return m;
            }
        }

        if (ptrT == NULL) //!un_exist
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Entered username doesn't exist.\n";
        }

    } while (un_exist == false);
    return m;
}

//calls msg_sent() & updates user's sent msg sll
void messager::send_msg(user *ptr)
{
    msg *ms = msg_sent(); //pointer to sent msg
    ms->from = ptr->username;

    //updating sender's (logged-in user's) sent msg sll
    msg *m = new msg(); //create new msg to update user's sent msgs sll
    m->sent = true;
    m->to = ms->to;
    m->from = ms->from;
    m->date = ms->date;
    m->text = ms->text;

    //insert sent msg at beginning of sent sll
    m->link = ptr->headS;
    ptr->headS = m;
}

int main()
{
    int ch;
    messager A;
    logininsystem l;
    do
    {
        system("clear");
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "----------------------------------------";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "******** WELCOME TO MESSENGER **********";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "0. Exit application";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "1. Create new account";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "2. Login to your account";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "3. Delete an existing account";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "4. Change Password";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "5. Admin Login";
        ch = input_num("Enter your choice: ");
        system("read -p '\n\n\t\t\t\t\tPress Enter to continue...' var");
        system("clear");
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "----------------------------------------";

        switch (ch)
        {
        case 0:
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "********* PROGRAM ENDED **********";
            break;

        case 1:
            A.create();
            break;

        case 2:
            A.login();
            break;

        case 3:
            A.remove();
            break;

        case 4:
            A.change_pw();
            break;

        case 5:
            l.Login();
            break;
        default:
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Invalid choice";
        }

    } while (ch != 0);
    return 0;
}



