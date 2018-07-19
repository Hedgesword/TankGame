// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	FVector ForceVector = GetForwardVector() * MaxTrackForce * Throttle;
	UPrimitiveComponent* TankRoot = (UPrimitiveComponent*)GetOwner()->GetRootComponent();
	TankRoot->AddForceAtLocation(ForceVector, GetComponentLocation());
	
}