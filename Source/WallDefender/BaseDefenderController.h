// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerDefender.h"
#include "Projectile.h"
#include "BaseDefenderController.generated.h"

/**
 * 
 */
UCLASS()
class WALLDEFENDER_API ABaseDefenderController : public APlayerController
{
	GENERATED_BODY()

protected:

	void SetupInputComponent() override;
	void Tick(float Duration) override;
	
public:
	ABaseDefenderController();

	void OnReleaseBow();
	void OnPressBow();

private:
	bool BowKeyHeld;
	float BowCurrentVelocity;
};
