// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseAIAttacker.generated.h"

UCLASS()
class WALLDEFENDER_API ABaseAIAttacker : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseAIAttacker();
	ABaseAIAttacker(const FObjectInitializer &FOI);

	UPROPERTY(EditAnywhere, Category = Behave)
		class UBehaviorTree* BotBehavior;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
