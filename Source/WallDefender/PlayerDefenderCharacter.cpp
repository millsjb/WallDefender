// Fill out your copyright notice in the Description page of Project Settings.

#include "WallDefender.h"
#include "PlayerDefenderCharacter.h"


// Sets default values
APlayerDefenderCharacter::APlayerDefenderCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerDefenderCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerDefenderCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerDefenderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

