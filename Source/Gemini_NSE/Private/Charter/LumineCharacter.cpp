//Copyright 2018-2022 Matrix-Studio
// 借物表：
// Model：miHoYo/Lumine
//Stage：Epic Games
//Motion：Epic Games
//Effect：Epic Games/UnrealEngine
//Tool：Apple/macOS/Epic Games/UnrealEngine/JetBrains/Rider


#include "Charter/LumineCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ALumineCharacter::ALumineCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this -> Construct();
	this -> CreateModel();
	this -> ThirdPerson();
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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
	PlayerInputComponent -> BindAxis("LookRight", this,&ALumineCharacter::AddControllerYawInput);
	PlayerInputComponent -> BindAxis("LookFWD", this,&ALumineCharacter::AddControllerPitchInput);

	
}
void ALumineCharacter::ThirdPerson()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	GetCharacterMovement() -> RotationRate =FRotator(0,540,0);
	SpringArmComponent -> SetupAttachment(RootComponent);
	SpringArmComponent -> SetRelativeLocation(FVector(0,0,100));
	SpringArmComponent -> SetRelativeRotation(FRotator(-15,0,0));
	SpringArmComponent -> bUsePawnControlRotation = true;
	CameraComponent -> SetupAttachment(SpringArmComponent);
	CameraComponent -> SetRelativeLocation(FVector::ZeroVector);
	CameraComponent -> bUsePawnControlRotation = false;
}

