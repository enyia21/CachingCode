// CachingCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>;

//Create eight Structs with array location and value.
struct cacheLocation {
    int location;
    string value;
};
int cacheMisses = 0;
string ConvertDecimalToRadix(int decimal, int radix) {
    string radixString = "";
    int i = decimal;
    int mod;
    if (decimal != 0) {
        while (i > 0) {
            mod = i % radix;
            i = i / radix;
            radixString = to_string(mod) + radixString;
        }
    }
    else {
        radixString = "0";
    }
    if (radixString.length() < 8) {
        while (radixString.length() < 8) {
            radixString = "0" + radixString;
        }
    }
    return radixString;
}
 
void fillArray(string arrayToBeFilled[], int length) {
    
    for (int i = 0; i < length; i++) {
        arrayToBeFilled[i] = ConvertDecimalToRadix(i, 2);
    }
}

void initCacheForFunctions(struct cacheLocation * myCache, string filledMemory[]) {  
    for (int i = 0; i < 8; i++) {
        myCache[i].location = i * 32;
        myCache[i].value = filledMemory[(i * 32)];
    }
}

bool checkIfCacheIsLoaded(struct cacheLocation* cache, string mem[], int userInput) {
    int cacheLocation = 0;
    cacheLocation = userInput / 32;
    switch (cacheLocation) {
    case 0:
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 1:
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }        
    break;
    case 2: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 3: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 4: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 5: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 6: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 7: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
    case 8: 
        if (userInput == cache[cacheLocation].location) {
            cout << "\nValue at location: " << userInput << " is " << cache[cacheLocation].value;
            return true;
        }
        else {
            cacheMisses++;
            cache[cacheLocation].location = userInput;
            cache[cacheLocation].value = mem[userInput];
            return false;
        }
        break;
     }
}

int main()
{
    /// <summary>
    /// Create a program in C++ which simulates a direct cache. The memory array that contains the data to be cached is
    /// byte addressable and can contain 256 single byte entries or lines. The cache has only 8 entries or lines. 
    /// The Data field in each line of the cache is 8 bits. Since the data stored in each line of the cache is only 8 bits, 
    /// there is no need for a line field. Only a tag field is needed which is log2(256) = 8 bits. 
    /// The memory array can be filled with any values of your choice.
    /// The program should work by taking user input of a memory address(index).
    /// This input represents the memory data that should be cached.Your program will check the cache to see if the item is already cached.
    /// If it is not, your program should count a cache miss, and then replace the item currently in the cache with the 
    /// data from the inputted address.Allow the user to input addresses(in a loop), until they so choose to end the program.
    /// The program should output the number of cache misses upon ending.
    /// </summary>
    /// <returns></returns>
    
    bool findValues = false;
    string checkCache = "N";
    int input;

    string mockMem[256];
    int memSize;
    memSize = 256;
    fillArray(mockMem, memSize);

    //Create a cache 
   

    struct cacheLocation UserCache[8];
    initCacheForFunctions(UserCache, mockMem);

    do {
        cout << "\nWould you like to check the memory cache? ";
        cin >> checkCache;
        if (checkCache == "Y") {
            findValues = true;
            cout << "Please input a value between 0 and 255: ";
            cin >> input;
            if (input < 0 || input > 255) {
                cout << "Please input a valid value! ";
            }
            else {
                if (checkIfCacheIsLoaded(UserCache, mockMem, input)) {
                    cout << "\nCache is hit";
                }
                else {
                    cout << "\nCache miss";
                }
            }
        }
        else if (checkCache == "N") {
            findValues = false;
        }
        else {
            cout << "\nPlease input valid values! ";
            findValues = true;
        }
    } while (findValues);
    cout << "\nNumber of misses: " << cacheMisses;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
