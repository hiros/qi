#if !defined(_QI_QI_COMMON_H_)
#define _QI_QI_COMMON_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

#define QI_OK 0
#define QI_ERR_INIT_CURSES 0x80001000

#define QI_KEY_NUL 0
#define QI_KEY_SOH 1   /* ^a ヘッディング開始   */
#define QI_KEY_STX 2   /* ^b テキスト開始       */
#define QI_KEY_ETX 3   /* ^c テキスト終了       */
#define QI_KEY_EOT 4   /* ^d 伝送終了           */
#define QI_KEY_ENQ 5   /* ^e 問合せ             */
#define QI_KEY_ACK 6   /* ^f 肯定応答           */
#define QI_KEY_BEL 7   /* ^g ベル               */
#define QI_KEY_BS 8    /* ^h 後退               */
#define QI_KEY_HT 9    /* ^i 水平タブ           */
#define QI_KEY_LF 10   /* ^j 改行               */
#define QI_KEY_VT 11   /* ^k 垂直タブ           */
#define QI_KEY_FF 12   /* ^l 書式送り           */
#define QI_KEY_CR 13   /* ^m 復帰               */
#define QI_KEY_SO 14   /* ^n シフトアウト       */
#define QI_KEY_SI 15   /* ^o シフトイン         */
#define QI_KEY_DLE 16  /* ^p 伝送制御拡張       */
#define QI_KEY_DC1 17  /* ^q 装置制御1,XON      */
#define QI_KEY_DC2 18  /* ^r 装置制御2          */
#define QI_KEY_DC3 19  /* ^s 装置制御3,XOFF     */
#define QI_KEY_DC4 20  /* ^t 装置制御4          */
#define QI_KEY_NAK 21  /* ^u 否定応答           */
#define QI_KEY_SYN 22  /* ^v 同期信号           */
#define QI_KEY_ETB 23  /* ^w 伝送ブロック終結   */
#define QI_KEY_CAN 24  /* ^x 取消               */
#define QI_KEY_EM 25   /* ^y 媒体終端           */
#define QI_KEY_SUB 26  /* ^x 置換               */
#define QI_KEY_ESC 27  /* ^[ エスケープ         */
#define QI_KEY_FS 28   /* ^\ ファイル分離標識   */
#define QI_KEY_GS 29   /* ^] グループ分離標識   */
#define QI_KEY_RS 30   /* ^^ レコード分離標識   */
#define QI_KEY_US 31   /* ^_ ユニット分離標識   */
#define QI_KEY_DEL 127 /* ^? DEL                */

#endif /* _QI_QI_COMMON_H_ */
