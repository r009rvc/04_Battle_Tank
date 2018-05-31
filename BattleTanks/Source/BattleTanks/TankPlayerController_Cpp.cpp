// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController_Cpp.h"


void ATankPlayerController_Cpp::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController_Cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}


ATank* ATankPlayerController_Cpp::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController_Cpp::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}

	FVector HitLocation; //Out Parameter
	
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace 
	{
	UE_LOG(LogTemp, Warning, TEXT("HitLoaction: %s"), *HitLocation.ToString());
// TODO Tell controlled tank to aim at this point 
	}

}
// Get world location of linetrace through crosshair, true if hits landscape 
bool ATankPlayerController_Cpp::GetSightRayHitLocation(FVector& HitLocation) const
{
HitLocation = FVector(1.0);

return true;
}