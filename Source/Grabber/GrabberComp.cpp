// Copyright Alberto Burgos 2017. 

#include "Grabber.h"
#include "GrabberComp.h"


// Sets default values for this component's properties
UGrabberComp::UGrabberComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
    bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberComp::BeginPlay()
{
	Super::BeginPlay();

#define OUT
}


// Called every frame
void UGrabberComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player viewpoint this tick
    FVector local_actor_location;
    FRotator local_actor_rotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint( OUT local_actor_location, OUT local_actor_rotation);

    //UE_LOG(LogTemp, Warning, TEXT("Location: %s and Rotation: %s"), 
    //       *local_actor_location.ToString(), 
    //       *local_actor_rotation.ToString()
    //);

    // Debug Line Trace (Just visualizing)
    FVector LineTraceEnd = local_actor_location + local_actor_rotation.Vector() * LineTraceReach;

    DrawDebugLine(
        GetWorld(),
        local_actor_location,
        LineTraceEnd,
        FColor(255.0f, 0 ,0),
        false,
        0.f,
        0.f,
        2.0f
        );

    // Ray-cast

    FCollisionQueryParams local_params = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());

    FHitResult hit;
    GetWorld()->LineTraceSingleByObjectType(
        OUT hit, 
        local_actor_location, 
        LineTraceEnd, 
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), 
        local_params
    );

    //See what we hit

    AActor* ActorHit = hit.GetActor();
    if (ActorHit != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()));
    }
}

