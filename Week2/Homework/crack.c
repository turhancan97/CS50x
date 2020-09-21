#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

bool findOneCharPasswords(string hashed, char salt[]);
bool findTwoCharsPasswords(string hashed, char salt[]);
bool findThreeCharsPasswords(string hashed, char salt[]);
bool findFourCharsPasswords(string hashed, char salt[]);
bool findFiveCharsPasswords(string hashed, char salt[]);

const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{   
    if(argc != 2) {
        printf("Wrong number of command line arguments");
        return 1;
    }
    
    string hashed = argv[1];
    
    char salt[3];  
    strncpy(salt, hashed, 2);
    salt[2] = '\0';
    
    if(!findOneCharPasswords(hashed, salt)) {
        if(!findTwoCharsPasswords(hashed, salt)) {
            if(!findThreeCharsPasswords(hashed, salt)) {
                if(!findFourCharsPasswords(hashed, salt)) {
                    findFiveCharsPasswords(hashed, salt);
                }
            }
        }
    }
}

bool findOneCharPasswords(string hashed, char salt[]) {
    for(int i = 0, n = strlen(letters); i < n; i++) {
        char password[2] = {letters[i], '\0'};
        if(strcmp(crypt(password, salt), hashed) == 0) {
            printf("%s\n", password);
            return true;
        }
    }
    return false;
}

bool findTwoCharsPasswords(string hashed, char salt[]) {
    for(int i = 0, n = strlen(letters); i < n; i++) {
        for(int j = 0; j < n; j++) {
            char password[3] = {letters[i], letters[j], '\0'};
            if(strcmp(crypt(password, salt), hashed) == 0) {
                printf("%s\n", password);
                return true;
            }
        }
    }
    return false;
}

bool findThreeCharsPasswords(string hashed, char salt[]) {
    for(int i = 0, n = strlen(letters); i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int a = 0; a < n; a++) {
                char password[4] = {letters[i], letters[j], letters[a], '\0'};
                if(strcmp(crypt(password, salt), hashed) == 0) {
                    printf("%s\n", password);
                    return true;
                }
            }
        }
    }
    return false;
}

bool findFourCharsPasswords(string hashed, char salt[]) {
    for(int i = 0, n = strlen(letters); i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int a = 0; a < n; a++) {
                for(int b = 0; b < n; b++) {
                    char password[5] = {letters[i], letters[j], letters[a], letters[b], '\0'};
                    if(strcmp(crypt(password, salt), hashed) == 0) {
                        printf("%s\n", password);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool findFiveCharsPasswords(string hashed, char salt[]) {
    for(int i = 0, n = strlen(letters); i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int a = 0; a < n; a++) {
                for(int b = 0; b < n; b++) {
                    for(int c = 0; c < n; c++) {
                        char password[6] = {
                            letters[i], letters[j], letters[a], 
                            letters[b], letters[c], '\0'
                            };
                        if(strcmp(crypt(password, salt), hashed) == 0) {
                            printf("%s\n", password);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

508ny6Rw0aRio
