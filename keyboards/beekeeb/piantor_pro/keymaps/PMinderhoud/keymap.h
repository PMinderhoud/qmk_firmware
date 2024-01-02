#pragma once
#include QMK_KEYBOARD_H

// Enums
enum layers {
    BASE,
    BASE_NOMOD,
    QWERTY,
    DIACRIT,
    SYM,
    NAV,
    FUNC,
    ADJUST,
};

enum custom_keycodes {
    PK_ISNOT = SAFE_RANGE,
    SELWORD,
    CAMELCSE,    // thisIsASample
    PASCLCSE,    // ThisIsASample
    CAPSWORD,    // THIS is a sample
    CONSTCSE,    // THIS_IS_A_SAMPLE
    LLOCK,
    PK_ZEROX,
    PK_DZERO,
    PK_TZERO
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

// UNICODE
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

// LAYER KEYS
#define L_SP_NAV LT(NAV,KC_SPC)
#define L_BS_SYM LT(SYM,KC_BACKSPACE)
#define L_RA_DIA LT(DIACRIT,KC_RALT)
#define L_TB_FNC LT(FUNC,KC_TAB)

#define SK_NWDSK G(C(KC_D))     // New desktop
#define SK_CLDSK G(C(KC_F4))     // Close desktop
#define SK_PRDSK G(C(KC_LEFT))     // Previous desktop
#define SK_NXDSK G(C(KC_RIGHT))     // Next desktop
