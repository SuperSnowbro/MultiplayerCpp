// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
*
*/
UCLASS()
class MULTIPLAYERCPP_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

		AMovingPlatform();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector Destination = FVector(70,0,0);

	UPROPERTY(EditAnywhere)
		float Speed = 20;

private:
	float Distance = 0;
	int Sign = 1;
	float Counter = 0;

};