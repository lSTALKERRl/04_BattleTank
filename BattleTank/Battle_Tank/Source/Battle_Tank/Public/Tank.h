// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "Tank.generated.h"

// Forward declarations
class AProjectile;
class UTankAimingComponent;
class UTankTurret;
class UTankBarrel;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

private:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.0; // TODO Find a sensible value

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf <AProjectile> ProjectileBlueprint;
	
	// Local barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr;
};
