// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIController.h"
#include "BaseAIAttacker.h"
#include "BasePlayerDefender.h"

ABaseAIController::ABaseAIController(const FObjectInitializer &FOI)
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void ABaseAIController::Posses(class APawn* InPawn)
{
	Super::Possess(InPawn);
	ABaseAIAttacker* Bot = Cast<ABaseAIAttacker>(InPawn);
	if (Bot != nullptr && Bot->BotBehavior != nullptr)
	{
		BlackboardComp->InitializeBlackboard(*(Bot->BotBehavior->BlackboardAsset));

		EnemyKeyID.SetNumber(BlackboardComp->GetKeyID("Enemy"));
		EnemyLocationID.SetNumber(BlackboardComp->GetKeyID("Destination"));

		BehaviorComp->StartTree(*(Bot->BotBehavior));
	}
}

void ABaseAIController::SearchForEnemy()
{
	APawn* MyBot = GetPawn();
	if (MyBot == NULL)
	{
		return;
	}

	const FVector MyLoc = MyBot->GetActorLocation();
	float BestDistSq = MAX_FLT;
	ABasePlayerDefender* BestPawn = NULL;

	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		ABasePlayerDefender* TestPawn = Cast<ABasePlayerDefender>(*It);

		if (TestPawn)
		{
			const float DistSq = FVector::Dist(TestPawn->GetActorLocation(), MyLoc);

			if (DistSq < BestDistSq)
			{
				BestDistSq = DistSq;
				BestPawn = TestPawn;
			}
		}
	}

	if (BestPawn)
	{
		SetEnemy(BestPawn);
	}

}

void ABaseAIController::SetEnemy(class APawn *InPawn)
{
	BlackboardComp->SetValueAsObject(EnemyKeyID, InPawn);
	BlackboardComp->SetValueAsVector(EnemyLocationID, InPawn->GetActorLocation());
}