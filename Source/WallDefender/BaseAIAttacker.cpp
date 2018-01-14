// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIAttacker.h"
#include "BaseAIController.h"


// Sets default values
ABaseAIAttacker::ABaseAIAttacker()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ABaseAIAttacker::ABaseAIAttacker(const FObjectInitializer &FOI)
{
	AIControllerClass = ABaseAIController::StaticClass();
}

// Called when the game starts or when spawned
void ABaseAIAttacker::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseAIAttacker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseAIAttacker::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

