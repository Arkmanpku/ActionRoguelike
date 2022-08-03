
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;

UCLASS()
class ACTIONROGUELIKE_API AExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	AExplosiveBarrel();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* RadialForceComp;

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	virtual void Tick(float DeltaTime) override;

};
