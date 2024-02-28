// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ActionRPGTarget : TargetRules
{
	public ActionRPGTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.AddRange(new string[] { "ActionRPG" });

		DefaultBuildSettings = BuildSettingsVersion.V2;
	}
}
