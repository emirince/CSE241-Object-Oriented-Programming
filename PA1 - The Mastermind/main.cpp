#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

bool firstCount(int secret[] , int user[],int size){        //So this function returns true if the secret number found by user
    int count = 0;                                          //If user couldn't find, then it returns how many number user guessed
    for(int i = 0 ; i < size; i++){
        if(secret[i]==user[i]){
            count++;
        }
    }
    if(count==size){
        return true;
    }
    else{ 
        cout << count;
        return false;
    }
}

void secondCount(int secret[], int user[], int size){       //This function returns the number of digits that found in the number but on the right digit
    int count = 0;
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size; j++){
            if(secret[i] == user[j] && i != j){
                count++;
            }
        }
    }
    cout << " " << count << endl;
}

bool checkUnique(int arr[], int size) {        //This returns true if the number user provided from command line is unique or returns true
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}


int main(int argc, char *argv[]){
    srand(time(NULL));
    if(argc < 2){
        cout << "E0" << endl;
        exit(1);
    }

    int numOfDigits;
    int secretNumber[9];

    if (argc == 2 && std::strcmp(argv[1], "-r") == 0) {
        cout << "E0\n";
        exit(1);
    }
    if(strcmp(argv[1], "-r") == 0){
        if(argc != 3){
            cout << "E0" << endl;
            exit(1);
        }

        numOfDigits = atoi(argv[2]);

        if (numOfDigits <= 0) {
            cout << "E0" << endl;
            exit(1);
        }
        if(numOfDigits < 1 || numOfDigits > 9){
            cout << "E0" << endl;
            exit(1);
        }

        secretNumber[0] = rand()%9+1;
        
        bool durum = false;
        
        int check = 0;

        while(durum == false){
            for(int i = 1 ; i < numOfDigits ; i++){         //This generates secret number. This works until number is not unique
                secretNumber[i] = rand()%10;
            }
            check = 0;
            for(int i = 0 ; i < numOfDigits ; i++){
                for(int j = i + 1 ; j < numOfDigits ; j++){
                    if(secretNumber[i]==secretNumber[j]){
                        check++;
                    }
                }
            }
        
            if(check>0){        
                durum = false;
            }
            else{   
                durum = true;
            }
        }
    } 
    
    else if (strcmp(argv[1], "-u") == 0) {
        if (argc != 3) {
            cout << "E0" << endl;
            exit(1);
        }

        int secretLength = strlen(argv[2]);

        if (secretLength < 1 || secretLength > 9) {
            cout << "E0" << endl;
            exit(1);
        }

        numOfDigits = secretLength;

        for (int i = 0; i < secretLength; i++) {       
            secretNumber[i] = argv[2][i] - '0';
        }

        if (!checkUnique(secretNumber, numOfDigits)) {
            cout << "E0" << endl;
            return 1;
        }

    } 
    else {
        cout << "E0" << endl;
        exit(1);

    }

    int gameTurn = 1; 

    int userGuess = 0; 

    int userNumber[numOfDigits];

    bool isGameOver = false;

    while(gameTurn < 100 && isGameOver == false){       //Game continues until user cant find until 100 is over or game is over.

        userGuess = 0;

        cin >> userGuess;

        int n = numOfDigits - 1;

        for(int i = 0; i < numOfDigits; i++){
            userNumber[i] = 0;
        }

        int userHane = 0;
        
        while(userGuess>0){         //This turn int into int array.
            
            userNumber[n] = userGuess % 10;
            userGuess = userGuess / 10;
            n--;
            userHane++;
        }
        
        if (userHane != numOfDigits){       //If 
            cout << "E1" << endl;
            exit(1);
        }
        
        isGameOver = firstCount(secretNumber,userNumber,numOfDigits);
        
        if(isGameOver==true){
            cout << "FOUND " << gameTurn << endl;
             }
            else{
                secondCount(secretNumber,userNumber,numOfDigits);
            }
        gameTurn++;
        }
    return 0; 
    }