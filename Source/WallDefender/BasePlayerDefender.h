// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayerDefender.generated.h"

UCLASS()
class WALLDEFENDER_API ABasePlayerDefender : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasePlayerDefender();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float GetBowMaxVelocity();
	float GetBowVelocityScale();

private:
	float MoveSpeed;
	float BowMaxVelocity;
	float BowVelocityScale;
	float BowCurrentVelocity;
};
