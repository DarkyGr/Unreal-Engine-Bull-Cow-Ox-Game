// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    //Setting Uo Game
    SetupGAme();

    PrintLine(TEXT("The Hiiden Word is: %s."), *HiddenWord);    //Debug Line

    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows Game!"));    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue..."));    

    //Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{    
    ClearScreen();   

    //Checking player guess
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("It's Correct :D"));
    }
    else{
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The Hidden Word is %i characters long, try again!"), HiddenWord.Len());
        }
        PrintLine(TEXT("Failed :c"));
    }
    
    //Check if isogram
    //Prompt to guess again
    //Check rihgt number char
    //Prompt to guess again
    
    //Remove life

    //Check if lives > 0
    //If yes Play Again
    //Show lives left
    //If no show Game Over and HiddenWord
    //Prompt to Play Again, Press Enter to Play Again
    //Check user input
    //Play Again or Quit
}

void UBullCowCartridge::SetupGAme()
{
    HiddenWord = TEXT("cakes");
    Lives = 4;
}