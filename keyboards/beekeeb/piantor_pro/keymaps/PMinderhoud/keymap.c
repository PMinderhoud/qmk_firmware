// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/achordion.h"

// Enums
enum layers {
    BASE,
    BASE_NOMOD,
    QWERTY,
    DIACRIT,
    FUNC,
    SYM,
    NAV,
    ADJUST,
};

enum custom_keycodes {
    PK_ISNOT = SAFE_RANGE,
    SELWORD,
};

enum unicode_names {
  U_SS_LOWER,
  U_SS_UPPER,
  U_NTIL_LOWER,
  U_NTIL_UPPER,
  U_CCED_LOWER,
  U_CCED_UPPER,
  U_IQUE_SYM,
  U_A_TREMA_L,
  U_A_TREMA_U,
  U_A_AIGU_L,
  U_A_AIGU_U,
  U_A_GRAVE_L,
  U_A_GRAVE_U,
  U_E_TREMA_L,
  U_E_TREMA_U,
  U_E_AIGU_L,
  U_E_AIGU_U,
  U_E_GRAVE_L,
  U_E_GRAVE_U,
  U_E_CIRC_L,
  U_E_CIRC_U,
  U_I_TREMA_L,
  U_I_TREMA_U,
  U_I_AIGU_L,
  U_I_AIGU_U,
  U_I_CIRC_L,
  U_I_CIRC_U,
  U_O_TREMA_L,
  U_O_TREMA_U,
  U_O_AIGU_L,
  U_O_AIGU_U,
  U_O_CIRC_L,
  U_O_CIRC_U,
  U_U_TREMA_L,
  U_U_TREMA_U,
  U_U_AIGU_L,
  U_U_AIGU_U,
  U_U_CIRC_L,
  U_U_CIRC_U,
  U_EURO,
};

// Home row mods for Base (Recurva) layer.
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_T LCTL_T(KC_T)
#define HOME_C LSFT_T(KC_C)
#define HOME_H RSFT_T(KC_H)
#define HOME_E RCTL_T(KC_E)
#define HOME_A LALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)

// Home row mods for QWERTY layer.
#define QHOME_A LGUI_T(KC_A)
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LSFT_T(KC_D)
#define QHOME_F LCTL_T(KC_F)
#define QHOME_J RCTL_T(KC_J)
#define QHOME_K RSFT_T(KC_K)
#define QHOME_L LALT_T(KC_L)
#define QHOME_SC RGUI_T(KC_SCLN)

#define DHOME_C LSFT_T(U_CCED)
#define DHOME_O RSFT_T(U_OTREM)

#define SHOME_EX LGUI_T(KC_EXLM)
#define SHOME_LT LALT_T(KC_LABK)
#define SHOME_GT LCTL_T(KC_RABK)
#define SHOME_EQ LSFT_T(KC_EQL)

#define NHOME_CZ LGUI_T(C(KC_Z))
#define NHOME_CX LALT_T(C(KC_X))
#define NHOME_CC LCTL_T(C(KC_C))
#define NHOME_CV LSFT_T(C(KC_V))

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
  [U_A_GRAVE_L]  = 0x00e0,  // à
  [U_A_GRAVE_L]  = 0x00c0,  // À
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
  [U_O_TREMA_L]  = 0x00f6,  // ö
  [U_O_TREMA_U]  = 0x00d6,  // Ö
  [U_O_AIGU_L]   = 0x00f3,  // ó
  [U_O_AIGU_U]   = 0x00d3,  // Ó
  [U_O_CIRC_L]   = 0x00f4,  // ô
  [U_O_CIRC_U]   = 0x00d4,  // Ô
  [U_U_TREMA_L]  = 0x00fc,  // ü
  [U_U_TREMA_U]  = 0x00dc,  // Ü
  [U_U_AIGU_L]   = 0x00fa,  // ú
  [U_U_AIGU_U]   = 0x00da,  // Ú
  [U_U_CIRC_L]   = 0x00fb,  // û
  [U_U_CIRC_U]   = 0x00db,  // Û
  [U_EURO]       = 0x20ac,  // €
};

#define U_SS UP(U_SS_LOWER, U_SS_UPPER)
// ñ and Ñ keycode.
#define U_NTIL UP(U_NTIL_LOWER, U_NTIL_UPPER)
// ç and Ç keycode.
#define U_CCED UP(U_CCED_LOWER, U_CCED_UPPER)
#define U_ATREM UP(U_A_TREMA_L, U_A_TREMA_U)
#define U_AAIGU UP(U_A_AIGU_L, U_A_AIGU_U)
#define U_AGRAV UP(U_A_GRAVE_L, U_A_GRAVE_L)
#define U_ETREM UP(U_E_TREMA_L, U_E_TREMA_U)
#define U_EAIGU UP(U_E_AIGU_L, U_E_AIGU_U)
#define U_EGRAV UP(U_E_GRAVE_L, U_E_GRAVE_U)
#define U_ECIRC UP(U_E_CIRC_L, U_E_CIRC_U)
#define U_ITREM UP(U_I_TREMA_L, U_I_TREMA_U)
#define U_IAIGU UP(U_I_AIGU_L, U_I_AIGU_U)
#define U_ICIRC UP(U_I_CIRC_L, U_I_CIRC_U)
#define U_OTREM UP(U_O_TREMA_L, U_O_TREMA_U)
#define U_OAIGU UP(U_O_AIGU_L, U_O_AIGU_U)
#define U_OCIRC UP(U_O_CIRC_L, U_O_CIRC_U)
#define U_UTREM UP(U_U_TREMA_L, U_U_TREMA_U)
#define U_UAIGU UP(U_U_AIGU_L, U_U_AIGU_U)
#define U_UCIRC UP(U_U_CIRC_L, U_U_CIRC_U)

#define L_SP_NAV LT(NAV,KC_SPC)
#define L_BS_SYM LT(SYM,KC_BACKSPACE)
#define L_RA_DIA LT(DIACRIT,KC_RALT)
#define L_TB_FNC LT(FUNC,KC_TAB)

#define SK_NWDSK G(C(KC_D))     // New desktop
#define SK_CLDSK G(C(KC_F4))     // Close desktop
#define SK_PRDSK G(C(KC_LEFT))     // Previous desktop
#define SK_NXDSK G(C(KC_RIGHT))     // Next desktop

#define RC(kc) RCTL(kc)

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
                                          KC_LSFT,L_SP_NAV,L_RA_DIA,     KC_ENT,L_BS_SYM,L_TB_FNC
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
      _______, _______, _______, _______,  U_EURO, _______,                      _______, _______, U_EGRAV, U_AGRAV, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______,  U_NTIL,  U_CCED, KC_LSFT, _______,                      U_UTREM, U_OTREM, U_ETREM, U_ATREM, U_ITREM, _______,
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
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,L_SP_NAV,L_RA_DIA,     KC_ENT,L_BS_SYM,L_TB_FNC
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PERC, KC_PLUS, KC_MINS,  KC_DLR, KC_LCBR,                      KC_RCBR,    KC_7,    KC_8,    KC_9,   KC_AT, KC_COLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_LABK, KC_RABK,SHOME_EQ, KC_LPRN,                      KC_RPRN,    KC_1,    KC_2,    KC_3,    KC_0, KC_QUES,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_CIRC, KC_ASTR, KC_SLSH, KC_UNDS, KC_LBRC,                      KC_RBRC,    KC_4,    KC_5,    KC_6, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_AMPR, _______, KC_PIPE,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, SELWORD, C(KC_N),C(KC_F4),                    G(KC_TAB),   KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,  SK_CLDSK,
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
      DM_REC1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY1,                      XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, MO(ADJUST),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DM_REC2, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, DM_PLY2,                      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, TG(BASE_NOMOD), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

enum combos {
  ECIRC,
  ICIRC,
  OCIRC,
  UCIRC,
  DBL_QTE,
  EXCLAMATION,
  QUESTION,
  COLON,
  ISNOT
};

const uint16_t PROGMEM ecirc_combo[] = {U_ETREM, U_EAIGU, COMBO_END};
const uint16_t PROGMEM icirc_combo[] = {U_ITREM, U_IAIGU, COMBO_END};
const uint16_t PROGMEM ocirc_combo[] = {U_OTREM, U_OAIGU, COMBO_END};
const uint16_t PROGMEM ucirc_combo[] = {U_UTREM, U_UAIGU,  COMBO_END};
const uint16_t PROGMEM dblqte_combo[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM exclamation_combo[] = {KC_SCLN, KC_L, COMBO_END};
const uint16_t PROGMEM question_combo[] = {KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_X, KC_K, COMBO_END};
const uint16_t PROGMEM notnull_combo[] = {KC_EXLM, SHOME_EQ, COMBO_END};


combo_t key_combos[] = {
  [ECIRC] = COMBO(ecirc_combo, U_ECIRC),
  [ICIRC] = COMBO(icirc_combo, U_ICIRC),
  [OCIRC] = COMBO(ocirc_combo, U_OCIRC),
  [UCIRC] = COMBO(ucirc_combo, U_UCIRC),
  [DBL_QTE] = COMBO(dblqte_combo, KC_DOUBLE_QUOTE),
  [EXCLAMATION] = COMBO(exclamation_combo, KC_EXCLAIM),
  [QUESTION] = COMBO(question_combo, KC_QUESTION),
  [COLON] = COMBO(colon_combo, KC_COLON),
  [ISNOT] = COMBO(notnull_combo, PK_ISNOT)
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  // Your macros ...
  switch (keycode) {
    case PK_ISNOT:
        if (record->event.pressed) {
            SEND_STRING(" is not ");
        }
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
