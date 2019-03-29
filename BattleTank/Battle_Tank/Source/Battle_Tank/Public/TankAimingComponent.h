// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declarations
class AProjectile;
class UTankTurret;
class UTankBarrel;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Ready
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf <AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0;		// TODO Find a sensible value

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

protected:
	UPROPERTY(BlueprintReadOnly)
	EFiringState FiringState = EFiringState::Reloading;

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation);

	void MoveBarrelTowards(FVector AimDirection);

	UFUNCTION(BlueprintCallable)
	void Fire();
};
