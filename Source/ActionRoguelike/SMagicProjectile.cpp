
#include "SMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASMagicProjectile::ASMagicProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;


	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(RootComponent);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
}

void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	SphereComp->OnComponentHit.AddDynamic(this, &ASMagicProjectile::OnHit);
}

void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASMagicProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FString ActorName = OtherActor->GetName();
	FString CompName = OtherComp->GetName();

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, ActorName);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, CompName);

	Destroy();
}