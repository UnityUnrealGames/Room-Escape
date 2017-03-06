// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomEscape.h"
#include "OpenDoor.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();

	if(!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("Pressure plate not assigned in %s"), *Owner->GetName());
	}
	// ...
	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	if(!PressurePlate)
	{
		return -1;
	}

	// Find all the overlapping actors
	TArray<AActor*> OveralappingActors;
	PressurePlate->GetOverlappingActors(OUT OveralappingActors);

	for(auto& actor : OveralappingActors)
	{
		TotalMass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(GetTotalMassOfActorsOnPlate() >= PressurePlateTriggerMass)
	{
		OnOpen.Broadcast();
	} 
	else
	{
		OnClose.Broadcast();
	}

	// ...
}


