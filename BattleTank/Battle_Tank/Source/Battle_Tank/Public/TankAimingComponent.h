// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Ready
};

 // Forward Declaration
class UTankTurret;
class UTankBarrel;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

protected:
	UPROPERTY(BlueprintReadOnly)
	EFiringState FiringState = EFiringState::Ready;

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void MoveBarrelTowards(FVector AimDirection);
};
