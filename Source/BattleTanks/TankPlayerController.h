// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		float CrosshairX = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairY = 0.33333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 10000000;

	ATank* GetControlledTank() const;

	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Move tank barrel towards crosshair
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
