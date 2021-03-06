// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
	float MaxTrackForce = 400000.0f;

	UFUNCTION(BlueprintCallable)
	void SetThrottle(float Throttle);
	
	
};
