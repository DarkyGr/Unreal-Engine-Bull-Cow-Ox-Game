// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay(){    // When the game starts
    Super::BeginPlay();

    //Setting Uo Game
    SetupGame();

    PrintLine(TEXT("The Hiiden Word is: %s."), *HiddenWord);    //Debug Line
    
}

void UBullCowCartridge::OnInput(const FString& Input){     // When the player hits enter
    
    
    if (bGameOver){
        ClearScreen();
        SetupGame();

    }else{  //Checking playerguess
        ProcessGuess(Input);
    }

}

void UBullCowCartridge::SetupGame(){
    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows Game!"));    

    //Set the hidden word
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have: %i lives"), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue..."));    //Prompt Player for guess

    const TCHAR HW[] = TEXT("cakes");
    \
    PrintLine(TEXT("Cahracter 1 of the hidden word is: %c"), HiddenWord[0]);    //Print 1th char of the hiddenword
    PrintLine(TEXT("The 4th character of hidden word is: %c"), HiddenWord[3]);  //Print 4th char of the hiddenword
}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT( "\nPress enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess){
    if (Guess == HiddenWord){
        PrintLine(TEXT("------------------------------------\nYou Won! :D"));
        EndGame();

    }else{

        //Check is isogram
        if (!IsIsogram(Guess))
        {
            PrintLine(TEXT("No repaeating letters, guess again."));
        }

        PrintLine(TEXT("Lost a live!"));
        PrintLine(TEXT("%i"), --Lives);
        
        if (Lives > 0)
        {
            if (Guess.Len() != HiddenWord.Len()){
                PrintLine(TEXT("Sorry try again!. \nYou have -> %i lives remaining"), Lives);
            }
        }else
        {
            PrintLine(TEXT("------------------------------------\nYou have no lives left!"));
            PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
            EndGame();
        }
    }
}

bool UBullCowCartridge::IsIsogram(FString Isogram)
{
    return true;    
}