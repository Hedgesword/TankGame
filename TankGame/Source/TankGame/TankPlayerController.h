// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be last include

UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Tell the tank to aim at the location in world space the crosshair is aiming at
	void AimAtCrosshair();

	// Get the location in world space the crosshair is aiming at
	bool GetCrosshairHitLocation(FVector& OutHitLocation) const;

	// Get the tank this controller is possessing
	ATank* GetControlledTank() const;

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	// Maximum distance the raytrace goes before it hits something
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	// Get the direction the crosshair is facing
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// Do a raycast and find the hit location in the world
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};