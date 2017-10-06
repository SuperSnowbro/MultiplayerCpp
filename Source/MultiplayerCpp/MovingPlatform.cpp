// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	Distance = Destination.Size();
	Destination = Destination.GetSafeNormal();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldOffset(Destination*DeltaTime*Speed*Sign);

	Counter += DeltaTime*Speed;

	if (Counter > Distance) {
		//UE_LOG(LogTemp, Warning, TEXT("SignChange!"));
		Sign = Sign*-1;
		Counter -= Distance;
		Counter = Counter*-1;
	}
}
