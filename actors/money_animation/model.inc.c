// Money Animation

static const Vtx money_animation_seg4_vertex_1[] = {
    {{{   -32,      0,      0}, 0, {     0,    992}, {0xff, 0xff, 0x64, 0xff}}},
    {{{    32,      0,      0}, 0, {   992,    992}, {0xff, 0xff, 0x64, 0xff}}},
    {{{    32,     64,      0}, 0, {   992,      0}, {0xff, 0xff, 0x64, 0xff}}},
    {{{   -32,     64,      0}, 0, {     0,      0}, {0xff, 0xff, 0x64, 0xff}}},
};

// 0x04032A88
ALIGNED8 static const Texture money_animation_texture_1[] = {
#include "actors/money_animation/money_animation_1.rgba16.inc.c"
};

// 0x04033288
ALIGNED8 static const Texture money_animation_texture_2[] = {
#include "actors/money_animation/money_animation_2.rgba16.inc.c"
};

// 0x04033A88
ALIGNED8 static const Texture money_animation_texture_3[] = {
#include "actors/money_animation/money_animation_3.rgba16.inc.c"
};

// 0x04034288
ALIGNED8 static const Texture money_animation_texture_4[] = {
#include "actors/money_animation/money_animation_4.rgba16.inc.c"
};

// 0x04034A88
ALIGNED8 static const Texture money_animation_texture_5[] = {
#include "actors/money_animation/money_animation_5.rgba16.inc.c"
};

// 0x04035288
ALIGNED8 static const Texture money_animation_texture_6[] = {
#include "actors/money_animation/money_animation_6.rgba16.inc.c"
};

// 0x04035A88
ALIGNED8 static const Texture money_animation_texture_7[] = {
#include "actors/money_animation/money_animation_7.rgba16.inc.c"
};

// 0x04036288
ALIGNED8 static const Texture money_animation_texture_8[] = {
#include "actors/money_animation/money_animation_8.rgba16.inc.c"
};

// 0x04036A88
ALIGNED8 static const Texture money_animation_texture_9[] = {
#include "actors/money_animation/money_animation_9.rgba16.inc.c"
};

// 0x04037288
ALIGNED8 static const Texture money_animation_texture_10[] = {
#include "actors/money_animation/money_animation_10.rgba16.inc.c"
};

// 0x04037A88
ALIGNED8 static const Texture money_animation_texture_11[] = {
#include "actors/money_animation/money_animation_11.rgba16.inc.c"
};

// 0x04038288
ALIGNED8 static const Texture money_animation_texture_12[] = {
#include "actors/money_animation/money_animation_12.rgba16.inc.c"
};

// 0x04038A88
ALIGNED8 static const Texture money_animation_texture_13[] = {
#include "actors/money_animation/money_animation_13.rgba16.inc.c"
};

// 0x04039288
ALIGNED8 static const Texture money_animation_texture_14[] = {
#include "actors/money_animation/money_animation_14.rgba16.inc.c"
};

// 0x04039A88
ALIGNED8 static const Texture money_animation_texture_15[] = {
#include "actors/money_animation/money_animation_15.rgba16.inc.c"
};

// 0x0403A288
ALIGNED8 static const Texture money_animation_texture_16[] = {
#include "actors/money_animation/money_animation_16.rgba16.inc.c"
};

// 0x0403AA88
ALIGNED8 static const Texture money_animation_texture_17[] = {
#include "actors/money_animation/money_animation_17.rgba16.inc.c"
};

// 0x0403B288
ALIGNED8 static const Texture money_animation_texture_18[] = {
#include "actors/money_animation/money_animation_18.rgba16.inc.c"
};

const Gfx money_animation_seg4_dl[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(money_animation_seg4_vertex_1, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

const Gfx money_animation_seg4_dl_1[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_1),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_2[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_2),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_3[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_3),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_4[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_4),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_5),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_6[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_6),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_7[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_7),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_8[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_8),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_9[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_9),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_10[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_10),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_11[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_11),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_12[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_12),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_13[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_13),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_14[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_14),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_15[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_15),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_16[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_16),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_17[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_17),
    gsSPBranchList(money_animation_seg4_dl),
};

const Gfx money_animation_seg4_dl_18[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, money_animation_texture_18),
    gsSPBranchList(money_animation_seg4_dl),
};