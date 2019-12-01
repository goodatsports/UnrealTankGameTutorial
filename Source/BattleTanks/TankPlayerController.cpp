// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayController not posessing Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PLAYER CONTROLLER controlling %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{	
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out param
	if (GetSightRayHitLocation(OutHitLocation))// Has side-effect, is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *OutHitLocation.ToString());
		// TODO Tell controlled tank to aim at this position
	}

}

// Get the world location of linetrace through crosshair, returns true if it intersects landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Get mouse cursor position
	// Project volume out from tank towards projected volume
	// If volume intersects with something else return true
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	OutHitLocation = FVector(1.0);
	return true;
}
