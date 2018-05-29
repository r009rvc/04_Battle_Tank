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
	
		public:
			ATank* GetControlledTank() const;
	
		virtual	void BeginPlay() override;
};
