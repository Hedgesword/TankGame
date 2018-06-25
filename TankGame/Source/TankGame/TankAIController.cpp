// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	ATank* player = GetPlayerTank();
	if (player)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is to be exterminated!"), *player->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("WHERE THE FUCK IS THE PLAYER?!"));
	}
}

ATank* ATankAIController::GetPlayerTank()
{
	//APlayerController* player = GetWorld()->GetFirstPlayerController();
	//return (ATank*)player;
	return (ATank*)GetWorld()->GetFirstLocalPlayerFromController();
}