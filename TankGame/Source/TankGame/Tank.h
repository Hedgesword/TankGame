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
	// Speed of the launched projectile
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 100000;

	// Time before the player can shoot again
	UPROPERTY(EditDefaultsOnly)
	float ReloadTime = 3.0f;

	// The component added to the tank that controls aiming
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	// Tell the aiming component to aim at a certain location in the world at a certain speed
	void AimAt(FVector AimLocation);

	// Set the reference to the barrel in the aiming component
	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetReferences(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* MovementComponent = nullptr;

private:
	// Time at which the tank last fired
	float LastLaunchTime = 3.0f;
};