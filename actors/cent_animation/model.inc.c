// Cent Animation

// 0x04030000
static const Vtx cent_animation_seg4_vertex[] = {
    {{{   -32,      0,      0}, 0, {     0,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,      0,      0}, 0, {  1984,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,     64,      0}, 0, {  1984,      0}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{   -32,     64,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0x00}}},
};

// 0x04030040
ALIGNED8 static const Texture cent_animation_seg4_texture_1[] = {
#include "actors/cent_animation/cent_animation_1.rgba16.inc.c"
};

// 0x04030840
ALIGNED8 static const Texture cent_animation_seg4_texture_2[] = {
#include "actors/cent_animation/cent_animation_2.rgba16.inc.c"
};

// 0x04031040
ALIGNED8 static const Texture cent_animation_seg4_texture_3[] = {
#include "actors/cent_animation/cent_animation_3.rgba16.inc.c"
};

// 0x04031840
ALIGNED8 static const Texture cent_animation_seg4_texture_4[] = {
#include "actors/cent_animation/cent_animation_4.rgba16.inc.c"
};

// 0x04032040
ALIGNED8 static const Texture cent_animation_seg4_texture_5[] = {
#include "actors/cent_animation/cent_animation_5.rgba16.inc.c"
};

// 0x04032840
ALIGNED8 static const Texture cent_animation_seg4_texture_6[] = {
#include "actors/cent_animation/cent_animation_6.rgba16.inc.c"
};

// 0x04033040
ALIGNED8 static const Texture cent_animation_seg4_texture_7[] = {
#include "actors/cent_animation/cent_animation_7.rgba16.inc.c"
};

// 0x04035000 - 0x04035068
const Gfx cent_animation_seg4_dl[] = {
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(cent_animation_seg4_vertex, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

// 0x04035068 - 0x04035080
const Gfx cent_animation_seg4_dl_1[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_1),
    gsSPBranchList(cent_animation_seg4_dl),
};

// 0x04035080 - 0x04035098
const Gfx cent_animation_seg4_dl_2[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_2),
    gsSPBranchList(cent_animation_seg4_dl),
};

// 0x04035098 - 0x040350B0
const Gfx cent_animation_seg4_dl_3[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_3),
    gsSPBranchList(cent_animation_seg4_dl),
};

// 0x040350B0 - 0x040350C8
const Gfx cent_animation_seg4_dl_4[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_4),
    gsSPBranchList(cent_animation_seg4_dl),
};

// 0x040350C8 - 0x040350E0
const Gfx cent_animation_seg4_dl_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_5),
    gsSPBranchList(cent_animation_seg4_dl),
};

// 0x040350E0 - 0x040350F8
const Gfx cent_animation_seg4_dl_6[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_6),
    gsSPBranchList(cent_animation_seg4_dl),
};

// 0x040350F8 - 0x04035110
const Gfx cent_animation_seg4_dl_7[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cent_animation_seg4_texture_7),
    gsSPBranchList(cent_animation_seg4_dl),
};
