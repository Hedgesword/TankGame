// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Player = GetPlayerTank();
	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is to be exterminated!"), *Player->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("WHERE THE FUCK IS THE PLAYER?!"));
	}
}

ATank* ATankAIController::GetPlayerTank()
{
	return (ATank*)GetWorld()->GetFirstLocalPlayerFromController();
}