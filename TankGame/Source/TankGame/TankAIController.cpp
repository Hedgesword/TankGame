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

	ATank* ControlledTank = (ATank*)GetPawn();
	ATank* PlayerTank = (ATank*)GetWorld()->GetFirstPlayerController()->GetPawn();

	ControlledTank->AimAt((PlayerTank->GetActorLocation() + FVector(0.0f, 0.0f, 1.0f)));
	ControlledTank->Fire();
}