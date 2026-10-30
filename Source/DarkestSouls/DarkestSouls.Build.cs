using UnrealBuildTool;

public class DarkestSouls : ModuleRules
{
    public DarkestSouls(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore"
        });
    }
}
