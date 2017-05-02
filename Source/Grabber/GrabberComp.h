// Copyright Alberto Burgos 2017. 

#pragma once

#include "Components/ActorComponent.h"
#include "GrabberComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRABBER_API UGrabberComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabberComp();
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    float LineTraceReach = 80.0f;

    UPhysicsHandleComponent* PhysicsHandle;

    UInputComponent* InputComponent;

    // Ray-cast and grab what it hits
    void Grab();
    void Release();

    // Find (assumed) attached physics handle component
    void FindPhysicsHandleComponent();

    //Setup (assumed) attached input component
    void SetupInputComponent();

    // Return hit for first physics body in reach
    FHitResult GetFirstPhysicsBodyInReach() const;
};
