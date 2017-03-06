// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenDoor();
	void CloseDoor();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool IsDoorOpen = false;
	float LastDoorOpenTime;

	AActor* Owner = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(VisibleAnywhere)
		float OpenAngle = -70.0f;
	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;
	UPROPERTY(VisibleAnywhere)
		float PressurePlateTriggerMass = 50.f;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();

};
