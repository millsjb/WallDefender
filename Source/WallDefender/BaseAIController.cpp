// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIController.h"

ABaseAIController::ABaseAIController(const FObjectInitializer &FOI)
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void ABaseAIController::Posses(class APawn* InPawn)
{

}

void ABaseAIController::SearchForEnemy()
{

}

void ABaseAIController::SetEnemy(class APawn *InPawn)
{

}