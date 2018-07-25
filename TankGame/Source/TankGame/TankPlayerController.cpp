// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

// Called when the game starts
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* ControlledTank = (ATank*)GetPawn();

	if (!ControlledTank) { return; }

	// Get the location the crosshair is aiming at
	FVector HitLocation;
	if (GetCrosshairHitLocation(HitLocation))
	{
		// Aim at that location plus one cm above it
		ControlledTank->AimAt(HitLocation + FVector(0.0f, 0.0f, 1.0f));
	}
}

// Get the location in world space the crosshair is aiming at
bool ATankPlayerController::GetCrosshairHitLocation(FVector& OutHitLocation) const
{
	// Get the position of the crosshair in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// Get the location of the camera and the direction the crosshair is facing
	FVector StartLocation;
	FVector LookDirection;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, StartLocation, LookDirection);

	// Do a raycast and find the hit location in the world
	if (DoRaycastInDirection(StartLocation, LookDirection, OutHitLocation))
	{
		return true;
	}
	return false;
}

// Do a raycast and find the hit location in the world
bool ATankPlayerController::DoRaycastInDirection(FVector StartLocation, FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}	
	return false;
}