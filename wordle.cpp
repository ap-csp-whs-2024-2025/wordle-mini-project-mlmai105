/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   
#include <ctime>     
#include <iostream>  
#include <string>    
#include <vector>    

std::vector<int> createSecret(int size){
    std::vector<int> code = {};
    int counter = 0;

    while (counter < size)
    {
        int val = rand() % 10;
        append(code, val);     
        counter = counter + 1;
    } 
    
    return code; 
}


std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess){
   
   std::vector<std::string> hint = {};
   int curr_index = 0;

    while(curr_index < length(guess))
    {
        if (guess[curr_index] != secret[curr_index])
        {
            append(hint, "X");
        }
        else
        {
            append(hint, "O");
        }
        curr_index = curr_index + 1;
    }  

    return hint;
}

bool winGame(std::vector<int> secret, std::vector<int> guess){
   int curr_index = 0; 

{
    while (curr_index < length(secret)) 
    {
        if(guess[curr_index] != secret[curr_index])
        {
            return false;
        }
        curr_index = curr_index + 1;
    }
    return true;
}
}

int main()
{
    srand(time(0)); 
    std::vector<int> secret_code = createSecret(4);
    std::cout << "Here is the secret code: ";
    display(secret_code);
         
    
    int randum_num = rand() % 10; 
   
    std::vector<int> guess = {-1, -1, -1, -1};
    std::vector<std::string> hint = {};    

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    
    while (!winGame(secret_code, guess))   
    {
        std::cout << "\nEnter your guess: ";
        guess = {};   
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            append(guess, input);    
        }

        hint = getHint(secret_code, guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
