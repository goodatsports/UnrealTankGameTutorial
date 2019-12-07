// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime) 
{

	Super::Tick(DeltaTime);
	if (GetPlayerTank()) 
	{
		// Aim at Player Tank if present
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI CONTROLLER found player: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}