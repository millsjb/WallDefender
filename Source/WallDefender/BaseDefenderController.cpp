// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseDefenderController.h"

ABaseDefenderController::ABaseDefenderController()
{
	BowKeyHeld = false;
	bShowMouseCursor = true;
	BowCurrentVelocity = 0.0f;
}

void ABaseDefenderController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("BowHeld", IE_Pressed, this, &ABaseDefenderController::OnPressBow);
	InputComponent->BindAction("BowHeld", IE_Released, this, &ABaseDefenderController::OnReleaseBow);

}

void ABaseDefenderController::Tick(float Duration)
{
	if (BowKeyHeld)
	{
		ABasePlayerDefender* Defender = (ABasePlayerDefender *)GetPawn();
		float MaxBowVelocity = Defender->GetBowMaxVelocity();
		float VelocityScale = Defender->GetBowVelocityScale();

		BowCurrentVelocity = FMath::Clamp(BowCurrentVelocity + VelocityScale * Duration, 0.0f, MaxBowVelocity);
		UE_LOG(LogTemp, Warning, TEXT("Velocity is now up to %f"), BowCurrentVelocity);
	}
}

void ABaseDefenderController::OnReleaseBow()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	UE_LOG(LogTemp, Warning, TEXT("OnReleaseBow Entered"));

	if (Hit.bBlockingHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Blocking hit registered!"));

		FVector SpawnLocation = GetPawn()->GetActorLocation();
		SpawnLocation.X += 100.0f;
		
		FRotator SpawnRotation = (Hit.ImpactPoint - SpawnLocation).Rotation();
		FActorSpawnParameters SpawnInfo;
		AProjectile *LaunchedArrow = GetWorld()->SpawnActor<AProjectile>(SpawnLocation, SpawnRotation, SpawnInfo);
		FVector ArrowVelocity = LaunchedArrow->GetActorForwardVector();
		ArrowVelocity *= BowCurrentVelocity;
		LaunchedArrow->SetVelocity(ArrowVelocity);
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Blocking hit not registered!"));
	}
	BowCurrentVelocity = 0.0f;
	BowKeyHeld = false;
}

void ABaseDefenderController::OnPressBow()
{
	BowKeyHeld = true;
}