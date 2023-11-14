#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
struct Movie {
    std::string title;
    double ticketPrice;
    int availableSeats;
};
struct Seat {
    int row;
    char column;
    bool isBooked;
};
struct Booking {
    Movie movie;
    Seat seat;
};
void displayMovies(const std::vector<Movie>& movies) {
    std::cout << "Available Movies:\n";
    std::cout << "-----------------\n";
    
    for (const Movie& movie : movies) {
        std::cout << movie.title << " - $" << std::fixed << std::setprecision(2) << movie.ticketPrice
                  << " (Available Seats: " << movie.availableSeats << ")\n";
    }
}
void displaySeating(const std::vector<std::vector<Seat>>& seating) {
    std::cout << "\nSeating Arrangement:\n";
    std::cout << "-------------------\n";
    for (const auto& row : seating) {
        for (const Seat& seat : row) {
            if (seat.isBooked) {
                std::cout << "B ";
            } else {
                std::cout << seat.row << seat.column << " ";
            }
        }
        std::cout << "\n";
    }
}
bool isSeatAvailable(const Seat& seat) {
    return !seat.isBooked;
}
bool makeBooking(Movie& movie, Seat& seat) {
    if (isSeatAvailable(seat)) {
        seat.isBooked = true;
        movie.availableSeats--;
        return true;
    } else {
        std::cout << "Error: This seat is already booked. Please choose another seat.\n";
        return false;
    }
}
int main() {
    std::vector<Movie> movies = {
        {"Avengers: Endgame", 12.99, 50},
        {"The Lion King", 10.50, 40},
        {"Joker", 11.75, 30}
    };
    std::vector<std::vector<Seat>> seating(5, std::vector<Seat>(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            seating[i][j] = {i + 1, static_cast<char>('A' + j), false};
        }
    }
    int choice;
    do {
        system("clear");
        std::cout << "Movie Ticket Booking System\n";
        std::cout << "1. View Movies\n";
        std::cout << "2. View Seating Arrangement\n";
        std::cout << "3. Make Booking\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                displayMovies(movies);
                break;
            case 2:
                displaySeating(seating);
                break;
            case 3: {
                int movieIndex, row;
                char column;
                displayMovies(movies);
                std::cout << "Enter the movie index, row, and column for your booking: ";
                std::cin >> movieIndex >> row >> column;
                if (movieIndex >= 1 && movieIndex <= movies.size() &&
                    row >= 1 && row <= 5 && column >= 'A' && column <= 'E') {
                    Movie& selectedMovie = movies[movieIndex - 1];
                    Seat& selectedSeat = seating[row - 1][column - 'A'];
                    if (makeBooking(selectedMovie, selectedSeat)) {
                        std::cout << "Booking successful! Total cost: $" << selectedMovie.ticketPrice << "\n";
                    }
                } else {
                    std::cout << "Invalid input. Please enter valid movie index, row, and column.\n";
                }
                break;
            }
            case 4:
                std::cout << "Exiting the program. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    } while (choice != 4);
    return 0;
}