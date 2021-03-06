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

	

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	// Maximum distance the raytrace goes before it hits something
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	// Do a raycast and find the hit location in the world
	bool DoRaycastInDirection(FVector StartLocation, FVector LookDirection, FVector& OutHitLocation) const;

	// Get the location in world space the crosshair is aiming at
	bool GetCrosshairHitLocation(FVector& OutHitLocation) const;
};