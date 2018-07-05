// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

// Called when the game starts
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation() + FVector(0.0f, 0.0f, 1000.0f));
}

// Get the tank the player is possessing
ATank* ATankAIController::GetPlayerTank()
{
	return (ATank*)GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Get the tank this ai controller is possessing
ATank* ATankAIController::GetControlledTank()
{
	return (ATank*)GetPawn();
}