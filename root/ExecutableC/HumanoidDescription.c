#include "tecroot.h"
#include "tecrootmem.h"
#include "roblox.h"
#include "rbxinstance.h"
#include "rbxgame.h"
#include "rbxaux.h"

#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>

int LoadHumanoidDescriptionDefault(int PlayerId)
{
	int HumanoidDescription = RBX_InstanceNew("HumanoidDescription");
	RBX_Color3 *SkinColor = RBX_Color3New(0.24, 0.3, 0.3);
	RBX_SetColor3Property(HumanoidDescription, "LeftArmColor", SkinColor);
	RBX_SetColor3Property(HumanoidDescription, "RightArmColor", SkinColor);
	RBX_SetColor3Property(HumanoidDescription, "LeftLegColor", SkinColor);
	RBX_SetColor3Property(HumanoidDescription, "RightLegColor", SkinColor);
	RBX_SetColor3Property(HumanoidDescription, "TorsoColor", SkinColor);
	RBX_SetColor3Property(HumanoidDescription, "HeadColor", SkinColor);
	int Player = RBX_GetPlayerFromCharacter(PlayerId);
	if (Player == 0) {
		return 0x8F;
	}
	RBX_SetObjectProperty(HumanoidDescription, "Parent", Player);
	return 0;
}
int main(char **args, size_t argc)
{
	int status = RBXUtility_RegisterPlayerAddedEvent(LoadHumanoidDescriptionDefault);
	return status;
}
