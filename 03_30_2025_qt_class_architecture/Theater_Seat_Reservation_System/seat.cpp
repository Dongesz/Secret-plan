#include "seat.h"

Seat::Seat() {
    int row;
    int col;
    bool reserved = false;

    bool reserve(int col, int row);{
        reserved = !reserved;
    }

    bool cancel(int row, int col){
        reserved = false;
    }

    bool isReserved(int row, int col){
        return reserved;
    }
}
