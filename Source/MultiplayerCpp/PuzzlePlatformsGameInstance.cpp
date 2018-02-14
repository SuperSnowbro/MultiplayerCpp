// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"

#include "Engine/Engine.h"
#include "MultiplayerCppCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> FoundMenuWidgetClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));

	if (!ensure(FoundMenuWidgetClass.Class != nullptr)) return;

	MenuWidgetClass = FoundMenuWidgetClass.Class;

	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuWidgetClass->GetName());
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();

	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCpp/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::CreateMainMenuUI()
{

	UUserWidget* MyMainMenu = CreateWidget<UUserWidget>(this, *MenuWidgetClass);

	if (!ensure(MyMainMenu != nullptr)) return;

	MyMainMenu->AddToViewport();

	APlayerController* Controller = GetFirstLocalPlayerController();

	if (!ensure(Controller != nullptr)) return;

	FInputModeUIOnly MyInputMode;

	MyInputMode.SetWidgetToFocus(MyMainMenu->TakeWidget());

	Controller->SetInputMode(MyInputMode);

	Controller->bShowMouseCursor = true;
}

void UPuzzlePlatformsGameInstance::Join(const FString & Address)
{
	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address)); //%s means that you are going to append something to the string (comma stuff), the star before Address means that you are getting the value of the reference 

	APlayerController* Controller = GetFirstLocalPlayerController();

	if (!ensure(Controller != nullptr)) return;

	Controller->ClientTravel(*Address, ETravelType::TRAVEL_Absolute);

}
