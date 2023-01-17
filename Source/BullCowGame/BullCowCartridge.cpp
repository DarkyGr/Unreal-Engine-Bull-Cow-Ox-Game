// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows Game!"));
    PrintLine(TEXT("Guess the 4 letter word!"));  //Magic Number remove
    PrintLine(TEXT("Press enter to continue...")); 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{    
    ClearScreen();
    FString HiddenWord = TEXT("cake");    
    if (HiddenWord == Input)
    {
        PrintLine(TEXT("It's Correct :D"));
    }
    else{
        PrintLine(TEXT("Failed :c"));
    }    
}