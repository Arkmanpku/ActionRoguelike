
#include "ExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

AExplosiveBarrel::AExplosiveBarrel()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");
	RadialForceComp->Radius = 2000.f;
	RadialForceComp->ImpulseStrength = 5000.f;
	RadialForceComp->bImpulseVelChange = true;
	RadialForceComp->SetupAttachment(RootComponent);
}

void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	MeshComp->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnHit);
}

void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExplosiveBarrel::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FString Name = OtherComp->GetName();
	FString ProjectileName = "SphereComp";
	if (Name.Equals(ProjectileName))
	{
		RadialForceComp->FireImpulse();
		Destroy();
	}

}

