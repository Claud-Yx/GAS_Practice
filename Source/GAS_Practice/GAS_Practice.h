// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN( LogSF, Log, All );

#define LOG_CALLINFO ANSI_TO_TCHAR(__FUNCTION__)
#define SF_LOG(Verbosity, Format, ...) UE_LOG(LogSF, Verbosity, TEXT("%s %s"), LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))


