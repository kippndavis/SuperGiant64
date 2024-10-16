// 0x16000F6C
const GeoLayout transparent_star_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         //GEO_DISPLAY_LIST(LAYER_TRANSPARENT, transparent_star_seg3_dl_body),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, PowerPaycheckTaken_SketchUp_mesh),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

const GeoLayout opaque_star_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         //GEO_DISPLAY_LIST(LAYER_TRANSPARENT, transparent_star_seg3_dl_body),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, PowerPaycheckTaken_SketchUp_mesh),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
