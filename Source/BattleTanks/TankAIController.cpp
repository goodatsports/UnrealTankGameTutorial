// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	if (PlayerTank) 
	{
		// Aim at Player Tank if present
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI CONTROLLER found player: %s"), *(PlayerTank->GetName()));
	}
}
