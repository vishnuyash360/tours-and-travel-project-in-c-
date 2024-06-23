#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
using namespace std;
int n;
fstream fout;
fstream fin;
bool validateDate(const std::string& dateString) {
    tm tm1 = {};
    istringstream ss(dateString);
    if (!(ss >> get_time(&tm1, "%d/%m/%Y"))) {
        // Parsing failed
        return false;
    }

    time_t userDate = mktime(&tm1);

    if (userDate == -1) {
        return false;
    }

    time_t currentDate = time(NULL);
    if (userDate < currentDate) {
        return false;
    }

    return true;
}
int validateName(const char* name) {
        for (int i = 0; name[i] != '\0'; ++i) {
            if (isdigit(name[i])) {
                return 0; 
            }
        }
        return 1; 
    }
  
class customer {
public:
    string username;
    char password[20];
    char email[40];
    char phoneNumber[15];
    char name[10];
    

    void signup();
    int login();
    int validateEmail(const char* email) {
    const char* gmailSuffix = "@gmail.com";
    int suffixLength = strlen(gmailSuffix);
    int len = strlen(email);
    if (len >= suffixLength && strcmp(email + len - suffixLength, gmailSuffix) == 0) {
    return 1;
    }

    return 0;
}

};
char* getHiddenPassword() {
    const char BACKSPACE = 8;
    const char ENTER = 13;

    char* password = new char[20];
    char ch;
    int i = 0;    while ((ch = _getch()) != ENTER) {
        if (ch == BACKSPACE && i > 0) {
            cout << "\b \b"; 
            i--;
        } else if (isprint(ch)) {
            cout << '*';
            password[i++] = ch;
        }
    }

    password[i] = '\0'; 
    cout << endl;

    return password;
}
void customer::signup() {
    cout << "\nEnter your name: ";
    cin>>name;
    if (!validateName(name)) {
        cout << "Invalid name. Please use only alphabetic characters.\n";
        return;
    }
  cout << "\nEnter your username: ";
    cin.ignore();
    getline(cin, username);

    cout << "\nEnter your password: ";
        strcpy(password, getHiddenPassword());
    cout << "\nEnter your email: ";
    cin>>email;
    if (validateEmail(email)) {
    cout << "Valid email. Registration successful!\n";
    } else {
    cout << "Invalid email. Please use a valid Gmail address.\n";
    return;
    }

    cout << "\nEnter your phone number: ";
    cin>>phoneNumber;
    if (strlen(phoneNumber) != 10) {
    if (phoneNumber[0] != '6' || phoneNumber[0] != '7'|| phoneNumber[0] != '8' || phoneNumber[0] !='9'){
    cout<<"Invalid Phone Number Please Reenter the Phone Number :"<<endl;
    return;
    }
    }
    

    ofstream fout("users.txt", ios::app);

    if (!fout) {
    cout << "Error opening file!" << endl;
    exit(1);
    }

    fout << username << " " << password << " " << email << " " << phoneNumber << " " << name << endl;

    fout.close();

    cout << "\nSignup successful!\n";
}
int customer::login() {
     string username1;
     char password1 [30];
    cout << "Enter username: ";
    cin >> username1;
    cout << "Enter password: ";
     strcpy(password1, getHiddenPassword());
    ifstream fin("users.txt");

    if (!fin) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    string user, pass, checkEmail, checkPhone, checkName;

    while (fin >> user >> pass >> checkEmail >> checkPhone >> checkName) {
        if (username1 == user && password1 == pass) {
            fin.close();
            return 1;
        }
    }

    fin.close();
    return 0;
}

class rail {
public:
    int mem ;
    char name1[20];
    char id[30];
    unsigned int price;
    char dest[50];
    string date;
    int seatNumber;
    char train_no[20];

    
    rail() {
    mem = 0;
    price = 0;
    }

    char* ret_name() {
    return name1;
    }

    char* ret_id() {
    return id;
    }

    void travelling(int);
    void output();

    int validateEmail(const char* email) {
    const char* gmailSuffix = "@gmail.com";
    int suffixLength = strlen(gmailSuffix);
    int len = strlen(email);

    if (len >= suffixLength && strcmp(email + len - suffixLength, gmailSuffix) == 0) {
    return 1;
    }

    return 0;
}
} r;
void rail::travelling(int mem) {
    int xx;
    cout << "\n 1235.Train-> Delhi to Bhopal";
    cout << "\n 2854.Train-> Delhi to Patna";
    cout << "\n 3545.Train-> Delhi to Varanasi";
    cout << "\n 4753.Train-> Delhi to Punjab";
    cout << "\n 5951.Train-> Delhi to Lucknow";
    cout << "\n Enter your choice : ";
    cin >> xx;
    cout << "\n Booking confirmed";
    if (xx == 1) {
    price = (mem * 1000);
    strcpy(dest, "Delhi_to_Bhopal");
    strcpy(train_no, "1235");
        }
    if (xx == 2) {
    price = (mem * 800);
    strcpy(dest, "Delhi_to_Patna");
    strcpy(train_no, "2854");
    }
    if (xx == 3) {
    price = (mem * 500);
    strcpy(dest, "Delhi_to_Varanasi");
    strcpy(train_no, "3545");
    }
    if (xx == 4) {
    price = (mem * 450);
    strcpy(dest, "Delhi_to_Punjab");
    strcpy(train_no, "4753");
    }
    if (xx == 5) {
    price = (mem * 600);
    strcpy(dest, "Delhi_to_Lucknow");
    strcpy(train_no, "5951");
    }
    cout << "\nTrain Number :" <<train_no << endl;
    cout << "\ngenerted price :" << price << endl;
   
}
void rail::output() {
   cout << "\n NAME : " << name1;
    cout << "\n E-MAIL : " << id;
    cout << "\n PASSENGERS : " << mem;
    cout << "\n DESTINATION : " << dest;
    cout << "\n TRAVELLING PRICE : " << price;
    cout << "\n TRAVELLING DATE : " << date << endl;
    cout << "\nTrain Number :" <<train_no << endl;

}

void entry1() {
    fout.open("Train.txt",ios::out|ios::app);
    while (1) {
    cout << "\n Enter your name : ";
    cin>>r.name1;
    if (!validateName(r.name1)) {
        cout << "Invalid name. Please use only alphabetic characters.\n";
        return;
    }
    cout << "\n Enter e-mail id : ";
    cin>>r.id;
    if (r.validateEmail(r.id)) {
    cout << "Valid email. Registration successful!\n";
    } else {
    cout << "Invalid email. Please use a valid Gmail address.\n";
    return;
    }
    cout << "\nEnter date of journey (dd/mm/yyyy): ";
    cin.ignore();
    getline(cin, r.date);
    if (validateDate(r.date)) {
        cout << "The date is valid." << endl;
    } else {
        cout << "The date is invalid. It cannot be earlier than today's date." << endl;
        return;
    }
    cout << "\n Enter the no. of passengers you are travel with : ";
    cin >> r.mem;
    if (r.mem >= 1 && r.mem <= 8) {
    r.travelling(r.mem);
    }
    for (int i = 0; i < r.mem; ++i) {
    r.seatNumber = rand() % 250 + 1;
    cout << "Seat for Passenger " << i + 1 << ": " << r.seatNumber << endl;
    }

        fout << r.name1 << " " << r.id << " " << r.price << " " << r.dest << " " << r.date << endl;
        break;
    }
    fout.close();
}

void display1() {
    fin.open("Train.txt", ios::in);
     if (!fin) {
    cout << "Error opening input file!" << endl;

    }

    while (fin >> r.name1 >> r.id >> r.price >> r.dest>>r.date) {
    cout << "\n NAME : " << r.name1;
    cout << "\n E-MAIL : " << r.id;
    cout << "\n PASSENGERS : " << r.mem;
    cout << "\n DESTINATION : " << r.dest;
    cout << "\n TRAVELLING PRICE : " << r.price;
    cout << "\n TRAVELLING DATE : " << r.date << endl;
    }
    fin.close();
}
 
void search1() {
    fin.open("Train.txt", ios::in);
    char n[20];
    cout << "\nSearch Your Booking by name : ";
    cin>>n;
    while (fin >> r.name1 >> r.id >> r.price >> r.dest>>r.date) {
    if (strcmpi(n, r.ret_name()) == 0) {
        r.output();
    }
    }
    fin.close();
}

void delete_booking1(char* id) {
    fin.open("Train.txt", ios::in);
    fout.open("new.txt", ios::out);
    char found = 'n';

    while (fin >> r.name1>> r.id >> r.price >> r.dest>>r.date) {
    if (strcmpi(id, r.ret_id()) != 0) {
        fout << r.name1 << " " << r.id << " " << r.price << " " << r.dest << endl;
    } else {
        found = 'y';
    }
    }

    fin.close();
    fout.close();

    if (found == 'n') {
    cout << "\n Record not found";
    } else {
    cout << "\n Account deleted\n";
    remove("Train.txt");
    rename("new.txt", "Train.txt");
    }
}


void train() {
    int x;
    char ans;
    char id1[30];
    do {
        
    cout << "\n....WELCOME TO RAILWAY SERVICES....";
    cout << "\n 1.Booking for train";
    cout << "\n 2.Display bookings";
    cout << "\n 3.Search your booking";
    cout << "\n 4.Delete booking";
    cout << "\n 5.Back To Main Menu";
    cout << "\n enter your choice : ";
    cin >> x;
    switch (x) {
        case 1:
        entry1();
        break;
        case 2:
        display1();
        break;
        case 3:
        search1();
        break;
        case 4:
        cout << "\n Enter the id to be deleted : ";
        cin >>id1;
        delete_booking1(id1);
        break;
        case 5:
           return ;
       }

    } while (x!=5);
}

class Travel {
    public:
    int mem;
    char name[20];
    char id[30];
    char tra;
    string date;
    unsigned int price;
    char dest[30];
    char plane_no[20];
    int seatNumber;
    Travel() {
    mem = 0;
    tra = 'a';
    price = 0;
    }

    char ret_tra() {
    return tra;
    }

    char* ret_name() {
    return name;
    }

    char* ret_id() {
    return id;
    }
    void travelling(char, int);
    void output();
    int validateEmail(const char* email) {
    const char* gmailSuffix = "@gmail.com";
    int suffixLength = strlen(gmailSuffix);
    int len = strlen(email);

    if (len >= suffixLength && strcmp(email + len - suffixLength, gmailSuffix) == 0) {
    return 1;
    }

    return 0;
    
}
}t;
void Travel::travelling(char choice, int mem) {
    int xx;
    if (choice == 'n' || choice == 'N') {
    cout << "\n 1.Flight-> Delhi to Jaipur";
    cout << "\n 1.Flight-> Mumbai to Bangalore";
    cout << "\n 1.Flight-> Kolkata to Chennai";
    
    cout << "\n Enter your choice : ";
    cin >> xx;
    
    if (xx == 1) {
        price = (mem * 2500);
        strcpy(dest, "Delhi_to_Jaipur");
        strcpy(plane_no, "3456");
    }
    else if (xx == 2) {
        // Case 2
        price = (mem * 3000);
        strcpy(dest, "Mumbai_to_Bangalore");
        strcpy(plane_no, "7890");
    } else if (xx == 3) {
        // Case 3
        price = (mem * 2000);
        strcpy(dest, "Kolkata_to_Chennai");
        strcpy(plane_no, "1234");
    }
    }

    if (choice == 'i' || choice == 'I') {
    cout << "\n 1.Flight-> Delhi to USA";
    cout << "\n 2.Flight-> Delhi to Dubai";
    cout << "\n 3.Flight-> Delhi to Chicago";
    cout << "\n 4.Flight-> Delhi to Paris";
    cout << "\n Enter your choice : ";
    cin >> xx;
    if (xx == 1) {
        price = (mem * 7000);
        strcpy(dest, "Delhi_to_USA");
        strcpy(plane_no, "5248");
    }
    if (xx == 2) {
        price = (mem * 17000);
        strcpy(dest, "Delhi_to_Dubai");
        strcpy(plane_no, "9856");
        
    }
    if (xx == 3) {
        price = (mem * 10000);
        strcpy(dest, "Delhi_to_Chicago");
        strcpy(plane_no, "8574");
    }
    if (xx == 4) {
        price = (mem * 16000);
        strcpy(dest, "Delhi_to_Paris");
        strcpy(plane_no, "2331");
    }
    }
    cout << "\n Booking confirmed";
    cout << "\nPlane Number :" <<plane_no << endl;
    cout << "\n Price generated:" << price << endl;
}

void Travel::output() {
    cout << "\n NAME : " << name;
    cout << "\n E-MAIL : " << id;
    cout << "\n PASSENGERS : " << mem;
    cout << "\n DESTINATION : " << dest;
    cout << "\n TRAVELING PRICE : " << price;
    cout << "\n TRAVELING DATE : " << date;

}

void entry() {
    char ch = 'y';
    ofstream fout("fly2.txt", ios::app);
    while (ch == 'y' || ch == 'Y') {
        system("cls");
        cout << "\n Enter your name : ";
    cin.ignore();
    cin.getline(t.name, sizeof(t.name));
    if (!validateName(t.name)) {
        cout << "Invalid name. Please use only alphabetic characters.\n";
        return;
    }
    cout << "\n Enter e-mail id : ";
    cin.getline(t.id, sizeof(t.id));
    if (t.validateEmail(t.id)) {
    cout << "Valid email. Registration successful!\n";
    } else {
    cout << "Invalid email. Please use a valid Gmail address.\n";
    return;
    }
    cout << "\nEnter date of journey (dd/mm/yyyy): ";
    cin>> t.date;
    if (validateDate(t.date)) {
        cout << "The date is valid." << endl;
    } else {
        cout << "The date is invalid. It cannot be earlier than today's date." << endl;
        return;
    }
    cout << "\n Enter the no. of passengers you are traveling with : ";
    cin >> t.mem;
    if (t.mem >= 1 && t.mem <= 10) {
    cout << "\n Where you want to travel (National = N & International = I) : ";
    cin >> t.tra;
    }
    t.travelling(t.tra, t.mem);
    for (int i = 0; i < r.mem; ++i) {
    t.seatNumber = rand() % 250 + 1;
    cout << "Seat for Passenger " << i + 1 << ": " << t.seatNumber << endl;
    }

        fout << t.ret_name() << " " << t.ret_id() << " " << t.dest << " " << t.price << " " << t.mem << " " << t.date << endl;
        cout << "\n More Record (Y/N) : ";
        cin >> ch;
    }
    fout.close();
}

void display() {
    ifstream fin("fly2.txt", ios::in);
    if (!fin) {
        cout << "Error opening input file!" << endl;
    }
    while ( fin >> t.name >> t.id >> t.dest >> t.price >>t.mem>> t.date) {
        
            t.output();
            cout<< endl;
            break;
        }
        fin.close();

}

void search() {
    fin.open("fly2.txt",ios::in);
    char n[20];
    cout << "\nSearch Your Booking by name : ";
    cin.ignore();
    cin.getline(n, sizeof(n));
   fin >> t.name >> t.id >> t.dest >> t.price >>t.mem>> t.date;
    while (!fin.eof()) {
    if (strcmpi(n, t.ret_name()) == 0) {
        t.output();
    }
    break;
    }
    fin.close();
}

void delete_booking(char* id) {
    fin.open("fly2.txt", ios::in);
    fout.open("second.txt", ios::out);
    char found = 'n';

   fin >> t.name >> t.id >> t.dest >> t.price >>t.mem>> t.date;
    while (!fin.eof()) {
        if (strcmpi(id, t.ret_id()) != 0) {
            fout << t.name << " " << t.id << " " << t.price << " " << t.dest << endl;
        } else {
            found = 'y';
        }
        break;
    }

    fin.close();
    fout.close();

    if (found == 'n') {
        cout << "\n Record not found";
    } else {
        cout << "\n Account deleted\n";
       
        remove("fly2.txt");
        rename("second.txt", "fly2.txt");
    }
}
 

void flight() {
    int x;
    char ans;
    char id1[30];
    do {
    
    cout << "\n....WELCOME TO AIRWAY SERVICES....";
    cout << "\n 1.Booking for flight";
    cout << "\n 2.Display bookings";
    cout << "\n 3.Search your booking";
    cout << "\n 4.Delete booking";
    cout << "\n 5.Return To Main Menu";
    cout << "\n enter your choice : ";
    cin >> x;
    switch (x) {
        case 1:
        entry();
        break;
        case 2:
        display();
        break;
        case 3:
        search();
        break;
        case 4:
        cout << "\n Enter the id to be deleted : ";
        cin >> id1;
        delete_booking(id1);
        break;
        case 5:
        return;
        default:
        cout << "\n Try Again\n";
    }
       } while (x!=5);
}

class Taxi {
    public:
    int mem;
    char name[20];
    char id[30];
    unsigned int price;
    int dest;
    int base;
    int pkm;
    int distance;
    string date;
    string cab_no;
    Taxi() {
    mem = 0;
    price = 0;
    pkm = 15;
    base = 50;
    }

    char* ret_name() {
    return name;
    }

    char* ret_id() {
    return id;
    }

    void input();
    void travelling(int);
    void output();
    int validateEmail(const char* email) {
    const char* gmailSuffix = "@gmail.com";
    int suffixLength = strlen(gmailSuffix);
    int len = strlen(email);

    if (len >= suffixLength && strcmp(email + len - suffixLength, gmailSuffix) == 0) {
    return 1;
    }

    return 0;
}
string generateCabNumber() {
    string cabNumber = "Cab-";
    for (int i = 0; i < 3; ++i) {
        char randomLetter = 'A' + rand() % 26; // ASCII value of 'A' is 65
        cabNumber += randomLetter;
    }
    for (int i = 0; i < 4; ++i) {
        char randomDigit = '0' + rand() % 10; // ASCII value of '0' is 48
        cabNumber += randomDigit;
    }
    return cabNumber;
}
}ti;

void Taxi::travelling(int dest) {
    switch (dest){
        case 1:
        distance = 15;
        break;
        case 2:
        distance = 20;
        break;
        case 3:
        distance = 30;
        break;
        case 4:
        distance = 15;
        break;
        case 5:
        distance = 5;
        break;
        case 6:
        distance = 17;
        break;
    }
    price = base + (pkm * distance);
        cout << "\n Booking confirmed";
        cout << "\n Price generated\n"<<price;
}

void Taxi::input() {
    cout << "\n Enter your name : ";
    cin.ignore();
    cin.getline(name, sizeof(name));
    if (!validateName(name)) {
        cout << "Invalid name. Please use only alphabetic characters.\n";
        return;
    }
    cout << "\n Enter e-mail id : ";
    cin.getline(id, sizeof(id));
    if (validateEmail(id)) {
    cout << "Valid email. Registration successful!\n";
    } else {
    cout << "Invalid email. Please use a valid Gmail address.\n";
    return;
    }
    cout << "\nEnter date of journey (dd/mm/yyyy): ";
   cin >> date; 
    if (validateDate(date)) {
        cout << "The date is valid." << endl;
    } else {
        cout << "The date is invalid. It cannot be earlier than today's date." << endl;
        return;
    }
    cab_no=generateCabNumber();
    cout << "\n Enter the no. of passengers you are traveling with : ";
    cin >> mem;
    if (mem >= 1 && mem <= 6) {
    cout << "\n Enter the destination : \n 1. Market \n2.Hospital\n3.School\n4.Police Station\n5.Mall";
    cin >> dest;
    travelling(dest);
    } else
    exit(1);
}

void Taxi::output() {
    cout << "\n NAME : " << name;
    cout << "\n E-MAIL : " << id;
    cout << "\n PASSENGERS : " << mem;
    cout << "\n DISTANCE : " << distance<<"KM.";
    cout << "\n TRAVELING PRICE : " << price;
    cout<< "\n Cab Date:"<<date;
    cout << "\n Cab Number:"<<cab_no;
    }

void entry2() {
    fout.open("taxi.txt", ios::app);
    while (1) {
    system("cls");
    Taxi ti;
    ti.input();
    fout << ti.ret_name() << " " << ti.ret_id() << " " << ti.distance << " " << ti.price << " " << ti.mem << " " << ti.date << " " << ti.cab_no << endl;
        break;
    }
    fout.close();
}

void display2() {
    fin.open("taxi.txt",ios::in);
    while (fin >> ti.name >> ti.id >> ti.distance >> ti.price >> ti.mem >> ti.date >>ti.cab_no ) {
    cout << "\n NAME : " << ti.name;
    cout << "\n E-MAIL : " << ti.id;
    cout << "\n PASSENGERS : " << ti.mem;
    cout << "\n DISTANCE : " << ti.distance<<"KM.";
    cout << "\n TRAVELING PRICE : " << ti.price;
    cout << "\n Cab Number:"<<ti.cab_no;
    cout << "\n Date:"<<ti.date;
    
    cout << endl;
    }
    fin.close();
}

void search2() {
    fin.open("taxi.txt",ios::in);
    char n[20];
    cout << "\nSearch Your Booking by name : ";
    cin.ignore();
    cin.getline(n, sizeof(n));
    while (fin >> ti.name >> ti.id >> ti.distance >> ti.price >> ti.mem >> ti.date >>ti.cab_no ) {
    if (strcmpi(n, ti.ret_name()) == 0) {
        ti.output();
    }
    }
    fin.close();
}

void delete_booking2(char* id) {
    fin.open("taxi.txt",ios::in);
    fout.open("data.txt", ios::out | ios::app);
    char found = 'n';
    while (fin >> ti.name >> ti.id >> ti.distance >> ti.price >> ti.mem >> ti.date >>ti.cab_no) {
    if (strcmpi(id, ti.ret_id()) != 0) {
       fout << ti.ret_name() << " " << ti.ret_id() << " " << ti.distance << " " << ti.price << " " << ti.mem << " " << ti.date << " " << ti.cab_no << endl;
    } else {
        found = 'y';
    }
    }
    fin.close();
    fout.close();
    if (found == 'y') {
    cout << "\n Account deleted\n";
    }
    else{
    cout << "\n record not found"; }
    remove("taxi.txt");
    rename("data.txt", "taxi.txt");
}

void road() {
    int x;
    char ans;
    char id1[30];
    do {
        
    cout << "\n....WELCOME TO ROADWAY SERVICES....";
    cout << "\n 1.Booking for taxi";
    cout << "\n 2.Display bookings";
    cout << "\n 3.Search your booking";
    cout << "\n 4.Delete booking";
    cout << "\n 5.Return To Main Menu";
    cout << "\n enter your choice : ";
    cin >> x;
    switch (x) {
        case 1:
        entry2();
        break;
        case 2:
        display2();
        break;
        case 3:
        search2();
        break;
        case 4:
        cout << "\n Enter the id to be deleted : ";
        cin >> id1;
        delete_booking2(id1);
        break;
        case 5:
        return;
       default:
       cout<<"wrong choice"<<endl;
    }

    } while (x!=5);
}

int main() {
    customer t1;
    int loggedIn = 0;
    
    do{
     cout <<"**********************************************************************\n";
     cout<<"*                                                                    *\n";
    cout <<"*....................Journey Quest Tours and Travel..................*\n";
    cout<<"*                                                                    *\n";
    cout << "*********************************************************************\n";
    cout<<"1 New User"<<endl;
    cout<<"2 Existing User"<<endl;
    cout<<"3 Book Train"<<endl;
    cout<<"4 Book Cab"<<endl;
    cout<<"5 Book Flight"<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"enter your choice :";
    cin>>n;
    switch (n){
    case 1:
     t1.signup();
        break;
     case 2:
     loggedIn = t1.login();
     if (loggedIn)
    cout << "Login successful!" << endl;
     else
    cout << "Login failed. Incorrect username or password." << endl;
    break;
    case 4:
        road();
        break;
     case 3 :
        train();
        break;
     case 5:
        flight();
        break;
    case 0:
        cout << "Exiting program. Goodbye!" << endl;
    break;
    default:
        cout << "Invalid choice! Please enter a valid option." << endl;
    }
    }
     while (n!=0);
 return 0;}
