#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

enum layer_number {
  _QWERTY = 0,
};

// Tap Dance declarations
enum {
    TD_SPC_ENT,
};


// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
};

#define SFT_ESC SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  _______,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,  _______,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                          KC_LALT, KC_LGUI, SFT_ESC, QK_LEAD, TD(TD_SPC_ENT), KC_TAB, KC_BSPC,    KC_RCTL
 )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return true;
}
#endif

// Using mnemonics for symbols
void leader_end_user(void) {

    if (leader_sequence_one_key(QK_LEAD)) {
        SEND_STRING(SS_TAP(X_ESC));

    } else if (leader_sequence_one_key(KC_D)) {
        SEND_STRING("-");
    } else if (leader_sequence_one_key(KC_U)) {
        SEND_STRING("_");
    } else if (leader_sequence_one_key(KC_P)) {
        SEND_STRING("+");
    } else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING("=");

    } else if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING("'");
    } else if (leader_sequence_two_keys(KC_Q, KC_Q)) {
        SEND_STRING("\"");
    } else if (leader_sequence_three_keys(KC_Q, KC_Q, KC_Q) || leader_sequence_one_key(KC_G)) {
        SEND_STRING("`");

    } else if (leader_sequence_one_key(KC_T)) {
        SEND_STRING("~");
    } else if (leader_sequence_one_key(KC_SLSH)) {
        SEND_STRING("\\");
    } else if (leader_sequence_two_keys(KC_SLSH, KC_SLSH)) {
        SEND_STRING("|");
    } else if (leader_sequence_one_key(KC_C)) {
        SEND_STRING(":");
    } else if (leader_sequence_one_key(KC_I)) {
        SEND_STRING("?");

    } else if (leader_sequence_one_key(KC_9)) {
        SEND_STRING("()");
    } else if (leader_sequence_two_keys(KC_9, KC_9)) {
        SEND_STRING("[]");
    } else if (leader_sequence_three_keys(KC_9, KC_9, KC_9)) {
        SEND_STRING("{}");

    } else if (leader_sequence_one_key(KC_COMM)) {
        SEND_STRING(SS_TAP(X_LEFT));
    } else if (leader_sequence_one_key(KC_DOT)) {
        SEND_STRING(SS_TAP(X_RIGHT));

    } else if (leader_sequence_two_keys(KC_1, KC_1)) {
        SEND_STRING(SS_TAP(X_F1));
    } else if (leader_sequence_two_keys(KC_2, KC_2)) {
        SEND_STRING(SS_TAP(X_F2));
    } else if (leader_sequence_two_keys(KC_3, KC_3)) {
        SEND_STRING(SS_TAP(X_F3));
    }
}
