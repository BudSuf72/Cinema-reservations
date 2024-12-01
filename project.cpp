#include <iostream>
using namespace std;
struct booking 
{
    string name;
    int movie_number;
    int seat;
	booking*link;    
};
struct movies
{
	int ID;
	string day;
	string movie;
	string price;
	movies*link;
};
booking*head_booking=NULL;
movies*head_movies=NULL;
bool isseatbooked(int movienumber, int seatnumber)
{
	booking*temp_booking=head_booking;
	while(temp_booking!=NULL)
	{
		if(temp_booking->movie_number==movienumber && temp_booking->seat==seatnumber)
		{
			return true;
		}
		temp_booking=temp_booking->link;
		{
			return false;
	
		}
	}
}
int countBookingsForMovie(int movienumber)
{
    int count=1;
    booking*temp_booking=head_booking;
    while (temp_booking!=NULL) 
	{
        if (temp_booking->movie_number == movienumber) 
		{
            count++;
        }
        temp_booking=temp_booking->link;
    }
    return count;
}
void insertFirst(string clientname,int movienumber,int seatnumber)
{
if (countBookingsForMovie(movienumber)>=16) 
{
        cout << "Sorry, you cannot book, because all seats are reserved";
        return;
}
if(isseatbooked(movienumber, seatnumber))
  {
	cout<<"The seat number "<<seatnumber <<"is already booked.\n";
    return;
  }
	booking*new_booking=new booking;
    new_booking->name=clientname;
    new_booking->movie_number=movienumber;
    new_booking->seat=seatnumber;
	new_booking->link=head_booking;
	head_booking=new_booking;
	cout<<"Your reservation has been completed successfully.\n";
}
void insertMiddle(string clientname,int movienumber,int seatnumber,int postion)
{
if (countBookingsForMovie(movienumber)>=16) 
{
        cout << "Sorry, you cannot book, because all seats are reserved";
        return;
}
if(isseatbooked(movienumber, seatnumber))
  {
	cout<<"The seat number "<<seatnumber <<"is already booked.\n";
    return;
  }
    booking*new_booking=new booking;
    new_booking->name=clientname;
    new_booking->movie_number=movienumber;
    new_booking->seat=seatnumber;
	new_booking->link=NULL;
	booking*temp_booking=head_booking;
	for(int i=0; i<postion-1; i++)
	{
		if(temp_booking->link==NULL)
		break;
		temp_booking=temp_booking->link;
		}
	new_booking->link=temp_booking->link;
	temp_booking->link=new_booking;	
	cout<<"Your reservation has been completed successfully.\n";	
}
void insertEnd(string clientname,int movienumber,int seatnumber)
{
if (countBookingsForMovie(movienumber)>=16) 
{
        cout << "Sorry, you cannot book, because all seats are reserved";
        return;
}
if(isseatbooked(movienumber, seatnumber))
  {
	cout<<"The seat number "<<seatnumber <<"is already booked.\n";
    return;
  }
   booking*last_booking;
   booking*new_booking=new booking;
   new_booking->name=clientname;
   new_booking->movie_number=movienumber;
   new_booking->seat=seatnumber;
   if(head_booking==NULL)
    {
   	head_booking=new_booking;
   	new_booking->link=NULL;
	}
	else
	{
		last_booking=head_booking;
		while(last_booking->link!=NULL)
		{
			last_booking=last_booking->link;
		}
		last_booking->link=new_booking;
		new_booking->link=NULL;
	}
cout<<"Your reservation has been completed successfully.\n";		
}
void deleteBooking(int seatnumber)
 {
    booking*temp_booking=head_booking;
    booking*prev_booking=NULL;

    while (temp_booking!=NULL && temp_booking->seat!=seatnumber) 
	{
        prev_booking=temp_booking;
        temp_booking=temp_booking->link;
    }
    if (temp_booking==NULL) 
	{
        cout<< "Booking not found.\n";
        return;
    }
    if (prev_booking==NULL) 
	{
        head_booking=temp_booking->link;
    } 
	else 
	{
        prev_booking->link=temp_booking->link;
    }
    delete temp_booking;
    cout<< "Booking for seat number " << seatnumber << " has been canceled.\n";
}
void displayEmptySeats(int totalSeats)
{
    bool seats[totalSeats+1]={false};

    booking*temp_booking=head_booking;
    while (temp_booking!=NULL) 
	{
        seats[temp_booking->seat]=true;
        temp_booking=temp_booking->link;
    }

    cout << "Empty seats are:\n";
    for (int i=1; i<=totalSeats; ++i) 
	{
        if (!seats[i]) 
		{
            cout << "Seat Number " << i << " is empty.\n";
        }
    }
}
void displayList()
{
	cout<<"\n1)Saturday : Forrest Gump 100RS\n"<<"2)Sunday : Die Hard 60RS\n"<<"3)Monday : Inception 80RS\n";
	cout<<"4)Tuesday : A Quiet Place 130RS\n"<<"5)Wednesday : Superbad 110RS\n"<<"6)Thursday : Toy Story 90RS\n";
	cout<<"7)Friday : Indiana Jones 70RS\n";
}
void displayModifiedList() 
{
    movies*temp_movies=head_movies;
    while(temp_movies!=NULL) 
	{
        cout <<temp_movies->ID << ") " <<temp_movies->day << " : " <<temp_movies->movie << " " <<temp_movies->price << "RS\n";
        temp_movies=temp_movies->link;
    }
}
void add(int ID, string day, string movie, string price)
{
   movies*last_movies;
   movies*new_movies=new movies;
   new_movies->ID=ID;
   new_movies->day=day;
   new_movies->movie=movie;
   new_movies->price=price;
   if(head_movies==NULL)
    {
   	head_movies=new_movies;
   	new_movies->link=NULL;
	}
	else
	{
		last_movies=head_movies;
		while(last_movies->link!=NULL)
		{
			last_movies=last_movies->link;
		}
		last_movies->link=new_movies;
		new_movies->link=NULL;
	}
}
void deleteByID(int ID) 
{
    movies* temp_movies = head_movies;
    movies* prev_movies = NULL;
    if (temp_movies != NULL && temp_movies->ID == ID) 
	{
        head_movies = temp_movies->link;
        delete temp_movies;
        cout<<"The movie has been deleted successfully";
        return;
    }
    while (temp_movies != NULL && temp_movies->ID != ID) 
	{
        prev_movies = temp_movies;
        temp_movies = temp_movies->link;
    }
    if (temp_movies == NULL)
	{
	cout<<"The movie you want to delete does not exist"; 
	return;
    }
    prev_movies->link = temp_movies->link;
    delete temp_movies;
    cout<<"The movie has been deleted successfully\n";
}
int main()
{   string clientname; int seatnumber; int movienumber;
    string username;
    string password;
    string user_username = "abc";
    string user_password = "123";
    string admin_username = "xyz";
    string admin_password = "567";
    bool LoginSuccess = false;
    bool IsAdmin = false;

    cout << "WELCOME! Please login below \n\n";
    do {
        cout << "Username:  ";
        cin >> username;
        cout << "Password:  ";
        cin >> password;

        if (username == user_username && password == user_password)
		{
            cout << "\nSuccessful Login as User\n\n";
            LoginSuccess = true;
        } 
		else if (username == admin_username && password == admin_password) 
		{
            cout << "\nSuccessful Login as Admin\n\n";
            LoginSuccess = true;
            IsAdmin = true;
        } 
		else 
		{
            cout << "Incorrect username or password combination\n";
            cout << "Please try to login again\n";
        }
    } while (!LoginSuccess);

    if (IsAdmin) 
	{   int operation;
        cout<<"WELCOME TO CINEMA ALKHAIL \n";
        displayList();
        add(1, "Saturday", "Forrest Gump", "100");
		add(2, "Sunday", "Die Hard", "60");
		add(3, "Monday", "Inception", "80");
		add(4, "Tuesday", "A Quiet Place", "130");
		add(5, "Wednesday", "Superbad", "110");
		add(6, "Thursday", "Toy Story", "90");
		add(7, "Friday", "Indiana Jones", "70");
        first:
        cout<<"\nIf you want to add a movie to the list,write number(1) \n";
        cout<<"If you want to delete a movie from the list,write number(2) \n";
        cout<<"If you want to view the list after modification,write number(3) \n";
        cout<<"If you want to exit,write number(4) \n";
        cout<<"\nPlease enter the operation number you want : ";
        cin>>operation;
        int ID; string day; string movie; string price;	
        switch(operation)
	    {
	  	case 1:
	  	{
	  	   cout<<"Enter the ID : ";
		   cin>>ID;	
		   cout<<"\nEnter a day : ";
		   cin>>day;	
		   cout<<"\nEnter the movie  : ";
		   cin>>movie;	
		   cout<<"\nEnter the price : ";
		   cin>>price;
		   add(ID,day,movie,price);	
		   goto first;
		   break;
		}
		case 2:
		{
		 int num;
		 cout<<"Enter the ID number by which you want to delete\n";
		 cin>>num;
		 deleteByID(num);
		 goto first;
		 break;
		}
		case 3:
		{
		 displayModifiedList();
		 goto first;
		 break;
		}
		case 4:
		{
		 cout<<"Exit\n";
		 goto out;
		 break;
		}
        default:
    	{
		cout<<"Sorry error";
		exit(0);
	    }
        }
    }
	else 
	{
    cout<<"WELCOME TO CINEMA ALKHAIL \n";
    displayList();
    int num; string clientname; int numberseat; int movienumber ; string ch;
    begin:
	cout<<"\nIf you want to add the booking,write the number 1\n";
    cout<<"If you want to search for empty seat,write the number 2\n";
    cout<<"If you want to cancel a booking,write the number 3\n";
    cout<<"If you want to exit,write the number 4\n";
    cout<<"\nPlease enter the operation number you want : ";
    cin>>num;
    switch(num)
    {
  	case 1:
  	    { 
  	    cout<<"\n1)If you want to add from the beginning,write(beginning)\n";
  	    cout<<"2)If you want to add from the middle,write(middle)\n";
  	    cout<<"3)If you want to add from the end,write(end)\n";
  	    cout<<"\nPlease write your choice: ";
  	    cin>>ch;
	    if(ch=="beginning")
	    {
		    cout<<"Enter clientname: \n";
	        cin>>clientname;
	        cout<<"And ID: \n";
		    cin>>movienumber;
		    cout<<"And enter seat number (1-5): ";
            cin >> seatnumber;
            if (seatnumber >= 1 && seatnumber <= 5)
                insertFirst(clientname,movienumber,seatnumber);
            else
                cout << "Invalid seat number for First.\n";
	   }
	    else if(ch=="middle")
		{   int postion;
		    cout<<"Enter clientname: \n";
	        cin>>clientname;
	        cout<<"And ID: \n";
		    cin>>movienumber;
		    cout << "And enter seat number (6-10): ";
                cin >> seatnumber;
                if (seatnumber >= 6 && seatnumber <= 10)
				{
                    cout<<"please choice number postion from 6 to 10\n";
		            cout<<"enter number postion : ";
	                cin>>postion;
                    insertMiddle(clientname,movienumber,seatnumber,postion);
                }
                else
                    cout << "Invalid seat number for Middle.\n";
	    }
	    else if(ch=="end")
	    {
		    cout<<"Enter clientname: \n";
	        cin>>clientname;
	        cout<<"And ID: \n";
		    cin>>movienumber;
		    cout<<"And enter seat number (11-15): ";
            cin >> seatnumber;
            if (seatnumber >= 11 && seatnumber <= 15)
                insertEnd(clientname,movienumber,seatnumber);
            else
                cout << "Invalid seat number for End.\n";
	   }
	    else
	    cout<<"Invalid choice";
	    goto begin;
  	break;
        }
    case 2:
    {
      displayEmptySeats(15);
	  goto begin;	
	break;			
	}
	case 3:
	    {
	 	cout<<"Enter seatnumber to cancel booking: \n";
	 	cin>>seatnumber;
	 	deleteBooking(seatnumber);
	 	goto begin;
	break;
	    }
	case 4:
		{
		cout<<"Exit\n";
		goto out;
	break; 	
		}
	default:
    	{
		cout<<"Sorry error";
		exit(0);
    	}
    }  
}
out:
exit(0);
    }   