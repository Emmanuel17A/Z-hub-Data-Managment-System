//FILE: 	ASSIGNMENT 1.cpp

//TITLE: 	Z HUB INNOVATOR's INFORMATION  MANAGEMENT SYSTEM

//SUBMITTED BY:

//GROUP MEMBERS : FULLNAMES                   : SIN                  : PROGROGRAM
/*            1 : Silas Chalwe                : 22177295             : Computer Engineering
              2 : Patience Mbewe              : 22175460             : Computer Science
              3 : Mwaba Emmanuel Mwangata     : 22109426             : Computer Science
              4 : William  Kalembwe           : 22103053             : Computer Science
              5 : Juma  Tandanya              : 22105146             : Computer Science
*/

//COURSE 	 	- 	INTRODUCTION TO PROGRAMMING FUNDAMENTALS
//COURSE  CODE	 	- 	CS150
//LECTURER	-	MR HAZEAL PHIRI
//DUE DATE	-	 14TH, NOVEMBER 2023

/*PURPOSE -   Z-Hub is an innovation hub that helps innovators bring their innovation to a stage
              where they can be commercialized.the program will help manage all innovator's data records and activities.
			  It provides abilities such as deletion of  innovator's and adding of
			  innovator's to the system, and also enables technicians  to view and search innovator's records.

*/
//ACTORS	- 	HUB MANAGER
//			-	COORDINATOR
//			-	TECHNICIAN

// THE RECORDS FOR INNOVATORS IS STORED IN A TEXT FILE CALLED "Innovator's Records.txt"
// FOR BACK UP ,BACK UP FILE CALLED "backup.txt" WAS CREATED
// FOR SECURITY THE :
//PASSWORDS FOR THE  HUB MANAGER  AND COORDINATOR ARE STORED IN A TEXT FILE NAMED "AdminSecurtyRecord.txt".
//PASSWORDS FOR THE TECHNICIAN ARE STORE IN A TEXT FILE NAMED "TECHSecurtyRecord.txt" IN  PROJECT FOLDER.
//FOR TESTING PURPOSES LOGIN CREDENTIALS FOR THE:
//                                               - HUB MANAGER  : ID = 2021, PASSWORD = test1234
//                                               - COORDINATOR  : ID = 2022, PASSWORD = test1234
 //                                              - TECHNICIAN   : ID = 2023, PASSWORD = test1234


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//global variable this means that they can be used by any functon
//int option;
int login_allowed; //stores a value returned from the login function thats used for checking if login is successfull or not

struct innovetors_Info//an array struct that will hold the details of innovators during the system run time
{
    string firstname;
    string surname;
    string passportNumber;
    string title;
    string category;
     int    age;
    string    patent_Status;
    string date_submission;
};
struct innovetors_Info innovetor[10];//will hold 10 innovetors and there respective details or information

//function prototype and the overall function in the program
void display_CATEGORY();
void edit(int);
void  DELETE(int);
void forgot_password();
int  Search(string);
void Add_innovator();
int login(string);
void terminate_program();
void welcomeheader();
void manager(int);
int display();
void welcome();
int addvarifyNRC_PASSPORT(string);//check if the nrc or passport been used for registration is already in the system or not
void wait(double);
void program();
void list_innovator();

//main function and where the execution of the program start from and ends
int main()
{
    program();
    return 0;

}

//the program
 void program()
{
    int select;//a variable used to store a value returned from the display function thats used for checking the selected option
    welcome();
    while (true)//user input varification
    {

        select = display();//function calling and assignment
        if (select == 1 || select == 2 || select == 3 || select == 4||select==5)
        {
            break;
        }
        else { cout << "\n\n\t\t\t\t\twrong option"; wait(10); system("cls"); }
    }


    if (select == 1)//managers section and execution
    {
        login_allowed = login("AdminSecurtyRecord.txt");
        system("cls"); welcomeheader();
        if (login_allowed == 1)
        {
            cout << "\n\n\n\t\t\t\t\t\tLogin successfully!\n\n\t\t\t\t\t\tAs Manager\n" << endl;
            wait(40);
            system("cls"); welcomeheader();

            manager(login_allowed);
        }

    }//end of maneger function
    else if (select == 2)//coordinator section and execution
    {
        login_allowed = login("AdminSecurtyRecord.txt");
        system("cls"); welcomeheader();
        if (login_allowed == 1)
        {
            cout << "\n\n\n\t\t\t\t\t\tLogin successfully!\n\n\t\t\t\t\t\tAs Coordinator\n" << endl;
            wait(40);
            system("cls"); welcomeheader();
            manager(login_allowed);
        }
    }
    else if (select == 3)//technicians section
    {
        system("cls"); welcomeheader();
        int converted_user_input;//used for exceptional handling
        login_allowed = login("TECHSecurtyRecord.txt");
        system("cls"); welcomeheader();
        if (login_allowed == 1)// returned value of 1 indicate login success
        {
                cout << "\n\n\n\t\t\t\t\t\tLogin successfully!\n\n\t\t\t\t\t\tAs Technician\n" << endl;
                wait(40); system("cls"); welcomeheader();
                while (true)// this implies  that if user keep entering unfound NRC or PASSPORT it will keep asking the user to enter the NRC or PASSPORT
               {
                string passport;
                cout << "\n\n\t\t\t\t Enter innovator's NRC/PASSPORT you wish to search :\n" << endl;
                cout << "\t\t\t\t\t"; cin >> passport;
                Search(passport);//the entered passport will be passed to search function for searching
                cout << "\n\n\t\t\t\t press 1 to go back or any key to exit :\n" << endl;

                string get_user_input_to_continue;//stores the users choice(value) if they wish to continue using the progam or not
                cin >> get_user_input_to_continue;
                //exceptional handling and convertion
                try{converted_user_input = stoi(get_user_input_to_continue);}
                catch(...){   converted_user_input = 0;}

                if (converted_user_input != 1) { terminate_program();  break; }

                system("cls"); welcomeheader();
                }
        }
    }
    //terminate if user select 4
    else if (select == 5)//if user to choice to exit
    {
        terminate_program();
    }
    else if (select==4)
    {
        forgot_password();
    }

   // return 0;
}
//end of program function and end of program execution


void wait(double maxprocess)//time processing function it ask the user to wait for a specific amount of time
{
    const int  waitlimit = 10000000;
    cout << "\n\n\t\t\t\t\t       Please wait......";
    double minprocess=0;
    maxprocess *= waitlimit;
    while (minprocess <= maxprocess)
    {
        minprocess++;
    }
}
//home page displayer function
int display()
{
    int Option;
    string option;

    welcomeheader();
     cout << "\n\n\t\t\t\t                         HOME PAGE\n ";
    cout << "\n\n\n\n\t\t\t\t1) Manager";
    cout << "\n\n\t\t\t\t2) Coordinator";
    cout << "\n\n\t\t\t\t3) Technician ";
    cout << "\n\n\t\t\t\t4) forgot your password";
    cout << "\n\n\t\t\t\t5) Exit the program \n\t\t\t\t_________________________________________________________________\n ";
    cout << "\t\t\t\t>> "; cin >> option;
    //exceptional handling
    try { Option = stoi(option); }
    catch (...)
    {
        Option = 0;
    }
    return Option;

}
//welcome function it desplays the below message as header ititle
void welcomeheader() {
    cout << "\t\t\t\t__________________________________________________________________\n";
    cout << "\t\t\t\t****WELCOME TO Z HUB INNOVETORS INFORMATION MANAGEMENT SYSTEM****\n";
    cout << "\t\t\t\t__________________________________________________________________\n";

}
void welcome()//display a welcome message at the first start of the program
{

    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME";
    cout << "                "; wait(40);
    system("cls");

}
// Function to verify user credentials from a file
bool verifyCredentials(const string& username, const string& password, ifstream& file) {
    string storedUsername, storedPassword;

    // Loop through each line in the file
    while (file >> storedUsername >> storedPassword) {
        // Check if the provided username and password match the stored credentials
        if (username == storedUsername && password == storedPassword) {
            return true; // Return true if the credentials match
        }
    }

    return false; // Return false if no matching credentials are found
}//end of verifying credentials

//login function  returns 1 if login succeed return  2 if fails return -1 indicating a failed login due to none existing file
int login(string filname) {

    system("cls");
    // Open the credentials file for reading and  Check if the file was opened successfully
    ifstream credentialsFile(filname, ios::app);
    if (!credentialsFile.is_open())
    {
        cout << "\n\t\t\t\tError: Unable to open credentials file." << endl;
        return -1; // Exit with an error code
    }

    string username, password;
    int attempts = 3;

    while (attempts > 0)//if the file is open
    {
        welcomeheader();
        //prompt the user to enter spepecific details
        cout << "\n\n\n\t\t\t\t\t\tEnter username: ";
        cin >> username;
        cout << "\n\n\n\t\t\t\t\t\tEnter password: ";
        cin >> password;
        //verify if user provided details is varied by passing it to verify credidentials
        if (verifyCredentials(username, password, credentialsFile)) {
            system("cls");

            return 1;
            break;
        }
        else {
            system("cls"); welcomeheader();

            cout << "\n\n\n\t\t\t\t\tInvalid credentials. Attempts remaining: " << --attempts << endl;
            wait(20);
            system("cls");
        }
        // Reset file position to the beginning for the next attempt
        credentialsFile.clear();
        credentialsFile.seekg(0, ios::beg);
    }
    // Allow the user three login attempts

    if (attempts == 0) {
        welcomeheader();
        cout << "\n\n\n\t\t\t\t\tToo many failed attempts. Access denied. system blocked!! " << endl; wait(30);
        terminate_program();
        // wait(60);  system("cls");


        return 2;//deny access
    }

    credentialsFile.close(); // Close the file when done
    return 0; //Exit the program
}

//manger function
void manager(int choice)
{
    //int choice;
    int press;
    //  choice = login("AdminSecurtyRecord.txt");
    if (choice == 1)
    {
        while (choice == 1)
        {

            system("cls"); welcomeheader();
            cout << "\n\n\n";
            cout << "\n\n\t\t\t\t1) Add Innovator\n";
            // cout<<"\n\t\t\t\t\t2.Delete Innovator";
            cout << "\n\n\t\t\t\t2) Search Innovator\n";
            // cout<<"\n\t\t\t\t\t3.Edit Innovator";
            cout << "\n\n\t\t\t\t3) Display Innovator by category\n";
            cout << "\n\n\t\t\t\t4) display available innovators \n";
             cout << "\n\n\t\t\t\t5) Exit the program\n";
            cout << "\t\t\t\t__________________________________________________________________\n";
            cout << "\n\t\t\t\t>> "; cin >> press;
            //crush
           // if(press==5){list_innovator();}
            if (press == 1)
            {
                Add_innovator();
            }

            else if (press == 2)
            {
                system("cls"); welcomeheader();
                int from_search;
                int get_user_choice;
                string EnteredpassportNumber;

                cout << "\n\n\t\t\t\t Enter innovator's NRC/PASSPORT you wish to search :\n" << endl;
                cout << "\t\t\t\t\t"; cin >> EnteredpassportNumber;

                from_search = Search(EnteredpassportNumber);
                system("cls"); welcomeheader();
                cout << "\n\n\n\t\t\t\t\t\t\t INNOVATOR FOUND!! " << endl;
                cout << "\n\t\t\t\t\tWhat do you wish to do with the found innovator ?\n";
                cout << "\n\t\t\t\t\t1.Delete Innovator \n";
                cout << "\n\t\t\t\t\t2.Edit Innovator\n";

                cout << "\n\t\t\t\t\t3.Go back to main menu \n";
                cout << "\n\t\t\t\t\t4.exit the program\n";
                cout << "\t\t\t\t__________________________________________________________________\n";

                cout << "\n\t\t\t\t\t>>"; cin >> get_user_choice;

                 //crushing
                  if (get_user_choice == 1 || get_user_choice == 2 || get_user_choice == 3 || get_user_choice == 4)
                {




                    if (get_user_choice == 1)
                    {
                        //delete
                        DELETE(from_search);

                        //  cout<<"delete ";break;
                    }
                    else if (get_user_choice == 2)
                    {
                        //edit
                        string  Do_you_want_to_continue;
                        int yes_do_to_continue;
                        edit(from_search);
                        system("cls"); welcomeheader();

                        cout << "\n\n\n\t\t\t\tInnovator found edited successfully\n\n";
                        cout << "\n\n\n\t\t\t\ttWhat do you wish to do found ? \n \n ";
                        cout << "\n\n\n\t\t\t\t1.Edit again\n\n";
                        cout << "\n\n\n\t\t\t\t2.Go back to main menu\n\n";
                        cout << "\n\n\n\t\t\t\t\3.Press any key to exit the program\n\n";


                        cout << "\t\t\t\t__________________________________________________________________\n";
                        cout << "\n\t\t\t\t\t>>"; cin >> Do_you_want_to_continue;
                        //exceptional handling
                        system("cls");
                        try { yes_do_to_continue = stoi(Do_you_want_to_continue); }  catch(...)  {      yes_do_to_continue = 0;  }

                        if (yes_do_to_continue==1)
                          {
                            edit(from_search);
                        }
                        else if (yes_do_to_continue == 2)
                        {
                            manager(choice);
                        }
                        else
                        {

                            terminate_program();

                        }

                    }



                    else if (get_user_choice == 3)
                    {
                        int main_menu = 1;

                        manager(main_menu);
                    }
                    else
                    {
                        //exit
                        // cout << "\n\n\t\t\t\t4) Exit\n";
                        terminate_program();
                    }
                }
                else
                {
                    cout << "\n\t\t\t\t Invalid option \n";

                }


            }



            else if (press == 3)
            {
                display_CATEGORY();
            }
            else if (press == 4)
            {   list_innovator(); }
            else if(press==5){
                terminate_program();
            }

            else { cout << "wrong option"; }


        }
    }
    else {
        welcomeheader();
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t SYSTEM BLOCKED!!";
    }
}
void Add_innovator() {

    int ask,  from_add_verify_NRC;
    fstream addtofile; addtofile.open("Innovator's Records.txt", ios::app);
    system("cls");
    //cout<<"\n\n\n\n";
    welcomeheader();
    do {

        if (!addtofile) { cout << "error"; }
        else
        {
            cout << "\n\n\n\t\t\t\t\t\tEnter your first name\n\n ";
            cout << "\t\t\t\t\t\t"; cin >> innovetor[1].firstname;
            system("cls"); welcomeheader();

            cout << "\n\n\n\t\t\t\t\t\tEnter your surname\n\n ";
            cout << "\t\t\t\t\t\t"; cin >> innovetor[1].surname;
            system("cls"); welcomeheader();

          do {
                cout << "\n\n\n\t\t\t\t\t\tEnter your NRC/passport no(xxxxxx/xx/x)\n\n";
                cout << "\t\t\t\t\t\t"; cin >> innovetor[1].passportNumber;
                //check if innovator entered id is in the system
                   from_add_verify_NRC=addvarifyNRC_PASSPORT(innovetor[1].passportNumber);

          } while (from_add_verify_NRC == 0);
           // end of checking
          // adding innovator starts here
            system("cls"); welcomeheader();
            cout << "\n\n\n\t\t\t\t\t\tEnter your age\n\n ";
            cout << "\t\t\t\t\t\t"; cin >> innovetor[1].age;

            system("cls"); welcomeheader();
            cout << "\n\n\n\t\t\t\t\t\tEnter your innovation title (without spaces  but special charecters are allowed)\n\n";
            cout << "\t\t\t\t\t\t"; cin >> innovetor[1].title;

            system("cls"); welcomeheader();
            cout << "\n\n\n\t\t\t\t\t\tEnter your date of submission(dd/mm/yyyy)\n\n";
            cout << "\t\t\t\t\t\t"; cin >> innovetor[1].date_submission;
            system("cls"); welcomeheader();
            string getpatentstatus;
            cout << "\n\n\n\t\t\t\t\t\tEnter patent status \n\n\t\t\t\t\t1.Patented\n\n\t\t\t\t\t2.Inprogress\n\n\t\t\t\t\t3.Not required\n";
            cout << "\t\t\t\t\t\t"; cin >> getpatentstatus;
            if (getpatentstatus == "1") { innovetor[1].patent_Status = "Patented"; }
            else if (getpatentstatus == "2") { innovetor[1].patent_Status = "Inprogress"; }
            else { innovetor[1].patent_Status = "Not_required"; }


            system("cls"); welcomeheader();
            string getcategory;
            cout << "\n\n\n\t\t\t\t\t\tEnter category \n\n\t\t\t\t\t1.FoodTech\n\n\t\t\t\t\t2.WoodTech\n\n\t\t\t\t\t3.MetalTech\n\n\t\t\t\t\t4.IT\n";
            cout << "\t\t\t\t\t\t"; cin >> getcategory;
            if (getcategory == "1") { innovetor[1].category = "FoodTech"; }
            else if (getcategory == "2") { innovetor[1].category = "WoodTech"; }
            else if (getcategory == "3") { innovetor[1].category = "MetalTech"; }
            else if (getcategory == "4") { innovetor[1].category = "IT"; }
            else { innovetor[1].category = " Null"; }
            system("cls"); welcomeheader();
            //adding the entered details or records to the file
            addtofile << innovetor[1].firstname << "\t" << innovetor[1].surname << "\t" << innovetor[1].passportNumber << "\t" << innovetor[1].age << "\t" << innovetor[1].title << "\t" << innovetor[1].date_submission << "\t" << innovetor[1].patent_Status << "\t" << innovetor[1].category << endl;
            cout << "n\n\n\t\t\t\t\t\tInnovator added successfully\n";

            wait(60); system("cls"); welcomeheader();

            cout << "\n\n\n\t\t\t\t\t\tDO you want to add another innovator ";
            cout << "\n\n\n\t\t\t\t\t\t1.Yes ";
            cout << "\n\n\n\t\t\t\t\t\t2.No\n";
            cout << "\n\t\t\t\t\t\t"; cin >> ask;
        }
        if (ask != 1)
        {
            addtofile.close();
            break;
        }

    } while (ask == 1);
}



int  Search(string EnteredpassportNumber)
{
    int user_position = {};//
    int get_choice_continue;//to allow user to go to next page
    string firstname, surname, age, title, date, patent, category, passportNumber;//
    string User_Found_Access, user_found = "userfound";
    int  p = 0;//p represent change in position while getting and storing content of a file

    fstream getfromfile;
    fstream addtofile_TEMPT;

    getfromfile.open("Innovator's Records.txt", ios::in);
    //addtofile_TEMPT.open("tempt.txt", ios::out);
    system("cls"); welcomeheader();
    if (getfromfile)
    {   //storing file into a struct array
        while (getfromfile >> innovetor[p].firstname >> innovetor[p].surname >> innovetor[p].passportNumber >> innovetor[p].age >> innovetor[p].title >> innovetor[p].date_submission >> innovetor[p].patent_Status >> innovetor[p].category)
        {
            p++;//change position
        }
        getfromfile.close();//close file after use


        for (int x = 0; x <= p; x++)
        {
            if (EnteredpassportNumber == innovetor[x].passportNumber)
            {
                system("cls"); welcomeheader();
                User_Found_Access = user_found;
                cout << "\n\n\t\t\t\t\t\t\t INNOVATOR FOUND!!\n";
                cout << "\n\t\t\t\t\t\t\t INNOVATOR INFORMATION\n";
                // cout <<"\n\n\n\t\t\t\t\t\t\t INNOVATOR FOUND!!\n";
                cout << "\n\t\t\t\t_____________________________________________________________________________";
                cout << "\n\n\t\t\t\t" << "FIRSTNAME: " << innovetor[x].firstname << "\n\n\t\t\t\tSURNAME: " << innovetor[x].surname << "\n\n\t\t\t\tNRC/PASSPORT NO: " << innovetor[x].passportNumber << "\n\n\t\t\t\tAGE: " << innovetor[x].age << "\n\n\t\t\t\tINNOVATION TITTLE: " << innovetor[x].title << "\n\n\t\t\t\tDATE OF SUBMISSION: " << innovetor[x].date_submission << "\n\n\t\t\t\tINNOVATORS PATENT STATUS: " << innovetor[x].patent_Status << "\n\n\t\t\t\tINNOVATORS CATEGORY: " << innovetor[x].category << endl;
                cout << "\n\n\t\t\t\t press 11 to go to next page  \n";
                cout << "\n\t\t\t\t_____________________________________________________________________________";
                string next_page; cout << "\n\t\t\t\t press: \n"; cout << "\t\t\t\t"; cin >> next_page;
               //exception handling
                int next;
                try{
                    next = stoi(next_page);
                }
                catch (...) { next = 0; }

                if (next == 11) {
                            user_position = x;
                    return user_position; break;
                }
                else
                {
                    terminate_program();
                }

            }

        }
        if (User_Found_Access != user_found)
        {
            system("cls"); system("cls"); welcomeheader();
            string user_passport;
            cout << "\n\n\t\t\t\t Invalid passport number. Please try again.\n\n" << endl;
            cout << "\n\n\t\t\t\t what do you wish to do? \n\n\t\t\t\tPress: 1.go back to search  or any key to exit the program\t\t\n\n";
            cout << "\t\t\t\t__________________________________________________________________\n";

            cout << "\n\n\n\t\t\t\t>>"; cin >> get_choice_continue;
            if (get_choice_continue == 1)
            {
                system("cls"); welcomeheader();

                cout << "\n\n\t\t\t\tEnter innovator's NRC/PASSPORT you wish to search :\n" << endl;
                cout << "\t\t\t\t\t"; cin >> user_passport;
                // break;
                user_position = Search(user_passport);
            }
            else { terminate_program(); wait(60); }


            return user_position;
        }

        //} while ( User_Found_Access != user_found);//end of do while



    }

    return user_position;

}
void terminate_program()//terminate program
{

    system("cls"); welcomeheader();

    cout << "\n\n\t\t\t\t\t program terminating.... !!\n";
    wait(40);
    system("cls");
    cout << "\n\t\t\t\t\t thank you for using this program \n";
    exit(0);
}


void  DELETE(int x_from_search)
{
    string EnteredpassportNumber;
    string firstname, surname,title, date, patent, category, passportNumber;//variable to receive content from file and pass them to respective arrays
    int  p = 0,age;
    fstream addtofile;
    addtofile.open("temptRecords.txt", ios::out);
    fstream backup("backup.txt", ios::out);
    fstream getfromfile;
    getfromfile.open("Innovator's Records.txt", ios::in);//open file


    if (getfromfile)
    {
        while (getfromfile >> firstname >> surname >> passportNumber >> age >> title >> date >> patent >> category)
        {
            // getting content from a file and store in an array
            innovetor[p].firstname = firstname;
            innovetor[p].surname = surname;
            innovetor[p].passportNumber = passportNumber;

            innovetor[p].age = age;
            innovetor[p].title = title;

            innovetor[p].date_submission = date;

            innovetor[p].patent_Status = patent;
            innovetor[p].category = category;

            backup << innovetor[p].firstname << "\t" << innovetor[p].surname << "\t" << innovetor[p].passportNumber << "\t" << innovetor[p].age << "\t" << innovetor[p].title << "\t" << innovetor[p].date_submission << "\t" << innovetor[p].patent_Status << "\t" << innovetor[p].category << endl;

            p++;
            if (p == 10)
                break;
        }
        getfromfile.close();

        system("cls"); welcomeheader();

        if (addtofile)
        {
            for (int x = 0; x <= p; x++)
            {// cout << "  "<<firstname << "  "<<surname<< "  "<<passportNumber <<"  "<< age << "  "<<title <<"  "<< date<<"  " << patent<<"  " << category;

                if (x == x_from_search)
                {
                    continue;
                }

                firstname = innovetor[x].firstname;
                surname = innovetor[x].surname;
                passportNumber = innovetor[x].passportNumber;
                age = innovetor[x].age;
                title = innovetor[x].title;
                date = innovetor[x].date_submission;
                patent = innovetor[x].patent_Status;
                category = innovetor[x].category;

                addtofile << firstname << "\t" << surname << "\t" << passportNumber << "\t" << age << "\t" << title << "\t" << date << "\t" << patent << "\t" << category << endl << endl;

            }


        }


    }
    getfromfile.close();
    addtofile.close();

    remove("Innovator's Records.txt");
    rename("temptRecords.txt", "Innovator's Records.txt");
    //cout<<" deleted";
    system("cls"); welcomeheader();
    cout << "\n\n\n\t\t\t\t\t innovator deleted successfully \n";
    wait(60);
}
//display by category



void display_CATEGORY()
{
    string  get_category;
    string invalid;

    fstream get_display_category("Innovator's Records.txt", ios::in);

    if (get_display_category)
    {
        int y = 0, position_number = 1;
        string firstname[10], surname[10], date[10], age[10], title[10], patent[10], category[10], pass_NRC[10];
        while (get_display_category >> firstname[y] >> surname[y] >> pass_NRC[y] >> age[y] >> title[y] >> date[y] >> patent[y] >> category[y]) { y++; }
        get_display_category.close();
        for (int x = 0; x >= 0; x++)
        {
            system("cls"); welcomeheader();
            cout << "\n\n\n\t\t\t\tEnter innovation category:\n\n\t\t\t\t1.FoodTech\n\n\t\t\t\t2.WoodTech\n\n\t\t\t\t3.MetalTech\n\n\t\t\t\t4.IT\n\n\t\t\t\t5.Previous page\n\n\t\t\t\t6.Exit\n";
            cout << "\n\t\t\t\t__________________________________________________________________\n";
            cout << "\t\t\t\t>>";
            cin >> get_category;

            //string cat[4];

                    //variable for entered categories
            string  foodtech = "1";
            string  woodtech = "2";
            string  metaltech = "3";
            string   IT = "4";
            string  backpage = "5";
            string  EXIT = "6";

            //variable for comparing with available category
            string  cat_food_tech = "FoodTech";
            string  cat_wood_tech = "WoodTech";
            string  cat_metal_tech = "MetalTech";
            string  cat_IT = "IT";
            string  if_not_found;

            system("cls"); welcomeheader();

            if (get_category == foodtech)
            {
                int position_number1 = 1;
                for (int y = 0; y <= 10; y++)
                {
                    if (cat_food_tech == category[y])
                    {
                        cout << "\n\n\n\t\t\t\t" << position_number1 << "." << firstname[y] << "  " << surname[y] << " " << pass_NRC[y] << " " << age[y] << "  " << title[y] << "  " << date[y] << "  " << patent[y] << "  " << category[y] << endl;
                        position_number1++;
                    }

                }
                int get_choice_continue;
                cout << "\n\n\n\t\t\t        press\n\n\t\t\t\t1.go back to previous\n\n\t\t\t\t2.exit program\n\n";
                cout << "\t\t\t\t__________________________________________________________________\n";

                cout << "\n\n\n\t\t\t\t>>"; cin >> get_choice_continue;
                if (get_choice_continue == 1)
                {

                }
                else { terminate_program(); wait(60); }
            }
            else if (get_category == woodtech)
            {
                int position_number2 = 1;
                for (int y = 0; y <= 10; y++)
                {
                    if (cat_wood_tech == category[y])
                    {

                        cout << "\n\n\n\t\t\t\t" << position_number2 << "." << firstname[y] << "  " << surname[y] << " " << pass_NRC[y] << " " << age[y] << "  " << title[y] << "  " << date[y] << "  " << patent[y] << "  " << category[y] << endl;
                        position_number2++;
                    }
                }

                int get_choice_continue;
                cout << "\n\n\n\t\t\t        press\n\n\t\t\t\t1.go back to previous\t\t\t\t Any exit program\n\n";
                cout << "\t\t\t\t__________________________________________________________________\n";

                cout << "\n\n\n\t\t\t\t>>"; cin >> get_choice_continue;
                if (get_choice_continue == 1)
                {

                }
                else { terminate_program(); wait(60); }
            }
            else if (get_category == metaltech)
            {
                int position_number3 = 1;
                for (int y = 0; y <= 10; y++)
                {
                    if (cat_metal_tech == category[y])
                    {
                        //position_number=y+1;
                        cout << "\n\n\n\t\t\t\t" << position_number3 << "." << firstname[y] << "  " << surname[y] << " " << pass_NRC[y] << " " << age[y] << "  " << title[y] << "  " << date[y] << "  " << patent[y] << "  " << category[y] << endl;
                        position_number3++;
                    }
                }
                int get_choice_continue;
                cout << "\n\n\n\t\t\t        press\n\n\t\t\t\t1.go back to previous\n\n\t\t\t\t2.exit program\n\n";
                cout << "\t\t\t\t__________________________________________________________________\n";

                cout << "\n\n\n\t\t\t\t>>"; cin >> get_choice_continue;
                if (get_choice_continue == 1)
                {

                }
                else { terminate_program(); wait(60); }

            }
            else if (get_category == IT)
            {
                position_number = 1;
                for (y = 0; y <= 10; y++)
                {
                    if (cat_IT == category[y])

                    {
                        cout << "\n\n\n\t\t\t\t" << position_number << "." << firstname[y] << "  " << surname[y] << " " << pass_NRC[y] << " " << age[y] << "  " << title[y] << "  " << date[y] << "  " << patent[y] << "  " << category[y] << endl;
                        position_number++;
                    }
                }

                int get_choice_continue;
                cout << "\n\n\n\t\t\t        press\n\n\t\t\t\t1.go back to previous\n\n\t\t\t\t2.exit program\n\n";
                cout << "\t\t\t\t__________________________________________________________________\n";

                cout << "\n\n\n\t\t\t\t>>"; cin >> get_choice_continue;
                if (get_choice_continue == 1)
                {

                }
                else { terminate_program(); wait(60); }
            }
            else if (get_category == backpage)
            {
                break;
            }
            else if (get_category == EXIT)
            {
                terminate_program(); wait(60);
            }
            else
            {
                cout << " \ninvalid\n\n";
            }


        }
        get_display_category.close();
        cout << endl << endl << endl;
    }
}

void edit(int use_position)
{
    string get_NRC;
    fstream getFromFile("Innovator's Records.txt", ios::in);
    fstream tempt("Innovator's Records.txt");
    system("cls"); welcomeheader();
    wait(60);
    if (getFromFile)//if the file is openned
    {
        int counter = 0;// counter are  a counter variable for change in position of innovator
        //getfrom file store in a struct array
        while (getFromFile >> innovetor[counter].firstname >> innovetor[counter].surname >> innovetor[counter].passportNumber >> innovetor[counter].age >> innovetor[counter].title >> innovetor[counter].date_submission >> innovetor[counter].patent_Status >> innovetor[counter].category)
        {
            counter++;
        }//end of getting from file
        system("cls"); welcomeheader();

        cout << "\n\n\n\t\t\t\tThe found innovator " << innovetor[use_position].firstname << endl;
        int get_option;
        string option;
        cout << "\n\t\t\t\twhat do you wish to edit \n\t\t\t\t1.first name\n\t\t\t\t2.surname\n\t\t\t\t3.age\n\t\t\t\t4.innovation category\n\t\t\t\t5.title\n\t\t\t\t6.patent status\n\t\t\t\t7.date\n\t\t\t\t8.press any key to exit\n\n";
        cout << "\t\t\t\t__________________________________________________________________\n";

        cout << " \t\t\t\t"; cin >> option;
        try {
            get_option = stoi(option);
        }
        catch (...) {
            system("cls"); welcomeheader();
            cout << " \n\t\t\t\t error invalid choice \n "; get_option = 0;
        }

        if (get_option == 1)
        {
            system("cls"); welcomeheader();
            cout << "\n\t\t\t\tEdit first name\n";
            cout << "\n\t\t\t\tEnter new first name\n";
            cin >> innovetor[use_position].firstname;
            cout << "\n\t\t\t\tNew first name is " << innovetor[use_position].firstname << endl;
            counter = 0;
            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }

        }
        else if (get_option == 2)
        {
            system("cls"); welcomeheader();

            cout << "\n\n\t\t\t\tEdit surname\n";
            cout << "\n\t\t\t\tEnter new surname\n";

            cin >> innovetor[use_position].surname;

            cout << "\n\t\t\t\tNew surname is " << innovetor[use_position].surname << endl;
            counter = 0;
            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }

        } //end of and start of edit age
        else if (get_option == 3)

        {
            cout << "\n\t\t\t\tEdit your age\n";
            cout << "\n\t\t\t\t\tEnter  your age\n";
            cin >> innovetor[use_position].age;
            cout << "\n\t\t\t\tNew age is " << innovetor[use_position].age << endl;
            counter = 0;
            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }
        }
        else if (get_option == 4)

        {
            system("cls"); welcomeheader();

            cout << "\n\n\n\t\t\t\tEdit your category\n";
            cout << "\n\t\t\t\tEnter  choice your category\n";
            cout << "\n\t\t\t\t1.FoodTech\n\t\t\t\t2.WoodTech\n\t\t\t\t3.IT\n\t\t\t\t4.MetalTech\n";
            int get_cat;
            cout << "\t\t\t\t__________________________________________________________________\n";
            cout << "\t\t\t\\t>>";
            cin >> get_cat;
            if (get_cat == 1) { innovetor[use_position].category = "FoodTech"; }
            else if (get_cat == 2) { innovetor[use_position].category = "WoodTech"; }
            else if (get_cat == 3) { innovetor[use_position].category = "IT"; }
            else if (get_cat == 4) { innovetor[use_position].category = "MetalTech"; }
            else {
                system("cls"); welcomeheader();
                cout << "\n\n\t\t\t\terror \n";
            }
            cout << "\n\t\t\t\tNew category is " << innovetor[use_position].category << endl;
            counter = 0;
            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }
        }
        else if (get_option == 5)
        {
            system("cls"); welcomeheader();
            cout << "\n\n\t\t\t\tEdit your title\n";
            cout << "\n\t\t\t\tEnter  choice your title\n";
            cin >> innovetor[use_position].title;
            cout << "\n\t\t\t\tNew category is " << innovetor[use_position].title << endl;
            counter = 0;

            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }
        }
        else if (get_option == 6)

        {
            system("cls"); welcomeheader();

            cout << "\n\n\t\t\t\tEdit your patent status\n";
            cout << "\n\n\t\t\t\t1.Inprogress\n\n\t\t\t\t2.No Required\n\n\t\t\t\t3.Patented\n\n";
            int get_patent;
            cin >> get_patent;

            //choice the patent status
            if (get_patent == 1) { innovetor[use_position].patent_Status = "Inprogress"; }
            else if (get_patent == 2) { innovetor[use_position].patent_Status = "No_Required"; }
            else if (get_patent == 3) { innovetor[use_position].patent_Status = "Patented"; }
            else {
                system("cls"); welcomeheader();
                cout << " \n\n\n\t\t\t\tinvalid \n";
            }

            cout << "\n\t\t\t\tNew patent status  is " << innovetor[use_position].category << endl;
            counter = 0;
            // add edited innovator to the file
            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }
            cout << "\n\t\t\t\t\tEdited successfully\n";
            //added to file
        }//end of edit category
        else if (get_option == 7)//start of edit date of submission
        {
            system("cls"); welcomeheader();

            cout << "\n\t\t\t\tEdit date of submission\n";
            cout << "\t\t\t\t\tEnter new submission\n";
            cin >> innovetor[use_position].date_submission;
            cout << "\n\t\t\t\tNew submission is " << innovetor[use_position].date_submission << endl;
            counter = 0;
            // add edited innovator to the file
            while (tempt << innovetor[counter].firstname << "\t" << innovetor[counter].surname << "\t" << innovetor[counter].passportNumber << "\t" << innovetor[counter].age << "\t" << innovetor[counter].title << "\t" << innovetor[counter].date_submission << "\t" << innovetor[counter].patent_Status << "\t" << innovetor[counter].category << endl)
            {
                counter++;
                if (counter == 10)
                    break;
            }
            cout << "\n\t\tt\t\tEdited successfully\n";
        }//end of edit date of submission
        else
        {
        terminate_program();
        }
   // }//end of if found innovator for edit
        getFromFile.close();
        tempt.close();
        // }//end of checkin if available
    }//end of the open file
    else
    {
        system("cls"); welcomeheader();
        cout << "\n\n\t\t\\tNot Open" << endl;
    }//end if file is not openned
}//end of edit function
int addvarifyNRC_PASSPORT(string entered_value)
{

        string Line[1000] = {}, line;//get and store content
        int pos_store = 0;//store position
        fstream getfile("Innovator's Records.txt", ios::in);
        if (!getfile) { cout << " error"; }
        else
        {  //get content
            while (getfile >> line)
            {
                Line[pos_store] = line;
                pos_store++;
            }
            // test if avilable
            for (int pos_continue = 0; pos_continue <= pos_store; pos_continue++)
            {
                if (entered_value == Line[pos_continue])
                {
                    //stop = pos_continue;
                    system("cls"); welcomeheader();
                    cout << "\n\n\n\t\t\t\tThe entered nrc/passport number already is in the system try another one\n\n";
                    return 0;//indicating user is in system
                }
                 //go here if not found
                if (pos_continue == pos_store)
                {
                    return pos_store;

                }
            }

        }
        return 1;//exist



}

//forgot password
void forgot_password()
{   //variable created for exceptional handling
    string contact;
    int con_tact;

    system("cls"); welcomeheader();   wait(60); system("cls"); system("cls"); welcomeheader();
    cout << "\n\n\n\t\t\t\t1.Contact the Administrator(for Coordinator and Technician only) \n\n";
    cout << "\n\t\t\t\t2.Contact the Development team(for Administrator and Hub manager)  \n\n";
    cout << "\n\t\t\t\t3. Any key Exit the program \n\n";
    cout << "\t\t\t\t__________________________________________________________________\n";
    cout << "\t\t\t\t>>"; cin >> contact;

    try
    {
        con_tact = stoi(contact);

    }
    catch (...)
    {

        con_tact = 0;
    }
    if (con_tact==1)
    {
        system("cls"); welcomeheader();
        cout << "\n\n\n\t\t\t\t Visit the Hub managers office they do have a manual for password reset \n\n";
        cout << "\n\n\n\t\t\t\t thank you for using the progam !!!!!! \n\n";

    }
    else if (con_tact==2)
    {
        string send;
        int se_nd;
        system("cls"); welcomeheader();
        cout << "\n\n\n\t\t\t\t1.Contact: 0961538892 \n\n";
        cout << "\n\t\t\t\t2.Send a call back message \n\n";
        cout << "\t\t\t\t__________________________________________________________________\n";
        cout << "\t\t\t\t>>"; cin >> send;

        try
        {
            se_nd = stoi(send);

        }
        catch (...)
        {

            se_nd= 0;
        }
        if (se_nd == 1)
        {
            system("cls"); welcomeheader();

            cout << "\n\n\n\t\t\t\t Make a call !!!!! \n\n";
            wait(60); terminate_program();
        }
        else if(se_nd==2)
        {
            system("cls"); welcomeheader();
            cout << "\n\n\n\t\t\t\tMessage sent our help assistant will call you back within 24hrs\n\n";
            wait(60); terminate_program();

        }
        else
        {
            system("cls"); welcomeheader();
            cout << "\n\n\n\t\t\t\t Message not sent \n\n";
            wait(60); terminate_program();

        }

    }
    else { terminate_program(); }



}


void list_innovator()
{
    fstream getfromfile_display("Innovator's Records.txt", ios::in);
    string get_all_line;
    int count_innovator = 1;
     system("cls"); welcomeheader();
      cout << "\n\n\t\t\t\t                         AVAILABLE  INNOVATOR(S) \n ";
    while(getline(getfromfile_display,get_all_line))
    {


        cout << "\n\n\t\t\t\t" <<count_innovator<<" " << get_all_line << endl;

        count_innovator++;
    }
    system("pause");
}
//end thank you
