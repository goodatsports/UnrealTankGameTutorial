// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

class UTankBarrel;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), Category = Setup)
class BATTLETANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float RotateSpeed);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotationPerSecond = 5;
	
};
