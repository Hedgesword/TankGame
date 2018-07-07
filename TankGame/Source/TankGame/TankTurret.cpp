// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	float ElevationChange = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Yaw + ElevationChange;

	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
	//Turret->AddRelativeRotation(FRotator(0, ElevationChange, 0).Quaternion());
}


