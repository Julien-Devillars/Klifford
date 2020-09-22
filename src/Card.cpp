#include "include/Card.h"


Card::Card(Number n, Color c) : _number(n), _color(c) {}

std::string Card::getColor() {
    switch (_color) {
    case 0:
        return "H";
    case 1:
        return "C";
    case 2:
        return "D";
    case 3:
        return "S";
    default:
        "Error Color";
    }

    return "Error Color";
}

std::string Card::getNumber() {
    switch (_number) {
        case 0:
            return "Joker";
        case 1:
            return "As";
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            return std::to_string(_number);
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return "Error Number";
        }

    return "Error Number";
}


std::string Card::DrawCarte() {
    return getNumber() + " " + getColor();
}