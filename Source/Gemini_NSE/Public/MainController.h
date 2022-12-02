// Copyright 2018-2022 Matrix-Studio

#pragma once

#include "CoreMinimal.h"
#include "Charter/LumineCharacter.h"
#include "GameFramework/PlayerController.h"
#include "MainController.generated.h"


UCLASS()
class GEMINI_NSE_API AMainController : public APlayerController
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AMainController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	UPROPERTY(EditInstanceOnly,Category="Basic Config");
	ALumineCharacter* Main;


	float FowardValue;
	UPROPERTY(EditInstanceOnly,Category="Basic Config");
	float RotaValue;

private:
	void Construct();
	void MoveFoward_BackWard(float Value);
	void MoveLeft_Right(float Value);
	void Jump();
	void StopJump();
	void PerssOne();
	void MouseTackPadLeft();
	void MouseTackPadRight();
	void MouseTackPadUP();
	void MouseTackPadDown();


	
	
	
};
