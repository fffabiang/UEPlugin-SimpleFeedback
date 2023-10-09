// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ForceFeedbackEffect.h"
#include "GameFramework/PlayerController.h"
#include "FeedbackHandler.generated.h"


UENUM(BlueprintType)
enum class EFeedbackLevel : uint8 {
	Low       UMETA(DisplayName = "Low"),
	Mid        UMETA(DisplayName = "Mid"),
	High        UMETA(DisplayName = "High"),
};


UCLASS()
class SIMPLEFEEDBACK_API AFeedbackHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFeedbackHandler();

	UFUNCTION(BlueprintCallable, Category = Feedback)
	static void SetFeedbackLevels(UForceFeedbackEffect* LowFeedback, UForceFeedbackEffect* MidFeedback, UForceFeedbackEffect* HighFeedback);

	UFUNCTION(BlueprintCallable, Category = Feedback)
	static void PlayFeedbackByLevel(EFeedbackLevel level, APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category = Feedback)
	static void PlayCustomFeedback(APlayerController* PlayerController, UForceFeedbackEffect* Effect);

private:
	//Low level controller feedback effect
	static UForceFeedbackEffect* FeedbackLevelLow;
	
	//Mid level controller feedback effect
	static UForceFeedbackEffect* FeedbackLevelMid;

	//High level controller feedback effect
	static UForceFeedbackEffect* FeedbackLevelHigh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
