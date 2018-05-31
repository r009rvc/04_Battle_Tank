// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_Cpp.generated.h"// Must

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController_Cpp : public APlayerController
{
	GENERATED_BODY()
	
		private:
			ATank* GetControlledTank() const;
	
		virtual	void BeginPlay() override;// Should stay Pubic: But we don't Derive From them here, so it doesn't matter.

		virtual	void Tick(float DeltaTime) override;// Should stay Pubic: But we don't Derive From them here, so it doesn't matter.
		
		//Start the tank moving the barrel so that a shot would hit where
		//the crosshair intersects the world
		void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape 
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;


};

