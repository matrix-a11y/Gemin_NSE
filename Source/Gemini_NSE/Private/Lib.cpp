// Copyright 2018-2022 Matrix-Studio


#include "Lib.h"

void Lib::echo(float Value, bool IsGoLog)
{
	FString Message = FString::Printf(TEXT("%f"));
	if (IsGoLog)
	{
		UE_LOG(LogTemp,Warning,TEXT("%s"));
	}
	else
	{
		GEngine -> AddOnScreenDebugMessage(-1,1.f,FColor::Green,Message);
	}
		
}




void Lib::echo(FString Value, bool IsGoLog)
{
	FString Message = FString::Printf(TEXT("%f"));
	if (IsGoLog)
	{
		UE_LOG(LogTemp,Warning,TEXT("%s"));
	}
	else
	{
		GEngine -> AddOnScreenDebugMessage(-1,1.f,FColor::Green,Message);
	}
		
}



