// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

UCLASS()
class TANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Called when the game starts
	void BeginPlay() override;

	// Called every frame
	void Tick(float DeltaTime) override;

private:
	// Get the tank the player is possessing
	ATank* GetPlayerTank();

	// Get the tank this ai controller is possessing
	ATank* GetControlledTank();
};
