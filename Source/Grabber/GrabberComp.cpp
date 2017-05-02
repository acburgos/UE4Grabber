// Copyright Alberto Burgos 2017. 

#include "Grabber.h"
#include "GrabberComp.h"

#define OUT

UGrabberComp::UGrabberComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
    bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

    PhysicsHandle = nullptr;
    InputComponent = nullptr;
}

void UGrabberComp::BeginPlay()
{
	Super::BeginPlay();
    FindPhysicsHandleComponent();
    SetupInputComponent();
}

void UGrabberComp::FindPhysicsHandleComponent()
{
        // Look for attached  Physics Handle
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (PhysicsHandle != nullptr)
    {

    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Physics Handle component missing in the Owner Actor"));
    }
}

void UGrabberComp::SetupInputComponent()
{
    InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    if (InputComponent != nullptr)
    {
        // Bind the input axis
        InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabberComp::Grab);
        InputComponent->BindAction("Grab", IE_Released, this, &UGrabberComp::Release);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Input Component missing in the Owner Actor"));
    }
}

void UGrabberComp::Grab()
{
    UE_LOG(LogTemp, Warning, TEXT("Grab Pressed"));
    
    //Line Trace
    GetFirstPhysicsBodyInReach();

    // Try and reach any actor with physics body collision channel set

    // If we hit something then attach a physics handle

    // TODO attach physics handle
}

void UGrabberComp::Release()
{
    UE_LOG(LogTemp, Warning, TEXT("Grab Released"));
    //TODO release physics handle
}

void UGrabberComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // if the physics handle is attached
        //move the object that we're holding

}

FHitResult UGrabberComp::GetFirstPhysicsBodyInReach() const
{
    // Get player viewpoint this tick
    FVector local_actor_location;
    FRotator local_actor_rotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT local_actor_location, OUT local_actor_rotation);

    // Debug Line Trace (Just visualizing)
    FVector LineTraceEnd = local_actor_location + local_actor_rotation.Vector() * LineTraceReach;

    //DrawDebugLine(
    //    GetWorld(),
    //    local_actor_location,
    //    LineTraceEnd,
    //    FColor(255.0f, 0, 0),
    //    false,
    //    0.f,
    //    0.f,
    //    2.0f
    //);

    // Ray-cast
    FCollisionQueryParams local_params = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());

    FHitResult hit;
    bool hitted = GetWorld()->LineTraceSingleByObjectType(
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
    return hit;
}

