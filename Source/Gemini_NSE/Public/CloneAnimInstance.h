// Copyright 2018-2022 Matrix-Studio

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LumineCharacter.generated.h"


/**
 * 
 */
UCLASS(Transient,Blueprintable,BlueprintType)
class GEMINI_NSE_API UCloneAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UCloneAnimInstance();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ALumineCharacter* Main;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
};
