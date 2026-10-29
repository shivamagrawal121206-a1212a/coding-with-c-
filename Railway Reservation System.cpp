#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int totalSeats = 30;

struct Passenger
{
    int seatNo;
    string name;
    int age;
    char gender;
    Passenger* next;
};

Passenger* head = NULL;

// Book a ticket
void bookTicket(int* seats)
{
    int seat = -1;

    for (int i = 0; i < totalSeats; i++)
    {
        if (seats[i] == 0)
        {
            seat = i;
            break;
        }
    }

    if (seat == -1)
    {
        cout << "No seats available!\n";
        return;
    }

    string name;
    int age;
    char gender;

    cout << "Enter Name: ";
    getline(cin >> ws, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Gender (M/F): ";
    cin >> gender;

    Passenger* newNode =
        (Passenger*)malloc(sizeof(Passenger));

    if (newNode == NULL)
    {
        cout << "Memory allocation failed!\n";
        return;
    }

    // Start the string object in allocated memory
    new (newNode) Passenger;

    newNode->seatNo = seat + 1;
    newNode->name = name;
    newNode->age = age;
    newNode->gender = gender;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Passenger* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    seats[seat] = 1;

    cout << "Ticket booked! Seat No: "
         << seat + 1 << "\n";
}

// Cancel a ticket
void cancelTicket(int* seats)
{
    int seatNo;

    cout << "Enter seat number to cancel: ";
    cin >> seatNo;

    if (seatNo < 1 || seatNo > totalSeats)
    {
        cout << "Invalid seat number!\n";
        return;
    }

    Passenger* temp = head;
    Passenger* prev = NULL;

    while (temp != NULL && temp->seatNo != seatNo)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Seat is not booked!\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    seats[seatNo - 1] = 0;

    temp->~Passenger();
    free(temp);

    cout << "Ticket cancelled successfully!\n";
}

// View seat status
void viewTrainStatus(int* seats)
{
    cout << "\nTrain Seat Status:\n";

    for (int i = 0; i < totalSeats; i++)
    {
        cout << "Seat " << i + 1 << ": ";

        if (seats[i] == 1)
            cout << "Booked\n";
        else
            cout << "Available\n";
    }
}

// View passenger details
void viewPassengerList()
{
    Passenger* temp = head;

    if (temp == NULL)
    {
        cout << "No passengers found!\n";
        return;
    }

    cout << "\nPassenger List:\n";

    while (temp != NULL)
    {
        cout << "Seat No: " << temp->seatNo
             << " | Name: " << temp->name
             << " | Age: " << temp->age
             << " | Gender: " << temp->gender
             << "\n";

        temp = temp->next;
    }
}

// Free allocated memory
void freeMemory(int* seats)
{
    Passenger* temp = head;

    while (temp != NULL)
    {
        Passenger* nextNode = temp->next;

        temp->~Passenger();
        free(temp);

        temp = nextNode;
    }

    head = NULL;
    free(seats);
}

int main()
{
    int* seats = (int*)malloc(totalSeats * sizeof(int));

    if (seats == NULL)
    {
        cout << "Memory allocation failed!\n";
        return 1;
    }

    for (int i = 0; i < totalSeats; i++)
    {
        seats[i] = 0;
    }

    int choice;

    do
    {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Train Status\n";
        cout << "4. View Passenger List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                bookTicket(seats);
                break;

            case 2:
                cancelTicket(seats);
                break;

            case 3:
                viewTrainStatus(seats);
                break;

            case 4:
                viewPassengerList();
                break;

            case 5:
                freeMemory(seats);
                cout << "Program closed successfully!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}