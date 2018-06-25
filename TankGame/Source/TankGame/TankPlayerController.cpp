// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	ATank* Tank = GetControlledTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is here!"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find the tank!"));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("I AM HERE!"));
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location through the crosshair
	// If it hits the landscape, tell the controlled tank to aim there
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return (ATank*)GetPawn();
}