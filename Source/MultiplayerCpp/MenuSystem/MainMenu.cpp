// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Components/Button.h"
bool UMainMenu::Initialize()
{
	if (!Super::Initialize()) return false;

	HostButton->OnClicked.AddDynamic(this, &UMainMenu::Test);

	return true;
}

void UMainMenu::Test()
{
	UWorld* World = GetWorld();

	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCpp/Maps/ThirdPersonExampleMap?listen");
}
