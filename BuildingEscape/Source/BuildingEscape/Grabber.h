
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		float Reach = 200.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputHandle = nullptr;
	
	//Ray-cast and grab whats in reach
	void Grab();

	//Once key is releaced
	void Release();

	//Checks to see if player has a physics handle
	void FindPhysicsHandleComponent();

	//setup (assumed) input component
	void SetupInputComponent();

	//return hit for a physics body in reach
	FHitResult GetFirstPhysicsBodyInReach();

	//gets the start of the player's viewpoint
	FVector GetReachLineStart();
	
	//returns current end of reach line
	FVector GetReachLineEnd();
};


