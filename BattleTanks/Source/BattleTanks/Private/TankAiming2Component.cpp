// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAiming2Component.h"


// Sets default values for this component's properties
UTankAiming2Component::UTankAiming2Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAiming2Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAiming2Component::SetBarrelReference(UStaticMeshComponent* BarrelToSeT)
{
	Barrel = BarrelToSeT;

}

// Called every frame
void UTankAiming2Component::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAiming2Component::AimAt(FVector HitLocation, float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Firing at %f"), LaunchSpeed);
}