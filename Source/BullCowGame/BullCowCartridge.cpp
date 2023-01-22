// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
// #include "HiddenWordList.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// Function to start game
void UBullCowCartridge::BeginPlay()
{ // When the game starts
    Super::BeginPlay();

    /*
        FPaths::ProjectContentDir() will return the absolute path to the Content directory
        The / operator has been overloaded to concatenate the two strings together ensuring a / inbetween them. So in this example that line of code would result in an FString with the value
    */
    /*
        In order for this to work in a packaged game you would need to add the WordLists directory to the list of Additional Non-Asset Directories to package in your Project Settings under Packaging.
        Alternatively you can just use the search.
    */
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");

    /*
        FFileHelper::LoadFileToStringArray loads a text file into a TArray of FStrings.
        The first argument is the TArray to populate and the second is the path to the file.

    FFileHelper::LoadFileToStringArray(Words, *WordListPath);
    */

    /*
        LoadFileToStringArrayWithPredicate takes an additional argument in the form of a function object which takes an FString and returns bool (a function that returns bool are "predicates").
        This new third argument is called a lambda. One of its uses is to be able to pass a function to another function.
    */

    // This Line replace the line "Isograms = GetValidWords(Words);"
    FFileHelper::LoadFileToStringArrayWithPredicate(Isograms, *WordListPath, [this](const FString &Word)
        {
            return Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word); 
        });

    // Valid Word List
    //  Isograms = GetValidWords(Words);  

    // Setting Up Game
    SetupGame();
}

// Fuction for start game
void UBullCowCartridge::OnInput(const FString &Input)
{ // When the player hits enter

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    { // Checking playerguess
        ProcessGuess(Input);
    }
}

// Function for Initialize variables and hiddenword messages
void UBullCowCartridge::SetupGame()
{
    // Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows Game!\n"));

    // Set the hidden word
    //  HiddenWord = Isograms[rand() % Isograms.Num()];
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have: %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nAnd press enter to continue...")); // Prompt Player for guess

    PrintLine(TEXT("The Hidden Word is: %s."), *HiddenWord); // Debug Line
}

// Function for Eng Game
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again."));
}

// Function for the process fo Game
void UBullCowCartridge::ProcessGuess(const FString &Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("------------------------------------\nYou Won! :D"));
        EndGame();
    }
    else
    {

        // Check is isogram
        if (!IsIsogram(Guess))
        {
            PrintLine(TEXT("\n--> No repaeating letters, guess again."));
        }

        --Lives;

        // Chec if the lifes == 0
        if (Lives > 0)
        {
            if (Guess.Len() != HiddenWord.Len())
            {
                LostLife(Lives);
            }
            else
            {
                if (Guess != HiddenWord)
                {
                    LostLife(Lives);
                }
            }
        }
        else
        {
            PrintLine(TEXT("------------------------------------\nYou have no lives left! X.X"));
            PrintLine(TEXT("The hidden word was: %s."), *HiddenWord);
            EndGame();
        }
    }
}

// Function for check the isogram
bool UBullCowCartridge::IsIsogram(const FString &Isogram) const
{
    for (int32 Index = 0; Index < Isogram.Len(); Index++)
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

// Function for Lost Life
void UBullCowCartridge::LostLife(int32 Lives)
{
    PrintLine(TEXT("\nLost a live!"));
    PrintLine(TEXT("Sorry try again!. \nYou have -> %i lives remaining."), Lives);
}

// Function valid words
TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString> &WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
}