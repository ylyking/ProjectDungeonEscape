// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "DungeonEscapeCharacter.generated.h"

UCLASS(Blueprintable)
class ADungeonEscapeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADungeonEscapeCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/**Movement Vectors*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector moveUpDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector moveLeftRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FFloat16 defaultMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FFloat16 dodgeMoveSpeed;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	/** Setup Input */
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	/** Move Player up/down */
	void MoveUpDown(float value);

	/** Move Player Left/Right */
	void MoveLeftRight(float value);

	/** Make Player dodge */
	void Dodge();
};

