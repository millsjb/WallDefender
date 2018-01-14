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
	UE_LOG(LogTemp, Warning, TEXT("In Possess"));
	Super::Possess(InPawn);
	ABaseAIAttacker* Bot = Cast<ABaseAIAttacker>(InPawn);
	if (Bot != nullptr && Bot->BotBehavior != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("My pawn or its behavior is NOT null :("));

		BlackboardComp->InitializeBlackboard(*(Bot->BotBehavior->BlackboardAsset));

		EnemyKeyID = BlackboardComp->GetKeyID("Enemy");
		EnemyLocationID = BlackboardComp->GetKeyID("Destination");

		BehaviorComp->StartTree(*(Bot->BotBehavior));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("My pawn or its behavior is null :("));
	}
}

void ABaseAIController::SearchForEnemy()
{
	UE_LOG(LogTemp, Warning, TEXT("In search for enemy"));

	APawn* MyBot = GetPawn();
	if (MyBot == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't search for enemy as my pawn is null :("));
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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find an enemy to search for :("));
	}

}

void ABaseAIController::SetEnemy(class APawn *InPawn)
{
	BlackboardComp->SetValueAsObject("Enemy", InPawn);
	BlackboardComp->SetValueAsVector("Destination", InPawn->GetActorLocation());
}

void ABaseAIController::Tick(float num)
{
	APawn* MyBot = GetPawn();

	FVector currLoc = MyBot->GetActorLocation();
	currLoc.X -= 1.0f;
	MyBot->SetActorLocation(currLoc);


	ABaseAIAttacker* attacker = dynamic_cast<ABaseAIAttacker*>(MyBot);

}