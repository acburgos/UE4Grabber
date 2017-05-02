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
};
