// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Tell the aiming component to aim at a certain location in the world at a certain speed
	void AimAt(FVector AimLocation);

	// Spawn a projectile at the end of the barrel if ready
	UFUNCTION(BlueprintCallable)
	void Fire();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;	

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* MovementComponent = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	// Set the reference to the barrel in the aiming component
	UFUNCTION(BlueprintCallable)
	void SetReferences(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

private:
	UTankBarrel * Barrel = nullptr;

	// Time at which the tank last fired
	float LastLaunchTime = 3.0f;	

	// Speed of the launched projectile
	UPROPERTY(EditDefaultsOnly)
	float LaunchSpeed = 100000;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Time before the tank is allowed to shoot another projectile
	UPROPERTY(EditDefaultsOnly)
	float ReloadTime = 3.0f;	

	// The component added to the tank that controls aiming
	UTankAimingComponent* TankAimingComponent = nullptr;
};