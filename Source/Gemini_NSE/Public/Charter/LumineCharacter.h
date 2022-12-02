//Copyright 2018-2022 Matrix-Studio

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "LumineCharacter.generated.h"

UCLASS()
class GEMINI_NSE_API ALumineCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALumineCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Live3D或MMD
	UPROPERTY(EditInstanceOnly,Category="Basic Config");
	USkeletalMesh* SkeletalMesh;
	//摇臂（用于装载镜头）
	UPROPERTY(EditInstanceOnly,Category="Basic Config");
	USpringArmComponent* SpringArmComponent;
	//镜头
	UPROPERTY(EditInstanceOnly,Category="Basic Config");
	UCameraComponent* CameraComponent;
	//是否移动
	UPROPERTY(EditInstanceOnly,Category="Basic Config");
	bool IsMove = false;

	
	void ThirdPerson();
private:
	void Construct();
	void CreateModel();
	
};
