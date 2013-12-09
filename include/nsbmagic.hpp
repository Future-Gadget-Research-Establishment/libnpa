#ifndef NSB_MAGIC_HPP
#define NSB_MAGIC_HPP

#define SWAP_UINT16(x) ((uint16_t)(((x) >> 8) | ((x) << 8)))

// TODO: Sort by value
enum /* Magic */ : uint16_t
{
    MAGIC_FWN_UNK = 0, // Fuwanovel eof extension?

    MAGIC_PARSE_TEXT = SWAP_UINT16(0xD800),
    MAGIC_SET_PARAM = SWAP_UINT16(0xD000), // STRING/INT/FLOAT
    MAGIC_CHAPTER_BEGIN = SWAP_UINT16(0x9400),
    MAGIC_IF = SWAP_UINT16(0x9800), // if() statement?
    MAGIC_ENDIF = SWAP_UINT16(0xCF00), // label definition?
    MAGIC_CALL = SWAP_UINT16(0xCE00),
    MAGIC_UNK1 = SWAP_UINT16(0xC600), // Logical condition
    MAGIC_UNK2 = SWAP_UINT16(0xC700), // Logical condition
    MAGIC_UNK3 = SWAP_UINT16(0xC800), // label epilogue/where .map file maps labels
    MAGIC_UNK4 = SWAP_UINT16(0xC900), //
    MAGIC_UNK5 = SWAP_UINT16(0x6800), // Get current script name?
    MAGIC_CLEAR_PARAMS = SWAP_UINT16(0x8E00),
    MAGIC_UNK7 = SWAP_UINT16(0x5B00), // return control to game/start scene
    MAGIC_LOGICAL_NOT_EQUAL = SWAP_UINT16(0xC100),
    MAGIC_CONCAT = SWAP_UINT16(0xA500),
    MAGIC_SET = SWAP_UINT16(0xB000),
    MAGIC_GET = SWAP_UINT16(0xD100),
    MAGIC_CHAPTER_END = SWAP_UINT16(0xD400),
    MAGIC_SCENE_BEGIN = SWAP_UINT16(0x9500),
    MAGIC_UNK14 = SWAP_UINT16(0xA300), // $MainGameName
    MAGIC_SCENE_END = SWAP_UINT16(0xD500),
    MAGIC_START_ANIMATION = SWAP_UINT16(0x2000),
    MAGIC_SET_STATE = SWAP_UINT16(0x2300), // Sets movie/audio (Play, Start, Pause, Resume)/BGBUF (AddRender, Passive) state, Start state for process (script thread)
    MAGIC_DESTROY = SWAP_UINT16(0x2400), // Deallocate/Destroy/Remove
    MAGIC_SET_OPACITY = SWAP_UINT16(0x2500),
    MAGIC_UNK20 = SWAP_UINT16(0x3900), // wait?? - Deprecated/broken!
    MAGIC_SLEEP_MS = SWAP_UINT16(0x3A00),
    MAGIC_PLACEHOLDER_PARAM = SWAP_UINT16(0x9100), // nullify parameter?
    MAGIC_SET_PLACEHOLDER = SWAP_UINT16(0xD200), // set value of null param : looks like its not a null, but a placeholder
    MAGIC_SET_AUDIO_STATE = SWAP_UINT16(0x4300), // Music fade effect? SetAudioState(STRING handle, INT num_seconds, INT volume, STRING tempo);
    MAGIC_UNK25 = SWAP_UINT16(0x2800), // Shake()
    MAGIC_ARRAY_READ = SWAP_UINT16(0xDE00), // Dereference pointer (STRING array, INT depth) ??
    MAGIC_UNK27 = SWAP_UINT16(0xE400), // phone related
    MAGIC_CREATE_BOX = SWAP_UINT16(0x1400),
    MAGIC_UNK29 = SWAP_UINT16(0x2B00), // Local to global?
    MAGIC_LOAD_MOVIE = SWAP_UINT16(0x1200),
    MAGIC_UNK31 = SWAP_UINT16(0x2C00), // UNK31(handle, x, y)
    MAGIC_APPLY_BLUR = SWAP_UINT16(0x2D00),
    MAGIC_CREATE_TEXTURE = SWAP_UINT16(0x1B00),
    MAGIC_DRAW_TO_TEXTURE = SWAP_UINT16(0x3000),
    MAGIC_LOGICAL_EQUAL = SWAP_UINT16(0xC000),
    MAGIC_FUNCTION_BEGIN = SWAP_UINT16(0x9700),
    MAGIC_FUNCTION_END = SWAP_UINT16(0xD700),
    MAGIC_UNK38 = SWAP_UINT16(0x0401), // phone/message related
    MAGIC_UNK39 = SWAP_UINT16(0x0501), // phone/message related
    MAGIC_UNK40 = SWAP_UINT16(0x7500), // Retrieve from array at index?
    MAGIC_LOAD_TEXTURE = SWAP_UINT16(0x0D00),
    MAGIC_UNK42 = SWAP_UINT16(0x6100), // get texture width?
    MAGIC_UNK43 = SWAP_UINT16(0xA800), // operator / (division)
    MAGIC_UNK44 = SWAP_UINT16(0xA700),
    MAGIC_LOGICAL_NOT = SWAP_UINT16(0xAC00), // Negate(!) previous parameter?
    MAGIC_UNK46 = SWAP_UINT16(0x9900), // Label definitions (end of while loop, see: MAGIC_LABEL)
    MAGIC_GET_MOVIE_TIME = SWAP_UINT16(0x5E00), // GetMovieDuration/TimeLeft?? TODO: Works on music as well
    MAGIC_UNK48 = SWAP_UINT16(0x9D00),
    MAGIC_UNK49 = SWAP_UINT16(0xC200),
    MAGIC_UNK50 = SWAP_UINT16(0x0B00), // copy BGBUF1 to new texture? (See: function.PrintBG)
    MAGIC_UNK51 = SWAP_UINT16(0x0700), // called after handle is MAGIC_DESTROYed UNK51(handle (bgbuf), unk, 0, 0, false);
    MAGIC_UNK52 = SWAP_UINT16(0x2F00), // called after unk51 UNK52(handle (from unk50), handle (bgbuf));
    MAGIC_UNK53 = SWAP_UINT16(0xFC00), // phone related UNK53(PhID_MAY, PhID_CRS, PhID_DAR, PhID_NONE);
    MAGIC_UNK54 = SWAP_UINT16(0xBE00), // operator++
    MAGIC_UNK55 = SWAP_UINT16(0xC400), // operator < ? <= ? > ? >= ?
    MAGIC_APPLY_MASK = SWAP_UINT16(0x3800),
    MAGIC_UNK57 = SWAP_UINT16(0xC300), // increment?
    MAGIC_UNK58 = SWAP_UINT16(0xA600),
    MAGIC_UNK59 = SWAP_UINT16(0xEB00), // FM_From_DAR0203 (.ogg)
    MAGIC_UNK60 = SWAP_UINT16(0xEA00),
    MAGIC_UNK61 = SWAP_UINT16(0xB100),
    MAGIC_UNK62 = SWAP_UINT16(0xFB00),
    MAGIC_UNK63 = SWAP_UINT16(0xB200),
    MAGIC_UNK64 = SWAP_UINT16(0xC500),
    MAGIC_UNK65 = SWAP_UINT16(0xDF00), // jump to loop begin/check condition?
    MAGIC_UNK66 = SWAP_UINT16(0x7A00),
    MAGIC_UNK67 = SWAP_UINT16(0x1C00),
    MAGIC_UNK68 = SWAP_UINT16(0x1900),
    MAGIC_CREATE_ARRAY = SWAP_UINT16(0x7200), // create array? variable # of args...see: st, achievements...
    MAGIC_BIND_IDENTIFIER = SWAP_UINT16(0x7300), // called right after 69, bind identifiers?
    MAGIC_UNK71 = SWAP_UINT16(0x1600),
    MAGIC_UNK72 = SWAP_UINT16(0x6200), // get texture height?
    MAGIC_UNK73 = SWAP_UINT16(0x7400), // get array size?
    MAGIC_SET_FONT_ATTRIBUTES = SWAP_UINT16(0x4E00), // SetFontAttributes(STRING font, INT size, STRING color1, STRING color2, INT unk, STRING unk)
    MAGIC_UNK75 = SWAP_UINT16(0x1300),
    MAGIC_CREATE_COLOR = SWAP_UINT16(0x0A00),
    MAGIC_UNK77 = SWAP_UINT16(0x0800),
    MAGIC_UNK78 = SWAP_UINT16(0x1800),
    MAGIC_UNK79 = SWAP_UINT16(0x3500),
    MAGIC_UNK80 = SWAP_UINT16(0x1C01),
    MAGIC_UNK81 = SWAP_UINT16(0xA900),
    MAGIC_UNK82 = SWAP_UINT16(0x6E00),
    MAGIC_FORMAT = SWAP_UINT16(0x6500),
    MAGIC_UNK84 = SWAP_UINT16(0x8A00),
    MAGIC_UNK85 = SWAP_UINT16(0x9A00),
    MAGIC_CALL_SCRIPT = SWAP_UINT16(0xA200), // seems incorrect: has path to nss/somefile.nsb as param
    MAGIC_UNK87 = SWAP_UINT16(0x9B00),
    MAGIC_UNK88 = SWAP_UINT16(0xDD00),
    MAGIC_UNK89 = SWAP_UINT16(0xE000),
    MAGIC_UNK90 = SWAP_UINT16(0x0101),
    MAGIC_UNK91 = SWAP_UINT16(0x5400),
    MAGIC_UNK92 = SWAP_UINT16(0x5500),
    MAGIC_UNK93 = SWAP_UINT16(0x6B00),
    MAGIC_UNK94 = SWAP_UINT16(0x0001),
    MAGIC_CREATE_THREAD = SWAP_UINT16(0x0900), // creates script thread? CreateThread(handle, priority, unk, unk, function)
    MAGIC_ZOOM = SWAP_UINT16(0x2600),
    MAGIC_UNK97 = SWAP_UINT16(0x6C00),
    MAGIC_UNK98 = SWAP_UINT16(0x3400),
    MAGIC_UNK99 = SWAP_UINT16(0x9C00),
    MAGIC_UNK100 = SWAP_UINT16(0xF700),
    MAGIC_UNK101 = SWAP_UINT16(0xF800),
    MAGIC_REGISTER_CALLBACK = SWAP_UINT16(0x5800), // Call script when button is pressed
    MAGIC_UNK103 = SWAP_UINT16(0x4F00),
    MAGIC_UNK104 = SWAP_UINT16(0x5100),
    MAGIC_UNK105 = SWAP_UINT16(0x5F00),
    MAGIC_UNK106 = SWAP_UINT16(0x4C00),
    MAGIC_UNK107 = SWAP_UINT16(0x4A00),
    MAGIC_UNK108 = SWAP_UINT16(0x5200),
    MAGIC_UNK109 = SWAP_UINT16(0x4000),
    MAGIC_UNK110 = SWAP_UINT16(0xBF00),
    MAGIC_UNK111 = SWAP_UINT16(0x4B00),
    MAGIC_UNK112 = SWAP_UINT16(0x3200),
    MAGIC_UNK113 = SWAP_UINT16(0x4100),
    MAGIC_UNK114 = SWAP_UINT16(0x5C00),
    MAGIC_UNK115 = SWAP_UINT16(0x1801),
    MAGIC_UNK116 = SWAP_UINT16(0xAA00),
    MAGIC_UNK117 = SWAP_UINT16(0xE800),
    MAGIC_UNK118 = SWAP_UINT16(0x1301),
    MAGIC_UNK119 = SWAP_UINT16(0x1D01),
    MAGIC_UNK120 = SWAP_UINT16(0x1201),
    MAGIC_UNK121 = SWAP_UINT16(0x1101),
    MAGIC_UNK122 = SWAP_UINT16(0xF100),
    MAGIC_UNK123 = SWAP_UINT16(0x1601),
    MAGIC_UNK124 = SWAP_UINT16(0xE500),
    MAGIC_UNK125 = SWAP_UINT16(0xE600),
    MAGIC_UNK126 = SWAP_UINT16(0xF600),
    MAGIC_UNK127 = SWAP_UINT16(0xED00), // see UNK59
    MAGIC_UNK128 = SWAP_UINT16(0xFA00),
    MAGIC_UNK129 = SWAP_UINT16(0x0F01),
    MAGIC_UNK130 = SWAP_UINT16(0xE700),
    MAGIC_UNK131 = SWAP_UINT16(0x5D00),
    MAGIC_UNK132 = SWAP_UINT16(0xE900),
    MAGIC_UNK133 = SWAP_UINT16(0x0C01),
    MAGIC_UNK134 = SWAP_UINT16(0x0D01),
    MAGIC_UNK135 = SWAP_UINT16(0x1701),
    MAGIC_UNK136 = SWAP_UINT16(0x0701),
    MAGIC_UNK137 = SWAP_UINT16(0xF300),
    MAGIC_UNK138 = SWAP_UINT16(0xF000),
    MAGIC_UNK139 = SWAP_UINT16(0x1901),
    MAGIC_UNK140 = SWAP_UINT16(0x1001),
    MAGIC_UNK141 = SWAP_UINT16(0xF500),
    MAGIC_UNK142 = SWAP_UINT16(0xEC00), // see UNK127
    MAGIC_UNK143 = SWAP_UINT16(0xF900),
    MAGIC_UNK144 = SWAP_UINT16(0x0A01),
    MAGIC_UNK145 = SWAP_UINT16(0xFE00),
    MAGIC_UNK146 = SWAP_UINT16(0xAE00),
    MAGIC_UNK147 = SWAP_UINT16(0x1401),
    MAGIC_UNK148 = SWAP_UINT16(0x1501),
    MAGIC_UNK149 = SWAP_UINT16(0xB900),
    MAGIC_UNK150 = SWAP_UINT16(0xAB00),
    MAGIC_UNK151 = SWAP_UINT16(0x0E00), // LoadTextureClip(handle, priority, x1, y1, x2, y2, h (unk), v (unk), file)
    MAGIC_UNK152 = SWAP_UINT16(0x0600), // LoadSt($nut, $立画優先度, $StPlaceX, $StPlaceY, 128, $St画像, false);
    MAGIC_UNK153 = SWAP_UINT16(0x0F00),
    MAGIC_UNK154 = SWAP_UINT16(0x3100),
    MAGIC_LOAD_AUDIO = SWAP_UINT16(0x1100), // LoadAudio(STRING handle, STRING type, STRING file); type is SE/BGM/VOICE
    MAGIC_SET_AUDIO_RANGE = SWAP_UINT16(0x4700), // PlayRange? Maybe this is where it gets loaded to memory
    MAGIC_UNK157 = SWAP_UINT16(0x4500), // Audio related (set speed) (STRING handle, INT unk, INT speed, STRING unk)
    MAGIC_UNK158 = SWAP_UINT16(0x4400), // Audio related (STRING handle, INT unk, STRING direction, STRING unk)
    MAGIC_SET_AUDIO_LOOP = SWAP_UINT16(0x4600),
    MAGIC_UNK160 = SWAP_UINT16(0x3700),
    MAGIC_UNK161 = SWAP_UINT16(0x7000), // LoadScript?
    MAGIC_UNK162 = SWAP_UINT16(0x6400),
    MAGIC_SET_TEXTBOX_ATTRIBUTES = SWAP_UINT16(0x0E01), // SetTextboxAttributes(STRING handle, INT unk, STRING font, INT unk, STRING color1, STRING color2, INT unk, STRING unk)
    MAGIC_UNK164 = SWAP_UINT16(0x1D00),
    MAGIC_DISPLAY_TEXT = SWAP_UINT16(0x4200),
    MAGIC_UNK166 = SWAP_UINT16(0x4900),
    MAGIC_UNK167 = SWAP_UINT16(0x5900),
    MAGIC_UNK168 = SWAP_UINT16(0x6000),
    MAGIC_UNK169 = SWAP_UINT16(0x0300),
    MAGIC_UNK170 = SWAP_UINT16(0x3C00),
    MAGIC_UNK171 = SWAP_UINT16(0x5300),
    MAGIC_UNK172 = SWAP_UINT16(0x6F00),
    MAGIC_UNK173 = SWAP_UINT16(0x6700),
    MAGIC_UNK174 = SWAP_UINT16(0x5600),
    MAGIC_UNK175 = SWAP_UINT16(0x5700),
    MAGIC_UNK176 = SWAP_UINT16(0x5000),
    MAGIC_UNK177 = SWAP_UINT16(0x7100),
    MAGIC_UNK178 = SWAP_UINT16(0x3600),
    MAGIC_UNK179 = SWAP_UINT16(0xF200),
    MAGIC_UNK180 = SWAP_UINT16(0xEF00),
    MAGIC_UNK181 = SWAP_UINT16(0x1700),
    MAGIC_UNK182 = SWAP_UINT16(0x4800),
    MAGIC_UNK183 = SWAP_UINT16(0xE300),
    MAGIC_UNK184 = SWAP_UINT16(0x6600),
    MAGIC_UNK185 = SWAP_UINT16(0x1A01),
    MAGIC_UNK186 = SWAP_UINT16(0x5A00),
    MAGIC_UNK187 = SWAP_UINT16(0xFF00), // UnlockTip (from function.TipsOn)
    MAGIC_UNK188 = SWAP_UINT16(0xD900),
    MAGIC_UNK189 = SWAP_UINT16(0x2700),
    MAGIC_UNK190 = SWAP_UINT16(0x2E00),
    MAGIC_UNK191 = SWAP_UINT16(0x0200),
    MAGIC_UNK192 = SWAP_UINT16(0x2E00),
    MAGIC_UNK193 = SWAP_UINT16(0xB800),
    MAGIC_UNK194 = SWAP_UINT16(0x3B00),
    MAGIC_UNKMAX = 195
};

#endif
