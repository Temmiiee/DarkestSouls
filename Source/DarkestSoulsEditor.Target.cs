using UnrealBuildTool;

public class DarkestSoulsEditorTarget : TargetRules
{
    public DarkestSoulsEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        ExtraModuleNames.Add("DarkestSouls");
    }
}
