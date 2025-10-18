//Movie Ticket Booking System in oop(c++)
#include<iostream>
#include<string>
using namespace std;
//use of classes,constructors
class MovieTicket {
private:
    static int nextTicketID; //static type for auto incrementation 
    int ticketID;
    string movieName;
    string showTime;
    string seatType;
    string formatType;
    double basePrice;
    double finalPrice;
    string bookingTime;

public:
    //default Constructor
    MovieTicket() {
        ticketID = nextTicketID++;
        movieName="";
        showTime="";
        seatType="Standard";
        formatType="2D";
        basePrice=10.0;
        finalPrice=basePrice;
        bookingTime="";
    }
    //parameter constructor1 (Without format type)
    MovieTicket(string movie, string time, string seat) {
        ticketID = nextTicketID++;
        movieName=movie;
        showTime=time;
        seatType=seat;
        formatType="2D"; 
        basePrice=10.0;
        calculateFinalPrice(); 
        finalPrice=basePrice;
        bookingTime="";
    }
    //parameter constructor2 (With format type)
    MovieTicket(string movie, string time, string seat, string format) {
        ticketID = nextTicketID++;
        movieName=movie;
        showTime=time;
        seatType=seat;
        formatType=format;
        basePrice=10.0;
        calculateFinalPrice(); 
        finalPrice=basePrice;
        bookingTime="";
    }
    //set seat type and again calculate Price
    void setSeatType(string seat) {
        seatType = seat;
        calculateFinalPrice();
    }
    //set format Type and again calculate Price
    void setFormatType(string format) {
        formatType=format;
        calculateFinalPrice();
    }
    //to calculate final price based on seat and format
    void calculateFinalPrice() {
        if (seatType=="Standard") {
            basePrice = 10.0;
        } else if (seatType=="Premium") {
            basePrice=15.0; 
        } else if (seatType=="VIP") {
            basePrice=20.0; 
        }
        if (formatType=="2D") {
            // No extra charge for 2D
        } else if (formatType == "3D") {
            basePrice+=3.0; 
        } else if (formatType == "IMAX") {
            basePrice+=7.0; 
        }
        finalPrice = basePrice;
    }
    //Applying a 10% discount if booking is made more than '3' days in advance.
    void applyBookingTimeDiscount(int DaysInAdvance) 
	{
        if (DaysInAdvance > 3) {
            finalPrice *= 0.9; 
        }
    }
    //to get ticket details
    string getTicketDetails() {
        return "\n--------- Movie Ticket ---------\n" +
               string("Ticket ID: ") + to_string(ticketID) + "\n" +
               "Movie: " + movieName + "\n" +
               "Show Time: " + showTime + "\n" +
               "Seat Type: " + seatType + "\n" +
               "Format: " + formatType + "\n" +
               "Base Price: $10.00\n" +
               "Final Price: $" + to_string(finalPrice) + "\n" +
               "---------------------------------\n";
    }
};

//initialize static variable
int MovieTicket::nextTicketID = 1001;

//main function
int main() {  
    char bookAnother;
    do {
        int DaysInAdvance, movieChoice, timeChoice;
        string movie, time, seat, format;
        cout << "\n-----------------#-Movie Ticket Booking System-#------------------" <<endl;
        cout <<  "   -----Wanna watch movies. Share some (correct) details.-----  " << endl;

        cout << "\nSelect a movie:\n";
        cout << "1. Interstellar\n";
        cout << "2. Batman\n";
        cout << "3. Lord of the Rings\n";
        cout << "Enter your choice (1-3): ";
        cin >> movieChoice;

        switch (movieChoice) {
            case 1: movie = "Interstellar"; break;
            case 2: movie = "Batman"; break;
            case 3: movie = "Lord of the Rings"; break;
            default: movie = "Unknown Movie"; break;
        }

        cout << "\nAvailable Show Times:\n";
        cout << "1. 1:00 PM\n";
        cout << "2. 5:00 PM\n";
        cout << "3. 9:00 PM\n";
        cout << "Enter your choice (1-3): ";
        cin >> timeChoice;
//switch cases
        switch (timeChoice) {
            case 1: time = "1:00 PM"; break;
            case 2: time = "5:00 PM"; break;
            case 3: time = "9:00 PM"; break;
            default: time = "Unknown Time"; break;
        }
//clear input buffer
        cin.ignore(); 
        cout << "\nEnter Seat Type you want (Standard/Premium/VIP): ";
        getline(cin, seat);
        cout << "Enter Format Type (2D/3D/IMAX): ";
        getline(cin, format);

        MovieTicket ticket1(movie, time, seat, format);

        cout << "Enter days in advance for booking discount: ";
        cin >> DaysInAdvance;
        ticket1.applyBookingTimeDiscount(DaysInAdvance);
        cout << ticket1.getTicketDetails() << endl;

        cout << "Do you want to book another ticket? (Y/N): ";
        cin >> bookAnother;

    } while (bookAnother == 'Y' || bookAnother == 'y');

    cout << "\n----Thank you for using the Movie Ticket Booking System!----\n";
    return 0;
}
