// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "PositionReport.h"
#include "GrabberGameModeBase.h"



// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

#ifdef E0_LOG_CHECK

    FString local_actor_name = GetOwner()->GetName();
    FString local_actor_position = "X= " + FString::SanitizeFloat(GetOwner()->GetActorLocation().X)+ ", " + 
        "Y: " + FString::SanitizeFloat(GetOwner()->GetActorLocation().Y) + ", " + 
        "Z: " + FString::SanitizeFloat(GetOwner()->GetActorLocation().Z);
    UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *local_actor_name, *local_actor_position);

#endif
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

