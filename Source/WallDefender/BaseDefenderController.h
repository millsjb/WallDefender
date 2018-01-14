// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseDefenderController.generated.h"

/**
 * 
 */
UCLASS()
class WALLDEFENDER_API ABaseDefenderController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void Tick(float num) override;
	
	
	
};
