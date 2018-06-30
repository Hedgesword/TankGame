// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Aim at a certain location in the world at a certain speed
	void AimAt(FVector AimLocation, float LaunchSpeed);

	// Sets a reference to the barrel of the tank
	void SetBarrelReference(UTankBarrel* BarrelToSet);
private:
	// Reference to the tank barrel
	UTankBarrel* Barrel = nullptr;

	// Rotate the barrel in the direction it is aiming
	void MoveBarrelTowards(FVector AimDirection);
};
