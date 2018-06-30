// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank* ATankAIController::GetPlayerTank()
{
	return (ATank*)GetWorld()->GetFirstPlayerController()->GetPawn();
}

ATank* ATankAIController::GetControlledTank()
{
	return (ATank*)GetPawn();
}