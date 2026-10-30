using UnrealBuildTool;

public class DarkestSoulsTarget : TargetRules
{
    public DarkestSoulsTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        ExtraModuleNames.Add("DarkestSouls");
    }
}
