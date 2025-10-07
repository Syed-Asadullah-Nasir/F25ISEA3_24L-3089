#include <iostream>
#include <string>
#include <conio.h> 

using namespace std;

string toLowerCase(const string& str) 
{
    string lower = "";
    for (int i = 0; str[i] != '\0'; ++i) 
    {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
            ch = ch + ('a' - 'A'); // ASCII conversion
        lower += ch;
    }
    return lower;
}

bool isPalindrome(const string& str) 
{
    int left = 0;
    int right = str.length() - 1;
    if (str.length() == 0 || str[0]==' ')
    {
        return false; 
    }
    else
    {
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
}

string promptUser() 
{
    string input;
    cout << endl;
    cout << "Enter a string to check: ";
    getline(cin, input);
    return toLowerCase(input);
}

void runPalindromeChecker() 
{
    cout << "Palindrome Checker (Press ESC to exit)" << endl;

    while (true) 
    {
        string input = promptUser();

		if (input.length() == 1 && input[0] == 27) // ESC key
        { 
            cout << "Exiting program." << endl;
            break;
        }

        if (isPalindrome(input))
        {
            cout << "Result: Palindrome" << endl;
        }
        else
        {
            cout << "Result: Not Palindrome" << endl;
        }

        cout << "Press any key to continue or ESC to exit..." << endl;
        char ch = _getch();
        if (ch == 27) // ESC key
        {
            break;
        }
    }
}

int main() 
{
    runPalindromeChecker();
    return 0;
}
