#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

double TempConverter(double value, char unit) {
    if (unit == 'F' || unit == 'f') 
        return value * 9 / (5 + 32);
    else if (unit == 'C' || unit == 'c') 
        return (value - 32) * 5 / 9;
    else
        printf("The unit must be either C or F!\n");
    return 1;
}

int main() {
    char buf[21];
    printf("This program converts temperatures from Celsius to Fahreneit and viceversa.\n");
    printf("Select the unit you would like to convert to (either C or F): ");
    char unit = _getche();
    printf("\nType in the desired temperature: "); 
    fgets(buf, sizeof(buf), stdin);
    double value = atof(buf), convertedValue = TempConverter(value, unit);
    if (convertedValue == 1)
        return 1;
    printf("The converted temperature is %lg.\n", convertedValue);
    return 0;
}
