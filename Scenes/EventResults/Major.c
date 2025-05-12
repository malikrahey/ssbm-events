#ifndef EVENT_MAJOR_C
#define EVENT_MAJOR_C

#include "Major.h"

static  MinorScene __attribute__((__used__)) minor_scene[] = {
    {
        .minor_id = MINOR_CSS,
        .heap_kind = SCENEHEAPKIND_UNK3,
        .minor_prep = (void*)0x801BAA60,
        .minor_decide = (void*)0x801BAAD0,
        .minor_kind = KIND_CSS,
        .load_data = (void*)0x80497758,
        .unload_data = (void*)0x80497758,
    },
    {
        .minor_id = MINOR_VS,
        .heap_kind = SCENEHEAPKIND_UNK3,
        .minor_prep = (void*)0x801BAD70,
        .minor_decide = VsDecide,
        .minor_kind = KIND_VS,
        .load_data = (void*)0x804978A0,
        .unload_data = (void*)0x804979D8,
    },
    {
        .minor_id = MINOR_RST,
        .heap_kind = SCENEHEAPKIND_UNK3,
        // .minor_prep = (void*)0x801B16A8,
        .minor_prep = ResultsPrep,
        .minor_decide = (void*)0x801B16C8,
        .minor_kind = KIND_RST,
        .load_data = (void*)0x8047C020,
        .unload_data = 0,
        },
    {
        .minor_id = 255,
        .heap_kind = 0,
        .minor_prep = 0,
        .minor_decide = 0,
        .minor_kind = 0,
        .load_data = 0,
        .unload_data = 0,
        },
};


void major_load(){
    Event_MajorLoad();
    return;
}

void major_exit(){
    // original just returns
    return;
}

void ResultsPrep(MinorScene *scene){
    OSReport("ScenePrep\n");
    ScDataVictory *rst_data = Scene_GetEnterData(scene);
    Event_ZeroSceneMem(rst_data);
    ScDataVictory *rst_data2 = (void*)0x804979dc;

    rst_data2->match_standings.is_teams = 0;
    rst_data2->match_standings.team_winner_num = 0;
    rst_data2->match_standings.winner_num = 2;
    rst_data2->match_standings.ply_standings[0].placement = 1;
    rst_data2->match_standings.ply_standings[1].placement = 0;
    rst_data2->match_standings.end_kind = 0;
    rst_data->x0 = rst_data2->x0;
    rst_data->x4 = rst_data2->x4;
    rst_data->match_standings = rst_data2->match_standings;

    return;
}

void VsDecide(MinorScene *scene){
    OSReport("SceneDecide\n");

    ScDataRst *rst_data = Scene_GetExitData(scene);
    if (rst_data->match_standings.end_kind == 0x7){
        rst_data->match_standings.end_kind = 9;
    }
    
    Event_VsDecide(scene);

    // lets manually set scene info as Event_VsDecide will cause a scene change
    stc_scene_info->major_curr = 0x2B;
    stc_scene_info->major_next = 0x2B;
    // stc_scene_info->major_prev = 1;
    *stc_pending_major_change = 0;


    Scene_SetNextMinor(MINOR_RST);
    return;
}

#endif
