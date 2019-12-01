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
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
		// TODO Tell controlled tank to aim at this position
	}

}

// Get the world location of linetrace through crosshair, returns true if it intersects landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair posistion
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairX, ViewportSizeY * CrosshairY);

	// De-project the screen position of the crosshair to a world direction
	// Line trace along look direction and see what intersects (up to a max range)

	return true;
}
