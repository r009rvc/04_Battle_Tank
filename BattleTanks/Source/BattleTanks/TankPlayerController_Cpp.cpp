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
	// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
// TODO Tell controlled tank to aim at this point 
	}

}
// Get world location of linetrace through crosshair, true if hits landscape 
bool ATankPlayerController_Cpp::GetSightRayHitLocation(FVector& HitLocation) const
{
HitLocation = FVector(1.0);

// Find the crosshair position in pixel coordinates 
int32 ViewportSizeX, ViewportSizeY;
GetViewportSize(ViewportSizeX, ViewportSizeY);
auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	// "De-project" the screen position of the crosshair to a world direction 
	// Line-trace along that look direction, and see what we hit (up to max range) 
return true;
}