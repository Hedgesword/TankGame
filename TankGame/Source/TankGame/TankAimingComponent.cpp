// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Tank.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
{
	// Protect pointer
	if (!Barrel) { return; }

	// Get the angle at which to aim the projectile
	FVector OutTossVelocity = FVector(57.0f);
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutTossVelocity, Barrel->GetSocketLocation(FName("EndOfBarrel")), AimLocation, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		// Normalize the vector
		//UE_LOG(LogTemp, Warning, TEXT("Solution found: %s"), *OutTossVelocity.ToString());
		OutTossVelocity = OutTossVelocity.GetSafeNormal();
		MoveBarrelTowards(OutTossVelocity);
		
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("No solution found"));
	}
}

void UTankAimingComponent::SetReferences(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;	

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->RotateTurret(DeltaRotator.Yaw);
}