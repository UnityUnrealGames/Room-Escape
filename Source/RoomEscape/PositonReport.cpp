// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomEscape.h"
#include "PositonReport.h"


// Sets default values for this component's properties
UPositonReport::UPositonReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositonReport::BeginPlay()
{
	Super::BeginPlay();
	FString objectName = GetOwner()->GetName();
	auto location = GetOwner()->GetTransform().GetLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("Position report reporting for %s at %s"), *objectName, *location)
	// ...
	
}


// Called every frame
void UPositonReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

