#include <iostream>
using namespace std;


// The length of the array has been hardcored.
const int arrsize = 100;

// The arrays and these varaiables are global so every functions can access them.
string userEmail[arrsize];
string userpassword[arrsize];
string gender[arrsize];
string dateOfBirth[arrsize];
int totalseats[4] = {15, 15, 15, 15};
int familyHallTiming1[arrsize];
int familyHallTiming2[arrsize];
int seats = 75;
int idx = 0;
int noOfMovie=0;
string timing1[arrsize];
string timing2[arrsize];
string movie[arrsize];
string goldenTiming1[arrsize];
string goldenTiming2[arrsize];
string goldPlusTiming1[arrsize];
string goldPlusTiming2[arrsize];
string silverPlusTiming1[arrsize];
string silverPlusTiming2[arrsize];
string silverTiming1[arrsize];
string silverTiming2[arrsize];
int cost[arrsize];

// All the functions used.
void header();
int login();
// Functions used for admin.
void admin(string email, string password);
void adminMenu();
void noofSeats();
void familyHallBooking();
void noofSeatsUnbook();
void timingsChange();
void addMovies();
void movieRecommend();
void discount();
// Functions used for customer.
void Customer();
bool verifyCustomer(string name, string password);
void customerSignup();
bool customerSignIn();
void customerMenu();
void viewMovie();
void movieSelection();
void ticketbooked();

main()
{
    int option;
    string email;
    string password;
    int result;

    system("cls");
    header();
    result=login();
    
    if (result == 1)
    {
        system("cls");
        header();
        admin(email, password);
    }
    else if ( result == 2)
    {
        system("cls");
        header();
        Customer();
        // if (customerSignIn() == false)
        // {
        //     cout << "Invalid. Please Enter again.";
        // }
        // else
        // {
        //     customerMenu();
        // }
    }
    else
    {
        system("cls");
        header();
    }
}

void header()
{
    cout << "                   ***********************************************" << endl;
    cout << "                   ***********************************************" << endl;
    cout << "                   ******* Cinema Ticket Management System *******" << endl;
    cout << "                   ***********************************************" << endl;
    cout << "                   ***********************************************" << endl;
}
int login()
{
    int option;
    cout << "Press 1 if you are an Admin" << endl;
    cout << "Press 2 if you are a Customer " << endl;
    cout << "Press 3 to Exit" << endl;
    cout << "Select an option: ";
    cin >> option;
    return option;
}
void admin(string email, string password)
{
    string answer;
    int option;

    cout << "Administrator " << endl;
    cout << "Enter Password: ";
    cin >> password;
    if (password == "admin123")
    {
        adminMenu();
    }
    else
    {
        cout << "Invalid." << endl;
        cout << "Your Rank?";
        cin >> answer;
        if (answer == "fifteen")
        {
            adminMenu();
        }
        else
        {
            login();
        }
    }
}
void adminMenu()
{
    int option;
    string email;
    string password;

    cout << "1.Number of seats already booked here: " << endl;
    cout << "2.Rows which are not full booked: " << endl;
    cout << "3.Family hall Booking " << endl;
    cout << "4.Change timings of movie: " << endl;
    cout << "5.Add new movie: " << endl;
    cout << "6.Add new recommendation: " << endl;
    cout << "7.Log out" << endl;
    cout << "Select an option: ";
    cin >> option;
    if (option == 1)
    {
        noofSeats();
    }
    if (option == 2)
    {
        noofSeatsUnbook();
    }
    if (option == 3)
    {
        familyHallBooking();
    }
    if (option == 4)
    {
        timingsChange();
    }
    if (option == 5)
    {
        addMovies();
    }
    if (option == 6)
    {
        movieRecommend();
    }
    if (option == 7)
    {
        login();
    }
    else
    {
        admin(email, password);
    }
}

void noofSeats()
{

    cout << "Total number of seats in cinema:" << seats << endl;
    cout << "Total number of gold tickets seats booked: " << totalseats[1] << endl;
    cout << "Total number of gold plus tickets seats booked: " << totalseats[2] << endl;
    cout << "Total number of silver tickets seats booked: " << totalseats[3] << endl;
    cout << "Total number of silver plus tickets seats booked: " << totalseats[4] << endl;
}
void noofSeatsUnbook()
{
    cout << "1.Total number of seats in cinema" << seats << endl;
    cout << "2.Total number of gold tickets seats unbooked: " << endl;
    cout << "3.Total number of gold plus tickets seats unbooked: " << endl;
    cout << "4.Total number of silver tickets seats unbooked: " << endl;
    cout << "5.Total number of silver plus tickets seats unbooked: " << endl;
    cout << "Select an option: ";
}
void familyHallBooking()
{
    cout << "gold Family hall booked or not: " <<  familyHallTiming1[]; << endl;
}
void timingsChange()
{
    int timings;
    cout << " Movie timings u want to change : ";
    cout << "movie[]:"
         << "Show1: 3:15pm" << '\t' << "Show2: 9pm ";
    cout << "Press1 to select the timings:";
    cin >> timings;
}
void addMovies()
{
    string movie_name;
    string timing1;
    string timing2;
    cout << "Add new movie: ";
    cin >> movie_name;
    cout << "5.Add timing 1 of the movie: " << endl;
    cin >> timing1;
    cout << "6.Add timing 2 of the movie: " << endl;
    cin >> timing2;
    movie[noOfMovie]=movie_name;
    timing1[noOfMovie]= timing1;


}
void movieRecommend()
{
    string movie;
    cout << " Recommend Movie to users:" << endl;
    cin >> movie;
}
void discount()
{
}

void Customer()
{
    int option;
    cout << "Customer " << endl;
    cout << "Do you want to:" << endl;
    cout << "1. SignIN:" << endl;
    cout << "2. SignUP:" << endl;
    cout << "Select an Option: ";
    cin >> option;
    if (option == 1)
    {
        customerSignIn();
    }
    if (option == 2)
    {
        customerSignup();
    }
    else
    {
        login();
    }
}

bool customerSignIn()
{
    string name;
    string password;
    int option;

    cout << "Enter your Email address: " << endl;
    cin >> name;
    cout << "Enter your password here: " << endl;
    cin >> password;
    bool check = verifyCustomer(name, password);
    if (check == false)
    {
        return false;
    }

    return true;
}

bool verifyCustomer(string name, string password)
{
    for (int i = 0; i < arrsize; i++)
    {
        if (name == userEmail[i] && password == userpassword[i])
        {
            return true;
        }
    }
    return false;
}

void customerSignup()
{
    string email;
    string password;

    cout << "Enter your email address. ";
    cin >> email;

    for (int i = 0; i < arrsize; i++)
    {
        if (email == userEmail[i])
        {
            cout << "Already exists";
            break;
        }
        else
        {

            cout << "Enter Password. ";
            cin >> password;

            if (password.length() == 8)
            {
                userEmail[idx] = email;
                userpassword[idx] = password;

                cout << "Enter your date of birth. ";
                cin >> dateOfBirth[idx];

                cout << "Your Gender here (M for Male and F for Female). ";
                cin >> gender[idx];
            }
            else
            {
                break;
            }
        }
    }
}
void customerMenu()
{
    int option;
    cout << "1. View all movies and timings" << endl;
    cout << "2. Select a movie" << endl;
    cout << "3. Exit" << endl;
    cout << "Select an option: ";
    cin >> option;
    if (option == 1)
    {
        viewMovie();
    }
    else if (option == 2)
    {
        movieSelection();
    }
    else if (option == 3)
    {
        customerSignIn();
    }
    else
    {
        cout << "Invalid. Try again.";
    }
}
void viewMovie()
{
    cout << "Available movies:" << '\n'
         << endl;
    cout << "1.GodFather " << '\t' << "1.  3:15pm      2.  8:00pm";
    cout << "Price of tickets " << '\n'
         << "gold plus ticket price:Rs.1100" << '\n'
         << "gold ticket price:Rs.950" << '\n'
         << "silver plus ticket price:Rs.850" << '\n'
         << "silver ticket price:Rs.750" << endl;
    cout << "2.Inception " << '\t' << "1.  1:00pm      2.  5:00pm" << endl;
    cout << "Price of tickets " << '\n'
         << "gold plus ticket price:Rs.1100" << '\n'
         << "gold ticket price:Rs.950" << '\n'
         << "silver plus ticket price:Rs.850" << '\n'
         << "silver ticket price:Rs.750" << endl;
    cout << "3.Bring the Soul " << '\t' << "1.  4:00pm     2.  10:00pm" << endl;
    cout << "Price of tickets " << '\n'
         << "gold plus ticket price:Rs.1100" << '\n'
         << "gold ticket price:Rs.950" << '\n'
         << "silver plus ticket price:Rs.850" << '\n'
         << "silver ticket price:Rs.750" << endl;
    cout << "4.My Name " << '\t' << "1.  1:00am     2.  12:00pm" << endl;
    cout << "Price of tickets " << '\n'
         << "gold plus ticket price:Rs.1100" << '\n'
         << "gold ticket price:Rs.950" << '\n'
         << "silver plus ticket price:Rs.850" << '\n'
         << "silver ticket price:Rs.750" << endl;
}
void movieSelection()
{
    string movie;
    int time;
    cout << "Enter a movie you want to watch:";
    cin >> movie;
    cout << "Please book in the tickets of the type of ticket u want to see: ";
    cin >> typeofSeats[idx];
    cout << "Select timings feasible for you: ";
    cin >> time;
}
void ticketbooked()
{
    int amount;

    cout << "Amount of tickets you booked: ";
    cin >> totalseats[idx];
    for (int i = 0; i < 4; i++)
    {
        totalseats[i] = totalseats[i] - 1;
    }
    cout << "(If tickets booked more than 10) Do you want to book a family hall?: Yes/No ";
    cout << "Your total amount: ";
    cin >> amount;
    cout << "Payment.." << '\n'
         << "debt/credit card: ";
}
void done()
{
    int exit;
    cout << "THANKS! YOU HAVE SUCCESSFULLY BOOKED YOUR TICKETS" << endl;
    cout << "ENJOY YOUR TIME " << endl;
    cout << "Press '0' to exit";
    cin >> exit;
    if (exit == 0)
    {
        header();
    }
}