// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "TankAimingComponent.generated.h"

 // Forward Declaration
class UTankBarrel;

// Holds 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	

	UTankBarrel * Barrel = nullptr;

protected:

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void MoveBarrelTowards(FVector AimDirection);

};
