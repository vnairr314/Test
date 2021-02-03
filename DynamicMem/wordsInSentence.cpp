/**

 Implement a function that gets a string containing a sentence. When called, it should create an return an array of strings that contain all
 the words in 'sentence'. It should also update the output parameter, outWordsArrSize, with the logical size of the new array that was created.

**/

#include <iostream>
#include <string>

using namespace std;

string *createWordsArray(string sentence, int &outWordsArrSize) {

    string *wordsArray = new string[1];
    int arrSize = 1;
    int sentenceLength = sentence.length();
    string word;
    int wordCounter = 0;
    int i = 0;

    while(sentenceLength >= 0) {

        if(sentence[i] == ' ' || sentence[i] == '\0') {

            if(wordCounter > 0) {

                string *tempArray;
                tempArray = new string[arrSize*2];
                for(int j = 0; j < wordCounter; j++) {
                    tempArray[j] = wordsArray[j];
                }
                delete []wordsArray;
                wordsArray = tempArray;
                arrSize *= 2;
            }

            wordsArray[wordCounter] = word;
            wordCounter++;
            word = "";
        }

        else {
            word += sentence[i];
        }

        i++;
        sentenceLength--;
    }

    outWordsArrSize = wordCounter;
    return wordsArray;

}

void printArray(string *arr, int arrSize) {

    cout << "Total number of words: " << arrSize << endl;
    cout << "Words in the sentence: [";

    for(int i = 0; i < arrSize; i++) {
        if(i == arrSize-1) {
            cout << arr[i] << "]" << endl;
        }
        else {
            cout << arr[i] << ", ";
        }
    }
}

int main() {

    string sentence;
    string *Arr;
    int outWordsArrSize;

    cout << "Enter a sentence: " << endl;
    getline(cin, sentence);

    Arr = createWordsArray(sentence, outWordsArrSize);
    printArray(Arr, outWordsArrSize);
    delete []Arr;
}
