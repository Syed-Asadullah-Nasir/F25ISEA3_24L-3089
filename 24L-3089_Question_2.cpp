// Console Based Hangman Game
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int maxWords = 150;
const int maxWordLength = 30;
const int maxMistakes = 7;

// Game state
char word[maxWordLength];
char guessedWord[maxWordLength];
char usedLetters[26];
int usedCount = 0;
int mistakes = 0;

int loadWords(char words[][maxWordLength], const char* filename) 
{
    ifstream file(filename);
    if (!file) 
    {
        cout << "Error: Cannot open file " << filename << endl;
        return 0;
    }

    int count = 0;
    while (file.getline(words[count], maxWordLength)) 
    {
        if (strlen(words[count]) > 0)
        {
            count++;
        }
        if (count >= maxWords)
        {
            break;
        }
    }

    file.close();
    return count;
}

void selectRandomWord(char words[][maxWordLength], int count) 
{
    int index = rand() % count;
    strcpy_s(word, words[index]);
}

void initializeGame() 
{
    int len = strlen(word);
    for (int i = 0; i < len; ++i)
    {
        guessedWord[i] = '_';
    }
    guessedWord[len] = '\0';
    usedCount = 0;
    mistakes = 0;
}

void displayWord() 
{
    cout << endl;
    cout << "Word: ";
    for (int i = 0; guessedWord[i] != '\0'; ++i)
        cout << guessedWord[i] << " ";
    cout << endl;
}

bool isLetterUsed(char letter) 
{
    for (int i = 0; i < usedCount; ++i)
    {
        if (usedLetters[i] == letter)
        {
            return true;
        }
    }
    return false;
}

bool updateGuessedWord(char letter) 
{
    bool found = false;
    for (int i = 0; word[i] != '\0'; ++i) 
    {
        if (word[i] == letter) 
        {
            guessedWord[i] = letter;
            found = true;
        }
    }
    return found;
}

bool isWordGuessed() 
{
    return strcmp(word, guessedWord) == 0;
}

void playHangman() 
{
    char words[maxWords][maxWordLength];
    int wordCount = loadWords(words, "words.txt");

    if (wordCount == 0) {
        cout << "No words loaded. Exiting." << endl;
        return;
    }

    selectRandomWord(words, wordCount);
    initializeGame();

    cout << "Welcome to Hangman!" << endl;
    cout << "You have " << maxMistakes << " chances to guess the word." << endl;

    while (mistakes <= maxMistakes)
    {
        displayWord();
        cout << "Used letters: ";
        for (int i = 0; i < usedCount; ++i)
            cout << usedLetters[i] << " ";
		cout << endl;
        cout << "Remaining mistakes : " << maxMistakes - mistakes << endl;

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        // Convert to lowercase
        if (guess >= 'A' && guess <= 'Z')
            guess += 'a' - 'A';

        if (isLetterUsed(guess)) 
        {
            cout << "You already used that letter. Try again." << endl;
            continue;
        }

        usedLetters[usedCount++] = guess;

        if (updateGuessedWord(guess))
        {
            cout << "Good guess!" << endl;
        }
        else 
        {
            mistakes++;
            cout << "Wrong guess!" << endl;
        }

        if (isWordGuessed()) 
        {
            displayWord();
            cout << endl;
            cout << "Congratulations! You guessed the word: " << word << endl;
            break;
        }

        if (mistakes > maxMistakes) 
        {
            cout << endl;
            cout << "Game Over! You've used all your chances." << endl;
            cout << "The word was: " << word << endl;
            break;
        }
    }
}

int main()
{
    srand(time(0));
    playHangman();
    return 0;
}

