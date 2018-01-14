// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("StaticMesh'/Game/Arrow_shot.Arrow_shot'"));
	RootComponent = MeshComp;
 	MeshComp->SetMobility(EComponentMobility::Movable);
 	MeshComp->SetStaticMesh(ProjectileMesh.Object);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComp->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector ProcessingLocation = GetActorLocation();
	ProcessingLocation += velocity;
	SetActorLocation(ProcessingLocation);
}

// Called to bind functionality to input
void AProjectile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AProjectile::SetVelocity(FVector _velocity)
{
	velocity = _velocity;
}

