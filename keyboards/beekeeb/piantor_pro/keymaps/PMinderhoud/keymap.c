// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include "keymap.h"
#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/achordion.h"
#include "features/caps_word.h"
#include "features/layer_lock.h"

// Mappings
const uint32_t unicode_map[] PROGMEM = {
  [U_SS_LOWER]   = 0x00df,  // ß
  [U_SS_UPPER]   = 0x1e9e,  // ẞ
  [U_NTIL_LOWER] = 0x00f1,  // ñ
  [U_NTIL_UPPER] = 0x00d1,  // Ñ
  [U_CCED_LOWER] = 0x00e7,  // ç
  [U_CCED_UPPER] = 0x00c7,  // Ç
  [U_IQUE_SYM]   = 0x00bf,  // ¿
  [U_A_TREMA_L]  = 0x00e4,  // ä
  [U_A_TREMA_U]  = 0x00c4,  // Ä
  [U_A_AIGU_L]   = 0x00e1,  // á
  [U_A_AIGU_U]   = 0x00c1,  // Á
  [U_A_CIRC_L]   = 0x00e2,  // â
  [U_A_CIRC_U]   = 0x00c2,  // Â
  [U_A_GRAVE_L]  = 0x00e0,  // à
  [U_A_GRAVE_U]  = 0x00c0,  // À
  [U_E_TREMA_L]  = 0x00eb,  // ë
  [U_E_TREMA_U]  = 0x00cb,  // Ë
  [U_E_AIGU_L]   = 0x00e9,  // é
  [U_E_AIGU_U]   = 0x00c9,  // É
  [U_E_GRAVE_L]  = 0x00e8,  // è
  [U_E_GRAVE_U]  = 0x00c8,  // È
  [U_E_CIRC_L]   = 0x00ea,  // ê
  [U_E_CIRC_U]   = 0x00ca,  // Ê
  [U_I_TREMA_L]  = 0x00ef,  // ï
  [U_I_TREMA_U]  = 0x00cf,  // Ï
  [U_I_AIGU_L]   = 0x00ed,  // í
  [U_I_AIGU_U]   = 0x00cd,  // Í
  [U_I_CIRC_L]   = 0x00ee,  // î
  [U_I_CIRC_U]   = 0x00ce,  // Î
  [U_I_GRAVE_L]  = 0x00ec,  // ì
  [U_I_GRAVE_U]  = 0x00cc,  // Ì
  [U_O_TREMA_L]  = 0x00f6,  // ö
  [U_O_TREMA_U]  = 0x00d6,  // Ö
  [U_O_AIGU_L]   = 0x00f3,  // ó
  [U_O_AIGU_U]   = 0x00d3,  // Ó
  [U_O_CIRC_L]   = 0x00f4,  // ô
  [U_O_CIRC_U]   = 0x00d4,  // Ô
  [U_O_GRAVE_L]  = 0x00f2,  // ò
  [U_O_GRAVE_U]  = 0x00d2,  // Ò
  [U_U_TREMA_L]  = 0x00fc,  // ü
  [U_U_TREMA_U]  = 0x00dc,  // Ü
  [U_U_AIGU_L]   = 0x00fa,  // ú
  [U_U_AIGU_U]   = 0x00da,  // Ú
  [U_U_CIRC_L]   = 0x00fb,  // û
  [U_U_CIRC_U]   = 0x00db,  // Û
  [U_U_GRAVE_L]  = 0x00f9,  // ù
  [U_U_GRAVE_U]  = 0x00d9,  // Ù
  [U_EURO_]       = 0x20ac,  // €
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_F,    KC_R,    KC_D,    KC_P,    KC_V,                         KC_Q,    KC_M,    KC_U,    KC_O,    KC_Y,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE,  HOME_S,  HOME_N,  HOME_T,  HOME_C,    KC_B,                       KC_DOT,  HOME_H,  HOME_E,  HOME_A,  HOME_I,KC_SLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_ESCAPE,    KC_Z,    KC_X,    KC_K,    KC_G,    KC_W,                         KC_J,    KC_L, KC_SCLN, KC_QUOT,KC_COMMA, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,L_SP_NAV,L_RA_DIA,   L_EN_SYM,  QK_REP,L_TB_FNC
                                      //`--------------------------'  `--------------------------'

  ),
      [BASE_NOMOD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_S,    KC_N,    KC_T,    KC_C, _______,                      _______,    KC_H,    KC_E,    KC_A,    KC_I, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

      [DIACRIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK, _______, _______, _______,  U_EURO, _______,                      U_UGRAV, U_OGRAV, U_EGRAV, U_AGRAV, U_IGRAV, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    U_SS,  U_NTIL,  U_CCED, KC_LSFT, _______,                      U_UTREM, U_OTREM, U_ETREM, U_ATREM, U_ITREM, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      U_UAIGU, U_OAIGU, U_EAIGU, U_AAIGU, U_IAIGU, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

    [QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, QHOME_A, QHOME_S, QHOME_D, QHOME_F,    KC_G,                         KC_H, QHOME_J, QHOME_K, QHOME_L,QHOME_SC, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,L_SP_NAV,L_RA_DIA,     KC_ENT,L_BS_SYM,L_TB_FNC
                                      //`--------------------------'  `--------------------------'
  ),
    [QWERTY_NOMOD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F, _______,                      _______,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK, KC_PERC, KC_PLUS, KC_MINS,  KC_DLR, KC_LCBR,                      KC_RCBR,    KC_7,    KC_8,    KC_9,   KC_AT, KC_COLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_LABK, KC_RABK,SHOME_EQ, KC_LPRN,                      KC_RPRN,    KC_1,    KC_2,    KC_3,    KC_0, KC_QUES,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_CIRC, KC_ASTR, KC_SLSH, KC_UNDS, KC_LBRC,                      KC_RBRC,    KC_4,    KC_5,    KC_6,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_AMPR, _______, KC_PIPE,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------------.
        LLOCK, XXXXXXX, XXXXXXX, SELWORD, C(KC_N),C(KC_F4),                    G(KC_TAB),   KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,  SK_CLDSK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+----------+----------+----------+----------+----------|
      KC_PSCR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, C(KC_A),                      KC_WSCH,   KC_LEFT,   KC_DOWN,     KC_UP,   KC_RGHT,  SK_NWDSK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+----------+----------+----------+----------+----------|
      C(KC_Y), C(KC_Z), C(KC_X), C(KC_C), C(KC_V), G(KC_V),                     SK_PRDSK,C(KC_PGUP), C(KC_END),C(KC_HOME),C(KC_PGDN),  SK_NXDSK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+----------+----------+----------+----------+----------|
                                          _______, _______, _______,    KC_WBAK, KC_WFWD,  KC_TAB
                                      //`--------------------------'  `--------------------------'
  ),

    [FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LLOCK,CONSTCSE,CAMELCSE,PASCLCSE,CAPSWORD, DM_PLY1,                      DM_REC1,   KC_F9,  KC_F10,  KC_F11,  KC_F12, MO(ADJUST),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, DM_PLY2,                      DM_REC2,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      DM_RSTP,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, DF(QWERTY), DF(BASE), XXXXXXX,                      XXXXXXX, TG(BASE_NOMOD), TG(QWERTY_NOMOD), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

enum combos {
  ACIRC,
  ECIRC,
  ICIRC,
  OCIRC,
  UCIRC,
  DBL_QTE,
  EXCLAMATION,
  QUESTION,
  COLON,
  ISNOT,
  DOT_SYM,
  DBL_QTE_SYM,
  ZEROX,
  DBLZERO,
  TRPLZERO
};

const uint16_t PROGMEM acirc_combo[] = {U_ATREM, U_AAIGU, COMBO_END};
const uint16_t PROGMEM ecirc_combo[] = {U_ETREM, U_EAIGU, COMBO_END};
const uint16_t PROGMEM icirc_combo[] = {U_ITREM, U_IAIGU, COMBO_END};
const uint16_t PROGMEM ocirc_combo[] = {U_OTREM, U_OAIGU, COMBO_END};
const uint16_t PROGMEM ucirc_combo[] = {U_UTREM, U_UAIGU,  COMBO_END};
const uint16_t PROGMEM dblqte_combo[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM exclamation_combo[] = {KC_SCLN, KC_L, COMBO_END};
const uint16_t PROGMEM question_combo[] = {KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_X, KC_K, COMBO_END};
const uint16_t PROGMEM notnull_combo[] = {KC_EXLM, SHOME_EQ, COMBO_END};
const uint16_t PROGMEM dotsym_combo[] = {KC_6, KC_DOT, COMBO_END};
const uint16_t PROGMEM dblqtesym_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM zerox_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM doublezero_combo[] = {KC_3, KC_0, COMBO_END};
const uint16_t PROGMEM triplezero_combo[] = {KC_2, KC_3, KC_0, COMBO_END};

combo_t key_combos[] = {
  [ACIRC] = COMBO(acirc_combo, U_ACIRC),
  [ECIRC] = COMBO(ecirc_combo, U_ECIRC),
  [ICIRC] = COMBO(icirc_combo, U_ICIRC),
  [OCIRC] = COMBO(ocirc_combo, U_OCIRC),
  [UCIRC] = COMBO(ucirc_combo, U_UCIRC),
  [DBL_QTE] = COMBO(dblqte_combo, KC_DOUBLE_QUOTE),
  [EXCLAMATION] = COMBO(exclamation_combo, KC_EXCLAIM),
  [QUESTION] = COMBO(question_combo, KC_QUESTION),
  [COLON] = COMBO(colon_combo, KC_COLON),
  [ISNOT] = COMBO(notnull_combo, PK_ISNOT),
  [DOT_SYM] = COMBO(dotsym_combo, KC_COMMA),
  [DBL_QTE_SYM] = COMBO(dblqtesym_combo, KC_DOUBLE_QUOTE),
  [ZEROX] = COMBO(zerox_combo, PK_ZEROX),
  [DBLZERO] = COMBO(doublezero_combo, PK_DZERO),
  [TRPLZERO] = COMBO(triplezero_combo, PK_TZERO),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  // Your macros ...
  switch (keycode) {
    case PK_ISNOT:
        if (record->event.pressed) {
            SEND_STRING(" is not ");
        }
        break;
    case PK_DZERO:
        if (record->event.pressed) {
            SEND_STRING("00");
        }
        break;
    case PK_TZERO:
        if (record->event.pressed) {
            SEND_STRING("000");
        }
        break;
    case PK_ZEROX:
        if (record->event.pressed) {
            SEND_STRING("0x");
        }
        break;
    case CAPSWORD:
        if (record->event.pressed) {
            toggle_caps_word_mode(CAPS_WORD_MODE_DEFAULT);
            return false;
        }
        break;
    case CAMELCSE:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            return false;
        }
        break;
    case PASCLCSE:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_PASCAL_CASE);
            return false;
        }
        break;
    case CONSTCSE:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            return false;
        }
        break;
  }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

// Disable achordion for the thumb keys
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case L_SP_NAV:
        case L_RA_DIA:
        case L_BS_SYM:
        case L_EN_SYM:
        case L_TB_FNC:
            return 0;
    }
    return 800;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Allow some one hand combinations
  switch (tap_hold_keycode) {
    case HOME_I:  // I + L (GUI+L - lock computer).
      if (other_keycode == KC_L) { return true; }
      break;
  }
  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
