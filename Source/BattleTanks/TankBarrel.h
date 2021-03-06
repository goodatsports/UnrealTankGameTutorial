// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), Category = Setup)
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 5;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 30;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDegrees = 0;
};
