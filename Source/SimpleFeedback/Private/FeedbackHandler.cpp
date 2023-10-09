// Fill out your copyright notice in the Description page of Project Settings.


#include "FeedbackHandler.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"


UForceFeedbackEffect* AFeedbackHandler::FeedbackLevelLow = nullptr;
UForceFeedbackEffect* AFeedbackHandler::FeedbackLevelMid = nullptr;
UForceFeedbackEffect* AFeedbackHandler::FeedbackLevelHigh = nullptr;

// Sets default values
AFeedbackHandler::AFeedbackHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFeedbackHandler::SetFeedbackLevels(UForceFeedbackEffect* LowFeedback, UForceFeedbackEffect* MidFeedback, UForceFeedbackEffect* HighFeedback)
{
	FeedbackLevelLow = LowFeedback;
	FeedbackLevelMid = MidFeedback;
	FeedbackLevelHigh = HighFeedback;
}
 
void AFeedbackHandler::PlayFeedbackByLevel(EFeedbackLevel level, APlayerController* PlayerController)
{

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Log, TEXT("Error getting player controller"));
	}

	switch (level)
	{
	case EFeedbackLevel::Low:
		if (FeedbackLevelLow)
			PlayCustomFeedback(PlayerController, FeedbackLevelLow);
		else
			UE_LOG(LogTemp, Error, TEXT("Invalid reference for LOW level feedback effect."));
		break;
	case EFeedbackLevel::Mid:
		if (FeedbackLevelMid)
			PlayCustomFeedback(PlayerController, FeedbackLevelMid);
		else
			UE_LOG(LogTemp, Error, TEXT("Invalid reference for MID level feedback effect."));
		break;
	case EFeedbackLevel::High:
		if (FeedbackLevelHigh)
			PlayCustomFeedback(PlayerController, FeedbackLevelHigh);
		else
			UE_LOG(LogTemp, Error, TEXT("Invalid reference for HIGH level feedback effect."));
		break;
	default:
		break;
	}

}

void AFeedbackHandler::PlayCustomFeedback(APlayerController* PlayerController, UForceFeedbackEffect* Effect)
{

	if (Effect != nullptr)
	{
		// Create a FForceFeedbackParameters struct to hold the feedback effect and other settings
		FForceFeedbackParameters FeedbackParams;
		FeedbackParams.bLooping = false;
		FeedbackParams.Tag = "CustomFeedback";

		PlayerController->ClientPlayForceFeedback(Effect, FeedbackParams);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid feedback effect reference"));
	}

}

// Called when the game starts or when spawned
void AFeedbackHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFeedbackHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

