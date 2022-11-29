//Copyright 2018-2022 Matrix-Studio
// 借物表：
// Model：miHoYo/Lumine
//Stage：Epic Games
//Motion：Epic Games
//Effect：Epic Games/UnrealEngine
//Tool：Apple/macOS/Epic Games/UnrealEngine/JetBrains/Rider


#include "Charter/LumineCharacter.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ALumineCharacter::ALumineCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this -> Construct();
	this -> CreateModel();

}
void ALumineCharacter::Construct()
{
	SkeletalMesh = LoadObject<USkeletalMesh>(NULL,TEXT("SkeletalMesh'/Game/Charters/Lumine/Lumine.Lumine'"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}
void ALumineCharacter::CreateModel()
{
	GetMesh() -> SetSkeletalMesh(SkeletalMesh);
	GetMesh() -> SetRelativeLocation(FVector(0,0,-100));
	GetMesh() -> SetRelativeRotation(FRotator(0,-90,0));
	GetCapsuleComponent() -> InitCapsuleSize(42,100);
}



// Called when the game starts or when spawned
void ALumineCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALumineCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALumineCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent -> BindAxis("LookRight", &ALumineCharacter::)

}

