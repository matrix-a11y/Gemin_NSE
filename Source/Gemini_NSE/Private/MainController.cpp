// Copyright 2018-2022 Matrix-Studio


#include "MainController.h"


AMainController::AMainController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	this -> Construct();
}
void AMainController::BeginPlay()
{
	Super::BeginPlay();
	Main = Cast<ALumineCharacter>(GetCharacter());
}
// Called every frame
void AMainController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent -> BindAxis("MoveForward_BackWard", this, &AMainController::MoveFoward_BackWard);
	InputComponent -> BindAxis("MoveLeft_Right",this,&AMainController::MoveLeft_Right);
//	InputComponent -> BindAction("Jump",IE_Pressed,this ,AMainController::Jump);
//	InputComponent -> BindAction("Jump",IE_Released,this,&AMainController::StopJump);
//	InputComponent -> BindAction("One",IE_Pressed,this,AMainController::PerssOne);
//	InputComponent -> BindAction("Mouse/TackPadLeft",IE_Pressed,this,&AMainController::MouseTackPadLeft);
//	InputComponent -> BindAction("Mouse/TackPadRight",IE_Pressed,this,&AMainController::MouseTackPadRight);
//	InputComponent -> BindAction("Mouse/TackPadUP",IE_Pressed,this,&AMainController::MouseTackPadUP);
//	InputComponent -> BindAction("Mouse/TackPadDown",IE_Pressed,this,&AMainController::MouseTackPadDown);
	
	
	
}
/*赤身裸体，可能会丢脸*/
void AMainController::Construct()
{
	InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent"));
}
void AMainController::MoveFoward_BackWard(float Value)
{
	FowardValue = Value;
	if (Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw,0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		Main -> AddMovementInput(Direction,Value);
	}
	if (FowardValue || RotaValue)
	{
		Main -> IsMove = true;
	}
	else
	{
		Main -> IsMove = false;
	}
}
void AMainController::MoveLeft_Right(float Value)
{
	RotaValue = Value;
	if (Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw,0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		Main -> AddMovementInput(Direction,Value);
	}
	if (FowardValue || RotaValue )
	{
		Main -> IsMove = true;
	}
	else
	{
		Main -> IsMove = false;
	}
		

}





