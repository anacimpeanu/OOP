#include "Exception.h"

const char *CNPEXCEPTION::what() {
    return "CNP INVALID!";
}

const char *NUMEXCEPTION::what() {
    return "NUME INVALID!";
}

const char *NRTEXCEPTION::what(){
    return "NR TELEFON INVALID";
}