// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPostionComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPostionComponent::UWorldPostionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPostionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPostion = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjectName);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjectPostion);
	
}


// Called every frame
void UWorldPostionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

