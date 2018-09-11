/*
    Roman numerals converter

    This sketch is converting Roman numerals to Arabic numbers and back.
    It is made by following the logic of Java example I found online.

    Created 15 August 2018
    By Dusan Lesan
*/

String input = "1884";
//String input = "MDCCCLXXXIV";

void setup() {
    Serial.begin(9600);
    Serial.print(input);
    if (isValidNumber(input)) {
        Serial.print(" converted to Roman numerals is: ");
        Serial.println(toRoman(input.toInt()));
    } else {
        Serial.print(" converted to Arabic numbers is: ");
        Serial.println(toArabic(input));
    }
}

void loop() {}

boolean isValidNumber(String str) {
   if (str.length() == 0) return false;
   for (byte i = 0; i < str.length(); i++)
   {
       if (!isDigit(str.charAt(i))) return false;
   }
   return true;
}

const String numberMatrix[14][2] = {
    {"1000", "M"},
    {"900", "CM"},
    {"500", "D"},
    {"400", "CD"},
    {"100", "C"},
    {"90", "XC"},
    {"50", "L"},
    {"40", "XL"},
    {"10", "X"},
    {"9", "IX"},
    {"5", "V"},
    {"4", "IV"},
    {"1", "I"},
    {"0", ""}
};

String toRoman(int number) {
    int index = 0;
    String output = "";
    while (floor(number) < 13) {
        index = floor(number);
        output += numberMatrix[index][1];
        number -= numberMatrix[index][0].toInt();
    }
    return output;
}

int floor(int number) {
    int index = 0;
    for (index; index < 14; index++) {
        if (numberMatrix[index][0].toInt() <= number) {
            return index;
        }
    }
    return index;
}

const String reversedNumberMatrix[14][2] = {
    {"900", "CM"},
    {"1000", "M"},
    {"400", "CD"},
    {"500", "D"},
    {"90", "XC"},
    {"100", "C"},
    {"40", "XL"},
    {"50", "L"},
    {"9", "IX"},
    {"10", "X"},
    {"4", "IV"},
    {"5", "V"},
    {"1", "I"},
    {"0", ""}
};

int toArabic(String romanNumber) {
    int index = 0;
    int output = 0;
    while (floor(romanNumber) < 13) {
        index = floor(romanNumber);
        output += reversedNumberMatrix[index][0].toInt();
        romanNumber.remove(romanNumber.indexOf(reversedNumberMatrix[index][1]), reversedNumberMatrix[index][1].length());
    }
    return output;
}
int floor(String number) {
    int index = 0;
    for (index; index < 14; index++) {
        if (number.indexOf(reversedNumberMatrix[index][1]) != -1) {
            return index;
        }
    }
    return index;
}
