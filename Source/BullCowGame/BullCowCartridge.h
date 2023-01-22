// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

//Add new Struct
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
	int32 Oxs = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();
	void EndGame();
	void ProcessGuess(const FString& Guess);
	bool IsIsogram(const FString& Word) const;
	void LostLife(int32 Lives);
	TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
	FBullCowCount GetBullsCowsOxs(const FString& Guess) const;	

	// Your declarations go below!
	private:
	FString HiddenWord;
	int32 Lifes;
	bool bGameOver;
	TArray<FString> Words;
	TArray<FString> Isograms;
	
};
