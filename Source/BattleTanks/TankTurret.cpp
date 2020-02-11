// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "TankBarrel.h"

// Rotate Turret Mesh Component some amount towards Aim Direction
void UTankTurret::Rotate(float RelativeSpeed)
{
	auto RotationChange = RelativeSpeed * MaxRotationPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

void UTankTurret::SetBarrelReference(UTankBarrel* BarrelToSet)
{

}