// spawn_star.inc.c

static struct ObjectHitbox sCollectStarHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_collect_star_init(void) {
    u8 starId = GET_BPARAM1(o->oBehParams);
#ifdef GLOBAL_STAR_IDS
    u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(starId / 7));
    if (currentLevelStarFlags & (1 << (starId % 7))) {
#else
    u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
    if (currentLevelStarFlags & (1 << starId)) {
#endif
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TRANSPARENT_STAR];
    } else {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_STAR];
    }

    obj_set_hitbox(o, &sCollectStarHitbox);
}

void bhv_collect_star_loop(void) {
    o->oFaceAngleYaw += 0x800;

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
        o->oInteractStatus = INT_STATUS_NONE;
    }

    // Only normal, non-transparent stars should have special behavior
    u8 starId = GET_BPARAM1(o->oBehParams);
    #ifdef GLOBAL_STAR_IDS
        u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(starId / 7));
        bool isStarCollected = currentLevelStarFlags & (1 << (starId % 7));
    #else
        u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
        u8 isStarCollected = currentLevelStarFlags & (1 << starId);
    #endif

    if (!isStarCollected) {
    // Generate a random number between 0 and 99 (inclusive)
        s32 randomNumber = random_u16() % 1000;

        // 20% chance for the fairly common event (randomNumber < 20)
        if (randomNumber <= 150) {
            // Trigger the fairly common event
            // Example: play a sound or increase star's rotation speed slightly
            spawn_object(o, MODEL_NONE, bhvMoneySpawn);
        }

        // 1% chance for the rare event (randomNumber == 0)
        if (randomNumber == 0) {
            randomNumber = random_u16() % 6;
            switch (randomNumber) {
                case 0:
                    play_sound(SOUND_GENERAL_CUSTOM_WHO_WANTS_SOME_DOUGH, o->header.gfx.cameraToObject);
                    break;
                case 1:
                    play_sound(SOUND_GENERAL_CUSTOM_WHAT_ABOUT_ME, o->header.gfx.cameraToObject);
                    break;
                case 2:
                    play_sound(SOUND_GENERAL_CUSTOM_SOMEBODY_GET_ME, o->header.gfx.cameraToObject);
                    break;
                case 3:
                    play_sound(SOUND_GENERAL_CUSTOM_SOME_MONEY_OVER_HERE, o->header.gfx.cameraToObject);
                    break;
                case 4:
                    play_sound(SOUND_GENERAL_CUSTOM_GET_SOME_OF_THIS, o->header.gfx.cameraToObject);
                    break;
                case 5:
                    play_sound(SOUND_GENERAL_CUSTOM_EY_OVER_HERE, o->header.gfx.cameraToObject);
                    break;
            }
        }
    }

}

void bhv_star_spawn_init(void) {
    s16 yaw;
    vec3f_get_yaw(&o->oPosVec, &o->oHomeVec, &yaw);
    vec3f_get_lateral_dist(&o->oPosVec, &o->oHomeVec, &o->oStarSpawnDisFromHome)
    o->oMoveAngleYaw = yaw;
    o->oVelY = (o->oHomeY - o->oPosY) / 30.0f;
    o->oForwardVel = o->oStarSpawnDisFromHome / 30.0f;
    o->oStarSpawnVelY = o->oPosY;

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
    if (o->oBehParams2ndByte == SPAWN_STAR_ARC_CUTSCENE_BP_DEFAULT_STAR || gCurrCourseNum == COURSE_BBH) {
#else
    if (o->oBehParams2ndByte == SPAWN_STAR_ARC_CUTSCENE_BP_DEFAULT_STAR) {
#endif
        cutscene_object(CUTSCENE_STAR_SPAWN, o);
    } else {
        cutscene_object(CUTSCENE_RED_COIN_STAR_SPAWN, o);
    }

    set_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
    cur_obj_become_intangible();
}

void bhv_star_spawn_loop(void) {
    switch (o->oAction) {
        case SPAWN_STAR_ARC_CUTSCENE_ACT_START:
            o->oFaceAngleYaw += 0x1000;
            if (o->oTimer > 20) {
                o->oAction = SPAWN_STAR_ARC_CUTSCENE_ACT_GO_TO_HOME;
            }
            break;

        case SPAWN_STAR_ARC_CUTSCENE_ACT_GO_TO_HOME:
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oStarSpawnVelY += o->oVelY;
            o->oPosY = o->oStarSpawnVelY + sins((o->oTimer * 0x8000) / 30) * 400.0f;
            o->oFaceAngleYaw += 0x1000;
            spawn_object(o, MODEL_NONE, bhvMoneySpawn);
            cur_obj_play_sound_1(SOUND_ENV_STAR);
            if (o->oTimer == 29) {
                o->oAction = SPAWN_STAR_ARC_CUTSCENE_ACT_BOUNCE;
                o->oForwardVel = 0;
                // Set to exact home coordinates
                vec3f_copy(&o->oPosVec, &o->oHomeVec);
                play_power_star_jingle();
            }
            break;

        case SPAWN_STAR_ARC_CUTSCENE_ACT_BOUNCE:
            if (o->oTimer < 20) {
                o->oVelY = 20 - o->oTimer;
            } else {
                o->oVelY = -10.0f;
            }

            spawn_object(o, MODEL_NONE, bhvMoneySpawn);
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oFaceAngleYaw = o->oFaceAngleYaw - o->oTimer * 0x10 + 0x1000;
            cur_obj_play_sound_1(SOUND_ENV_STAR);

            if (o->oPosY < o->oHomeY) {
                cur_obj_play_sound_2(SOUND_GENERAL_STAR_APPEARS);
                cur_obj_become_tangible();
                o->oPosY = o->oHomeY;
                o->oAction = SPAWN_STAR_ARC_CUTSCENE_ACT_END;
            }
            break;

        case SPAWN_STAR_ARC_CUTSCENE_ACT_END:
            o->oFaceAngleYaw += 0x800;
            if (o->oTimer == 20) {
                gObjCutsceneDone = TRUE;
                clear_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                obj_mark_for_deletion(o);
                o->oInteractStatus = INT_STATUS_NONE;
            }

            // Only normal, non-transparent stars should have special behavior
            // This seems to work for only spawned red coins/secret stars
            u8 starId = GET_BPARAM1(o->oBehParams);
            #ifdef GLOBAL_STAR_IDS
                u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(starId / 7));
                bool isStarCollected = currentLevelStarFlags & (1 << (starId % 7));
            #else
                u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
                u8 isStarCollected = currentLevelStarFlags & (1 << starId);
            #endif

            if (!isStarCollected) {
            // Generate a random number between 0 and 99 (inclusive)
                s32 randomNumber = random_u16() % 1000;

                // 20% chance for the fairly common event (randomNumber < 20)
                if (randomNumber <= 150) {
                    // Trigger the fairly common event
                    // Example: play a sound or increase star's rotation speed slightly
                    spawn_object(o, MODEL_NONE, bhvMoneySpawn);
                }

                // 1% chance for the rare event (randomNumber == 0)
                if (randomNumber == 0) {
                    randomNumber = random_u16() % 6;
                    switch (randomNumber) {
                        case 0:
                            play_sound(SOUND_GENERAL_CUSTOM_WHO_WANTS_SOME_DOUGH, o->header.gfx.cameraToObject);
                            break;
                        case 1:
                            play_sound(SOUND_GENERAL_CUSTOM_WHAT_ABOUT_ME, o->header.gfx.cameraToObject);
                            break;
                        case 2:
                            play_sound(SOUND_GENERAL_CUSTOM_SOMEBODY_GET_ME, o->header.gfx.cameraToObject);
                            break;
                        case 3:
                            play_sound(SOUND_GENERAL_CUSTOM_SOME_MONEY_OVER_HERE, o->header.gfx.cameraToObject);
                            break;
                        case 4:
                            play_sound(SOUND_GENERAL_CUSTOM_GET_SOME_OF_THIS, o->header.gfx.cameraToObject);
                            break;
                        case 5:
                            play_sound(SOUND_GENERAL_CUSTOM_EY_OVER_HERE, o->header.gfx.cameraToObject);
                            break;
                    }
                }
            }
            break;
        }
}

struct Object *spawn_star(struct Object *starObj, f32 x, f32 y, f32 z) {
    // Should add something here to fix stuff like the Toad stars
    starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStarSpawnCoordinates, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
    starObj->oBehParams = o->oBehParams;
    vec3f_set(&starObj->oHomeVec, x, y, z);
    starObj->oFaceAnglePitch = 0;
    starObj->oFaceAngleRoll = 0;
    return starObj;
}

void spawn_default_star(f32 x, f32 y, f32 z) {
    struct Object *starObj = NULL;
    starObj = spawn_star(starObj, x, y, z);
    starObj->oBehParams2ndByte = SPAWN_STAR_ARC_CUTSCENE_BP_DEFAULT_STAR;
}

void spawn_red_coin_cutscene_star(f32 x, f32 y, f32 z) {
    struct Object *starObj = NULL;
    starObj = spawn_star(starObj, x, y, z);
    starObj->oBehParams2ndByte = SPAWN_STAR_ARC_CUTSCENE_BP_HIDDEN_STAR;
}

void spawn_no_exit_star(f32 x, f32 y, f32 z) {
    struct Object *starObj = NULL;
    starObj = spawn_star(starObj, x, y, z);
    starObj->oBehParams2ndByte = SPAWN_STAR_ARC_CUTSCENE_BP_HIDDEN_STAR;
    starObj->oInteractionSubtype |= INT_SUBTYPE_NO_EXIT;
}

void bhv_hidden_red_coin_star_init(void) {
    struct Object *starObj = NULL;

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
    if (gCurrCourseNum != COURSE_JRB) {
        spawn_object(o, MODEL_TRANSPARENT_STAR, bhvRedCoinStarMarker);
    }
#else
    spawn_object(o, MODEL_TRANSPARENT_STAR, bhvRedCoinStarMarker);
#endif

    // check if bparam2 specifies a total number of coins that should spawn the star
    if (o->oBehParams2ndByte != 0) {
        o->oHiddenStarTriggerTotal = o->oBehParams2ndByte;
        o->oHiddenStarTriggerCounter = gRedCoinsCollected;
        if (o->oHiddenStarTriggerCounter >= o->oHiddenStarTriggerTotal) {
            starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
            starObj->oBehParams = o->oBehParams;
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        }
    }
    else {
        s16 numRedCoinsRemaining = count_objects_with_behavior(bhvRedCoin);
        if (numRedCoinsRemaining == 0) {
            starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
            starObj->oBehParams = o->oBehParams;
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        }
        o->oHiddenStarTriggerTotal = numRedCoinsRemaining + gRedCoinsCollected;
        o->oHiddenStarTriggerCounter = o->oHiddenStarTriggerTotal - numRedCoinsRemaining;
    }
    
}

void bhv_hidden_red_coin_star_loop(void) {
    gRedCoinsCollected = o->oHiddenStarTriggerCounter;

    switch (o->oAction) {
        case HIDDEN_STAR_ACT_INACTIVE:
            if (o->oHiddenStarTriggerCounter == o->oHiddenStarTriggerTotal) {
                o->oAction = HIDDEN_STAR_ACT_ACTIVE;
            }
            break;

        case HIDDEN_STAR_ACT_ACTIVE:
            if (o->oTimer > 2) {
                spawn_red_coin_cutscene_star(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}
