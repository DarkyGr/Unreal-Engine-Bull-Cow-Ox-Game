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

void UBullCowCartridge::SetupGame(){
    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows Game!"));    

    //Set the hidden word
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have: %i lives"), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue...")); 
}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT( "\nPress enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess){
    if (Guess == HiddenWord){
        PrintLine(TEXT("------------------------------------\nYou Won! :D"));
        EndGame();
    }
    else{            
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
            EndGame();
        }
    }
}