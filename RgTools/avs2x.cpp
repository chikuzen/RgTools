#include "removegrain.h"
#include "clense.h"
#include "repair.h"
#include "vertical_cleaner.h"



const AVS_Linkage *AVS_linkage = nullptr;

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit3(IScriptEnvironment* env, const AVS_Linkage* const vectors) {
    AVS_linkage = vectors;

    env->AddFunction("RemoveGrain", "c[mode]i[modeU]i[modeV]i[planar]b", Create_RemoveGrain, 0);
    env->AddFunction("Repair", "cc[mode]i[modeU]i[modeV]i[planar]b", Create_Repair, 0);
    env->AddFunction("Clense", "c[previous]c[next]c[grey]b", Create_Clense, 0);
    env->AddFunction("ForwardClense", "c[grey]b", Create_ForwardClense, 0);
    env->AddFunction("BackwardClense", "c[grey]b", Create_BackwardClense, 0);
    env->AddFunction("VerticalCleaner", "c[mode]i[modeU]i[modeV]i[planar]b", Create_VerticalCleaner, 0);
    return "Itai, onii-chan!";
}
