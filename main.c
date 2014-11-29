#include <signal.h>
#include "qi_common.h"
#include "curses.h"

typedef struct QiState
{
	WINDOW *win;
	int curX;
	int curY;
	char ch;
#define QI_MODE_EDT 0
#define QI_MODE_CMD 1
	int mode;
} QiState;

static int _doStateBar(QiState *st)
{
	getyx(st->win, st->curY, st->curX);
	mvwprintw(st->win, 0, 0, "W:%3d H:%3d - W:%3d H:%3d [%02x] mode:%s", COLS, LINES, st->curX, st->curY, st->ch,
			  st->mode == QI_MODE_EDT ? "EDIT" : "CMD ");
	wmove(st->win, st->curY, st->curX);

	return 0;
}

static int _moveLeft(QiState *st)
{
	wmove(st->win, st->curY, st->curX - 1);
	return 0;
}

static int _moveRight(QiState *st)
{
	wmove(st->win, st->curY, st->curX + 1);
	return 0;
}

static int _moveUp(QiState *st)
{
	if (st->curY == 1) {
		return -1;
	}
	wmove(st->win, st->curY - 1, st->curX);
	return 0;
}

static int _moveDown(QiState *st)
{
	wmove(st->win, st->curY + 1, st->curX);
	return 0;
}

static int _doCmd(QiState *st)
{
	switch (st->ch) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
		break;
	case 'e':
		break;
		st->mode = QI_MODE_EDT;
		break;
	case 'f':
		break;
	case 'g':
		break;
	case 'h':
		_moveLeft(st);
		break;
	case 'i':
		st->mode = QI_MODE_EDT;
		break;
	case 'j':
		_moveDown(st);
		break;
	case 'k':
		_moveUp(st);
		break;
	case 'l':
		_moveRight(st);
		break;
	case 'm':
		break;
	case 'n':
		break;
	case 'o':
		break;
	case 'p':
		break;
	case 'q':
		break;
	case 'r':
		break;
	case 's':
		break;
	case 't':
		break;
	case 'u':
		break;
	case 'v':
		break;
	case 'w':
		break;
	case 'x':
		break;
	case 'y':
		break;
	case 'z':
		break;
	case '-':
		break;
	case '=':
		break;
	case '`':
		break;
	case '[':
		break;
	case ']':
		break;
	case ';':
		break;
	case ',':
		break;
	case '.':
		break;
	case '/':
		break;
	default:
		break;
	}

	return 0;
}

static int _doEdit(QiState *st)
{
	switch (st->ch) {
	case QI_KEY_SOH: /* ^a ヘッディング開始   */
	case QI_KEY_STX: /* ^b テキスト開始       */
	case QI_KEY_ETX: /* ^c テキスト終了       */
	case QI_KEY_EOT: /* ^d 伝送終了           */
	case QI_KEY_ENQ: /* ^e 問合せ             */
	case QI_KEY_ACK: /* ^f 肯定応答           */
	case QI_KEY_BEL: /* ^g ベル               */
		st->mode = QI_MODE_CMD;
		break;
	case QI_KEY_BS:  /* ^h 後退               */
	case QI_KEY_HT:  /* ^i 水平タブ           */
	case QI_KEY_LF:  /* ^j 改行               */
	case QI_KEY_VT:  /* ^k 垂直タブ           */
	case QI_KEY_FF:  /* ^l 書式送り           */
	case QI_KEY_CR:  /* ^m 復帰               */
	case QI_KEY_SO:  /* ^n シフトアウト       */
	case QI_KEY_SI:  /* ^o シフトイン         */
	case QI_KEY_DLE: /* ^p 伝送制御拡張       */
	case QI_KEY_DC1: /* ^q 装置制御1,XON      */
	case QI_KEY_DC2: /* ^r 装置制御2          */
	case QI_KEY_DC3: /* ^s 装置制御3,XOFF     */
	case QI_KEY_DC4: /* ^t 装置制御4          */
	case QI_KEY_NAK: /* ^u 否定応答           */
	case QI_KEY_SYN: /* ^v 同期信号           */
	case QI_KEY_ETB: /* ^w 伝送ブロック終結   */
	case QI_KEY_CAN: /* ^x 取消               */
	case QI_KEY_EM:  /* ^y 媒体終端           */
	case QI_KEY_SUB: /* ^x 置換               */
	case QI_KEY_ESC: /* ^[ エスケープ         */
	case QI_KEY_FS:  /* ^\ ファイル分離標識   */
	case QI_KEY_GS:  /* ^] グループ分離標識   */
	case QI_KEY_RS:  /* ^^ レコード分離標識   */
	case QI_KEY_US:  /* ^_ ユニット分離標識   */
		break;
	case QI_KEY_DEL: /* ^? DEL                */
		_moveLeft(st);
		wdelch(st->win);
		break;
	default:
		winsch(st->win, st->ch);
		wmove(st->win, st->curY, st->curX + 1);
		break;
	}
	return 0;
}

int main(void)
{
	int ret;
	QiState st;

	ret = qiInitCurses(&st.win);
	if (ret != QI_OK) {
		goto _EXIT;
	}

	qiDraw256colors();

	ret = qiDisableEcho();
	if (ret != QI_OK) {
		goto _EXIT;
	}

	st.ch = 0;
	st.mode = QI_MODE_CMD;

	for (;;) {
		_doStateBar(&st);

		st.ch = wgetch(st.win);
		if (st.mode == QI_MODE_CMD) {
			_doCmd(&st);
		} else {
			_doEdit(&st);
		}
		wrefresh(st.win);
	}

_EXIT:
	qiTermCurses();
	return 0;
}
