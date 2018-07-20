// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "Components/InputComponent.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add default components to the class
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Tell the aiming component to aim at a certain location in the world at a certain speed
void ATank::AimAt(FVector AimLocation)
{
	TankAimingComponent->AimAt(AimLocation, LaunchSpeed);
}

// Set the reference to the barrel in the aiming component
void ATank::SetReferences(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	TankAimingComponent->SetReferences(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
}

void ATank::Fire()
{
	if (!Barrel) { return; }

	// If ready to fire
	if (FPlatformTime::Seconds() - LastLaunchTime > ReloadTime)
	{
		// Spawn projectile at end of barrel socket location with a launch speed
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("EndOfBarrel")), Barrel->GetSocketRotation(FName("EndOfBarrel")));
		Projectile->Fire(LaunchSpeed);
		LastLaunchTime = FPlatformTime::Seconds();
	}	
}