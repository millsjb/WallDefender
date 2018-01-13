// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BaseAIController.generated.h"


/**
 * 
 */
UCLASS()
class WALLDEFENDER_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(transient)
	UBlackboardComponent* BlackboardComp;
		
	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorComp;
	
	virtual void Posses(class APawn *InPawn);

	void SetEnemy(class APawn *InPawn);

	UFUNCTION(BlueprintCallable, Category = Behavior)
	void SearchForEnemy();

public:
	ABaseAIController(const FObjectInitializer &FOI);

protected:
	uint8 EnemyKeyID;
	uint8 EnemyLocationID;



};
