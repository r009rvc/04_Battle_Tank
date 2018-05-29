// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController_Cpp.h"



ATank* ATankPlayerController_Cpp::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}