// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this, 
		OutLaunchVelocity, 
		StartLocation, 
		HitLocation, 
		LaunchSpeed, 
		false, 
		0, 
		0, 
		ESuggestProjVelocityTraceOption::Type::DoNotTrace
	);

	auto Time = GetWorld()->GetTimeSeconds();

	if (bHaveAimSolution)
	{
		//Calculate the OutLaunchVelocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveTurret(AimDirection);
		MoveBarrel(AimDirection);

	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("TIME: %f No aiming solution found"), Time);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	// If Barrel Mesh Direction != Aim Direction
	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;
	// If Barrel Mesh Direction != Aim Direction

	// If Yaw switches signs and the rotation would go in opposite direction, flip sign before rotating
	if (FMath::Abs(DeltaRotator.Yaw) > 180.F)
	{
		DeltaRotator.Yaw = -1.F * DeltaRotator.Yaw;
	} 

	Turret->Rotate(DeltaRotator.Yaw);
}