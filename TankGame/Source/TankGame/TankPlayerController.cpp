// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

// Called when the game starts
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

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();
}

// Tell the tank to aim at the location in world space the crosshair is aiming at
void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get the location the crosshair is aiming at
	FVector HitLocation;
	if (GetCrosshairHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get the location in world space the crosshair is aiming at
bool ATankPlayerController::GetCrosshairHitLocation(FVector& OutHitLocation) const
{
	// Get the position of the crosshair in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// Get the direction the crosshair is facing
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Do a raycast and find the hit location in the world
		FVector HitLocation;
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("World Location: %s"), *HitLocation.ToString());
	}

	return true;
}

// Get the direction the crosshair is facing
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector Dummy;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, Dummy, LookDirection);
}

// Do a raycast and find the hit location in the world
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}

// Get the tank this controller is possessing
ATank* ATankPlayerController::GetControlledTank() const
{
	return (ATank*)GetPawn();
}