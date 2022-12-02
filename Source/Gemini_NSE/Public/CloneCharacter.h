// Copyright 2018-2022 Matrix-Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CloneCharacter.generated.h"

UCLASS()
class GEMINI_NSE_API ACloneCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACloneCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
