
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SGameplayInterface.generated.h"

UINTERFACE(MinimalAPI)
class USGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONROGUELIKE_API ISGameplayInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);

};
