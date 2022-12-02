// Copyright 2018-2022 Matrix-Studio

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LumineCharacter.generated.h.h"
#include "Charter/LumineCharacter.h"
#include "CloneAnimInstance.generated.h"

/**
 * 
 */
/*我是人类冒险家的象征*/
/*上面的，你是凯瑟林吗*/
UCLASS(Transient,Blueprintable,BlueprintType)
class GEMINI_NSE_API UCloneAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UCloneAnimInstance();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	UPROPERTY(EditAnywhere,)
	ALumineCharacter* Main;
	
	
	
	
};
