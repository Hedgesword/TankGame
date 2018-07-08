// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Speed of the launched projectile
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;

	// The component added to the tank that controls aiming
	UTankAimingComponent* TankAimingComponent = nullptr;

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
};