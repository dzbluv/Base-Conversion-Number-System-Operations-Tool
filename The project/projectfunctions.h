#ifndef PROJECTFUNCTIONS_H_INCLUDED
#define PROJECTFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sav(char* bin, int bits, char* output) { // Save binary number in fixed bits
    char temp = '0';  // Default sign bit for positive
    int zero;
    int len = strlen(bin);
    if (bin[0] == '-') {  // Handle negative numbers
        memmove(bin, bin + 1, len);  // Remove negative sign
        temp = '1';}  // Set sign bit for negative
    len = strlen(bin);  // Update length after removing sign
    if (len < bits) {  // Pad if binary is shorter than required bits
        zero = bits - len - 1;
        if (zero > 0) {for (int i = 1; i <= zero; i++) {output[i] = '0';}}  // Add padding zeros
        output[0] = temp;  // Set sign bit
        strcpy(output + zero + 1, bin);  // Copy binary digits
        output[bits] = '\0';  // Null-terminate output
    }
}
void rc(char* output) {  // restricted complement function
    int i;
    if (output[0] == '1'){  // If the number is negative (sign bit is 1)
        for (i = 1; i < strlen(output); i++) {
            if (output[i] == '0') {output[i] = '1';}  // If the bit is '0', flip it to '1'
            else {output[i] = '0';}  // If the bit is '1', flip it to '0'
        }
    }
}
void tc(char* output) {  // true complement function
    int len = strlen(output);
    int first_one;
    if (output[0] == '1') {  // If the number is negative (sign bit is 1)
        for (int i = len - 1; i >= 1; i--) {  // Search for the first '1' from the right
            if (output[i] == '1') {
                first_one = i;
                break;
            }
        }
        for (int j = 1; j < first_one; j++) {  // Flip the bits before the first '1'
            if (output[j] == '1') {output[j] = '0';}
            else {output[j] = '1';}
        }
    }
}
// Function to check if a string is valid for the given base (2, 8, 10, or 16)
int check_valid(const char* number, int base) {
    int len = strlen(number);
    int strt = 0;
    // Skip the sign if present
    if (number[0] == '-') {strt = 1;}
    // Check each character in the number
    for (int i = strt; i < len; i++) {
        if (number[i] == '.') continue;  // Allow decimal point
        char dgt = number[i];
        // Validate based on base
        if (base == 2) {if (dgt != '0' && dgt != '1') {return 1;}  // Base 2: only '0' and '1'
        } else if (base == 8) {
            if (dgt < '0' || dgt > '7') {return 1;}  // Base 8: digits '0'-'7'
        } else if (base == 10) {
            if (dgt < '0' || dgt > '9') {return 1;}  // Base 10: digits '0'-'9'
        } else if (base == 16) {
            if (!((dgt >= '0' && dgt <= '9') || (dgt >= 'A' && dgt <= 'F') || (dgt >= 'a' && dgt <= 'f'))) {return 1;}  // Base 16: '0'-'9', 'A'-'F', 'a'-'f'
        }
    }
    return 0;  // Valid number
}
// Function to convert a decimal (base 10) number to a string in another base (2, 8, or 16)
void fromb10(double decimal, char* result, int base) {
    int sign;
    // Set the sign of the number
    if (decimal < 0) {sign = -1;}  // Negative
    else {sign = 1;}   // Positive
    decimal = fabs(decimal);  // Work with absolute value
    int integer_part = (int)decimal;
    double fractional_part = decimal - integer_part;
    int index = 0;
    // Add minus sign if negative
    if (sign == -1) {result[index] = '-';
        index++;}
    // Convert the integer part to target base
    char int_temp[64];
    int int_index = 0;
    if (integer_part == 0) {int_temp[int_index] = '0';  // If 0, just add '0'
        int_index++;}
    else {
        while (integer_part > 0) {int remainder = integer_part % base;
            // Convert remainder to appropriate digit or letter
            if (remainder < 10) {int_temp[int_index] = remainder + '0';}
            else {int_temp[int_index] = remainder - 10 + 'A';}
            int_index++;
            integer_part /= base;
        }
    }
    // Reverse the integer part
    for (int i = int_index - 1; i >= 0; i--) {
        result[index] = int_temp[i];
        index++;}
    // Convert fractional part to target base
    if (fractional_part > 0) {result[index] = '.';
        index++;
        for (int i = 0; i < 8; i++) {  // Limit to 8 digits
            fractional_part *= base;
            int frac_bit = (int)fractional_part;
            // Convert fraction to appropriate digit or letter
            if (frac_bit < 10) {result[index] = frac_bit + '0';}
            else {result[index] = frac_bit - 10 + 'A';}
            index++;
            fractional_part -= frac_bit;
            if (fractional_part == 0) break;  // Stop when no more fraction
        }
    }
    result[index] = '\0';  // Null-terminate the result
}
// Function to convert a string from base 2, 8, or 16 to a decimal (base 10) number
double tob10(const char* input, int base) {
    double decimal = 0;
    int len = strlen(input);
    int sign;
    // Set sign based on input
    if (input[0] == '-') {sign = -1;}  // Negative
    else {sign = 1;}   // Positive
    int point_pos;
    // Find the decimal point position
    if (strchr(input, '.') != NULL) {point_pos = strchr(input, '.') - input;}
    else {point_pos = len;}
    // Convert the integer part
    int start_index; // Skip sign if negative
    if (sign == -1){
        start_index=1;
    }else {start_index =0;
    }

    for (int i = start_index; i < point_pos; i++) {
        char dgt = input[i];
        int digit_value;
        // Handle different digit ranges
        if (dgt >= '0' && dgt <= '9') {digit_value = dgt - '0';}
        else if (dgt >= 'A' && dgt <= 'F') {digit_value = dgt - 'A' + 10;}
        else if (dgt >= 'a' && dgt <= 'f') {digit_value = dgt - 'a' + 10;}
        else {return 0;}  // Invalid character
        if (digit_value >= base) {return 0;}  // Invalid digit for base
        decimal = decimal * base + digit_value;}
    // Convert the fractional part
    double fraction = 1.0 / base;
    for (int i = point_pos + 1; i < len; i++) {
        char dgt = input[i];
        int digit_value;
        // Handle digits
        if (dgt >= '0' && dgt <= '9') {digit_value = dgt - '0';}
        else if (dgt >= 'A' && dgt <= 'F') {digit_value = dgt - 'A' + 10;}
        else if (dgt >= 'a' && dgt <= 'f') {digit_value = dgt - 'a' + 10;}
        else {return 0;}  // Invalid character
        if (digit_value >= base) {return 0;}  // Invalid digit for base
        decimal += digit_value * fraction;
        fraction /= base;
    }
    return decimal * sign;  // Return the result with correct sign
}

#endif // PROJECTFUNCTIONS_H_INCLUDED
