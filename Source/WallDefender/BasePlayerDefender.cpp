// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePlayerDefender.h"
#include "BaseDefenderController.h"


// Sets default values
ABasePlayerDefender::ABasePlayerDefender()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BowVelocityScale = 25.0f;
	BowMaxVelocity = 175.0f;
}

// Called when the game starts or when spawned
void ABasePlayerDefender::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayerDefender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currLoc = this->GetActorLocation();
	currLoc.X += 1.0f;
	this->SetActorLocation(currLoc);

}

// Called to bind functionality to input
void ABasePlayerDefender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABasePlayerDefender::GetBowMaxVelocity()
{
	return BowMaxVelocity;
}

float ABasePlayerDefender::GetBowVelocityScale()
{
	return BowVelocityScale;
}

