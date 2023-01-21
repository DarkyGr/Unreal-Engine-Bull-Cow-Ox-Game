// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

//Function to start game
void UBullCowCartridge::BeginPlay(){    // When the game starts
    Super::BeginPlay();

    //Setting Uo Game
    SetupGame();

    for (int32 i = 0; i < 5; i++)
    {
        PrintLine(TEXT("%s"), *Words[i]);
    }
        
}

//Fuction for start game
void UBullCowCartridge::OnInput(const FString& Input){     // When the player hits enter

    if (bGameOver){
        ClearScreen();
        SetupGame();

    }else{  //Checking playerguess
        ProcessGuess(Input);
    }

}

//Function for Initialize variables and hiddenword messages 
void UBullCowCartridge::SetupGame(){
    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows Game!\n"));    

    //Set the hidden word
    // HiddenWord = TEXT("cakes");
    HiddenWord = Words[rand() % Words.Num()];
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("The Hidden Word is: %s."), *HiddenWord);    //Debug Line

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have: %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nAnd press enter to continue..."));    //Prompt Player for guess

    // const TCHAR HW[] = TEXT("cakes");    
    // PrintLine(TEXT("The 1th character of the hidden word is: %c"), HiddenWord[0]);    //Print 1th char of the hiddenword
    // PrintLine(TEXT("The 4th character of the hidden word is: %c"), HiddenWord[3]);  //Print 4th char of the hiddenword  

    // IsIsogram(HiddenWord);
}

//Function for Eng Game
void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT( "\nPress enter to play again."));
}

//Function for the process fo Game
void UBullCowCartridge::ProcessGuess(FString Guess){
    if (Guess == HiddenWord){
        PrintLine(TEXT("------------------------------------\nYou Won! :D"));
        EndGame();
    }else{

        // Check is isogram
        if (!IsIsogram(Guess))
        {
            PrintLine(TEXT("\n--> No repaeating letters, guess again."));
        }

        --Lives;       
        
        //Chec if the lifes == 0
        if (Lives > 0)
        {
            if (Guess.Len() != HiddenWord.Len()){
                LostLife(Lives);
            }else{
                if (Guess != HiddenWord)
                {
                    LostLife(Lives);
                }
            }
        }else
        {
            PrintLine(TEXT("------------------------------------\nYou have no lives left! X.X"));
            PrintLine(TEXT("The hidden word was: %s."), *HiddenWord);
            EndGame();            
        }
    }
}

//Function for check the isogram
bool UBullCowCartridge::IsIsogram(FString Isogram) const
{
    for (int32 Index =0; Index < Isogram.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Isogram.Len(); Comparison++)
        {
            if (Isogram[Index] == Isogram[Comparison])
            {
                return false;
            }            
        }        
    }
    
    return true;
}

//Function for Lost Life
void UBullCowCartridge::LostLife(int32 Lives)
{
    PrintLine(TEXT("\nLost a live!"));
    PrintLine(TEXT("Sorry try again!. \nYou have -> %i lives remaining."), Lives);
}