#include "common.hh"

class Conversion {
private:
    static const long hundred = 100;
    static const long thousand = 10 * hundred;
    static const long million = 10 * hundred * thousand;
    static const long billion = thousand * million;
    const vector<string> tens = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                                  "Eighty", "Ninety"};
    const vector<string> zero_to_nineteen = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    string toWords(long num) {
        if (num >= billion) {
            return toWords(num / billion) + " Billion" + toWords(num % billion);
        } else if (num >= million) {
            return toWords(num / million) + " Million"  + toWords(num % million);
        } else if (num >= thousand) {
            return toWords(num / thousand) + " Thousand" + toWords(num % thousand);
        } else if (num >= 100) {
            return toWords(num / hundred) + " Hundred" + toWords(num % hundred);
        } else if (num >= 20) {
            return " " + tens[ (num / 10) - 2] + toWords(num % 10);
        } else if (num > 0) {
            return " " + zero_to_nineteen[num];
        } else {
            return "";
        }
    }
public:
    string convertToWords(long num) {
        if (num == 0) {
            return "Zero";
        } else {
            string result = toWords(num);
            result.erase(result.begin());
            return result;
        }
    }
};

int main() {
    Conversion  c;
    cout << c.convertToWords(100001) << endl;
    cout << c.convertToWords(7998208001) << endl;
    cout << c.convertToWords(998) << endl;
    cout << c.convertToWords(2000000000000) << endl;
    cout << c.convertToWords(1234567891) << endl;

    return 0;
}

