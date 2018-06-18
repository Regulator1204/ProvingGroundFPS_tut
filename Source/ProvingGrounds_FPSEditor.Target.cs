// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProvingGrounds_FPSEditorTarget : TargetRules
{
	public ProvingGrounds_FPSEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("ProvingGrounds_FPS");
	}
}
