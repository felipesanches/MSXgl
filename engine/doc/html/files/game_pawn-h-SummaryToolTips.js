﻿NDSummary.OnToolTipsLoaded("File:game_pawn.h",{699:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype699\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> GamePawn_Initialize(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"first\"></td><td class=\"PType\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">Game_Sprite*&nbsp;</td><td class=\"PName last\">sprtList,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">sprtNum,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">sprtID,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">Game_Action*&nbsp;</td><td class=\"PName last\">actList</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Initialize a game pawn.</div></div>",248:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype248\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> GamePawn_SetPosition(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">x,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">y</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set game pawn position. Force movement even if collision is activated.</div></div>",249:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype249\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> GamePawn_SetAction(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">id</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set game pawn current action index.</div></div>",250:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype250\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> GamePawn_Update(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Update animation of the game pawn. Must be called once a frame.</div></div>",251:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype251\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> GamePawn_Draw(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Update rendering of the game pawn. Must be called once a frame.</div></div>",252:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype252\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> GamePawn_SetMovement(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn,</td></tr><tr><td class=\"PType first\">i8&nbsp;</td><td class=\"PName last\">dx,</td></tr><tr><td class=\"PType first\">i8&nbsp;</td><td class=\"PName last\">dy</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set pawn relative movement. Collision can prevent part of the movement.&nbsp; Only available if GAMEPAWN_USE_PHYSICS compile option is set to TRUE.</div></div>",579:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype579\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline void</span> GamePawn_SetTargetPosition(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">x,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">y</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set pawn absolute movement. Collision can prevent part of the movement.&nbsp; Only available if GAMEPAWN_USE_PHYSICS compile option is set to TRUE.</div></div>",587:"<div class=\"NDToolTip TFunction LC\"><div class=\"TTSummary\">Set pawn physics callback Only available if GAMEPAWN_USE_PHYSICS compile option is set to TRUE.</div></div>",590:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype590\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 GamePawn_GetPhysicsState(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Game_Pawn*&nbsp;</td><td class=\"PName last\">pawn</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get pawn physics state.&nbsp; Only available if GAMEPAWN_USE_PHYSICS compile option is set to TRUE.</div></div>"});