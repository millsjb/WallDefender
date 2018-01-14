// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseDefenderController.h"

void ABaseDefenderController::Tick(float num)
{
	APawn* MyBot = GetPawn();

	FVector currLoc = MyBot->GetActorLocation();
	currLoc.X += 1.0f;
	MyBot->SetActorLocation(currLoc);

}


