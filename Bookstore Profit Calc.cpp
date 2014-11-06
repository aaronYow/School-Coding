#include <iostream>

using namespace std;

//Function Prototypes
int getBooksOrdered();
int getBookStock();
int getBookCode();
int getBookPrice();
int getBookReqOpt();
int getBookOldNew();
int getProspEnroll();
int getBookDiscrep(int, int);
int figureCost(double, int);
int getBuyPercent(double, int);
int figureRevenue(double, int);
int getProjectedProfit(double, int);
void displayInfo(int, int, int, int, int, int, int, int, int, double);


int main()
{
    const double newReq = .9;
    const double oldReq = .65;
    const double newOpt = .4;
    const double oldOpt = .2;
    double salesPercent, bookPrice, projectedRevenue;
    int bookCode, bookStock, booksOrdered, bookOldNew, orderCost, studentsBuying;
    int bookReqOpt, prospectiveEnrollment, countOrder = 0, totalCost = 0, totalProfit = 0, projectedProfit;
    char userChoice;

    //Loop code until user is done entering books
    do {
        //Function call to get book code
        bookCode = getBookCode();

        //Function call to get book price
        bookPrice = getBookPrice();

        //Function call to get number of said book in stock
        bookStock = getBookStock();

        //Function call to get whether book is required or optional
        bookReqOpt = getBookReqOpt();

        //Function call to get whether book is old or new
        bookOldNew = getBookOldNew();

        //Function call to get prospective enrollment
        prospectiveEnrollment = getProspEnroll();

        //Figure the percentage of prospective enrollment to be buying the book
        if(bookOldNew == 1 && bookReqOpt == 1)
        {
            salesPercent = oldReq;
        }
        else if(bookOldNew == 0 && bookReqOpt == 1)

        {
            salesPercent = newReq;
        }
        else if(bookOldNew == 1 && bookReqOpt == 0)
        {
            salesPercent = oldOpt;
        }
        else if(bookOldNew == 0 && bookReqOpt == 0)
        {
            salesPercent = newOpt;
        }

        //Function call to get number of books to be ordered
        booksOrdered = getBookDiscrep(prospectiveEnrollment, bookStock);

        //Function call to figure total order cost for store
        orderCost = figureCost(bookPrice, booksOrdered);

        //Function call to determine percentage of prospective enrollment who will buy
        studentsBuying = getBuyPercent(salesPercent, prospectiveEnrollment);

        //Function call to calculate revenue
        projectedRevenue = figureRevenue(bookPrice, studentsBuying);

        //Function call to determine projected profit (if any)
        projectedProfit = getProjectedProfit(projectedRevenue, orderCost);

        //Function call to display previously input info
        displayInfo(bookCode, bookStock, bookReqOpt, bookOldNew, bookPrice, prospectiveEnrollment, projectedProfit, booksOrdered, orderCost, projectedRevenue);

        //Update order counter
        countOrder++;

        //Keep running total of all orders and total profit
        totalCost += orderCost;

        totalProfit += projectedProfit;

        //Ask user if they wish the code to repeat
        cout << "Do you wish to add another order? Enter (Y) to continue, or (N) to exit." << endl;
        cin >> userChoice;

    }while(userChoice == 'Y' || userChoice == 'y');

    cout << "The total cost of all " << countOrder << " orders will be $" << totalCost << "\n"
         << "The total projected profit of all " << countOrder << " orders is $" << totalProfit << endl;



    return 0;
}

    //defining function to get book code
    int getBookCode()
    {
        int bookCode;

        //Accept book code from user
        cout << "Please input book code." << endl;
        cin >> bookCode;

        return bookCode;
    }

    //defining function to get price of 1 book
    int getBookPrice()
    {
        double bookPrice;

        //Accept ptice of single book from user
        cout << "Please enter the price of a single copy of the book. \n$";
        cin >> bookPrice;

        //Validate whether price is 0 or less
        if(bookPrice <= 0)
        {
            cout << "Please enter a number above 0 for the price." << endl;
            cin >> bookPrice;
        }


        return bookPrice;
    }

    //defining function to see how many books are in stock
    int getBookStock()
    {
        int bookStock;

        //Accept amount of books already on site
        cout << "Please enter the amount of books already in stock." << endl;
        cin >> bookStock;

        return bookStock;
    }

    //defining function to see whether or not the books are required or optional
    int getBookReqOpt()
    {
        char userInput;
        int bookReqOpt;

        //Accept optional/required value from user
        cout << "Is this particular book required? Enter (Y) if it is, or (N) if it is optional." << endl;
        cin >>userInput;

        if(userInput == 'Y' || userInput == 'y')
        {
            bookReqOpt = 1;
        }
        else if(userInput == 'N' || userInput == 'n')n
        {
            bookReqOpt = 0;
        }

        return bookReqOpt;
    }

    //defining function to see whether the book is old or new
    int getBookOldNew()
    {
        char userInput2;
        int bookOldNew;

        //Accept whether the book has been used before or not
        cout << "Has this particular book been used before in a class? Enter (Y) or (N)." << endl;
        cin >> userInput2;

        if(userInput2 == 'Y' || userInput2 == 'y')
        {
            bookOldNew = 1;
        }
        else if(userInput2 == 'N' || userInput2 == 'n')
        {
            bookOldNew = 0;
        }

        return bookOldNew;
    }

    //defining functions to get prospective enrollment
    int getProspEnroll()
    {
        int prospectiveEnrollment;

        //Accept number of prospective students
        cout << "Please enter number of prospective enrollments." << endl;
        cin >> prospectiveEnrollment;

        return prospectiveEnrollment;

    }

    //defining function to determine number of books to be ordered
    int getBookDiscrep(int prospectiveEnrollment, int bookStock)
    {
        int booksOrdered;

        booksOrdered = (prospectiveEnrollment - bookStock);

        return booksOrdered;
    }

    //defining function to determine the total cost for the store
    int figureCost(double bookPrice, int booksOrdered )
    {
        int discountPrice, orderCost;

        discountPrice = bookPrice * .8;
        orderCost = discountPrice * booksOrdered;

        return orderCost;
    }

    //defining function to determine the projected number of enrollment who will buy based on preknown percentages
    int getBuyPercent(double salesPercent, int prospectiveEnrollment)
    {
        int studentsBuying;

        studentsBuying = prospectiveEnrollment * salesPercent;

        return studentsBuying;
    }

    //defining function to determine gross revenue from books
    int figureRevenue(double bookPrice, int studentsBuying)
    {
        int revenue;

        revenue = bookPrice * studentsBuying;

        return revenue;
    }

    //defining to calculate profits
    int getProjectedProfit(double projectedRevenue, int orderCost)
    {
        int projectedProfit;

        projectedProfit = projectedRevenue - orderCost;

        if(projectedProfit <= 0)
        {
            cout << "WARNING: This order is projected to not turn any profit." << endl;
        }

        return projectedProfit;
    }

    //defining function to output user input info
    void displayInfo(int bookCode, int bookStock, int bookReqOpt, int bookOldNew, int bookPrice, int prospectiveEnrollment, int projectedProfit, int booksOrdered, int orderCost, double projectedRevenue)
    {
        cout << "You input:\n"
             << "Book Code: " << bookCode << "\n"
             << "Price of 1 copy of the book: $" << bookPrice << "\n"
             << "Number of book in stock: " << bookStock << "\n"
             << "Prospective Enrollment: " << prospectiveEnrollment << " students" << "\n";
        if(bookReqOpt == 1)
        {
            cout << "The book is required for the course" << endl;
        }
        else if(bookReqOpt == 0)
        {
            cout << "The book is optional for the course" << endl;
        }
        if(bookOldNew == 0)
        {
            cout << "The book has not been used before in the class" << endl;
        }
        else if(bookOldNew == 1)
        {
            cout << "The book has been previously used in the class" << endl;
        }
        cout << "You need to order " << booksOrdered << " of these books.\n"
             << "This order will cost $" << orderCost << "\n"
             << "Projected revenue is $" << projectedRevenue << "\n"
             << "Projected profit for this order is: $" << projectedProfit << "\n";
    }
